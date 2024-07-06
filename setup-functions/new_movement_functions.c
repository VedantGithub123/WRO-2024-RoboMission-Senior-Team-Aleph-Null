// Gets the speed of the motor depending on where it is
float motionProfile(float startSpeed, float speed, float endSpeed, float accRate, float deccRate, float targetDistance, float currentDistance, float time, bool accelTime, bool shouldStop)
{
    // Makes sure all the variables are valid
    startSpeed = fabs(startSpeed);
    endSpeed = fabs(endSpeed);
    targetDistance = fabs(targetDistance);

    if (accRate == 0) {
        accRate = INFINITY;
    }

    if (deccRate == 0) {
        deccRate = INFINITY;
    }

    bool movingBackwards = false;
    if (speed < 0)
    {
        movingBackwards = true;
        speed = fabs(speed);
        currentDistance *= -1;
    }

    accRate = fabs(accRate) * (speed-startSpeed > 0 ? 1 : -1);
    deccRate = fabs(deccRate) * (endSpeed-speed > 0 ? 1 : -1);


    // Starts setting the speed based on where it is
    float newSpeed = 0;

    // If the robot is behind, set the speed to the starting speed
    if (currentDistance <= 0)
    {
        newSpeed = startSpeed;
    }

    // Setting the speed for between the start and target for only degrees or only time
    if (!accelTime){
        // Find intersection point of accel line and deccel line
        float accelIntersection = (speed-startSpeed)/accRate;

        float deccelIntersection = (speed-endSpeed)/deccRate + targetDistance - 0.5;

        // If the intersection points are valid, get the speed in a certain way
        if (accelIntersection <= deccelIntersection)
        {
            if (currentDistance < accelIntersection && currentDistance > 0)
            {
                newSpeed = accRate * currentDistance + startSpeed;
            }
            else if (currentDistance > deccelIntersection && currentDistance < targetDistance-0.5)
            {
                newSpeed = deccRate * (currentDistance - targetDistance + 0.5) + endSpeed;
            }
            else
            {
                newSpeed = speed;
            }
        }
        else
        {
            // If there will be no or infinite intersections, speed will go directly from start to end
            if (accRate == deccRate)
            {
                newSpeed = currentDistance*(endSpeed-startSpeed)/(targetDistance-0.5) + startSpeed;
            }
            else
            {
                // Finds intersection point of the accel and deccel lines
                float accDeccIntersection = ((startSpeed-endSpeed)/deccRate + targetDistance - 0.5)/(1-accRate/deccRate);

                // If the intersection is not valid, the speed will go directly from start to end
                if (accDeccIntersection < 0 || accDeccIntersection > targetDistance-0.5)
                {
                    newSpeed = currentDistance*(endSpeed-startSpeed)/(targetDistance-0.5) + startSpeed;
                }
                // If the current distance is before the intersection point, use accRate
                else if (currentDistance < accDeccIntersection)
                {
                    newSpeed = accRate * currentDistance + startSpeed;
                }
                // If the current distance is past the intersection point use, deccRate
                else
                {
                    newSpeed = deccRate * (currentDistance - targetDistance + 0.5) + endSpeed;
                }
            }
        }
    }
    else
    {
        // Setting the speed for between the start and target for accel time and decel degrees
        if (accRate > 0 && deccRate < 0)
        {
            newSpeed = min2(min2(deccRate * (currentDistance - targetDistance + 0.5) + endSpeed, speed), accRate * time + startSpeed);
        }
        else if (accRate < 0 && deccRate < 0)
        {
            newSpeed = min2(max2(accRate * time + startSpeed, speed), deccRate * (currentDistance - targetDistance + 0.5) + endSpeed);

        }
        else if (accRate > 0 && deccRate > 0)
        {
            newSpeed = max2(min2(accRate * time + startSpeed, speed), deccRate * (currentDistance - targetDistance + 0.5) + endSpeed);
        }
        else
        {
            newSpeed = max2(max2(deccRate * (currentDistance - targetDistance + 0.5) + endSpeed, speed), accRate * time + startSpeed);
        }
    }

    // Different overshoot behaviour depending on whether the motor should stop or not
    if (shouldStop)
    {
        // If the motor should stop, set the speed to the ending speed with the right direction
        if (currentDistance >= targetDistance-0.5)
        {
            newSpeed = endSpeed*sgn(targetDistance-currentDistance);
        }
    }
    else
    {
        // If the motor should not stop, set the speed to the ending speed
        if (currentDistance >= targetDistance-0.5)
        {
            newSpeed = endSpeed;
        }
    }


    // Stops the motor in the acceptable range if the motor should stop
    if (fabs(targetDistance-currentDistance) < 0.5 && shouldStop)
    {
        newSpeed = 0;
    }

    return newSpeed*(movingBackwards ? -1 : 1);
}

