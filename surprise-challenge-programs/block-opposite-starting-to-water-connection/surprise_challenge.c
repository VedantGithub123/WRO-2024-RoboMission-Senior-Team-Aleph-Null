void surpriseChallenge()
{
	// Add the following code to the very beginning of the program
	if (startedClose == false){
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
		
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 200, defaultAcc, defaultAcc, true, RELDEG);
		turn1MotorAccMinspeed(80, defaultMinspeed, defaultMinspeed, -183, 0.2, 0.2, true, RIGHT);
		moveNoSyncParam(-80, -80, defaultMinspeed, defaultMinspeed, 1200, defaultAcc, defaultAcc, true, RELDEG);
		moveSimpleWallSquare(-100, -100, 800, TIME);
		setSpeed(0, 0);
		resetRelative();
		turn1MotorNoSettle(100, 50, RIGHT);
		turn1MotorNoSettle(100, -55, LEFT);
		moveSimpleWallSquare(-30, -30, 600, TIME);
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 10, 0.2, 0.2, true, RIGHT);
		moveNoSyncAccParamWallSquare(50, 50, 50, 20, 590, false, RELDEG);
		setSpeed(0, 0);
		resetRelative();
		moveArmAbsSimple(100, clawDegreeOpen+70, CLAW);
		moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 100, defaultAcc, defaultAcc, true, RELDEG);
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 94, 0.2, 0.2, true, LEFT);
		moveSimpleWallSquare(-50, -50, 600, TIME);
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 1150, defaultAcc, defaultAcc, true, RELDEG);
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, 0.2, 0.2, true, RIGHT);
		moveSenseOneSensorNoSync(28, 30, 30, false, 2, BLACK, COLOR);
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 200, defaultAcc, defaultAcc, true, RELDEG);
		setArmSpeed(CLAW, -100);
		moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 900, defaultAcc, defaultAcc, true, RELDEG);
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, LEFT);
		moveSimpleWallSquare(-100, -100, 1000, TIME);
		setSpeed(0, 0);
		resetRelative();
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 126, defaultAcc, defaultAcc, true, RELDEG);
	}
	else{
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
		moveArmAbsSimple(100, -145, CLAW);
		turn1MotorAccMinspeed(80, defaultMinspeed, defaultMinspeed, 90, 0.2, 0.2, true, LEFT);
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 800, defaultAcc, defaultAcc, true, RELDEG);
		turn1MotorAccMinspeed(80, defaultMinspeed, defaultMinspeed, 90, 0.2, 0.2, true, RIGHT);
		moveSenseOneSensorNoSync(30, 30, 30, true, 2, BLACK, COLOR);
		turn1MotorAccMinspeed(80, defaultMinspeed, defaultMinspeed, 90, 0.2, 0.2, true, RIGHT);
		moveSenseOneSensorNoSync(0, 30, 30, true, 3, BLACK, COLOR);
		lineFollowTwoSensor(40, defaultMinspeed, defaultMinspeed, 200, defaultAcc, defaultAcc, 0.2, 15, true, 2, 3, RELDEG);
		lineFollowTwoSensorStopTwoSensor(40, 40, defaultAcc, 0.15, 18, true, 2, 10, LESSREFL, 3, 10, LESSREFL);
		moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 200, defaultAcc, defaultAcc, true, RELDEG);
		turn1MotorAccMinspeed(80, defaultMinspeed, defaultMinspeed, -90, 0.2, 0.2, true, RIGHT);
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 220, defaultAcc, defaultAcc, true, RELDEG);
		setArmSpeed(CLAW, -100);
		sleep(200);
		moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 580, defaultAcc, defaultAcc, true, RELDEG);
		moveArmAbsSimple(100, -200, CLAW);
		turn1MotorAccMinspeed(80, defaultMinspeed, defaultMinspeed, -30, 0.2, 0.2, true, RIGHT);
		moveSimpleWallSquare(-100, -100, 1500, TIME);
		setSpeed(0, 0);
		resetRelative();
		moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 126, defaultAcc, defaultAcc, true, RELDEG);
	}

	// Add the following code the the very end of the program
    moveArmAbsSimple(100, 100, LIFT);
	moveArmAbsSimple(100, -145, CLAW);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 450, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(100, defaultMinspeed, defaultMinspeed, 50, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 576, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(100, defaultMinspeed, defaultMinspeed, 40, defaultAcc, defaultAcc, true, LEFT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 2005, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(100, defaultMinspeed, defaultMinspeed, 23, defaultAcc, defaultAcc, true, LEFT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 144, defaultAcc, defaultAcc, true, RELDEG);
}