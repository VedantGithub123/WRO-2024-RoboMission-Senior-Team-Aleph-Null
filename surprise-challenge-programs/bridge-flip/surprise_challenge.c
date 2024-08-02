void surpriseChallenge()
{
    // Add the following code to the very end of the program
    moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 241, defaultAcc, defaultAcc, LIFT);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, -104, defaultAcc, defaultAcc, CLAW);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 594, defaultAcc, defaultAcc, true, RELDEG);
	turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 115, defaultAcc, defaultAcc, true);
	moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 1089, defaultAcc, defaultAcc, false, RELDEG);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();
	turn1MotorAccMinspeed(100, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
	moveSenseOneSensorSimple(-50, -50, defaultMinspeed, true, 1, BLACK, COLOR);
	turn2MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 93, defaultAcc, defaultAcc, true);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 587, 0.2, 0.2, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
	moveSenseOneSensorSimple(20, 20, defaultMinspeed, true, 3, WHITE, COLOR);
	setArmSpeed(LIFT, -100);
	sleep(300);
}