// Moves the drivetrain to a certain target (CM, Degrees, Seconds)
void move(float lSpeed, float rSpeed, float startSpeed, float endSpeed, float distance, float accRate, float deccRate, float turnkP, float turnkD, bool shouldStop, int state)
{
    // Switches based on the state
    if (state == RELCM)
    {
        distance = degFromCM(distance);
        state = RELDEG;
    }
    else if (state == TIME)
    {
        deccRate *= timeAccelRatio;
    }
    accRate *= timeAccelRatio;

    float prevTurnErr = 0;

    turnkP = fabs(turnkP);
    turnkD = fabs(turnkD);

    if (sgn(rSpeed)!=sgn(lSpeed))
    {
        turnkP *= turnPIDScale;
        turnkD *= turnPIDScale;
    }
    if (fabs(rSpeed)!=fabs(lSpeed))
    {
        turnkP *= turnPIDScale;
        turnkD *= turnPIDScale;
    }

    startSpeed = fabs(startSpeed);
    endSpeed = fabs(endSpeed);

    if (fabs(lSpeed) > fabs(rSpeed))
    {
        distance = fabs(distance)*sgn(lSpeed);
    }
    else
    {
        distance = fabs(distance)*sgn(rSpeed);
    }

    // Variables for the main loop
    float leftSpeed;
    float rightSpeed;
    float turnErr;
    float steer;

    // Starts the main loop
    clearTimer(T2);

    while (true)
    {
        // Does the exit conditions
        if (state == TIME)
        {
            if (time1(T2)>=fabs(distance))
            {
                break;
            }
        }
        else
        {
            if (time1(T2)>=3000)
            {
                break;
            }
            if (!shouldStop)
            {
                if (fabs(lSpeed) > fabs(rSpeed))
                {
                    if (fabs(getRelDegrees(LEFT)) >= fabs(distance)-0.5 && fabs(getRelDegrees(RIGHT)) >= fabs(distance*rSpeed/lSpeed)-0.5)
                    {
                        break;
                    }
                }
                else
                {
                    if (fabs(getRelDegrees(RIGHT)) >= fabs(distance)-0.5 && fabs(getRelDegrees(LEFT)) >= fabs(distance*lSpeed/rSpeed)-0.5)
                    {
                        break;
                    }
                }
            }
            else
            {
                if (fabs(lSpeed) > fabs(rSpeed))
                {
                    if (fabs(getRelDegrees(LEFT)-distance) <= 0.5 && fabs(getRelDegrees(RIGHT)-distance*rSpeed/lSpeed) <= 0.5)
                    {
                        break;
                    }
                }
                else
                {
                    if (fabs(getRelDegrees(RIGHT)-distance) <= 0.5 && fabs(getRelDegrees(LEFT)-distance*lSpeed/rSpeed) <= 0.5)
                    {
                        break;
                    }
                }
            }
        }

        // Gets the speeds the motors should move at
        if (state == TIME)
        {
            if (fabs(lSpeed) >= fabs(rSpeed))
            {
                leftSpeed = motionProfile(startSpeed, lSpeed, endSpeed, accRate, deccRate, distance, time1(T2)*sgn(lSpeed), time1(T2)*sgn(lSpeed), false, shouldStop);
                rightSpeed = leftSpeed*rSpeed/lSpeed;
            }
            else
            {
                rightSpeed = motionProfile(startSpeed, rSpeed, endSpeed, accRate, deccRate, distance, time1(T2)*sgn(rSpeed), time1(T2)*sgn(rSpeed), false, shouldStop);
                leftSpeed = rightSpeed*lSpeed/rSpeed;
            }
        }
        else
        {
            if (fabs(lSpeed) >= fabs(rSpeed))
            {
                leftSpeed = motionProfile(startSpeed, lSpeed, endSpeed, accRate, deccRate, distance, getRelDegrees(LEFT), time1(T2), true, shouldStop);
                rightSpeed = motionProfile(startSpeed*rSpeed/lSpeed, rSpeed, endSpeed*rSpeed/lSpeed, accRate*rSpeed/lSpeed, deccRate*rSpeed/lSpeed, distance*rSpeed/lSpeed, getRelDegrees(RIGHT), time1(T2), true, shouldStop);
            }
            else
            {
                rightSpeed = motionProfile(startSpeed, rSpeed, endSpeed, accRate, deccRate, distance, getRelDegrees(RIGHT), time1(T2), true, shouldStop);
                leftSpeed = motionProfile(startSpeed*lSpeed/rSpeed, lSpeed, endSpeed*lSpeed/rSpeed, accRate*lSpeed/rSpeed, deccRate*lSpeed/rSpeed, distance*lSpeed/rSpeed, getRelDegrees(LEFT), time1(T2), true, shouldStop);
            }
        }

        // Move sync PD below
        turnErr = getRelDegrees(LEFT)*rSpeed-getRelDegrees(RIGHT)*lSpeed;
        turnErr /= (fabs(rSpeed)+fabs(lSpeed));

        if (sgn(lSpeed)!=sgn(rSpeed))
        {
            turnErr *= -1.0;
        }

        // PD Implementation
        steer = turnErr*turnkP+(turnErr-prevTurnErr)*turnkD;

        if (lSpeed == 0)
        {
            leftSpeed = -10*sgn(getRelDegrees(LEFT))*(fabs(getRelDegrees(LEFT))<0.5 ? 0 : 1);
        }
        else if (rSpeed == 0)
        {
            rightSpeed = -10*sgn(getRelDegrees(RIGHT))*(fabs(getRelDegrees(RIGHT))<0.5 ? 0 : 1);
        }
        else
        {
            if (steer > 0)
            {
                leftSpeed -= sgn(lSpeed)*fabs(steer)*(fabs(leftSpeed)+fabs(rightSpeed));
            }
            else
            {
                rightSpeed -= sgn(rSpeed)*fabs(steer)*(fabs(leftSpeed)+fabs(rightSpeed));
            }
        }

        prevTurnErr = turnErr;

        setSpeed(leftSpeed, rightSpeed);
    }

    // Resets the motor based on where it should be
    if (state == TIME)
    {
        float totalTravelled = fabs(getRelDegrees(LEFT))+fabs(getRelDegrees(RIGHT));
        relativeBaseLeft += totalTravelled*lSpeed/(fabs(lSpeed)+fabs(rSpeed));
        relativeBaseRight += totalTravelled*rSpeed/(fabs(lSpeed)+fabs(rSpeed));
    }
    else
    {
        if (fabs(lSpeed) > fabs(rSpeed))
        {
            relativeBaseLeft += distance;
            relativeBaseRight += distance * rSpeed/lSpeed;
        }
        else
        {
            relativeBaseRight += distance;
            relativeBaseLeft += distance * lSpeed/rSpeed;
        }
    }

    if (shouldStop)
    {
        setSpeed(0, 0);
    }
    else
    {
        if (fabs(lSpeed) > fabs(rSpeed))
        {
            setSpeed(endSpeed*sgn(lSpeed), endSpeed*sgn(lSpeed)*rSpeed/lSpeed);
        }
        else
        {
            setSpeed(endSpeed*sgn(rSpeed)*lSpeed/rSpeed, endSpeed*sgn(rSpeed));
        }
    }
}

