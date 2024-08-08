void surpriseDay()
{
    // Resets the arms
    startTask(armReset);
    sleep(300);
    moveSimpleNoSettle(30, 30, 90, RELDEG);
    turn1MotorNoSettle(100, -100, RIGHT);
    resetRelative();
    setSpeed(0, 0);
    moveArmSimple(-100, 730, LIFT, TIME);
    resetArmAbs(LIFT);
    startTask(liftArmForFirstBlock);
    stopTask(armReset);

    // Collects the first 4 blocks
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, RED, COLOR);
    moveSenseOneSensorNoSync(30, 30, 30, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(15, 15, 30, 15, 527, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(CLAW, -100);
    sleep(100)
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    moveNoSyncAccParamWallSquare(20, 20, 20, 20, 73, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
     sleep(100)
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    moveNoSyncAccParamWallSquare(20, 20, 20, 20, 73, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
     sleep(100)
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    moveNoSyncAccParamWallSquare(20, 20, 20, 20, 73, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(150)
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    turn1Motor(100, 90, RIGHT);

    // Collects the 5th block for the first stack
    moveNoSyncAccParamWallSquare(-40, -40, 30, 60, 600, false, TIME);
    resetRelative();
    setSpeed(0, 0);
     turn1MotorNoSettle(100, 98, RIGHT);
    moveNoSyncParamWallSquare(100, 100, 50, 30, 1000, 0.4, 0.4, false, RELDEG);
     moveSenseOneSensorNoSync(25, 30, 30, false, 3, RED, COLOR);
    moveSenseOneSensorNoSync(28, 30, 30, false, 3, BROWN, COLOR);

 	moveNoSyncAccParamWallSquare(23, 25, 30, 12, 326, false, RELDEG);

	resetRelative();
    setSpeed(0, 0);
	turn1MotorNoSettle(30, 8, LEFT);

	moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(200);

    // Puts the stack away
    moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 1240, defaultAcc, defaultAcc, true, RELDEG);
    turn1Motor(30, 95, LEFT);
    moveSimpleWallSquare(-100, -100, 500, TIME);
   	resetRelative();
    setSpeed(0, 0);
    startTask(armDownToPlaceStack);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 600, defaultAcc, defaultAcc, true, RELDEG);
    startTask(openClawForPlacingStacks);
    sleep(200);

    // Goes to the next 4 blocks
    startTask(liftArmForFirstBlock);
    moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 600, defaultAcc, defaultAcc, true, RELDEG);
    moveSimpleWallSquare(-100, -100, 300, TIME);
    resetRelative();
    setSpeed(0, 0);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RELDEG);
    turn1Motor(30, 90, LEFT);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 820, defaultAcc, defaultAcc, true, RELDEG);
    turn2MotorAccMinspeed(100, 100, 20, 100, 0.4, 0.4, true);

    moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 1000, defaultAcc, defaultAcc, true, RELDEG);
    moveSimpleWallSquare(-100, -100, 1000, TIME);
    resetRelative();
    setSpeed(0, 0);
    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);

    // Collects the next 4 blocks
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, RED, COLOR);
    moveSenseOneSensorNoSync(30, 30, 30, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(15, 15, 30, 15, 527, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(CLAW, -100);
    sleep(100)
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    moveNoSyncAccParamWallSquare(20, 20, 20, 20, 73, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
     sleep(100)
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    moveNoSyncAccParamWallSquare(20, 20, 20, 20, 73, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
     sleep(100)
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    moveNoSyncAccParamWallSquare(20, 20, 20, 20, 73, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(150)
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    // Goes to the 5th block
    moveNoSyncAccParamWallSquare(40, 40, 30, 12, 200, false, RELDEG);
    turn1MotorNoSettle(100, 90, RIGHT);
    moveSimpleWallSquare(-100, -100, 500, TIME);
   	resetRelative();
    setSpeed(0, 0);

    moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 1300, defaultAcc, defaultAcc, true, RELDEG);
    turn2MotorAccMinspeed(100, 100, 20, 180, 0.4, 0.4, true);
    moveSimpleWallSquare(-50, -50, 2400, TIME);
   	resetRelative();
    setSpeed(0, 0);

    // Collects the 5th block for the 2nd stack
   	moveNoSyncMinspeedParam(40, 40, 90, 0.4, 0.25, false, RELDEG);
   	turn1MotorAccMinspeed(100, 20, 20, 90, 0.2, 0.2, true, RIGHT);
    resetRelative();
    moveSenseOneSensorSimple(60, 60, 40, false, 3, RED, COLOR);
	moveSenseOneSensorSimple(60, 60, 40, false, 1, BROWN, COLOR);
	resetRelative();
    moveNoSyncAccParam(30, 30, 60, 12, 232, true, RELDEG);
    moveArmAbsSimple(100, 360, LIFT);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    turn1MotorNoSettle(30, -18, RIGHT);
	moveSimpleNoSettle(-20, -20, 45, RELDEG);
	turn1MotorNoSettle(30, -21, LEFT);
	moveSimpleNoSettle(20, 20, 55, RELDEG);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen-10, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(blocksLow);

    // Puts the 2nd stack away
    moveSenseOneSensorSimple(-100, -100, 50, false, 3, RED, COLOR);
    moveSenseOneSensorSimple(-100, -100, 100, false, 3, WHITE, COLOR);
    moveNoSyncAccParam(-100, -100, 100, 100, 80, false, RELDEG);
    turn1MotorAccMinspeed(100, 100, 40, -87, 0.4, 0.4, false, RIGHT);

	moveNoSyncAccParamWallSquare(-40, -40, 100, 100, 500, true, TIME);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimpleNoSettle(100, 100, 600, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(200);

    startTask(liftArmForFirstBlock);
    moveNoSyncAccParam(-100, -100, 100, 100, 600, false, RELDEG);
	moveSimpleWallSquare(-100, -100, 400, TIME);
   	resetRelative();
    setSpeed(0, 0);

    // Collects the debris near the bridge
	moveNoSyncAccParam(100, 100, 100, 100, 250, false, RELDEG);
	turn1MotorNoSettle(100, 90, LEFT);
	lineFollowOneSensorStopOneSensor(50, 50, defaultAcc, 0.4, 20, true, 3, 50, 2, BLACK, COLOR)
	moveNoSyncAccParam(50, 50, 20, 20, 705, true, RELDEG);
	setArmSpeed(CLAW, -100);
	sleep(700);
	moveNoSyncAccParam(-100, -100, 20, 20, 2000, true, RELDEG);
	turn1MotorNoSettle(100, 30, LEFT);
	moveArmAbsSimple(100, -200, CLAW);
	turn1MotorNoSettle(100, -120, LEFT);
	moveSimpleWallSquare(-100, -100, 400, TIME);
   	resetRelative();
    setSpeed(0, 0);

    // Collects the debris near the water connection
    turn1Motor(100, 92, LEFT);
    moveSenseOneSensorSimple(30, 30, 20, true, 3, RED, COLOR);
    moveNoSyncAccParam(-100, -100, 20, 20, 230, true, RELDEG);
   	turn1Motor(100, -90, LEFT);
   	moveSimpleWallSquare(-100, -100, 400, TIME);
   	resetRelative();
    setSpeed(0, 0);
	moveArmAbsSimple(100, -290, CLAW);
    moveNoSyncAccParam(100, 100, 20, 20, 500, true, RELDEG);
    turn1Motor(100, 150, LEFT);
    moveNoSyncAccParam(100, 100, 20, 20, 300, true, RELDEG);
    turn1Motor(100, -150, LEFT);
    moveSimpleWallSquare(-100, -100, 800, TIME);
   	resetRelative();
    setSpeed(0, 0);
    
    // Puts the ruins in the earth allies and ends in base
    turn1Motor(100, 90, RIGHT);
    moveSenseOneSensorSimple(-30, -30, 20, true, 1, RED, COLOR);
    turn1Motor(100, 110, LEFT);
	moveArmAbsSimple(100, -250, CLAW);
    moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 1283, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 56, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncAccParamWallSquare(40, 40, 12, 100, 400, false, RELDEG);
	moveSenseOneSensor(60, 60, 60, 0.4, 0, 0, false, 3, WHITE, COLOR);
	moveNoSyncAccParamWallSquare(80, 100, 100, 50, 950, false, RELDEG);
	resetRelative();
    setSpeed(0, 0);
    moveSimple(-100, -100, 500, RELDEG);
}