// Function to develop a motion profile for any motor that is not synced with another motor
float motionProfiling(float minSpeed, float maxSpeed, float acc, float dist, float curDegrees)
{
    if (maxSpeed < minSpeed)
    {
        maxSpeed = minSpeed;
    }
    if (acc == 0)
    {
        acc = INFINITY;
    }
    float speed = minSpeed;
    bool negative = false;
    if (dist < 0)
    {
        dist *= -1.0;
        negative = true;
        curDegrees *= -1.0;
    }
    float err = dist-curDegrees;
    float y = (maxSpeed-minSpeed)/2.0;


    if (err < 0.5)
    {
        if (err > -1.0*sqrt(y/acc))
        {
            speed = -1.0*acc*err*err-minSpeed;
        }
        else if (err > -2.0*sqrt(y/acc))
        {
            err = err+2.0*sqrt(y/acc);
            speed = acc*err*err-maxSpeed;
        }
        else
        {
            speed = -1.0*maxSpeed;
        }
    }
    else if (err > 0.5)
    {
        if (err < sqrt(y/acc) && err < dist/2.0)
        {
            speed = acc*err*err+minSpeed;
        }
        else if (err < 2.0*sqrt(y/acc) && err<dist/2)
        {
            err = err-2.0*sqrt(y/acc);
            speed = -1.0*acc*err*err+maxSpeed;
        }
        else if (err >= dist+2.0*sqrt(y/acc))
        {
            speed = maxSpeed;
        }
        else if (err > dist-sqrt(y/acc) && err < dist+sqrt(y/acc))
        {
            err = err-dist;
            speed = acc*err*err+minSpeed;
        }
        else if (err > dist+sqrt(y/acc))
        {
            err = err-dist-2.0*sqrt(y/acc);
            speed = -1*acc*err*err+maxSpeed;
        }
        else if (err > dist-2.0*sqrt(y/acc) && err<dist)
        {
            err = err-dist+2.0*sqrt(y/acc);
            speed = -acc*err*err+maxSpeed;
        }
        else
        {
            speed = maxSpeed;
        }
    }
    else
    {
        speed = 0;
    }

    if (negative)
    {
        speed *= -1.0;
    }

    return speed;

}

// Function to develop a motion profile for any motor that is synced with another motor
float motionProfilingSynched(float minSpeed, float maxSpeed, float acc, float dist, float curDegrees, float time){
    if (maxSpeed < minSpeed)
    {
        maxSpeed = minSpeed;
    }
    acc = acc/fabs(maxSpeed);
    if (acc == 0)
    {
        acc = INFINITY;
    }
    float speed = minSpeed;
    bool negative = false;
    if (dist < 0)
    {
        dist *= -1.0;
        negative = true;
        curDegrees *= -1.0;
    }
    float err = dist-curDegrees;
    float y = (maxSpeed-minSpeed)/2.0;

    if (err < 0.5)
    {
        if (err > -1.0*sqrt(y/acc))
        {
            speed = -1.0*acc*err*err-minSpeed;
        }
        else if (err > -2.0*sqrt(y/acc))
        {
            err = err+2.0*sqrt(y/acc);
            speed = acc*err*err-maxSpeed;
        }
        else
        {
            speed = -1.0*maxSpeed;
        }
    }
    else if (err > 0.5)
    {
        if (err < sqrt(y/acc) && err < dist/2.0)
        {
            speed = acc*err*err+minSpeed;
        }
        else if (err < 2.0*sqrt(y/acc) && err<dist/2)
        {
            err = err-2.0*sqrt(y/acc);
            speed = -1.0*acc*err*err+maxSpeed;
        }
        else
        {
            speed = maxSpeed;
        }
    }
    else
    {
        speed = 0;
    }

    if (negative)
    {
        speed *= -1.0;
    }

    err = time;
    float accSpeed;
    acc /= 20.0;
    minSpeed = 0;
    y = maxSpeed/2.0;

    if (err < sqrt(y/acc))
    {
        accSpeed = acc*err*err+minSpeed;
    }
    else if (err < 2.0*sqrt(y/acc))
    {
        err = err-2.0*sqrt(y/acc);
        accSpeed = -1.0*acc*err*err+maxSpeed;
    }
    else
    {
        accSpeed = maxSpeed;
    }

    if (fabs(speed)>fabs(accSpeed)){
        speed = fabs(accSpeed)*sgn(speed);
    }

    return speed;

}