// Moves the drivetrain to a certain absolute target (CM, Degrees)
void moveAbs(float speed, float startSpeed, float endSpeed, float lTarget, float rTarget, float accRate, float deccRate, float turnkP, float turnkD, int state)
{
    // Converts the state
    if (state == ABSCM)
    {
        lTarget = degFromCM(lTarget);
        rTarget = degFromCM(lTarget);
    }

    // Sets the target degrees
    lTarget = lTarget-getAbsDegrees(LEFT);
    rTarget = rTarget-getAbsDegrees(RIGHT);

    float lSpeed;
    float rSpeed;

    float target = (fabs(lTarget)>fabs(rTarget)) ? lTarget : rTarget; // Gets the larger target degree

    // Gets the speeds based on the target degrees
    if (fabs(lTarget)>fabs(rTarget))
    {
        lSpeed = fabs(speed)*sgn(lTarget);
        rSpeed = rTarget/lTarget*lSpeed;
    }
    else if (rTarget != 0)
    {
        rSpeed = fabs(speed)*sgn(rTarget);
        lSpeed = lTarget/rTarget*rSpeed;
    }

    move(lSpeed, rSpeed, startSpeed, endSpeed, target, accRate, deccRate, turnkP, turnkD, true, RELDEG);
}

// Moves the drivetrain until one sensor sees a target
void moveSenseOneSensor(float lSpeed, float rSpeed, float startSpeed, float accRate, float turnkP, float turnkD, bool shouldStop, int sensor, int target, int state)
{
    accRate *= timeAccelRatio;

    float prevTurnErr = 0;

    turnkP = fabs(turnkP);
    turnkD = fabs(turnkD);

    if (sgn(rSpeed)!=sgn(lSpeed))
    {
        turnkP *= turnPIDScale;
        turnkD *= turnPIDScale;
    }
    if (fabs(rSpeed)!=fabs(lSpeed))
    {
        turnkP *= turnPIDScale;
        turnkD *= turnPIDScale;
    }

    startSpeed = fabs(startSpeed);

    float distance;

    if (fabs(lSpeed) > fabs(rSpeed))
    {
        distance = 100000*sgn(lSpeed);
    }
    else
    {
        distance = 100000*sgn(rSpeed);
    }

    // Variables for the main loop
    float leftSpeed;
    float rightSpeed;
    float turnErr;
    float steer;

    // Starts the main loop
    clearTimer(T2);

    while (true)
    {
        // Does the exit conditions
        if (time1(T2) >= 10000)
        {
            break;
        }
        if (state == GREATREFL && getReflection(sensor)>=target)
        {
            break;
        }
        else if (state == LESSREFL && getReflection(sensor)<=target)
        {
            break;
        }
        else if (state == COLOR && getColor(sensor) == target)
        {
            break;
        }

        // Gets the speeds the motors should move at
        if (fabs(lSpeed) >= fabs(rSpeed))
        {
            leftSpeed = motionProfile(startSpeed, lSpeed, lSpeed, accRate, accRate, distance, time1(T2), time1(T2), false, shouldStop);
            rightSpeed = leftSpeed*rSpeed/lSpeed;
        }
        else
        {
            rightSpeed = motionProfile(startSpeed, rSpeed, rSpeed, accRate, accRate, distance, time1(T2), time1(T2), false, shouldStop);
            leftSpeed = rightSpeed*lSpeed/rSpeed;
        }

        // Move sync PD below
        turnErr = getRelDegrees(LEFT)*rSpeed-getRelDegrees(RIGHT)*lSpeed;
        turnErr /= (fabs(rSpeed)+fabs(lSpeed));

        if (sgn(lSpeed)!=sgn(rSpeed))
        {
            turnErr *= -1.0;
        }

        // PD Implementation
        steer = turnErr*turnkP+(turnErr-prevTurnErr)*turnkD;

        if (lSpeed == 0)
        {
            leftSpeed = -10*sgn(getRelDegrees(LEFT))*(fabs(getRelDegrees(LEFT))<0.5 ? 0 : 1);
        }
        else if (rSpeed == 0)
        {
            rightSpeed = -10*sgn(getRelDegrees(RIGHT))*(fabs(getRelDegrees(RIGHT))<0.5 ? 0 : 1);
        }
        else
        {
            if (steer > 0)
            {
                leftSpeed -= sgn(lSpeed)*fabs(steer)*(fabs(leftSpeed)+fabs(rightSpeed));
            }
            else
            {
                rightSpeed -= sgn(rSpeed)*fabs(steer)*(fabs(leftSpeed)+fabs(rightSpeed));
            }
        }

        prevTurnErr = turnErr;

        setSpeed(leftSpeed, rightSpeed);
    }

    // Resets the motor based on where it should be
    float totalTravelled = fabs(getRelDegrees(LEFT))+fabs(getRelDegrees(RIGHT));
    relativeBaseLeft += totalTravelled*lSpeed/(fabs(lSpeed)+fabs(rSpeed));
    relativeBaseRight += totalTravelled*rSpeed/(fabs(lSpeed)+fabs(rSpeed));

    if (shouldStop)
    {
        setSpeed(0, 0);
    }
    else
    {
        setSpeed(lSpeed, rSpeed);
    }
}

