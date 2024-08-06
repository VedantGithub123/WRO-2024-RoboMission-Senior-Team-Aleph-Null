void surpriseDay()
{
    setArmSpeed(LIFT, 100);
    sleep(400);
    setArmSpeed(LIFT, 0);
    moveArmSimple(100, 500, CLAW, TIME);
    resetArmAbs(CLAW);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);
    moveArmSimple(-100, 700, LIFT, TIME);
    resetArmAbs(LIFT);
	setArmSpeed(CLAW, 0);
	setArmSpeed(LIFT, 0);
    sleep(50);

    // Moves barrier

    moveArmAbsSimple(100, 200, LIFT);

    moveSimpleWallSquare(-100, -100, 1000, TIME);
    setSpeed(0, 0);
    resetRelative();
    moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 990, 0.2, 0.2, true, RELDEG);
    turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true);
	moveNoSyncParam(30, 30, defaultMinspeed, defaultMinspeed, 100, 0.2, 0.2, true, RELDEG);
    moveNoSyncParam(-30, -30, defaultMinspeed, defaultMinspeed, 208, 0.2, 0.2, true, RELDEG);
    turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, -180, defaultAcc, defaultAcc, true);
    moveArmSimple(100, 1000, LIFT, TIME);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 443, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(30, defaultMinspeed, defaultMinspeed, 10, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(30, 30, defaultMinspeed, defaultMinspeed, 170, defaultAcc, defaultAcc, true, RELDEG);
    moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 204, defaultAcc, defaultAcc, LIFT);
    moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 545, 0.2, 0.2, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
    moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 285, 0.2, 0.2, true, RELDEG);
    moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 318, defaultAcc, defaultAcc, LIFT);
    moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 161, 0.2, 0.2, true, RELDEG);
    turn1MotorAccMinspeed(100, defaultMinspeed, defaultMinspeed, -150, defaultAcc, defaultAcc, true, RIGHT);
	moveArmAbsSimple(100, 200, LIFT);
    moveSimpleWallSquare(-100, -100, 1500, TIME);
    setSpeed(0, 0);
    resetRelative();

    // Puts debris away

    moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 767, 0.2, 0.2, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 600, 0.2, 0.2, true, RELDEG);
	moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 3, RED, COLOR);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 263, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 564, 0.2, 0.2, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 265, defaultAcc, defaultAcc, true, RELDEG);
	moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 186, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -41, defaultAcc, defaultAcc, true, LEFT);
	moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 500, 0.2, 0.2, false, RELDEG);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();

    // Reverses water connection

    setArmSpeed(LIFT, 100);
    moveNoSyncMinspeedParam(100, 100, 790, 0.2, 0.2, true, RELDEG);
	turn2MotorAcc(30, 91.5, 0.2, 0.2);
	moveNoSyncAccParam(-100, -100, 20, 30, 250, false, RELDEG);
    moveSenseOneSensor(-30, -30, 30, 0.3, 0, 0, true, 1, WHITE, COLOR);
	moveArmAbsSimple(100, 200, LIFT);
    moveSimple(100, 100, 800, RELDEG);
    turn2Motor(30, -90);
    moveSimpleWallSquare(-100, -100, 1500, TIME);
	setSpeed(0, 0);
	resetRelative();

    // Makes the first pyramid
	startTask(liftArmForFirstBlock);
	turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);
	moveSenseOneSensorNoSync(30, 30, 20, false, 3, RED, COLOR);
    moveSenseOneSensorNoSync(30, 30, 30, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(15, 15, 30, 15, 65, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(CLAW, -100);
	sleep(300);
	moveArmAbsSimple(100, 230, LIFT);

	moveNoSyncParam(-100, -100, 100, 100, 200, 0.4, 0.4, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    turn1MotorAccMinspeed(100, 100, 20, 95, 0.4, 0.4, false, RIGHT);
    moveNoSyncAccParamWallSquare(-40, -40, 20, 40, 900, false, TIME);
    resetRelative();
    setSpeed(0, 0);

	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 274, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
	lineFollowOneSensor(50, defaultMinspeed, defaultMinspeed, 1258, defaultAcc, defaultAcc, 0.4, 20, true, 3, 50, RELDEG);
	moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 2, BLACK, COLOR);

	moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 530, 0.2, 0.2, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 374, 0.2, 0.2, true, RELDEG);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 257, defaultAcc, defaultAcc, LIFT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 49, defaultAcc, defaultAcc, true, RELDEG);
	moveArmSimple(100, 1000, LIFT, TIME);
	moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 300, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 1269, defaultAcc, defaultAcc, true, RELDEG);
	turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true);
	moveArmAbsSimple(100, 300, LIFT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 150, defaultAcc, defaultAcc, true, RELDEG);
	moveArmSimple(100, 1000, LIFT, TIME);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 220, defaultAcc, defaultAcc, LIFT);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -19, defaultAcc, defaultAcc, true, LEFT);
	moveSimple(-30, -30, 50, RELDEG);
	moveArmAbsSimple(100, clawDegreeOpen, CLAW);

	// Makes the second pyramid
	moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 334, 0.2, 0.2, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 80, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 1654, 0.2, 0.2, true, RELDEG);
	turn2Motor(30, 100);
	moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 900, 0.2, 0.2, true, RELDEG);
    moveSimpleWallSquare(-100, -100, 1500, TIME);
	setSpeed(0, 0);
	resetRelative();

	startTask(liftArmForFirstBlock);
	turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);
	moveSenseOneSensorNoSync(30, 30, 20, false, 3, RED, COLOR);
    moveSenseOneSensorNoSync(30, 30, 30, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(15, 15, 30, 15, 85, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(CLAW, -100);
	sleep(300);
	moveArmAbsSimple(100, 230, LIFT);

	moveNoSyncParam(-100, -100, 100, 100, 200, 0.4, 0.4, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    turn1MotorAccMinspeed(100, 100, 20, 95, 0.4, 0.4, false, RIGHT);
    moveNoSyncAccParamWallSquare(-40, -40, 20, 40, 900, false, TIME);
    resetRelative();
    setSpeed(0, 0);

	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 234, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
	lineFollowOneSensor(50, defaultMinspeed, defaultMinspeed, 1258, defaultAcc, defaultAcc, -0.4, -20, true, 3, 50, RELDEG);
	moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 2, BLACK, COLOR);

	moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 374, 0.2, 0.2, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 344, 0.2, 0.2, true, RELDEG);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 257, defaultAcc, defaultAcc, LIFT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 49, defaultAcc, defaultAcc, true, RELDEG);
	moveArmSimple(100, 1000, LIFT, TIME);
	moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 168, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -94, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 1330, defaultAcc, defaultAcc, true, RELDEG);
	turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true);
    moveArmAbsSimple(100, 300, LIFT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 150, defaultAcc, defaultAcc, true, RELDEG);
	moveArmSimple(100, 1000, LIFT, TIME);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 220, defaultAcc, defaultAcc, LIFT);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -19, defaultAcc, defaultAcc, true, LEFT);
	moveSimple(-30, -30, 50, RELDEG);
	moveArmAbsSimple(100, clawDegreeOpen, CLAW);

	// Makes the stack of 4 in blue
	moveSimple(-30, -30, 200, RELDEG);
	turn1Motor(100, -190, RIGHT);
	moveSimpleWallSquare(-100, -100, 1500, TIME);
	setSpeed(0, 0);
	resetRelative();
	turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);
    moveArmAbsSimple(100, armDegreeForFirst, LIFT);

	moveSenseOneSensorNoSync(20, 20, 20, false, 3, BLACK, COLOR);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(300);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 74, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);
    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
	startTask(liftArmBeforeBlocks);
    sleep(300);
	moveNoSyncAccParamWallSquare(20, 20, 30, 20, 84, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);
    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
	startTask(liftArmBeforeBlocks);

	moveNoSyncParam(-100, -100, 100, 100, 200, 0.4, 0.4, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    turn1MotorAccMinspeed(100, 100, 20, 95, 0.4, 0.4, false, RIGHT);
    moveNoSyncAccParamWallSquare(-40, -40, 20, 40, 900, false, TIME);
    resetRelative();
    setSpeed(0, 0);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 1250, 0.2, 0.2, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
	lineFollowOneSensor(50, defaultMinspeed, defaultMinspeed, 958, defaultAcc, defaultAcc, 0.4, 20, true, 3, 50, RELDEG);
	moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 2, BLACK, COLOR);

	moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 455, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -44, defaultAcc, defaultAcc, true, LEFT);
	moveNoSyncParamWallSquare(-50, -50, defaultMinspeed, defaultMinspeed, 394, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -10, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParamWallSquare(-50, -50, defaultMinspeed, defaultMinspeed, 104, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -40, defaultAcc, defaultAcc, true, RIGHT);

	moveSenseOneSensorNoSync(30, 30, 20, false, 3, BLACK, COLOR);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 30, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);
    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
	startTask(liftArmBeforeBlocks);

    moveNoSyncAccParamWallSquare(-70, -100, 100, 20, 380, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    turn1Motor(100, 106, RIGHT);
    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimpleNoSettle(100, 100, 370, RELDEG);
    startTask(openClawForPlacingStacks);
    sleep(200);
    startTask(liftArmForFirstBlock);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 800, false, TIME);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(LIFT, 0);

}