// Moves the drivetrain to a certain target (CM, Degrees, Seconds)
void move(float leftMaxSpeed, float rightMaxSpeed, float minSpeed, float distance, float acc, float turnkP, float turnkD, int state)
{
    // Switches based on the state
    if (state == RELCM)
    {
        distance = degFromCM(distance);
        state = RELDEG;
    }
    else if (state == TIME)
    {
        acc *= 0.002;
    }

    // Sets all the variables to the right values and signs
    float leftDegrees = 0;
    float rightDegrees = 0;
    float leftMinSpeed = 0;
    float rightMinSpeed = 0;
    float leftAcc = 0;
    float rightAcc = 0;

    int prevTime = -1;
    float prevTurnErr = 0;

    if (fabs(leftMaxSpeed) > fabs(rightMaxSpeed))
    {
        leftDegrees = fabs(distance)*sgn(leftMaxSpeed);
        rightDegrees = rightMaxSpeed/leftMaxSpeed*leftDegrees;
        leftMaxSpeed = fabs(leftMaxSpeed);
        rightMaxSpeed = fabs(rightMaxSpeed);
        leftMinSpeed = max2(5, fabs(minSpeed));
        rightMinSpeed = max2(5, fabs(rightMaxSpeed/leftMaxSpeed*leftMinSpeed));
        leftAcc = fabs(acc);
        rightAcc = fabs(rightMaxSpeed/leftMaxSpeed*leftAcc);
    }
    else
    {
        rightDegrees = fabs(distance)*sgn(rightMaxSpeed);
        leftDegrees = leftMaxSpeed/rightMaxSpeed*rightDegrees;
        leftMaxSpeed = fabs(leftMaxSpeed);
        rightMaxSpeed = fabs(rightMaxSpeed);
        rightMinSpeed = max2(5, fabs(minSpeed));
        leftMinSpeed = max2(5, fabs(leftMaxSpeed/rightMaxSpeed*rightMinSpeed));
        rightAcc = fabs(acc);
        leftAcc = fabs(leftMaxSpeed/rightMaxSpeed*rightAcc);
    }
    turnkP = fabs(turnkP);
    turnkD = fabs(turnkD);

    // Variables for the main loop
    float leftSpeed;
    float rightSpeed;
    float turnErr;
    float steer;

    // Starts the main loop
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
            if (fabs(getRelDegrees(LEFT)-leftDegrees)<=0.5 && fabs(getRelDegrees(RIGHT)-rightDegrees)<=0.5)
            {
                break;
            }
        }

        // Motion Profiling Speed
        if (state == TIME)
        {
            if (fabs(leftMaxSpeed)>fabs(rightMaxSpeed))
            {
                leftSpeed = motionProfiling(leftMinSpeed, leftMaxSpeed, leftAcc, leftDegrees, time1(T2)*sgn(leftDegrees));
                rightSpeed = leftSpeed*rightDegrees/leftDegrees;
            }
            else
            {
                rightSpeed = motionProfiling(rightMinSpeed, rightMaxSpeed, rightAcc, rightDegrees, time1(T2)*sgn(rightDegrees));
                leftSpeed = rightSpeed*leftDegrees/rightDegrees;
            }
        }
        else
        {
            if (fabs(leftMaxSpeed)>fabs(rightMaxSpeed))
            {
                leftSpeed = motionProfilingSynched(leftMinSpeed, leftMaxSpeed, leftAcc, leftDegrees, getRelDegrees(LEFT), time1(T2));
                rightSpeed = motionProfilingSynched(rightMinSpeed, rightMaxSpeed, rightAcc, fabs(leftDegrees)*sgn(rightDegrees), getRelDegrees(RIGHT)*fabs((rightMaxSpeed!=0 ? (leftMaxSpeed/rightMaxSpeed) : INFINITY)), time1(T2));
            }
            else
            {
                rightSpeed = motionProfilingSynched(rightMinSpeed, rightMaxSpeed, rightAcc, rightDegrees, getRelDegrees(RIGHT), time1(T2));
                leftSpeed = motionProfilingSynched(leftMinSpeed, leftMaxSpeed, leftAcc, fabs(rightDegrees)*sgn(leftDegrees), getRelDegrees(LEFT)*fabs((leftMaxSpeed!=0 ? (rightMaxSpeed/leftMaxSpeed) : INFINITY)), time1(T2));
            }
        }

        // Steering Correction
        turnErr = getRelDegrees(LEFT)*rightDegrees-getRelDegrees(RIGHT)*leftDegrees;
        turnErr /= fabs(rightDegrees)+fabs(leftDegrees);

        if (leftDegrees == 0)
        {
            turnErr = 0;
        }
        if (rightDegrees == 0)
        {
            turnErr = 0;
        }
        if (sgn(leftDegrees)!=sgn(rightDegrees))
        {
            turnErr*=-1.0;
        }

        // PD Implementation
        steer = turnErr*turnkP+(turnErr-prevTurnErr)/(time1(T2)-prevTime)*turnkD;

        if (steer > 0)
        {
            leftSpeed -= ((sgn(leftDegrees)!=0) ? sgn(leftDegrees) : 0)*fabs(steer);
        }
        else
        {
            rightSpeed -= ((sgn(rightDegrees)!=0) ? sgn(rightDegrees) : 0)*fabs(steer);
        }

        prevTurnErr = turnErr;
        prevTime = time1(T2);
        setSpeed(leftSpeed, rightSpeed);
        sleep(1);
    }

    setSpeed(0, 0);
}