// Moves the drivetrain until both sensors sees a target
void moveSenseTwoSensor(float lSpeed, float rSpeed, float startSpeed, float accRate, float turnkP, float turnkD, bool shouldStop, int sensor1, int target1, int state1, int sensor2, int target2, int state2)
{
    accRate *= timeAccelRatio;

    float prevTurnErr = 0;

    turnkP = fabs(turnkP);
    turnkD = fabs(turnkD);

    if (sgn(rSpeed)!=sgn(lSpeed))
    {
        turnkP *= turnPIDScale;
        turnkD *= turnPIDScale;
    }
    if (fabs(rSpeed)!=fabs(lSpeed))
    {
        turnkP *= turnPIDScale;
        turnkD *= turnPIDScale;
    }

    startSpeed = fabs(startSpeed);

    float distance;

    if (fabs(lSpeed) > fabs(rSpeed))
    {
        distance = 100000*sgn(lSpeed);
    }
    else
    {
        distance = 100000*sgn(rSpeed);
    }

    // Variables for the main loop
    float leftSpeed;
    float rightSpeed;
    float turnErr;
    float steer;

    bool sensor1Exit = false;

    // Starts the main loop
    clearTimer(T2);

    while (true)
    {
        // Does the exit conditions
        if (time1(T2)>=10000)
        {
            break;
        }

        if (state1 == GREATREFL && getReflection(sensor1)>=target1)
        {
            sensor1Exit = true;
        }
        else if (state1 == LESSREFL && getReflection(sensor1)<=target1)
        {
            sensor1Exit = true;
        }
        else if (state1 == COLOR && getColor(sensor1) == target1)
        {
            sensor1Exit = true;
        }
        else
        {
            sensor1Exit = false;
        }

        if (sensor1Exit)
        {
            if (state2 == GREATREFL && getReflection(sensor2)>=target2)
            {
                break;
            }
            else if (state2 == LESSREFL && getReflection(sensor2)<=target2)
            {
                break;
            }
            else if (state2 == COLOR && getColor(sensor2) == target2)
            {
                break;
            }
        }

        // Gets the speeds the motors should move at
        if (fabs(lSpeed) >= fabs(rSpeed))
        {
            leftSpeed = motionProfile(startSpeed, lSpeed, lSpeed, accRate, accRate, distance, time1(T2), time1(T2), false, shouldStop);
            rightSpeed = leftSpeed*rSpeed/lSpeed;
        }
        else
        {
            rightSpeed = motionProfile(startSpeed, rSpeed, rSpeed, accRate, accRate, distance, time1(T2), time1(T2), false, shouldStop);
            leftSpeed = rightSpeed*lSpeed/rSpeed;
        }

        // Move sync PD below
        turnErr = getRelDegrees(LEFT)*rSpeed-getRelDegrees(RIGHT)*lSpeed;
        turnErr /= (fabs(rSpeed)+fabs(lSpeed));

        if (sgn(lSpeed)!=sgn(rSpeed))
        {
            turnErr *= -1.0;
        }

        // PD Implementation
        steer = turnErr*turnkP+(turnErr-prevTurnErr)*turnkD;

        if (lSpeed == 0)
        {
            leftSpeed = -10*sgn(getRelDegrees(LEFT))*(fabs(getRelDegrees(LEFT))<0.5 ? 0 : 1);
        }
        else if (rSpeed == 0)
        {
            rightSpeed = -10*sgn(getRelDegrees(RIGHT))*(fabs(getRelDegrees(RIGHT))<0.5 ? 0 : 1);
        }
        else
        {
            if (steer > 0)
            {
                leftSpeed -= sgn(lSpeed)*fabs(steer)*(fabs(leftSpeed)+fabs(rightSpeed));
            }
            else
            {
                rightSpeed -= sgn(rSpeed)*fabs(steer)*(fabs(leftSpeed)+fabs(rightSpeed));
            }
        }

        prevTurnErr = turnErr;

        setSpeed(leftSpeed, rightSpeed);
    }

    // Resets the motor based on where it should be
    float totalTravelled = fabs(getRelDegrees(LEFT))+fabs(getRelDegrees(RIGHT));
    relativeBaseLeft += totalTravelled*lSpeed/(fabs(lSpeed)+fabs(rSpeed));
    relativeBaseRight += totalTravelled*rSpeed/(fabs(lSpeed)+fabs(rSpeed));

    if (shouldStop)
    {
        setSpeed(0, 0);
    }
    else
    {
        setSpeed(lSpeed, rSpeed);
    }
}

