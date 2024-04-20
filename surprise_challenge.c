void surpriseChallenge()
{
    moveArm(100, 100, 100, 0.01, LIFT, RELDEG);
	moveSimple(-80, -80, 110, RELDEG);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);
	turn1Motor(-140, -150, RIGHT);
	moveSimpleNone(-100, -100, 1500, TIME);
	sleep(100);

	moveSimpleAcc(50, 50, 160, 0.2, RELDEG);
	turn1Motor(50, 91, LEFT);
	moveSimpleAcc(50, 50, 1965, 0.2, RELDEG);
	moveSenseSimple(20, 20, BLACK, 3, COLOR);
	moveSimpleAcc(-50, -50, 110, 0.2, RELDEG);
	turn1Motor(-50, -90, RIGHT);
	moveArm(100, 100, 1000, 0.01, LIFT, TIME);
	moveSimpleAcc(50, 50, 180, 0.2, RELDEG);
	moveArm(-100, -100, 1000, 0.01, CLAW, TIME);
	setArmSpeed(CLAW, -100);
	sleep(100);
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
	turn1Motor(50, 90, LEFT);
	moveSimpleAcc(50, 50, 2030, 0.2, RELDEG);
	turn1Motor(50, 30, RIGHT);
	moveArm(100, 100, 300, 0.01, CLAW, TIME);

}