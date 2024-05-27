float clawDegree = 162;
float waterClawDegree = 333;

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
	moveArmAbs(40, 40, 480, 0.3, CLAW);
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
	moveSimpleAcc(50, 50, 284, 0.2, RELDEG);
	turn1Motor(50, 90, LEFT);
	moveSenseSimple(20, 20, BLACK, 2, COLOR);
	moveSimpleAcc(50, 50, 277, 0.2, RELDEG);
	turn2Motor(20, 90);
	moveArmAbs(60, 30, 120, 0.3, LIFT);
	moveSimpleAcc(50, 50, 200, 0.2, RELDEG);
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
	turn2Motor(20, 90);
	moveSimpleAcc(50, 50, 840, 0.2, RELDEG);
	moveSenseSimple(20, 20, RED, 2, COLOR);
	turn2Motor(20, 91.5);
	startTask(readyLiftForPicking2);
	moveSimpleAccMinspeed(50, 50, 12, 500, 0.2, RELDEG);
	moveSimple(-12, -12, 110, RELDEG);
	sleep(100);
	moveArm(60, 30, 30, 0.3, LIFT, RELDEG);
	moveArmAbs(100, 100, waterClawDegree, 0.7, CLAW);
	startTask(liftUp1000);
	moveSimpleNone(-100, -100, 1500, TIME);
	sleep(50);
}