// Line follows with one sensor for degrees, seconds, or cm
void lineFollowOneSensor(float speed, float startSpeed, float endSpeed, float distance, float accRate, float deccRate, float kP, float kD, bool shouldStop, int sensor, float midpoint, int state)
{
    if (state == RELCM)
    {
        distance = degFromCM(distance);
        state = RELDEG;
    }

    if (state == TIME)
    {
        accRate *= timeAccelRatio;
        deccRate *= timeAccelRatio;
    }

    distance = fabs(distance)*sgn(speed);
    startSpeed = fabs(startSpeed);
    endSpeed = fabs(endSpeed);
    midpoint = fabs(midpoint);

    kD = fabs(kD)*sgn(kP);

    float err;
    float steer;
    float newSpeed;

    float prevErr = 0;
    clearTimer(T2);
    resetRelative();

    while (true)
    {
        // Does the exit conditions
        if (state == TIME)
        {
            if (time1(T2)>=fabs(distance))
            {
                break;
            }
        }
        else
        {
            if (time1(T2)>=3000)
            {
                break;
            }
            if (fabs(getRelDegrees(LEFT)+getRelDegrees(RIGHT))>=2.0*fabs(distance))
            {
                break;
            }
        }

        // Gets the speed
        newSpeed = motionProfile(startSpeed, speed, endSpeed, accRate, deccRate, distance, (getRelDegrees(LEFT)+getRelDegrees(RIGHT))/2.0, time1(T2), false, shouldStop);

        // Does the PD controller
        err = getReflection(sensor)-midpoint;
        steer = err*kP+(err-prevErr)*kD;

        prevErr = err;

        // Sets the speeds
        setSpeed(newSpeed+steer, newSpeed-steer);

    }

    resetRelative();

    if (shouldStop)
    {
        setSpeed(0, 0);
    }
    else
    {
        setSpeed(endSpeed*sgn(speed), endSpeed*sgn(speed));
    }
}

