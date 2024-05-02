float clawDegree = 162;
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
    moveSimple(100, 100, 110, RELDEG);	
	if (!startedClose){
		moveArm(100, 100, 300, 0.01, LIFT, TIME);
		moveSimple(100, 100, 300, RELDEG);
		startTask(liftUp500);
		turn1Motor(100, 140, RIGHT);
	}	
	else {																		
		turn1Motor(100, 80, RIGHT);
		
	}
	moveSimpleAcc(100, 100, 200, 0.2, RELDEG);
	moveSenseSimple(-20, -20, RED, 2, COLOR);
	if (!startedClose){
		moveSimpleAcc(50, 50, 200, 0.2, RELDEG);
		turn1Motor(100, -60, RIGHT);
		moveSimpleAcc(50, 50, 500, 0.2, RELDEG);

	}
	else {
	moveSimpleAcc(50, 50, 600, 0.2, RELDEG);
	}
	turn2Motor(40, -60);
	moveSimpleAcc(50, 50, 180, 0.2, RELDEG);
	moveArm(100, 100, 300, 0.01, LIFT, TIME);
	sleep(200);
	moveSimpleAcc(-50, -50, 120, 0.2, RELDEG);
	turn1Motor(100, -80, RIGHT);
	startTask(liftUp500);
	if (!startedClose){
		moveSimpleAcc(-100, -100, 250, 0.2, RELDEG);

	}
	else{
		moveSimpleAcc(-100, -100, 400, 0.2, RELDEG);
	}
	moveSenseSimple(-20, -20, RED, 3, COLOR);
	moveSimpleAcc(-100, -100, 100, 0.2, RELDEG);
	turn1Motor(100, -60, RIGHT);
	moveSimpleNone(-30, -30, 1000, TIME);
	stopTask(liftUp500);
}