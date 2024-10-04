void surpriseChallenge()
{
    // Add the following code after the wall square after dropping the last stack
    turn1MotorAccMinspeed(100, 50, 20, 90, 0.4, 0.4, true, RIGHT);
    moveSenseOneSensorSimple(-40, -40, 20, true, 3, RED, COLOR);
    turn1Motor(100, 92, LEFT);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 600, true, TIME);
    resetRelative();
    setSpeed(0, 0);
    moveArmAbsSimple(100, 200, LIFT);

    moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 1150, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(70, defaultMinspeed, defaultMinspeed, 90, defaultAcc, defaultAcc, true, LEFT);
    moveSenseOneSensor(50, 50, defaultMinspeed, defaultAcc, defaultkP, defaultkD, false, 1, BLACK, COLOR);
    moveNoSyncParam(50, 50, 50, defaultMinspeed, 125, defaultAcc, defaultAcc, true, RELDEG);
    moveNoSyncParam(-100, -100, defaultMinspeed, defaultMinspeed, 1383, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(-100, defaultMinspeed, defaultMinspeed, -92, defaultAcc, defaultAcc, true, LEFT);
    moveNoSyncParam(-100, -100, defaultMinspeed, 100, 1030, defaultAcc, defaultAcc, false, RELDEG);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 700, true, TIME);
    resetRelative();
    setSpeed(0, 0);

    turn1Motor(100, 90, RIGHT);
    turn2Motor(60, 90);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 700, true, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Add the following code at the end of the program
    moveArmAbsSimple(100, 130, LIFT);
	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 732, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(100, defaultMinspeed, defaultMinspeed, -90, defaultAcc, defaultAcc, true, LEFT);
	moveSimpleWallSquare(-100, -100, 1000, TIME);
	setSpeed(0, 0);
	resetRelative();
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 63, defaultAcc, defaultAcc, true, RELDEG);
	turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 95, defaultAcc, defaultAcc, true, RIGHT);
	moveNoSyncParam(50, 50, defaultMinspeed, defaultMinspeed, 410, defaultAcc, defaultAcc, true, RELDEG);
	setArmSpeed(CLAW, -100);
	sleep(300);
    
    moveNoSyncParamWallSquare(-100, -100, defaultMinspeed, defaultMinspeed, 480, defaultAcc, defaultAcc, true, RELDEG);
    turn2Motor(50, 180);
    setArmSpeed(CLAW, 100);
    sleep(100);

}