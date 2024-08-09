void surpriseDay()
{
    startTask(armReset);
    sleep(300);
    moveSimpleNoSettle(30, 30, 90, RELDEG);
    turn1MotorNoSettle(100, -103, RIGHT);
    resetRelative();
    setSpeed(0, 0);
    moveArmSimple(-100, 700, LIFT, TIME);
    resetArmAbs(LIFT);
    startTask(liftArmForFirstBlock);
    stopTask(armReset);

    resetRelative();
    moveSenseOneSensorNoSync(30, 25, 20, false, 3, BROWN, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 75, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

	//red block
    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(150);

    turn1Motor(100, -60, LEFT);
    moveSenseOneSensorNoSync(30, 30, 20, true, 2, BLACK, COLOR);
   	lineFollowOneSensor(50, defaultMinspeed, defaultMinspeed, 1000, defaultAcc, defaultAcc, -0.4, -20, true, 2, 50, RELDEG);
   	moveSenseOneSensorNoSync(20, 20, 50, true, 3, BLACK, COLOR);
   	moveNoSyncAccParam(-40, -40, 15, 15, 225, true, RELDEG);
   	turn1Motor(100, -89, RIGHT);

   	//green block
   	moveNoSyncAccParam(40, 40, 20, 20, 186, true, RELDEG);
   	stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);
    moveNoSyncAccParam(-50, -50, 20, 20, 420, true, RELDEG);
    moveSenseOneSensorNoSync(30, 25, 20, true, 2, BLACK, COLOR);
    turn2MotorAccMinspeed(40, 40, 20, 180, 0.4, 0.4, true);
    moveNoSyncAccParamWallSquare(-50, -50, 50, 50, 1800, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    //yellow blocks
    moveNoSyncAccParam(40, 40, 20, 20, 570, true, RELDEG);
   	turn1MotorNoSettle(100, -90, LEFT);
    lineFollowOneSensorStopOneSensor(50, 50, defaultAcc, -0.35, -20, true, 2, 50, 1, BLACK, COLOR);
    moveNoSyncAccParam(20, 20, 50, 15, 115, true, RELDEG);
    turn1MotorNoSettle(100, -90, LEFT);

    moveNoSyncAccParam(40, 40, 20, 20, 280, true, RELDEG);
   	stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);

    turn1Motor(50, -90, RIGHT);
    moveNoSyncAccParam(40, 40, 20, 20, 680, true, RELDEG);
    startTask(armDownToPlaceStack);
    turn1Motor(50, 90, LEFT);
    moveSimple(20, 20, 30, RELDEG)
    startTask(openClawForPlacingStacks);
    sleep(200);

    moveSimpleWallSquare(-100, -100, 1000, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Red stack
    moveArmAbsSimple(50, 130, LIFT);
    turn1Motor(50, 90, RIGHT);
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, RED, COLOR);
    resetRelative();
    moveNoSyncAccParam(30, 30, 30, 20, 115, true, RELDEG);

    turn2Motor(30, 90);
    moveSimpleWallSquare(-100, -100, 1000, TIME);
    resetRelative();
    setSpeed(0, 0);

    moveNoSyncParam(30, 30, defaultMinspeed, defaultMinspeed, 635, 0.2, 0.2, true, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(300);
    moveArmAbsSimple(100, 190, LIFT);

    moveSimple(50, 50, 600, RELDEG);
    turn1Motor(50, 90, LEFT);
    lineFollowOneSensorStopOneSensor(50, 50, defaultAcc, -0.4, -20, false, 2, 50, 1, BLACK, COLOR);
    moveNoSyncParam(30, 30, 50, 15, 100, 0.2, 0.2, true, RELDEG);

    turn1Motor(50, 90, RIGHT);
    moveSimple(-50, -50, 450, RELDEG);
    moveSimple(50, 50, 350, RELDEG);

    turn1Motor(100, -180, LEFT);
    moveSimpleWallSquare(-40, -40, 1300, TIME);
    resetRelative();
    setSpeed(0, 0);

    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 42, defaultAcc, defaultAcc, true, LEFT);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -54, defaultAcc, defaultAcc, true, RIGHT);
    
    moveArmAbsSimple(50, 130, LIFT);
	moveSenseOneSensorNoSync(30, 25, 20, false, 3, RED, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 330, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, -270, defaultAcc, defaultAcc, CLAW);
    moveNoSyncParam(-80, -100, defaultMinspeed, defaultMinspeed, 540, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 102, defaultAcc, defaultAcc, true, RIGHT);
    moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();

    // Large debris
    turn1Motor(50, 90, RIGHT);
    moveArmAbsSimple(50, 230, LIFT);
    moveSimple(50, 50, 480, RELDEG);
    turn1Motor(50, 60, LEFT);
    moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();

    // Yellow block
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 400, 0.2, 0.2, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, 0.2, 0.2, true, LEFT);
	moveSenseOneSensorNoSync(50, 50, 20, false, 2, BLACK, COLOR);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 450, 0.2, 0.2, true, RELDEG);
    turn2Motor(20, 90);
    moveArmAbsSimple(50, 140, LIFT);
    moveArmAbsSimple(50, -230, CLAW);
    moveSimple(40, 40, 280, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(300);
    turn1Motor(50, -187, LEFT);
    moveArmAbsSimple(50, 230, LIFT);
    moveSimple(40, 40, 350, RELDEG);
    moveArmAbsSimple(50, -230, CLAW);
    moveSimple(-40, -40, 300, RELDEG);

    // Blue tower
    turn1Motor(50, 90, RIGHT);
    moveSimple(-50, -50, 350, RELDEG);
    turn1Motor(50, -90, LEFT);
    moveSenseOneSensorNoSync(-100, -100, 20, false, 1, BLACK, COLOR);
    moveNoSyncParam(-100, -100, 100, defaultMinspeed, 100, 0.2, 0.2, true, RELDEG);
    turn2Motor(20, -112);

    moveArmAbsSimple(50, 170, LIFT);
    moveSimpleWallSquare(50, 50, 1660, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(1000);
    moveSimple(-100, -100, 950, RELDEG);
}