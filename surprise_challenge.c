void surpriseChallenge()
{
    moveArm(100, 100, 100, 0.01, LIFT, RELDEG);
	moveSimple(-80, -80, 110, RELDEG);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);
	turn1Motor(-140, -150, RIGHT);
	moveSimpleNone(-100, -100, 1500, TIME);
	sleep(100);
}