// Moves the drivetrain to a certain absolute target (CM, Degrees)
void moveAbs(float maxSpeed, float minSpeed, float lDeg, float rDeg, float acc, float turnkP, float turnkD, int state)
{
    if (state == ABSCM)
    {
        lDeg = degFromCM(lDeg);
        rDeg = degFromCM(rDeg);
    }
    lDeg = lDeg-getAbsDegrees(LEFT);
    rDeg = rDeg-getAbsDegrees(RIGHT);
    float lSpeed;
    float rSpeed;
    float target = (fabs(lDeg)>fabs(rDeg)) ? lDeg : rDeg;
    if (target == 0){return;}
    if (fabs(lDeg)>fabs(rDeg))
    {
        lSpeed = fabs(maxSpeed)*sgn(lDeg);
        rSpeed = rDeg/lDeg*lSpeed;
    }
    else
    {
        rSpeed = fabs(maxSpeed)*sgn(rDeg);
        lSpeed = lDeg/rDeg*rSpeed;
    }
    move(lSpeed, rSpeed, minSpeed, target, acc, turnkP, turnkD, RELDEG);
}

// Moves the drivetrain to a certain sensing
void moveSense(float leftMaxSpeed, float rightMaxSpeed, float minSpeed, float targetRefl, float acc, float turnkP, float turnkD, int port, int state)
{
    acc *= 0.002;

    // Sets all the variables to the right values and signs
    float leftDegrees = 0;
    float rightDegrees = 0;
    float leftMinSpeed = 0;
    float rightMinSpeed = 0;
    float leftAcc = 0;
    float rightAcc = 0;
    float distance = 10000;

    int prevTime = -1;
    float prevTurnErr = 0;

    if (fabs(leftMaxSpeed) > fabs(rightMaxSpeed))
    {
        leftDegrees = fabs(distance)*sgn(leftMaxSpeed);
        rightDegrees = rightMaxSpeed/leftMaxSpeed*leftDegrees;
        leftMaxSpeed = fabs(leftMaxSpeed);
        rightMaxSpeed = fabs(rightMaxSpeed);
        leftMinSpeed = max2(5, fabs(minSpeed));
        rightMinSpeed = max2(5, fabs(rightMaxSpeed/leftMaxSpeed*leftMinSpeed));
        leftAcc = fabs(acc);
        rightAcc = fabs(rightMaxSpeed/leftMaxSpeed*leftAcc);
    }
    else
    {
        rightDegrees = fabs(distance)*sgn(rightMaxSpeed);
        leftDegrees = leftMaxSpeed/rightMaxSpeed*rightDegrees;
        leftMaxSpeed = fabs(leftMaxSpeed);
        rightMaxSpeed = fabs(rightMaxSpeed);
        rightMinSpeed = max2(5, fabs(minSpeed));
        leftMinSpeed = max2(5, fabs(leftMaxSpeed/rightMaxSpeed*rightMinSpeed));
        rightAcc = fabs(acc);
        leftAcc = fabs(leftMaxSpeed/rightMaxSpeed*rightAcc);
    }
    turnkP = fabs(turnkP);
    turnkD = fabs(turnkD);

    // Variables for the main loop
    float leftSpeed;
    float rightSpeed;
    float turnErr;
    float steer;

    // Starts the main loop
    clearTimer(T2);
    resetRelative();

    while (true)
    {
        // Does the exit conditions
        if (time1(T2)>=10000)
        {
            break;
        }
        if (state == GREATREFL && getReflection(port)>=targetRefl)
        {
            break;
        }
        else if (state == LESSREFL && getReflection(port)<=targetRefl)
        {
            break;
        }
        else if (state == COLOR && getColor(port) == targetRefl)
        {
            break;
        }


        if (fabs(leftMaxSpeed)>fabs(rightMaxSpeed))
        {
            leftSpeed = motionProfiling(leftMinSpeed, leftMaxSpeed, leftAcc, leftDegrees, time1(T2)*sgn(leftDegrees));
            rightSpeed = leftSpeed*rightDegrees/leftDegrees;
        }
        else
        {
            rightSpeed = motionProfiling(rightMinSpeed, rightMaxSpeed, rightAcc, rightDegrees, time1(T2)*sgn(rightDegrees));
            leftSpeed = rightSpeed*leftDegrees/rightDegrees;
        }

        // Steering Correction
        turnErr = getRelDegrees(LEFT)*rightDegrees-getRelDegrees(RIGHT)*leftDegrees;
        turnErr /= fabs(rightDegrees)+fabs(leftDegrees);

        if (leftDegrees == 0)
        {
            turnErr = fabs(turnErr);
        }
        if (rightDegrees == 0)
        {
            turnErr = -1.0*fabs(turnErr);
        }
        if (sgn(leftDegrees)!=sgn(rightDegrees))
        {
            turnErr*=-1.0;
        }

        // PD Implementation
        steer = turnErr*turnkP+(turnErr-prevTurnErr)/(time1(T2)-prevTime)*turnkD;

        if (steer > 0)
        {
            leftSpeed -= ((sgn(leftDegrees)!=0) ? sgn(leftDegrees) : 0)*fabs(steer);
        }
        else
        {
            rightSpeed -= ((sgn(rightDegrees)!=0) ? sgn(rightDegrees) : 0)*fabs(steer);
        }

        prevTurnErr = turnErr;
        prevTime = time1(T2);
        setSpeed(leftSpeed, rightSpeed);
        sleep(1);
    }

    setSpeed(0, 0);
}

