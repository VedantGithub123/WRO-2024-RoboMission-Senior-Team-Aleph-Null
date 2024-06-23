// Simple Movement Functions (For Degrees/Time/Turning)

void moveNoSyncParam(float lSpeed, float rSpeed, float startSpeed, float endSpeed, float distance, float accRate, float deccRate, bool shouldStop, int state)
{
    move(lSpeed, rSpeed, startSpeed, endSpeed, distance, accRate, deccRate, defaultkP, defaultkD, shouldStop, state);
}

void moveNoSyncParamWallSquare(float lSpeed, float rSpeed, float startSpeed, float endSpeed, float distance, float accRate, float deccRate, bool shouldStop, int state)
{
    move(lSpeed, rSpeed, startSpeed, endSpeed, distance, accRate, deccRate, 0, 0, shouldStop, state);
}

void moveNoSyncAccParam(float lSpeed, float rSpeed, float startSpeed, float endSpeed, float distance, bool shouldStop, int state)
{
    move(lSpeed, rSpeed, startSpeed, endSpeed, distance, 0.4, 0.4, defaultkP, defaultkD, shouldStop, state);
}

void moveNoSyncAccParamWallSquare(float lSpeed, float rSpeed, float startSpeed, float endSpeed, float distance, bool shouldStop, int state)
{
    move(lSpeed, rSpeed, startSpeed, endSpeed, distance, 0.4, 0.4, 0, 0, shouldStop, state);
}

void moveNoSyncMinspeedParam(float lSpeed, float rSpeed, float distance, float accRate, float deccRate, bool shouldStop, int state)
{
    move(lSpeed, rSpeed, 12, 12, distance, accRate, deccRate, defaultkP, defaultkD, shouldStop, state);
}

void moveNoSyncMinspeedParamWallSquare(float lSpeed, float rSpeed, float distance, float accRate, float deccRate, bool shouldStop, int state)
{
    move(lSpeed, rSpeed, 12, 12, distance, accRate, deccRate, 0, 0, shouldStop, state);
}

void moveSimple(float lSpeed, float rSpeed, float distance, int state)
{
    move(lSpeed, rSpeed, 12, 12, distance, 0.4, 0.4, defaultkP, defaultkD, true, state);
}

void moveSimpleWallSquare(float lSpeed, float rSpeed, float distance, int state)
{
    move(lSpeed, rSpeed, 12, 12, distance, 0.4, 0.4, 0, 0, true, state);
}

void turn1MotorEverything(float speed, float startSpeed, float endSpeed, float angle, float accRate, float deccRate, float turnkP, float turnkD, bool shouldStop, int port)
{
    speed = fabs(speed);

    if (port == LEFT)
    {
        move(speed*sgn(angle), 0, startSpeed, endSpeed, fabs(angle)/360.0*2.0*wheelDist*PI, accRate, deccRate, turnkP, turnkD, shouldStop, RELCM);
    }
    else
    {
        move(0, speed*sgn(angle)*-1, startSpeed, endSpeed, fabs(angle)/360.0*2.0*wheelDist*PI, accRate, deccRate, turnkP, turnkD, shouldStop, RELCM);
    }
}

void turn1MotorAccMinspeed(float speed, float startSpeed, float endSpeed, float angle, float accRate, float deccRate, bool shouldStop, int port)
{
    turn1MotorEverything(speed, startSpeed, endSpeed, angle, accRate, deccRate, 0, 0, shouldStop, port);
}

void turn1MotorAcc(float speed, float angle, float accRate, float deccRate, int port)
{
    turn1MotorAccMinspeed(speed, 12, 12, angle, accRate, deccRate, true, port);
}

void turn1Motor(float speed, float angle, int port)
{
    turn1MotorAcc(speed, angle, 0.4, 0.4, port);
}

void turn2MotorEverything(float speed, float startSpeed, float endSpeed, float angle, float accRate, float deccRate, float turnkP, float turnkD, bool shouldStop)
{
    speed = fabs(speed);

    move(speed*sgn(angle), -speed*sgn(angle), startSpeed, endSpeed, fabs(angle)/360.0*wheelDist*PI, accRate, deccRate, turnkP, turnkD, shouldStop, RELCM);
}

void turn2MotorAccMinspeed(float speed, float startSpeed, float endSpeed, float angle, float accRate, float deccRate, bool shouldStop)
{
    turn2MotorEverything(speed, startSpeed, endSpeed, angle, accRate, deccRate, 0, 0, true);
}

void turn2MotorAcc(float speed, float angle, float accRate, float deccRate)
{
    turn2MotorAccMinspeed(speed, 12, 12, angle, accRate, deccRate, true);
}

void turn2Motor(float speed, float angle)
{
    turn2MotorAcc(speed, angle, 0.4, 0.4);
}


// Simple Arm Functions (Degrees/Time/Absolute)

void moveArmSimple(float speed, float distance, int port, int state)
{
    moveArm(speed, 30, 30, distance, 0.4, 0.4, true, port, state);
}

void moveArmAbsSimple(float speed, float distance, int port)
{
    moveArmAbs(speed, 30, 30, distance, 0.4, 0.4, true, port);
}


// Simple Move Sensing Functions


// Simple Line Following Functions


