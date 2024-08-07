void surpriseChallenge()
{
    // Add the following code after the wall square before the first water connection
    moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 130, defaultAcc, defaultAcc, LIFT);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, -250, defaultAcc, defaultAcc, CLAW);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 300, 0.2, 0.2, true, RELDEG);
	turn2Motor(20, -90);
	moveSenseOneSensorSimple(-20, -20, defaultMinspeed, true, 2, RED, COLOR);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 620, 0.2, 0.2, true, RELDEG);
	setArmSpeed(CLAW, -30);
	sleep(1300);
	setArmSpeed(CLAW, -100);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 230, defaultAcc, defaultAcc, LIFT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 50, 0.2, 0.2, true, RELDEG);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 190, defaultAcc, defaultAcc, LIFT);
	moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, -250, defaultAcc, defaultAcc, CLAW);
	moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 600, 0.2, 0.2, true, RELDEG);
	turn2Motor(30, 90);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
    setSpeed(0, 0);
    resetRelative();
}