// Line follows with one sensor until sensing with two sensors
void lineFollowOneSensorStopTwoSensor(float speed, float startSpeed, float accRate, float kP, float kD, bool shouldStop, int lineFollowSensor, float midpoint, int sensor1, int target1, int state1, int sensor2, int target2, int state2)
{
    accRate *= timeAccelRatio;

    startSpeed = fabs(startSpeed);
    midpoint = fabs(midpoint);

    kD = fabs(kD)*sgn(kP);

    float distance = 100000*sgn(speed);

    float err;
    float steer;
    float newSpeed;

    bool sensor1Exit = false;

    float prevErr = 0;
    clearTimer(T2);
    resetRelative();

    while (true)
    {
        // Does the exit conditions
        if (time1(T2)>=10000)
        {
            break;
        }

        if (state1 == GREATREFL && getReflection(sensor1)>=target1)
        {
            sensor1Exit = true;
        }
        else if (state1 == LESSREFL && getReflection(sensor1)<=target1)
        {
            sensor1Exit = true;
        }
        else if (state1 == COLOR && getColor(sensor1) == target1)
        {
            sensor1Exit = true;
        }
        else
        {
            sensor1Exit = false;
        }

        if (sensor1Exit)
        {
            if (state2 == GREATREFL && getReflection(sensor2)>=target2)
            {
                break;
            }
            else if (state2 == LESSREFL && getReflection(sensor2)<=target2)
            {
                break;
            }
            else if (state2 == COLOR && getColor(sensor2) == target2)
            {
                break;
            }
        }

        // Gets the speed
        newSpeed = motionProfile(startSpeed, speed, speed, accRate, accRate, distance, (getRelDegrees(LEFT)+getRelDegrees(RIGHT))/2.0, time1(T2), false, shouldStop);

        // Does the PD controller
        err = getReflection(lineFollowSensor)-midpoint;
        steer = err*kP+(err-prevErr)*kD;

        prevErr = err;

        // Sets the speeds
        setSpeed(newSpeed+steer, newSpeed-steer);

    }

    resetRelative();

    if (shouldStop)
    {
        setSpeed(0, 0);
    }
    else
    {
        setSpeed(speed, speed);
    }
}

// Line follows with one sensor until sensing with one sensor
void lineFollowOneSensorStopOneSensor(float speed, float startSpeed, float accRate, float kP, float kD, bool shouldStop, int lineFollowSensor, float midpoint, int sensor, int target, int state)
{
    accRate *= timeAccelRatio;

    startSpeed = fabs(startSpeed);
    midpoint = fabs(midpoint);

    kD = fabs(kD)*sgn(kP);

    float distance = 100000*sgn(speed);

    float err;
    float steer;
    float newSpeed;

    float prevErr = 0;
    clearTimer(T2);
    resetRelative();

    while (true)
    {
        // Does the exit conditions
        if (time1(T2)>=10000)
        {
            break;
        }
        if (state == GREATREFL && getReflection(sensor)>=target)
        {
            break;
        }
        else if (state == LESSREFL && getReflection(sensor)<=target)
        {
            break;
        }
        else if (state == COLOR && getColor(sensor) == target)
        {
            break;
        }

        // Gets the speed
        newSpeed = motionProfile(startSpeed, speed, speed, accRate, accRate, distance, (getRelDegrees(LEFT)+getRelDegrees(RIGHT))/2.0, time1(T2), false, shouldStop);

        // Does the PD controller
        err = getReflection(lineFollowSensor)-midpoint;
        steer = err*kP+(err-prevErr)*kD;

        prevErr = err;

        // Sets the speeds
        setSpeed(newSpeed+steer, newSpeed-steer);

    }

    resetRelative();

    if (shouldStop)
    {
        setSpeed(0, 0);
    }
    else
    {
        setSpeed(speed, speed);
    }
}

