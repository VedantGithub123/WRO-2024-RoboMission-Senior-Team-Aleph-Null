void surpriseChallenge()
{
    moveArmAbsSimple(40, -100, CLAW);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    // Add the following code to the end of the program
    if (startedClose)
    {
        moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 681, defaultAcc, defaultAcc, true, RELDEG);
        turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, LEFT);
        moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 440, defaultAcc, defaultAcc, false, RELDEG);
        moveSimpleWallSquare(-100, -100, 1000, TIME);
        setSpeed(0, 0);
        resetRelative();
        turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
        moveSenseOneSensorSimple(-20, -20, defaultMinspeed, true, 3, RED, COLOR);
        moveNoSyncParam(-20, -20, defaultMinspeed, defaultMinspeed, 92, defaultAcc, defaultAcc, true, RELDEG);
        turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true);
        moveSimpleWallSquare(-50, -50, 1000, TIME);
        setSpeed(0, 0);
        resetRelative();
        moveNoSyncParam(20, 20, defaultMinspeed, defaultMinspeed, 132, defaultAcc, defaultAcc, true, RELDEG);
    }
    else
    {
        moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 681, defaultAcc, defaultAcc, true, RELDEG);
        turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, LEFT);
        moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 440, defaultAcc, defaultAcc, false, RELDEG);
        moveSimpleWallSquare(-100, -100, 1000, TIME);
        setSpeed(0, 0);
        resetRelative();
		sleep(400);
        moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 131, defaultAcc, defaultAcc, true, RELDEG);
        turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
        moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 1927, 0.2, 0.2, true, RELDEG);
        moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 3, BLACK, COLOR);
        turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 100, defaultAcc, defaultAcc, true);
        moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 1495, 0.2, 0.2, true, RELDEG);
        moveSimpleWallSquare(-100, -100, 1000, TIME);
        setSpeed(0, 0);
        resetRelative();
        turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
        moveSenseOneSensorSimple(-20, -20, defaultMinspeed, true, 3, RED, COLOR);
        moveNoSyncParam(-20, -20, defaultMinspeed, defaultMinspeed, 92, defaultAcc, defaultAcc, true, RELDEG);
        turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true);
        moveSimpleWallSquare(-50, -50, 1000, TIME);
        setSpeed(0, 0);
        resetRelative();
        moveNoSyncParam(20, 20, defaultMinspeed, defaultMinspeed, 132, defaultAcc, defaultAcc, true, RELDEG);
    }
}