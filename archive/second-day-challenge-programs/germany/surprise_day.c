void surpriseDay()
{
    // Arm Resets
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

    // Collects the green blocks
    moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 370, defaultAcc, defaultAcc, LIFT);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 3, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 880, defaultAcc, defaultAcc, true, RELDEG);
    moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 262, defaultAcc, defaultAcc, LIFT);

    // Puts away the green blocks
   	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -5, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 1900, defaultAcc, defaultAcc, true, RELDEG);
    turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true);
    moveSimpleWallSquare(-100, -100, 1000, TIME);
    setSpeed(0, 0);
    resetRelative();
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 1304, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
    lineFollowOneSensor(50, defaultMinspeed, defaultMinspeed, 850, defaultAcc, defaultAcc, 0.4, 20, true, 2, 50, RELDEG);
    moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 2, BLACK, COLOR);
    moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 473, defaultAcc, defaultAcc, true, RELDEG);
    turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true);
    moveArmSimple(100, 1000, LIFT, TIME);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 200, defaultAcc, defaultAcc, true, RELDEG);
    moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 250, defaultAcc, defaultAcc, true, RELDEG);
    moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 130, defaultAcc, defaultAcc, LIFT);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -155, defaultAcc, defaultAcc, true, RIGHT);
    moveSimpleWallSquare(-100, -100, 1000, TIME);
    setSpeed(0, 0);
    resetRelative();
    moveArmAbsSimple(100, -200, CLAW);

    // Collects the red blocks
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 275, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 600, defaultAcc, defaultAcc, true, RELDEG);
	moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 3, BLACK, COLOR);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 85, defaultAcc, defaultAcc, true, LEFT);
	moveSimpleWallSquare(-100, -100, 1500, TIME);
	setSpeed(0, 0);
	resetRelative();
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 830, 0.2, 0.2, true, RELDEG);
	turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true);
	moveNoSyncParam(20, 20, defaultMinspeed, defaultMinspeed, 200, defaultAcc, defaultAcc, true, RELDEG);
	moveArmSimple(-100, 1000, CLAW, TIME);
	setArmSpeed(CLAW, -100);

    // Puts away the red blocks while pushing the blue blocks
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -40, defaultAcc, defaultAcc, true, LEFT);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -35, defaultAcc, defaultAcc, true, RIGHT);
	moveSenseOneSensorSimple(-20, -20, defaultMinspeed, true, 2, BLUE, COLOR);
    moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 1510, defaultAcc, defaultAcc, true, RELDEG);
    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 360, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, LEFT);
	moveSimpleWallSquare(-100, -100, 2000, TIME);
	setSpeed(0, 0);
	resetRelative();
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 42, defaultAcc, defaultAcc, true, LEFT);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -54, defaultAcc, defaultAcc, true, RIGHT);

	moveSenseOneSensorNoSync(30, 25, 20, false, 3, RED, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 730, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, -270, defaultAcc, defaultAcc, CLAW);
    moveNoSyncParam(-80, -100, defaultMinspeed, defaultMinspeed, 540, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 102, defaultAcc, defaultAcc, true, RIGHT);
    moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();

    // Goes to the yellow blocks
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 971, 0.2, 0.2, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, 0.2, 0.2, true, LEFT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 2219, 0.2, 0.2, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, RIGHT);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();

    // Pushes the yellow blocks
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 45, defaultAcc, defaultAcc, true, RIGHT);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -45, defaultAcc, defaultAcc, true, LEFT);
	moveSenseOneSensorSimple(-20, -24, defaultMinspeed, true, 3, RED, COLOR);
	moveNoSyncParam(-30, -30, defaultMinspeed, defaultMinspeed, 1009, defaultAcc, defaultAcc, true, RELDEG);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 1052, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();

    // Does the second yellow blocks
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 240, defaultAcc, defaultAcc, LIFT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 506, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, 0.2, 0.2, true, RIGHT);
	moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 3, RED, COLOR);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 350, defaultAcc, defaultAcc, LIFT);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 240, defaultAcc, defaultAcc, LIFT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 890, 0.2, 0.2, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 93, 0.2, 0.2, true, RIGHT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 1124, 0.2, 0.2, true, RELDEG);
	moveSimple(-30, -30, 150, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -33, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 1034, 0.2, 0.2, true, RELDEG);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();

    // Collects the red blocks
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 48, defaultAcc, defaultAcc, true, RIGHT);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -45, defaultAcc, defaultAcc, true, LEFT);
	moveSenseOneSensorSimple(20, 24, defaultMinspeed, true, 1, RED, COLOR);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, -290, defaultAcc, defaultAcc, CLAW);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 370, defaultAcc, defaultAcc, LIFT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 618, defaultAcc, defaultAcc, true, RELDEG);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 170, defaultAcc, defaultAcc, LIFT);
	moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 1050, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();

    // Puts the red blocks away
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
	moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 1, RED, COLOR);
	moveSimple(30, 30, 50, RELDEG);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 370, defaultAcc, defaultAcc, LIFT);
	moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 518, defaultAcc, defaultAcc, true, RELDEG);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 240, defaultAcc, defaultAcc, LIFT);
	turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 493, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, 0.2, 0.2, true, LEFT);
	moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 3, BLACK, COLOR);
	moveSimple(30, 30, 80, RELDEG);
	turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true);
	moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 428, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);

    // Gets and puts the last block in the base
	lineFollowOneSensor(50, defaultMinspeed, defaultMinspeed, 850, defaultAcc, defaultAcc, 0.4, 20, true, 2, 50, RELDEG);
    moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 2, BLACK, COLOR);
	turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 859, 0.2, 0.2, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 131, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 1799, 0.2, 0.2, true, RELDEG);
}