// Function to keep default parameters in the move function
void moveSimple(float leftMaxSpeed, float rightMaxSpeed, float distance, int state)
{
    move(leftMaxSpeed, rightMaxSpeed, 9, distance, 0.4, 2, 10, state);
}

void moveSimpleNone(float leftMaxSpeed, float rightMaxSpeed, float distance, int state)
{
    move(leftMaxSpeed, rightMaxSpeed, 9, distance, 0.4, 0, 0, state);
}

// Function to keep default parameters in the moveAbs function
void moreAbsSimple(float maxSpeed, float lDeg, float rDeg, int state)
{
    moveAbs(maxSpeed, 9, lDeg, rDeg, 0.4, 2, 10, state);
}

// Function to keep default parameters in the moveSense function
void moveSenseSimple(float leftMaxSpeed, float rightMaxSpeed, float targetRefl, int port, int state)
{
    moveSense(leftMaxSpeed, rightMaxSpeed, 9, targetRefl, 0.3, 2, 10, port, state);
}

// Function to turn with 2 motors
void turn2Motor(float speed, float angle)
{
    speed = fabs(speed);
    moveSimple(speed*sgn(angle), speed*sgn(angle)*-1.0, angle/360.0*wheelDist*PI, RELCM);
}

// Function to turn with 1 motor
void turn1Motor(float speed, float angle, int port)
{
    speed = fabs(speed);
    if (port == LEFT)
    {
        moveSimple(speed*sgn(angle), 0, angle/360.0*2.0*wheelDist*PI, RELCM);
    }
    else
    {
        moveSimple(0, speed*sgn(angle), angle/360.0*2.0*wheelDist*PI, RELCM);
    }
}

