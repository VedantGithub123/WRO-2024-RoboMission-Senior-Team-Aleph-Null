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
    move(lSpeed, rSpeed, startSpeed, endSpeed, distance, defaultAcc, defaultAcc, defaultkP, defaultkD, shouldStop, state);
}

void moveNoSyncAccParamWallSquare(float lSpeed, float rSpeed, float startSpeed, float endSpeed, float distance, bool shouldStop, int state)
{
    move(lSpeed, rSpeed, startSpeed, endSpeed, distance, defaultAcc, defaultAcc, 0, 0, shouldStop, state);
}

void moveNoSyncMinspeedParam(float lSpeed, float rSpeed, float distance, float accRate, float deccRate, bool shouldStop, int state)
{
    move(lSpeed, rSpeed, defaultMinspeed, defaultMinspeed, distance, accRate, deccRate, defaultkP, defaultkD, shouldStop, state);
}

void moveNoSyncMinspeedParamWallSquare(float lSpeed, float rSpeed, float distance, float accRate, float deccRate, bool shouldStop, int state)
{
    move(lSpeed, rSpeed, defaultMinspeed, defaultMinspeed, distance, accRate, deccRate, 0, 0, shouldStop, state);
}

void moveSimple(float lSpeed, float rSpeed, float distance, int state)
{
    move(lSpeed, rSpeed, defaultMinspeed, defaultMinspeed, distance, defaultAcc, defaultAcc, defaultkP, defaultkD, true, state);
}

void moveSimpleWallSquare(float lSpeed, float rSpeed, float distance, int state)
{
    move(lSpeed, rSpeed, defaultMinspeed, defaultMinspeed, distance, defaultAcc, defaultAcc, 0, 0, true, state);
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
        move(0, speed*sgn(angle), startSpeed, endSpeed, fabs(angle)/360.0*2.0*wheelDist*PI, accRate, deccRate, turnkP, turnkD, shouldStop, RELCM);
    }
}

void turn1MotorAccMinspeed(float speed, float startSpeed, float endSpeed, float angle, float accRate, float deccRate, bool shouldStop, int port)
{
    turn1MotorEverything(speed, startSpeed, endSpeed, angle, accRate, deccRate, 0, 0, shouldStop, port);
}

void turn1MotorAcc(float speed, float angle, float accRate, float deccRate, int port)
{
    turn1MotorAccMinspeed(speed, defaultMinspeed, defaultMinspeed, angle, accRate, deccRate, true, port);
}

void turn1Motor(float speed, float angle, int port)
{
    turn1MotorAcc(speed, angle, defaultAcc, defaultAcc, port);
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
    turn2MotorAccMinspeed(speed, defaultMinspeed, defaultMinspeed, angle, accRate, deccRate, true);
}

void turn2Motor(float speed, float angle)
{
    turn2MotorAcc(speed, angle, defaultAcc, defaultAcc);
}


// Simple Arm Functions (Degrees/Time/Absolute)

void moveArmSimple(float speed, float distance, int port, int state)
{
    moveArm(speed, defaultArmMinspeed, defaultArmMinspeed, distance, defaultAcc, defaultAcc, true, port, state);
}

void moveArmAbsSimple(float speed, float distance, int port)
{
    moveArmAbs(speed, defaultArmMinspeed, defaultArmMinspeed, distance, defaultAcc, defaultAcc, port);
}


// Simple Move Sensing Functions

void moveSenseOneSensorSimple(float lSpeed, float rSpeed, float startSpeed, bool shouldStop, int sensor, int target, int state)
{
    moveSenseOneSensor(lSpeed, rSpeed, startSpeed, defaultAcc, defaultkP, defaultkD, shouldStop, sensor, target, state);
}

void moveSenseTwoSensorSimple(float lSpeed, float rSpeed, float startSpeed, bool shouldStop, int target1, int state1, int target2, int state2)
{
    moveSenseTwoSensor(lSpeed, rSpeed, startSpeed, defaultAcc, defaultkP, defaultkD, shouldStop, 2, target1, state1, 3, target2, state2);
}
