void surpriseChallenge()
{
    // Add the following code to the end of the program
    moveArmAbsSimple(100, 160, LIFT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 732, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, LEFT);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 59, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 448, defaultAcc, defaultAcc, true, RELDEG);
	setArmSpeed(CLAW, -100);
	sleep(300);
    //moveArmAbsSimple(100, armDegreeToDrop, LIFT);
	moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 1152, defaultAcc, defaultAcc, true, RELDEG);
	if (!startedClose || 1)
	{
		turn2MotorAccMinspeed(20, defaultMinspeed, defaultMinspeed, 180, defaultAcc, defaultAcc, true);
		moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 1400, defaultAcc, defaultAcc, true, RELDEG);
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, RIGHT);
		moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 832, defaultAcc, defaultAcc, true, RELDEG);
        turn1Motor(100, 40, RIGHT);
	}
    setArmSpeed(CLAW, 100);
    sleep(100);
}