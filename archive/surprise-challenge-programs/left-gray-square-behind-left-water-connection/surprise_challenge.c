void surpriseChallenge()
{
    // Replace the lift moving down for the last water connection with the following code
    moveArmAbsSimple(100, armDegreeToDrop+20, LIFT);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 260, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 100, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 600, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(100, 50, 100, -45, defaultAcc, defaultAcc, true, RIGHT);
}