// Line follows with two sensors for degrees, seconds, or cm
void lineFollowTwoSensor(float speed, float startSpeed, float endSpeed, float distance, float accRate, float deccRate, float kP, float kD, bool shouldStop, int sensor1, int sensor2, int state)
{
    if (state == RELCM)
    {
        distance = degFromCM(distance);
        state = RELDEG;
    }

    if (state == TIME)
    {
        accRate *= timeAccelRatio;
        deccRate *= timeAccelRatio;
    }

    distance = fabs(distance)*sgn(speed);
    startSpeed = fabs(startSpeed);
    endSpeed = fabs(endSpeed);

    kD = fabs(kD)*sgn(kP);

    float err;
    float steer;
    float newSpeed;

    float prevErr = 0;
    clearTimer(T2);
    resetRelative();

    while (true)
    {
        // Does the exit conditions
        if (state == TIME)
        {
            if (time1(T2)>=fabs(distance))
            {
                break;
            }
        }
        else
        {
            if (time1(T2)>=3000)
            {
                break;
            }
            if (fabs(getRelDegrees(LEFT)+getRelDegrees(RIGHT))>=2.0*fabs(distance))
            {
                break;
            }
        }

        // Gets the speed
        newSpeed = motionProfile(startSpeed, speed, endSpeed, accRate, deccRate, distance, (getRelDegrees(LEFT)+getRelDegrees(RIGHT))/2.0, time1(T2), false, shouldStop);

        // Does the PD controller
        err = getReflection(sensor1)-getReflection(sensor2);
        steer = err*kP+(err-prevErr)*kD;

        prevErr = err;

        // Sets the speeds
        setSpeed(newSpeed+steer, newSpeed-steer);

    }

    resetRelative();

    if (shouldStop)
    {
        setSpeed(0, 0);
    }
    else
    {
        setSpeed(endSpeed*sgn(speed), endSpeed*sgn(speed));
    }
}

// Line follows with two sensors until sensing with two sensors
void lineFollowTwoSensorStopTwoSensor(float speed, float startSpeed, float accRate, float kP, float kD, bool shouldStop, int sensor1, int target1, int state1, int sensor2, int target2, int state2)
{
    accRate *= timeAccelRatio;

    startSpeed = fabs(startSpeed);

    kD = fabs(kD)*sgn(kP);

    float err;
    float steer;
    float newSpeed;

    float distance = 100000*sgn(speed);

    float sensor1Exit = false;

    float prevErr = 0;
    clearTimer(T2);
    resetRelative();

    while (true)
    {
        // Does the exit conditions
        if (time1(T2)>=10000)
        {
            break;
        }

        if (state1 == GREATREFL && getReflection(sensor1)>=target1)
        {
            sensor1Exit = true;
        }
        else if (state1 == LESSREFL && getReflection(sensor1)<=target1)
        {
            sensor1Exit = true;
        }
        else if (state1 == COLOR && getColor(sensor1) == target1)
        {
            sensor1Exit = true;
        }
        else
        {
            sensor1Exit = false;
        }

        if (sensor1Exit)
        {
            if (state2 == GREATREFL && getReflection(sensor2)>=target2)
            {
                break;
            }
            else if (state2 == LESSREFL && getReflection(sensor2)<=target2)
            {
                break;
            }
            else if (state2 == COLOR && getColor(sensor2) == target2)
            {
                break;
            }
        }

        // Gets the speed
        newSpeed = motionProfile(startSpeed, speed, speed, accRate, accRate, distance, (getRelDegrees(LEFT)+getRelDegrees(RIGHT))/2.0, time1(T2), false, shouldStop);

        // Does the PD controller
        err = getReflection(sensor1)-getReflection(sensor2);
        steer = err*kP+(err-prevErr)*kD;

        prevErr = err;

        // Sets the speeds
        setSpeed(newSpeed+steer, newSpeed-steer);

    }

    resetRelative();

    if (shouldStop)
    {
        setSpeed(0, 0);
    }
    else
    {
        setSpeed(speed, speed);
    }
}

