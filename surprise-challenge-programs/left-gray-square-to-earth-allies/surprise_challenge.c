void surpriseChallenge()
{
    // Add this code at the end of the program
    moveArmAbsSimple(100, 100, LIFT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 732, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, LEFT);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 63, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 448, defaultAcc, defaultAcc, true, RELDEG);
	setArmSpeed(CLAW, -100);
	sleep(300);
    moveSimple(-50, -50, 100, RELDEG);
    turn2Motor(30, -45);
}