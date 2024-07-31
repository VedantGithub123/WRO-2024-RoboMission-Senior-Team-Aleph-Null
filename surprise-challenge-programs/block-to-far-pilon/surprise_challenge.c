void surpriseChallenge()
{
    // Add the following code to the end of the program
    moveArmAbsSimple(100, armDegreeToDrop+20, LIFT);
    moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 800, 0.2, 0.2, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -96, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(-100, -100, defaultMinspeed, 100, 470, defaultAcc, defaultAcc, false, RELDEG);
    moveSimpleWallSquare(-100, -100, 1000, TIME);
    setSpeed(0, 0);
    resetRelative();
    moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 785, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 35, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 500, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 70, defaultAcc, defaultAcc, true, RIGHT);
}