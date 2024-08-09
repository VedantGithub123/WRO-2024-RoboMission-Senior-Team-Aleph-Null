void surpriseDay()
{
    // Collects the close red blocks
    startTask(armReset);
    sleep(300);
    moveSimpleNoSettle(30, 30, 90, RELDEG);
    turn1MotorNoSettle(100, -100, RIGHT);
    resetRelative();
    setSpeed(0, 0);
    moveArmSimple(-100, 700, LIFT, TIME);
    resetArmAbs(LIFT);
    startTask(liftArmForFirstBlock);
    stopTask(armReset);

    moveSenseOneSensorNoSync(30, 30, 20, false, 3, RED, COLOR);
    moveSenseOneSensorNoSync(30, 30, 30, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(15, 15, 30, 15, 65, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(150);

    // 2nd Block
    moveNoSyncAccParamWallSquare(40, 40, 20, 20, 145, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    startTask(liftArmForFarGreenBlue);

    // Goes to the far red blocks
    moveSimpleNoSettle(-80, -100, 160, RELDEG);

    turn1MotorAccMinspeed(100, 100, 100, 48, 0.4, 0.4, false, RIGHT);

    moveNoSyncParam(100, 100, 100, 100, 1660, 0.25, 0.25, false, RELDEG);

    turn2MotorAccMinspeed(100, 100, 20, 162, 0.4, 0.4, true);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 600, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);

    // Collects the far red blocks
    moveSenseOneSensorNoSync(30, 30, 20, false, 2, RED, COLOR);
    moveSenseOneSensorNoSync(30, 30, 30, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(20, 20, 30, 12, 43, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(250);

    // 2nd Block
    moveNoSyncAccParamWallSquare(30, 30, 15, 15, 145, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);

    //puts red stack away
    moveNoSyncParam(-60, -100, defaultMinspeed, defaultMinspeed, 350, defaultAcc, defaultAcc, false, RELDEG);
    setSpeed(0, 0);
    resetRelative();
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncAccParamWallSquare(-40, -40, -40, -40, 600, true, TIME);
    setSpeed(0, 0);
    resetRelative();
    startTask(armDownToPlaceStack);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
    resetRelative();
    sleep(200);
    startTask(openClawForPlacingStacks);
    sleep(100);
    startTask(liftArmForFirstBlock);
    moveNoSyncParam(-100, -100, 100, 100, 80, 0.25, 0.25, false, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 400, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);
    stopTask(openClawForPlacingStacks);

    // Collects the far yellow blocks
    moveSenseOneSensorNoSync(30, 30, 30, false, 3, RED, COLOR);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 250, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(250);

    // 2nd Block
    moveNoSyncAccParamWallSquare(40, 40, 20, 20, 138, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst-10, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(150);

    moveNoSyncParam(-60, -100, defaultMinspeed, defaultMinspeed, 350, defaultAcc, defaultAcc, false, RELDEG);
    setSpeed(0, 0);
    resetRelative();
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 600, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    //goes to close yellow blocks
    moveNoSyncParam(100, 100, 100, 100, 1200, 0.25, 0.25, false, RELDEG);
    turn1MotorAccMinspeed(100, 100, 100, 90, 0.4, 0.4, false, LEFT);
    moveNoSyncParam(100, 100, 100, 100, 660, 0.25, 0.25, false, RELDEG);

    turn1MotorAccMinspeed(100, 100, 100, -90, 0.4, 0.4, false, RIGHT);

    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 600, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);

    //collects close yellow blocks
    moveSenseOneSensorNoSync(-30, -30, -30, false, 3, RED, COLOR);
    startTask(liftArmBeforeBlocks);
    resetRelative();
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 440, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 20, RELDEG);
    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(250);

    // 2nd Block
    moveNoSyncAccParamWallSquare(30, 30, 20, 20, 151, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 20, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);


    //puts yellow stack away
    moveSenseOneSensorNoSync(-60, -100, 30, true, 2, RED, COLOR);
    resetRelative();
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 105, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncAccParamWallSquare(-30, -30, -30, -30, 800, true, TIME);
    setSpeed(0, 0);
    resetRelative();
    startTask(armDownToPlaceStack);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 95, defaultAcc, defaultAcc, true, RIGHT);
    resetRelative();
    sleep(200);
    startTask(openClawForPlacingStacks);
    sleep(100);
    startTask(liftArmForFirstBlock);
    moveNoSyncParam(-100, -100, 100, 100, 80, 0.25, 0.25, false, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -85, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 400, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);
    stopTask(openClawForPlacingStacks);

    //collects close green/blue blocks
     moveSenseOneSensorNoSync(20, 20, 20, false, 3, BLACK, COLOR);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    sleep(300);

    // 2nd Block
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 74, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(150);
    startTask(liftArmBeforeBlocks);
    moveSimpleNoSettle(-60, -100, 160, RELDEG);

    turn1MotorAccMinspeed(100, 100, 100, 100, 0.4, 0.4, false, RIGHT);
    moveNoSyncAccParamWallSquare(-40, -40, -40, -40, 800, true, TIME);
    setSpeed(0, 0);
    resetRelative();
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 1400, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(100, 100, 100, -180, 0.4, 0.4, false, RIGHT);
    moveNoSyncAccParamWallSquare(-40, -40, -40, -40, 800, true, TIME);
    setSpeed(0, 0);
    resetRelative();
    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);

    //collects far green/blue blocks
    moveSenseOneSensorNoSync(20, 20, 20, false, 3, BLACK, COLOR);
    moveNoSyncParam(40, 40, defaultMinspeed, defaultMinspeed, 50, defaultAcc, defaultAcc, true, RELDEG);
    moveNoSyncParam(-40, -40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RELDEG);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(150);
    startTask(liftArmBeforeBlocks);
    sleep(300);
    moveNoSyncParam(40, 40, defaultMinspeed, defaultMinspeed, 80, defaultAcc, defaultAcc, true, RELDEG);

    //second block
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(150);
    startTask(liftArmBeforeBlocks);

    //puts green/blue stack away
    moveNoSyncParam(-60, -100, defaultMinspeed, defaultMinspeed, 200, defaultAcc, defaultAcc, false, RELDEG);
    setSpeed(0, 0);
    resetRelative();
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncAccParamWallSquare(-40, -40, -40, -40, 600, true, TIME);
    setSpeed(0, 0);
    resetRelative();
    startTask(armDownToPlaceStack);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
    moveSenseOneSensorNoSync(40, 40, 20, true, 3, RED, COLOR);
    resetRelative();
    sleep(200);
    startTask(openClawForPlacingStacks);
    sleep(100);
    startTask(liftArmForFirstBlock);
    moveNoSyncParam(-100, -100, 100, 100, 80, 0.25, 0.25, false, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 400, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    //water connection
    moveNoSyncParam(100, 100, 20, 20, 1100, 0.25, 0.25, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
    moveSenseOneSensorNoSync(20, 20, 20, false, 3, BLACK, COLOR);
    moveNoSyncParam(100, 100, 20, 20, 1500, 0.25, 0.25, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 1000, true, TIME);
    setSpeed(0, 0);
    resetRelative();
    setArmSpeed(LIFT, 100);
    moveNoSyncParam(50, 50, 20, 20, 700, 0.25, 0.25, true, RELDEG);
    turn2MotorAccMinspeed(20, 20, 20, 92, 0.4, 0.4, true);
    resetRelative();
    moveSenseOneSensor(-30, -30, 30, defaultAcc, defaultkP/2, defaultkD/2, true, 1, WHITE, COLOR);
    moveArmAbsSimple(100, armDegreeToDrop+20, LIFT);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 40, defaultAcc, defaultAcc, true, RIGHT);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 38, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(100, 100, 20, 20, 1910, 0.25, 0.25, true, RELDEG);
    moveNoSyncParam(-100, -100, 20, 20, 150, 0.25, 0.25, true, RELDEG);
   	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 800, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    // 2nd Water connection
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 88, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncParam(-100, -100, 20, 20, 800, 0.25, 0.25, true, RELDEG);
    moveSenseOneSensorNoSync(-20, -20, 20, false, 1, BLACK, COLOR);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -88, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 400, true, TIME);
    setSpeed(0, 0);
    resetRelative();
    setArmSpeed(LIFT, 100);
    moveNoSyncParam(100, 100, 20, 20, 1110, 0.25, 0.25, true, RELDEG);
    turn1Motor(50, -90, LEFT);
    moveSenseOneSensor(-30, -30, 30, defaultAcc, defaultkP/2, defaultkD/2, true, 1, WHITE, COLOR);
    moveArmAbsSimple(100, armDegreeToDrop+20, LIFT);

    // Debris
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 20, defaultAcc, defaultAcc, true, RIGHT);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 20, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(50, 50, 20, 20, 690, 0.25, 0.25, true, RELDEG);
    moveNoSyncParam(-50, -50, 20, 20, 710, 0.25, 0.25, true, RELDEG);
    turn2MotorAccMinspeed(20, 20, 20, 90, 0.4, 0.4, true);
    moveNoSyncParam(50, 50, 20, 20, 360, 0.25, 0.25, true, RELDEG);
    turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, -150, defaultAcc, defaultAcc, true);
    moveSenseOneSensorNoSync(40, 40, 20, false, 2, BLACK, COLOR);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 60, defaultAcc, defaultAcc, true, LEFT);
    lineFollowOneSensorStopOneSensor(50, 50, defaultAcc, -0.4, -20, true, 2, 50, 1, BLACK, COLOR);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(50, 50, 20, 20, 200, 0.25, 0.25, true, RELDEG);
    moveNoSyncParam(-50, -50, 20, 20, 300, 0.25, 0.25, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -180, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(-50, -50, 20, 20, 1000, 0.25, 0.25, true, RELDEG);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 800, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    // Final Debris
    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);
    setArmSpeed(LIFT, 100);
    sleep(700);
    moveSenseOneSensor(100, 100, 20, 0.4, 0, 0, false, 2, BLUE, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(100, 100, 100, 20, 150, true, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    moveArmAbsSimple(40, 160, LIFT);

    moveSimpleNoSettle(-80, -100, 535, RELDEG);
    turn1MotorNoSettle(100, 100, RIGHT);
    moveSimpleWallSquare(-40, -40, 900, TIME);
    setSpeed(0, 0);
    resetRelative();
    moveArmAbsSimple(40, 220, LIFT);

    moveSimple(50, 50, 620, RELDEG);
}