// Function to line follow with one sensor
void lineFollow(float maxSpeed, float minSpeed, float distance, float midpoint, float acc, float kP, float kD, int port, int state)
{
    if (state == RELCM)
    {
        distance = degFromCM(distance);
        state = RELDEG;
    }

    maxSpeed = fabs(maxSpeed);
    minSpeed = max2(5, (minSpeed));
    distance = fabs(distance);
    acc = fabs(acc);
    kD = fabs(kD)*sgn(kP);

    float err;
    float steer;
    float speed;

    int prevTime = -1;
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
            if (time1(T2)>=10000)
            {
                break;
            }
            if (getRelDegrees(LEFT)+getRelDegrees(RIGHT)>=2.0*distance)
            {
                break;
            }
        }

        if (state==TIME)
        {
            speed = motionProfiling(minSpeed, maxSpeed, acc, distance, time1(T2));
        }
        else
        {
            speed = motionProfiling(minSpeed, maxSpeed, acc, distance, 0.5*(getRelDegrees(LEFT)+getRelDegrees(RIGHT)));
        }

        err = getReflection(port)-midpoint;
        steer = err*kP+(err-prevErr)/(time1(T2)-prevTime)*kD;
        // steer*=speed/100.0;
        prevErr = err;
        prevTime = time1(T2);
        setSpeed(speed+steer, speed-steer);
        sleep(1);

    }
    setSpeed(0, 0);
}

// Function to line follow with one sensor with default parameters
void lineFollowSimple(float maxSpeed, float distance, float midpoint, float side, int port, int state)
{
    lineFollow(maxSpeed, 10, distance, midpoint, 0.02, side*0.4, side*25, port, state);
}

// Function to line follow with one sensor until another sensor sees something
void lineFollowSense(float maxSpeed, float minSpeed, float target, float midpoint, float acc, float kP, float kD, int port, int stopPort, int state)
{
    maxSpeed = fabs(maxSpeed);
    minSpeed = fabs(minSpeed);
    float distance = 10000;
    acc = fabs(acc);
    kD = fabs(kD)*sgn(kP);

    float err;
    float steer;
    float speed;

    int prevTime = -1;
    float prevErr = 0;
    clearTimer(T2);
    resetRelative();
    while (true)
    {
        if (time1(T2)>=10000)
        {
            break;
        }
        if (state == GREATREFL && getReflection(stopPort)>=target)
        {
            break;
        }
        else if (state == LESSREFL && getReflection(stopPort)<=target)
        {
            break;
        }
        else if (state == COLOR && getColor(stopPort) == target)
        {
            break;
        }

        if (state==TIME)
        {
            speed = motionProfiling(minSpeed, maxSpeed, acc, distance, time1(T2));
        }
        else
        {
            speed = motionProfiling(minSpeed, maxSpeed, acc, distance, 0.5*(getRelDegrees(LEFT)+getRelDegrees(RIGHT)));
        }

        err = getReflection(port)-midpoint;
        steer = err*kP+(err-prevErr)/(time1(T2)-prevTime)*kD;

        prevErr = err;
        prevTime = time1(T2);
        setSpeed(speed+steer, speed-steer);
        sleep(1);

    }
    setSpeed(0, 0);
}

