void surpriseChallenge()
{
    // Add the following code to the very end of the program
    moveArmAbsSimple(100, 100, LIFT);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 450, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(80, defaultMinspeed, defaultMinspeed, 95, 0.2, 0.2, true, RIGHT);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 180, defaultAcc, defaultAcc, true, RELDEG);
    moveArmAbsSimple(100, 200, LIFT);
}