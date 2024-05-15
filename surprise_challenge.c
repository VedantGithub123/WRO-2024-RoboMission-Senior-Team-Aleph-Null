float clawDegree = 152;
float waterClawDegree = 330;

task liftUp500()
{
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);
	stopTask(liftUp500);
}

task liftUp500Delayed()
{
	sleep(800);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);
	stopTask(liftUp500Delayed);
}

task liftUp1000()
{
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
	stopTask(liftUp1000);
}

task liftDown()
{
	moveArm(100, 100, 800, 0.01, LIFT, TIME);
	stopTask(liftDown);
}

task readyLiftForPicking()
{
	moveArm(60, 30, clawDegree-10, 0.3, LIFT, RELDEG);
	stopTask(readyLiftForPicking);
}

task readyLiftForPicking2()
{
	moveArm(60, 30, clawDegree-10, 0.3, LIFT, RELDEG);
	stopTask(readyLiftForPicking);
}

task clawReady()
{
	moveArmAbs(100, 30, 300, 0.3, CLAW);
	stopTask(clawReady);
}

task clawWater()
{
	moveArmAbs(100, 100, 480, 0.3, CLAW);
	stopTask(clawWater);
}

task readyLiftForGreenBlue()
{
	moveArm(100, 100, 124, 0.3, LIFT, RELDEG);
	stopTask(readyLiftForGreenBlue);
}

task clawBackDown(){
	moveArmAbs(100, 100, waterClawDegree, 0.7, CLAW);
	stopTask(clawBackDown);
}

task releaseBlocks(){
	moveArm(100, 100, 124, 0.3, LIFT, RELDEG);
	sleep(250);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);
	stopTask(releaseBlocks);
}

task debrisLiftOpenClose(){
	moveArm(100, 100, 145, 0.3, LIFT, RELDEG);
	sleep(250);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);
	stopTask(releaseBlocks);
}

void surpriseChallenge()
{
	moveArm(100, 100, 100, 0.01, LIFT, RELDEG);
	moveSimple(-80, -80, 110, RELDEG);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);
	turn1Motor(-140, -150, RIGHT);
	moveSimpleNone(-100, -100, 1500, TIME);
	sleep(100);

	moveSimpleAcc(50, 50, 243, 0.2, RELDEG);
	turn1Motor(50, 90, LEFT);
	moveSimpleAcc(50, 50, 1964, 0.2, RELDEG);
	moveArm(100, 100, 150, 0.01, LIFT, RELDEG);
	moveSenseSimple(20, 20, BLACK, 2, COLOR);
	startTask(liftUp1000);
	sleep(1000);
	turn2Motor(20, -90);
	moveSimpleNone(-100, -100, 1000, TIME);
	sleep(50);
	moveSimpleAcc(50, 50, 790, 0.2, RELDEG);
	turn1Motor(50, 90, LEFT);
	moveSimpleAcc(50, 50, 338, 0.2, RELDEG);
}