// Line follows with two sensors until sensing with one sensor
void lineFollowTwoSensorStopOneSensor(float speed, float startSpeed, float accRate, float kP, float kD, bool shouldStop, int sensor1, int sensor2, int stopSensor, int stopTarget, int state)
{
    accRate *= timeAccelRatio;

    startSpeed = fabs(startSpeed);

    kD = fabs(kD)*sgn(kP);

    float err;
    float steer;
    float newSpeed;

    float distance = 100000*sgn(speed);

    float prevErr = 0;
    clearTimer(T2);
    resetRelative();

    while (true)
    {
        // Does the exit conditions
        if (time1(T2)>=10000)
        {
            break;
        }
        if (state == GREATREFL && getReflection(stopSensor)>=stopTarget)
        {
            break;
        }
        else if (state == LESSREFL && getReflection(stopSensor)<=stopTarget)
        {
            break;
        }
        else if (state == COLOR && getColor(stopSensor) == stopTarget)
        {
            break;
        }

        // Gets the speed
        newSpeed = motionProfile(startSpeed, speed, speed, accRate, accRate, distance, (getRelDegrees(LEFT)+getRelDegrees(RIGHT))/2.0, time1(T2), false, shouldStop);

        // Does the PD controller
        err = getReflection(sensor1)-getReflection(sensor2);
        steer = err*kP+(err-prevErr)*kD;

        prevErr = err;

        // Sets the speeds
        setSpeed(newSpeed+steer, newSpeed-steer);

    }

    resetRelative();

    if (shouldStop)
    {
        setSpeed(0, 0);
    }
    else
    {
        setSpeed(speed, speed);
    }
}

// Line squares
void lineSquare(int mid1, int mid2, int port1, int port2, float kP, float kD, int time)
{
    // Verifies variables
    clearTimer(T2);
    resetRelative();
    mid1 = fabs(mid1);
    mid2 = fabs(mid2);
    port1 = fabs(port1);
    port2 = fabs(port2);
    time = fabs(time);

    float prevErr1 = 0;
    float prevErr2 = 0;


    while (time1(T2)<time)
    {
        // PD implementation for each side (Maybe add modified PID later)
        setSpeed((getReflection(port1)-mid1)*kP+(getReflection(port1)-mid1-prevErr1)*kD, (getReflection(port2)-mid2)*kP+(getReflection(port2)-mid2-prevErr2)*kD);

        // Stores previous error values
        prevErr1 = getReflection(port1)-mid1;
        prevErr2 = getReflection(port2)-mid2;
    }

    resetRelative();
    setSpeed(0, 0);

}

// Moves an arm to a certain relative target
void moveArm(float speed, float startSpeed, float endSpeed, float distance, float accRate, float deccRate, bool shouldStop, int port, int state)
{
    // Verifies all the variables
    distance = fabs(distance)*sgn(speed);
    startSpeed = fabs(startSpeed);
    endSpeed = fabs(endSpeed);

    if (state == TIME)
    {
        accRate *= timeAccelRatio;
        deccRate *= timeAccelRatio;
    }

    TTimers TARM = T3;

    if (port == LIFT)
    {
        TARM = T4;
    }

    clearTimer(TARM);

    while (true)
    {
        // Breaking conditions
        if (state==TIME)
        {
            if (time1(TARM)>=fabs(distance))
            {
                break;
            }
        }
        else
        {
            if (time1(TARM)>3000)
            {
                break;
            }
            if (fabs(getArmDegrees(port)-distance)==0 && shouldStop)
            {
                break;
            }
            if (fabs(getArmDegrees(port))>=fabs(distance) && !shouldStop)
            {
                break;
            }
        }

        // Sets the speed of the arm from the motion profile
        setArmSpeed(port, motionProfile(startSpeed, speed, endSpeed, accRate, deccRate, (state==TIME ? fabs(distance)*sgn(speed) : distance), ((state==TIME) ? time1(TARM)*sgn(speed) : getArmDegrees(port)), time1(TARM), false, shouldStop));
    }

    // Resets the arm
    if (state == TIME)
    {
        resetArm(port);
    }
    else
    {
        if (port == LIFT)
        {
            relativeBaseLift += distance;
        }
        else
        {
            relativeBaseClaw += distance;
        }
        resetArm(port);
    }

    // Stops the arm if so
    if (shouldStop)
    {
        setArmSpeed(port, 0);
    }
}

// Moves an arm to an absolute target
void moveArmAbs(float speed, float startSpeed, float endSpeed, float target, float accRate, float deccRate, int port)
{
    // Sets all the right values
    target = target-getArmDegreesAbs(port);
    if (target == 0){return;}
    speed = fabs(speed)*sgn(target);

    // Calls the movement function
    moveArm(speed, startSpeed, endSpeed, target, accRate, deccRate, true, port, RELDEG);
}
