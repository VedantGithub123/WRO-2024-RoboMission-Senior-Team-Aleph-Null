void surpriseChallenge()
{
    // Add the following code after the wall square after dropping the last stack
    // Surprise Challenge
    // Goes to the blocks
    moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 872, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(100, defaultMinspeed, defaultMinspeed, 46, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 743, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(100, defaultMinspeed, defaultMinspeed, -132, defaultAcc, defaultAcc, true, RIGHT);
    moveSimpleWallSquare(-100, -100, 1000, TIME);
    setSpeed(0, 0);
    resetRelative();
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 285, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 94, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 785, defaultAcc, defaultAcc, true, RELDEG);
    moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 3, BLACK, COLOR);
    moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 550, defaultAcc, defaultAcc, true, RELDEG);
    turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, -92, defaultAcc, defaultAcc, true);

    // Collects the blocks
    moveArmAbsSimple(100, 200, LIFT);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 230, defaultAcc, defaultAcc, true, RELDEG);
    setArmSpeed(LIFT, 100);
    sleep(700);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -92, defaultAcc, defaultAcc, true, RIGHT);

    // Puts the blocks away
    moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 395, defaultAcc, defaultAcc, true, RELDEG);
    turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 91, defaultAcc, defaultAcc, true);
    moveArmAbsSimple(100, 200, LIFT);
    moveSimpleWallSquare(-100, -100, 1000, TIME);
    setSpeed(0, 0);
    resetRelative();
    moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 1350, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
    moveSimple(40, 40, 70, RELDEG);
    // Goes back to normal position
    moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 312, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, LEFT);
    moveSimpleWallSquare(-100, -100, 1000, TIME);
    setSpeed(0, 0);
    resetRelative();
}