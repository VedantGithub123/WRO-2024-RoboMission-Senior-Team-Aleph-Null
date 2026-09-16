void surpriseDay()
{
    startTask(armReset);
    sleep(1500);
    moveArmSimple(-100, 700, LIFT, TIME);
    resetArmAbs(LIFT);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 800, true, TIME);
    setSpeed(0, 0);
    resetRelative();
    setArmSpeed(LIFT, 100);
    moveNoSyncMinspeedParam(100, 100, 780, 0.2, 0.2, true, RELDEG);
    turn2MotorAcc(30, 91.5, 0.2, 0.2);
    moveSenseOneSensor(-30, -30, 30, defaultAcc, defaultkP/2, defaultkD/2, true, 1, WHITE, COLOR);
    moveArmAbsSimple(100, armDegreeToDrop+20, LIFT);
    moveNoSyncMinspeedParam(100, 100, 1000, 0.2, 0.2, true, RELDEG);
    turn1MotorNoSettle(100, -90, LEFT);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 1000, true, TIME);
    startTask(liftArmForFirstBlock);
    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);


    stopTask(armReset);
    getReflection(3);

    moveSenseOneSensorNoSync(30, 30, 20, false, 3, 50, LESSREFL);
    moveNoSyncAccParamWallSquare(15, 15, 30, 15, 60, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(200);

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

    turn1MotorAccMinspeed(100, 100, 100, 56, 0.4, 0.4, false, RIGHT);

    moveNoSyncParam(100, 100, 100, 100, 1660, 0.25, 0.25, false, RELDEG);

    turn2MotorAccMinspeed(100, 100, 20, 162, 0.4, 0.4, true);
    getReflection(3);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 600, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);

    // Collects the far red blocks
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, 50, LESSREFL);
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

    //puts first stack away
    moveNoSyncParam(-100, -100, 100, 100, 200, 0.4, 0.4, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    turn1MotorAccMinspeed(100, 100, 20, 95, 0.4, 0.4, false, RIGHT);

    moveNoSyncAccParamWallSquare(-40, -40, 20, 40, 900, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    moveNoSyncParam(70, 70, 30, 30, 810, 0.4, 0.4, false, RELDEG);

    turn1MotorAccMinspeed(50, 15, 15, 91, 0.4, 0.4, false, LEFT);

    moveSenseOneSensor(100, 100, 15, 0.4, 0, 0, false, 1, BLUE, COLOR);
    resetRelative();
    startTask(armDownToPlaceStack);
    moveNoSyncParam(100, 100, 100, 30, 370, 0.4, 0.2, true, RELDEG);
    resetRelative();

    startTask(openClawForPlacingStacks);
    sleep(100);
    moveNoSyncParam(-100, -100, 15, 15, 740, 0.25, 0.4, false, RELDEG);
    stopTask(openClawForPlacingStacks);
    startTask(liftArmForFirstBlock);
    turn1MotorAccMinspeed(50, 15, 15, -93, 0.4, 0.4, false, LEFT);

    moveNoSyncAccParamWallSquare(-100, -100, 15, 60, 1100, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    turn1MotorNoSettle(100, 45, LEFT);
    turn1MotorNoSettle(100, -52, RIGHT);

    //collects second stack
    moveSenseOneSensorNoSync(25, 20, 20, false, 3, BLACK, COLOR);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -60);
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
    sleep(200);

    //third block
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    sleep(300);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 74, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(200);

    //puts second stack away
    moveSimpleNoSettle(-80, -100, 700, RELDEG);
    turn1MotorNoSettle(100, 124, RIGHT);
    moveSimpleWallSquare(-60, -60, 900, TIME);
    setSpeed(0, 0);
    resetRelative();
    moveSimpleNoSettle(100, 100, 600, RELDEG);


    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);

    startTask(openClawForPlacingStacks);
    sleep(100);
    startTask(liftArmForFirstBlock);

    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 900, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    turn1MotorNoSettle(100, 70, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);
    setArmSpeed(LIFT, 100);


    // Collects the debris
    moveSenseOneSensor(100, 100, 20, 0.4, 0, 0, false, 2, BLUE, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(40, 40, 60, 20, 170, true, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    moveArmAbsSimple(40, 160, LIFT);
    moveSimpleNoSettle(-80, -100, 305, RELDEG);
    turn1MotorNoSettle(100, 128, RIGHT);
    moveSimpleWallSquare(-40, -40, 1200, TIME);
    setSpeed(0, 0);
    resetRelative();
    setArmSpeed(LIFT, 100);

    //puts away debris
    moveSimpleNoSettle(50, 50, 1100, RELDEG);
    turn1MotorNoSettle(50, 92, RIGHT);
    moveSenseOneSensor(50, 50, 20, 0.4, 0, 0, false, 2, BLACK, COLOR);
    moveSimpleNoSettle(50, 50, 540, RELDEG);
    turn1MotorNoSettle(50, 92, RIGHT);
	sleep(100);
    turn1MotorNoSettle(50, -89, RIGHT);
    startTask(liftArmForFirstBlock);
    moveSimple(-50, -50, 550, RELDEG);
    turn1MotorNoSettle(50, -92, LEFT);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 900, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);

    //collects third stack
    moveSenseOneSensorNoSync(-15, -15, 15, false, 3, RED, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 430, false, RELDEG);
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
    startTask(liftArmBeforeBlocks);
    sleep(250);

    //third block
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
    startTask(liftArmBeforeBlocks);
    sleep(250);

    //puts third stack away
    moveNoSyncAccParamWallSquare(-60, -100, 20, 20, 300, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    turn1Motor(100, 113, RIGHT);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 800, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimpleNoSettle(100, 100, 600, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(200);

    startTask(liftArmForFirstBlock);

    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 800, false, TIME);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(LIFT, 0);

    //Moves second yellow debris
    moveSimple(100, 100, 270, RELDEG);
    turn1Motor(100, 90, LEFT);
    moveSenseOneSensor(50, 50, 15, 0.4, 0, 0, true, 2, BLACK, COLOR);
    turn2MotorAcc(50, -90, 0.2, 0.2);
    moveArmAbsSimple(100, -210, CLAW);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 1000, false, TIME);
    resetRelative();
    setSpeed(0, 0);
    moveSimple(100, 100, 1300, RELDEG);
    turn1Motor(100, 180, RIGHT);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 1300, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, 200, LIFT);
    moveSimple(30, 30, 40, RELDEG);
    turn1Motor(50, 92, RIGHT);
    moveSenseOneSensor(20, 20, 15, 0.4, 0, 0, false, 3, RED, COLOR);
    moveSimple(50, 50, 550, RELDEG);
    setArmSpeed(LIFT, 100);
    sleep(700);
    moveSenseOneSensor(-20, -20, 15, 0.4, 0, 0, true, 1, RED, COLOR);
    turn2MotorAcc(50, 185, 0.2, 0.2);
    moveArmAbsSimple(100, 200, LIFT);
    moveSimple(-100, -100, 200, RELDEG);
    turn1Motor(100, -90, LEFT);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 400, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    //moves last debris
    moveSimple(100, 100, 700, RELDEG);
    turn1Motor(100, 90, LEFT);
    moveSimple(100, 100, 600, RELDEG);
    moveSimple(-100, -100, 320, RELDEG);
    turn1Motor(100, -90, LEFT);

    //second water connection
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 1500, false, TIME);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(LIFT, 100);
    moveNoSyncMinspeedParam(100, 100, 828, 0.2, 0.2, true, RELDEG);
    resetRelative();
    turn1MotorAcc(50, 90, 0.2, 0.2, LEFT);
    moveSimple(-40, -40, 300, RELDEG);

    moveSenseOneSensor(-30, -30, 30, defaultAcc, defaultkP/2, defaultkD/2, true, 1, WHITE, COLOR);
    moveArmAbsSimple(100, armDegreeToDrop+30, LIFT);
    turn1Motor(100, 140, LEFT);
    moveSimple(100, 100, 350, RELDEG);
    turn2MotorAcc(20, -188, 0.2, 0.2);
    moveSimple(80, 80, 700, RELDEG);
    moveSenseOneSensor(80, 80, 15, 0.4, 0, 0, true, 2, WHITE, COLOR);
    moveSenseOneSensor(80, 80, 80, 0.4, 0, 0, true, 2, BLACK, COLOR);
    turn1Motor(100, 45, LEFT);
    moveSenseOneSensor(80, 80, 15, 0.4, 0, 0, true, 3, RED, COLOR);
}