// Function to line follow with two sensors
void lineFollow2(float maxSpeed, float minSpeed, float distance, float bias, float acc, float kP, float kD, int port1, int port2, int state)
{
    if (state == RELCM)
    {
        distance = degFromCM(distance);
        state = RELDEG;
    }

    maxSpeed = fabs(maxSpeed);
    minSpeed = fabs(minSpeed);
    distance = fabs(distance);
    acc = fabs(acc);
    kD = fabs(kD)*sgn(kP);

    float err;
    float steer;
    float speed;

    int prevTime = -1;
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
            if (time1(T2)>=10000)
            {
                break;
            }
            if (getRelDegrees(LEFT)+getRelDegrees(RIGHT)>=2.0*distance)
            {
                break;
            }
        }

        if (state==TIME)
        {
            speed = motionProfiling(minSpeed, maxSpeed, acc, distance, time1(T2));
        }
        else
        {
            speed = motionProfiling(minSpeed, maxSpeed, acc, distance, 0.5*(getRelDegrees(LEFT)+getRelDegrees(RIGHT)));
        }

        err = bias+getReflection(port1)-getReflection(port2);
        steer = err*kP+(err-prevErr)/(time1(T2)-prevTime)*kD;

        prevErr = err;
        prevTime = time1(T2);
        setSpeed(speed+steer, speed-steer);
        sleep(1);

    }
    setSpeed(0, 0);
}

// Function to line square: kP: 0.5, kD: 10
void lineSquare(int mid1, int mid2, int port1, int port2, float kP, float kD, int time)
{
    clearTimer(T2);
    resetRelative();
    mid1 = fabs(mid1);
    mid2 = fabs(mid2);
    port1 = fabs(port1);
    port2 = fabs(port2);
    time = fabs(time);

    int prevTime = -1;
    float prevErr1 = 0;
    float prevErr2 = 0;


    while (time1(T2)<time)
    {
        setSpeed((getReflection(port1)-mid1)*kP+(getReflection(port1)-mid1-prevErr1)*kD, (getReflection(port2)-mid2)*kP+(getReflection(port2)-mid2-prevErr2)*kD);
        prevTime = time1(T2);
        prevErr1 = getReflection(port1)-mid1;
        prevErr2 = getReflection(port2)-mid2;
        sleep(1);
    }

    setSpeed(0, 0);

}

// Function to move arm relative to its current position: acc: 0.05
void moveArm(float maxSpeed, float minSpeed, float distance, float acc, int port, int state)
{
    distance = fabs(distance)*sgn(maxSpeed);
    minSpeed = max2(fabs(minSpeed), 5);
    maxSpeed = fabs(maxSpeed);
    acc = fabs(acc);
    if (state == TIME)
    {
        acc *= 0.02;
    }

    clearTimer(T2);
    resetArm(port);

    while (true)
    {
        if (state==TIME)
        {
            if (time1(T2)>=fabs(distance))
            {
                break;
            }
        }
        else
        {
            if (time1(T2)>10000)
            {
                break;
            }
            if (fabs(getArmDegrees(port)-distance)<=0)
            {
                break;
            }
        }

        setArmSpeed(port, motionProfiling(minSpeed, maxSpeed, acc, distance, ((state==TIME) ? time1(T2) : getArmDegrees(port))));
    }
    setArmSpeed(port, 0);
}

// Function to move arm to an absolute position: acc: 0.05
void moveArmAbs(float maxSpeed, float minSpeed, float target, float acc, int port)
{
    target = target-getArmDegreesAbs(port);
    if (target == 0){return;}
    maxSpeed = fabs(maxSpeed)*sgn(target);
    moveArm(maxSpeed, minSpeed, target, acc, port, RELDEG);
}
