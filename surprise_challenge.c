void surpriseChallenge()
{
    moveArm(100, 100, 100, 0.01, LIFT, RELDEG);
	moveSimple(-80, -80, 110, RELDEG);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);
	turn1Motor(-140, -150, RIGHT);
	moveSimpleNone(-100, -100, 1500, TIME);
	sleep(100);

	moveSimpleAcc(100, 100, 151, 0.2, RELDEG);
	turn1Motor(100, 91, LEFT);
	moveSimpleAcc(100, 100, 1854, 0.2, RELDEG);
	moveSenseSimple(20, 20, BLACK, 3, COLOR);
	turn2Motor(50, -90);
	moveSimpleNone(-100, -100, 1000, TIME);
	sleep(50);
	moveSimpleAcc(100, 100, 1245, 0.2, RELDEG);
	turn1Motor(100, 90, LEFT);
	moveSimpleAcc(50, 50, 613, 0.2, RELDEG);
	turn2Motor(30, -180);
	moveSimpleAcc(100, 100, 1674, 0.2, RELDEG);
	moveSenseSimple(20, 20, BLACK, 2, COLOR);
	moveSimpleAcc(100, 100, 414, 0.2, RELDEG);
	turn2Motor(50, -90);
	moveSimpleNone(-100, -100, 1000, TIME);
	sleep(50);
	moveSimpleAcc(100, 100, 618, 0.2, RELDEG);
}