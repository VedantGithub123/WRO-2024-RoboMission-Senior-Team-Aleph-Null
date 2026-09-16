	setArmSpeed(LIFT, 100);
	sleep(400);
	setArmSpeed(LIFT, 0);
	moveArmSimple(100, 500, CLAW, TIME);
	resetArmAbs(CLAW);
	moveArmAbsSimple(100, -290, CLAW);
	moveArmSimple(-100, 700, LIFT, TIME);
	resetArmAbs(LIFT);

	setArmSpeed(CLAW, 0);
	setArmSpeed(LIFT, 0);
	sleep(50);
	moveArmAbsSimple(100, 100, LIFT);
	moveArmAbsSimple(100, clawDegreeOpen+70, CLAW);

	if(startedClose){
		moveSimpleWallSquare(-100, -100, 1000, TIME);
		setSpeed(0, 0);
		resetRelative();
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 274, defaultAcc, defaultAcc, true, RELDEG);
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
		lineFollowOneSensor(60, defaultMinspeed, defaultMinspeed, 1458, defaultAcc, defaultAcc, 0.4, 20, true, 3, 50, RELDEG);
		moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 2, BLACK, COLOR);
	}
	else{
		moveSimpleWallSquare(-100, -100, 1000, TIME);
		setSpeed(0, 0);
		resetRelative();
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 452, defaultAcc, defaultAcc, true, RELDEG);
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 482, defaultAcc, defaultAcc, true, RELDEG);
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 416, defaultAcc, defaultAcc, true, RELDEG);
		moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 2, BLACK, COLOR);
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 118, defaultAcc, defaultAcc, true, RIGHT);
		lineFollowOneSensor(60, defaultMinspeed, defaultMinspeed, 300, defaultAcc, defaultAcc, 0.4, 20, true, 3, 50, RELDEG);
		moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 2, BLACK, COLOR);
}
	moveNoSyncParam(-30, -30, defaultMinspeed, defaultMinspeed, 30, defaultAcc, defaultAcc, true, RELDEG);
	turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true);
	moveNoSyncParam(30, 30, defaultMinspeed, defaultMinspeed, 166, defaultAcc, defaultAcc, true, RELDEG);
	moveArmSimple(-100, 1000, CLAW, TIME);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, RIGHT);
	lineFollowOneSensor(40, defaultMinspeed, defaultMinspeed, 1006, defaultAcc, defaultAcc, -0.4, -20, true, 2, 50, RELDEG);
	moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 3, BLACK, COLOR);

	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 1529, defaultAcc, defaultAcc, true, RELDEG);
	turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true);
	moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 325, defaultAcc, defaultAcc, true, RELDEG);
	moveSimpleWallSquare(-100, -100, 800, TIME);
	setSpeed(0, 0);
	resetRelative();
	moveArmAbsSimple(100, 230, LIFT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 710, 0.2, 0.2, true, RELDEG);
	moveArmSimple(100, 1000, CLAW, TIME);
	moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 281, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, LEFT);
	moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 385, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, RIGHT);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();
	moveNoSyncParam(30, 30, defaultMinspeed, defaultMinspeed, 139, defaultAcc, defaultAcc, true, RELDEG);
    if (!startedClose){
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 55, defaultAcc, defaultAcc, true, LEFT);
		moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 2000, defaultAcc, defaultAcc, true, RELDEG);
		turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 125, defaultAcc, defaultAcc, true);
		moveSimpleWallSquare(-100, -100, 1000, TIME);
		setSpeed(0, 0);
		resetRelative();
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 274, defaultAcc, defaultAcc, true, RELDEG);
	}