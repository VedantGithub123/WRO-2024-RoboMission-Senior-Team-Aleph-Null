float clawDegree = 145;

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
	moveArmAbs(100, 30, 420, 0.3, CLAW);
	stopTask(clawWater);
}

task readyLiftForGreenBlue()
{
	moveArm(100, 100, 124, 0.3, LIFT, RELDEG);
	stopTask(readyLiftForGreenBlue);
}

task clawBackDown(){
	moveArmAbs(100, 100, 330, 0.7, CLAW);
	stopTask(clawBackDown);
}

task releaseBlocks(){
	moveArm(100, 100, 124, 0.3, LIFT, RELDEG);
	sleep(250);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);
	stopTask(releaseBlocks);
}

void code()
{
	setArmSpeed(CLAW, -100);
    // Go to the other side if the robot started far
    if (!startedClose)
    {
        turn1Motor(100, 51, LEFT);
        moveSimpleAcc(100, 100, 1920, 0.5, RELDEG);
        turn2Motor(100, 128);
    }

    // Goes to the first 4 blocks
    moveSimpleNone(-100, -100, 1000, TIME);
	resetMotorEncoder(d);
	setArmSpeed(CLAW, 0);
    sleep(100);
    moveSimpleAcc(100, 100, 290, 0.25, RELDEG);
    turn1Motor(100, 90, LEFT);
	resetRelative();
	moveSenseSuper(100, 100, 30, 100, BLACK, 0.005, 0.0005, 0.001, 3, true, false, false, COLOR);
	moveSuper(100, 100, 160, 100, 15, 0.004, 0.0005, 0.001, false, true, true, RELDEG);
    turn2Motor(50, 89.5);
    startTask(liftDown);
    startTask(clawReady);
	lineSquare(53, 50, 2, 3, -0.4, -50, 1000);
	setSpeed(0, 0);
	resetRelative();
	sleep(100);

	// Collects the first 4 blocks
	resetRelative();
    moveSimpleAcc(30, 30, 95, 0.15, RELDEG);
	stopTask(clawReady);
    // moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
    setArmSpeed(CLAW, -100);
	sleep(500);
    moveSimple(100, 100, 65, RELDEG);
    moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
    moveArm(100, 100, 50, 0.01, LIFT, RELDEG);
    moveSimple(100, 100, 70, RELDEG);
    moveArm(-100, -100, 500, 0.01, LIFT, TIME);

	// Goes to the yellow area
	turn1Motor(100, -55, LEFT);
	turn1Motor(100, -55, RIGHT);
	lineSquare(53, 43, 2, 3, -0.45, -50, 1000);
	resetRelative();
	moveSimpleAcc(-70, -70, 660, 0.2, RELDEG);

	// Stacks the first 4 blocks
	moveArm(60, 30, clawDegree-10, 0.3, LIFT, RELDEG);
	moveSimpleAcc(-15, -15, 107, 0.1, RELDEG);
    sleep(200);
	moveArm(60, 30, 30, 0.3, LIFT, RELDEG);
	moveArmAbs(100, 100, 310, 0.7, CLAW);
	moveSimpleAcc(-100, -100, 100, 0.2, RELDEG);
	startTask(liftUp1000);

    // Goes to the next 4 blocks
	turn2Motor(50, -90);
    lineSquare(50, 50, 2, 3, -0.4, -75, 1000);
	resetRelative();
    moveSimpleAcc(50, 50, 150, 0.17, RELDEG);
    turn1Motor(100, 89, RIGHT);
	stopTask(liftUp1000);
    startTask(liftDown);
    moveSimpleAcc(-50, -50, 30, 0.2, RELDEG);
	lineSquare(50, 45, 2, 3, -0.4, -50, 1000);
	resetRelative();
	setSpeed(0, 0);
	sleep(100);

	// Collects the next 4 blocks
	resetRelative();
    moveSimpleAcc(30, 30, 103, 0.15, RELDEG);
	stopTask(liftDown);
    // moveArm(-100, -100, 1000, 0.7, CLAW, TIME);
    setArmSpeed(CLAW, -100);
	sleep(500);
    moveSimple(100, 100, 62, RELDEG);
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
    moveArm(100, 100, 50, 0.01, LIFT, RELDEG);
    moveSimple(100, 100, 70, RELDEG);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);

	// Positions for stacking the next 4 blocks
	moveSimple(-100, -100, 140, RELDEG);
	turn1Motor(100, -90, RIGHT);
	moveSenseSimple(-20, -20, BLACK, 3, COLOR);
	lineSquare(50, 52, 2, 3, -0.5, -50, 1000);
	moveSimpleAcc(100, 100, 210, 0.2, RELDEG);
	turn2Motor(30, 90);
	moveSimpleNone(-50, -50, 1500, TIME);
	sleep(100);

	// Stacks the next 4 blocks
	startTask(readyLiftForPicking);
	moveSimpleAcc(50, 50, 260, 0.1, RELDEG);
	moveSimpleAcc(-15, -15, 114, 0.1, RELDEG);
	sleep(200);
	moveArm(60, 30, 30, 0.3, LIFT, RELDEG);
	moveArmAbs(100, 100, 230, 0.7, CLAW);
	moveArm(100, 100, 500, 0.3, LIFT, TIME);
    // moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
	setArmSpeed(CLAW, -100);
	sleep(500);
	moveArm(-50, 20, 195, 0.1, LIFT, RELDEG);

    // Goes to the first stack of blocks
    turn1Motor(60, 59, LEFT);
	turn1Motor(60, 59, RIGHT);
    if (getReflection(2)<50){
        moveSenseSimple(0, 100, 40, 2, GREATREFL);
    }else{
        moveSenseSimple(100, 0, 60, 2, LESSREFL);
    }
	lineFollow(30, 30, 180, 50, 0.1, 0.6, 100, 2, RELDEG);
	resetRelative();
	moveSenseSimple(25, 25, YELLOW, 3, COLOR);

	// Makes the stacks of 4
	moveArm(-100, -100, 1000, 0.25, LIFT, TIME);
	moveSimple(-13, -13, 83, RELDEG);
	moveArm(50, 30, 70, 0.3, LIFT, RELDEG);
	moveSimple(-25, -25, 57, RELDEG);
	sleep(200);
	moveArm(50, 50, 20, 0.2, LIFT, RELDEG);
	sleep(100);
	moveArmAbs(100, 10, 300, 0.7, CLAW);
	moveArm(-50, 50, 60, 0.3, LIFT, RELDEG);
	startTask(liftUp500Delayed);
    moveSenseSimple(-50, -50, BLACK, 3, COLOR);

	// Collects the green/blue blocks if they are there
	if (!startedClose)
	{
		lineSquare(50, 52, 2, 3, 0.4, 50, 1000);
		turn1Motor(100, 150, LEFT);
		turn1Motor(100, -30, RIGHT);
		moveSimple(100, 100, 20, RELDEG);

		startTask(liftDown);
		lineSquare(50, 50, 2, 3, -0.4, -50, 1000);
		resetRelative();
		setSpeed(0, 0);
		sleep(100);
		resetRelative();
		moveSimpleAcc(30, 30, 100, 0.15, RELDEG);
		stopTask(clawReady);
		// moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
		setArmSpeed(CLAW, -100);
		sleep(500);
		moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
		moveSimpleAcc(30, 30, 70, 0.15, RELDEG);
		turn1Motor(50, -90, LEFT);
	}
	else
	{
		moveSimpleNone(-50, -50, 1000, TIME);
		sleep(100);
		moveSimple(100, 100, 254, RELDEG);
		turn1Motor(100, 90, LEFT);
	}

    // Collects the two debris on the left side
	moveSenseSimple(-25, -25, BLACK, 2, COLOR);
	moveSimpleAcc(100, 100, 625, 0.2, RELDEG);
	turn2Motor(50, 60);
	moveArm(100, 100, 62, 0.3, LIFT, RELDEG);
	moveSimple(100, 100, 240, RELDEG);
	startTask(liftUp500);
	moveSimpleAcc(60, -44, 680, 0.15, RELDEG);
	moveSimpleNone(-50, -50, 1000, TIME);
	sleep(100);

    // Moves the red stack over
	moveSimpleAcc(100, 100, 1670, 0.2, RELDEG);
	moveArm(100, 100, 94, 0.3, LIFT, RELDEG);
	startTask(liftUp500Delayed);
	moveSimpleAcc(-100, -100, 590, 0.2, RELDEG);
	turn1Motor(50, -92, RIGHT);
    moveSenseSimple(-40, -40, RED, 1, COLOR);
	moveSimple(-40, -40, 50, RELDEG);
    moveArm(100, 100, 1000, 0.01, LIFT, TIME);
    moveSimple(15, 15, 300, RELDEG);
    moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
	turn1Motor(100, 158, RIGHT);

    // Goes to the the spot for the close green/blue blocks
	moveSuper(100, 100, 300, 15, 100, 0.004, 0.0003, 0.001, true, false, false, RELDEG);
	moveSenseSuper(100, 100, 100, 100, BLACK, 0.005, 0.0003, 0.001, 3, false, false, false, COLOR);
	moveSuper(100, 100, 255, 100, 15, 0.004, 0.0003, 0.001, false, true, true, RELDEG);
	moveSenseSimple(0, 100, 40, 2, LESSREFL);
	lineFollow(70, 30, 820, 55, 0.3, -0.6, 80, 2, RELDEG);
	resetRelative();
	moveSenseSimple(30, 30, BLACK, 3, COLOR);
    sleep(100);
	moveSimpleAcc(-100, -100, 380, 0.15, RELDEG);
	

    // Collects the green/blue blocks if they are there
	if (startedClose)
    {
		turn1Motor(50, -92.5, RIGHT);
		if(skipGreenBlueStack) // Collects with rack gear if not stacking
		{
			moveArm(100, 100, 100, 0.01, LIFT, RELDEG);
			moveSimple(100, 100, 220, RELDEG);
			moveArm(-100, -100, 500,0.01, LIFT, TIME);
		}
		else // Collects with claw if stacking
		{
			moveSimpleAcc(60, 60, 35, 0.2, RELDEG);
			startTask(liftDown);
			lineSquare(50, 50, 2, 3, -0.4, -50, 1000);
			resetRelative();
			setSpeed(0, 0);
			sleep(100);
			resetRelative();
			moveSimpleAcc(30, 30, 105, 0.15, RELDEG);
			stopTask(clawReady);
			// moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
			setArmSpeed(CLAW, -100);
			sleep(500);
			moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
		}
	}

	if (skipGreenBlueStack)
	{
		if (startedClose)
		{ // If the blocks are in the rack gear, open it while moving backwards
			turn1Motor(-100, -20, RIGHT);
			turn1Motor(-100, -20, LEFT);
			moveSuper(-100, -100, 300, 15, 100, 0.004, 0.0003, 0.001, true, false, false, RELDEG);
			moveSenseSuper(-100, -100, 100, 100, WHITE, 0.005, 0.0003, 0.001, 2, false, false, false, COLOR);
			moveSuper(-100, -100, 250, 100, 100, 0.004, 0.0003, 0.001, false, false, false, RELDEG);
			startTask(releaseBlocks);
			moveSimpleNone(-100, -85, 2000, TIME);
		}
		else
		{ // If the blocks are in the claw, place them down and then move back
			turn1Motor(100, -62.5, RIGHT);
			turn1Motor(100, 30, LEFT);
			moveSuper(-100, -100, 400, 15, 100, 0.004, 0.0003, 0.001, true, false, false, RELDEG);
			moveSenseSuper(-100, -100, 100, 100, WHITE, 0.005, 0.0003, 0.001, 2, false, false, false, COLOR);
			moveSuper(-100, -100, 450, 100, 10, 0.004, 0.0003, 0.001, false, true, false, RELDEG);
			setSpeed(0, 0);
			startTask(liftDown);
			sleep(300);
			moveArmAbs(100, 100, 330, 0.7, CLAW);
			turn1Motor(100, -10, LEFT);
			stopTask(liftDown);
			startTask(liftUp1000);
			moveSimpleNone(-100, -100, 1200, TIME);
		}
	}
	else
	{ // If there is a stack of 4
		// Collects the final green/blue blocks
		if (!startedClose)
		{
			turn1Motor(50, -92.5, RIGHT);
		}
		moveSuper(-100, -100, 990, 15, 100, 0.006, 0.0005, 0.001, true, false, false, RELDEG);
		moveSuper(-50, -50, 1500, 50, 12, 0.004, 0.0005, 0.001, false, true, true, TIME);
		sleep(100);
		moveSimple(100, 100, 50, RELDEG);
		turn1Motor(50, 90.5, RIGHT);
		startTask(readyLiftForGreenBlue);
		moveSuper(100, 100, 180, 15, 50, 0.004, 0.0003, 0.001, true, false, false, RELDEG);
		moveSenseSuper(100, 100, 50, 50, RED, 0.005, 0.0003, 0.001, 2, false, false, false, COLOR);
		moveSuper(100, 100, 410, 50, 15, 0.002, 0.0003, 0.001, false, true, true, RELDEG);
		moveArm(-100, -100, 500, 0.01, LIFT, TIME);

		// Makes 2 stacks of 2 in the blue area
		moveSimpleAcc(-100, -100, 950, 0.2, RELDEG);
		turn1Motor(100, -90, RIGHT);
		moveSimpleNone(-100, -100, 500, TIME);
		sleep(100);
		startTask(readyLiftForPicking2);
		moveSimpleAcc(50, 50, 700, 0.2, RELDEG);
		moveSimple(-15, -15, 104, RELDEG);
		sleep(200);
		moveArm(60, 30, 30, 0.3, LIFT, RELDEG);
		moveArmAbs(100, 100, 330, 0.7, CLAW);
		moveArm(-100, 100, 70, 0.3, LIFT, RELDEG);
		startTask(liftUp500Delayed);
		moveSimpleNone(-100, -100, 1500, TIME);
		sleep(100);
	}

    // Collects the debris and does the water connection
	turn1Motor(100, 90, RIGHT);
	moveSuper(100, 100, 300, 15, 50, 0.004, 0.0005, 0.001, true, false, false, RELDEG);
	moveSenseSuper(100, 100, 50, 50, RED, 0.005, 0.0005, 0.001, 2, false, false, false, COLOR);
	moveSuper(100, 100, 165, 50, 15, 0.004, 0.0005, 0.001, false, true, true, RELDEG);
	turn2Motor(50, 90);
	moveSimpleNone(-100, -100, 1000, TIME);
	sleep(100);
	moveSimpleAcc(100, 100, 588, 0.2, RELDEG);
	turn2Motor(30, -90);

	// Goes to the water connection differently if not making the stack of 4
	if(skipGreenBlueStack)
	{
		moveArm(100, 50, 75, 0.3, LIFT, RELDEG);
		moveSimpleAcc(100, 100, 221, 0.2, RELDEG);
		moveArm(100, 100, 1000, 0.01, LIFT, TIME);
		moveSimpleAcc(100, 100, 100, 0.2, RELDEG);
	}
	else
	{
		startTask(liftDown);
		sleep(300);
		moveSimpleAcc(100, 100, 321, 0.2, RELDEG);
	}

	startTask(clawWater);
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
	
	// Different endings if not making the stack of 4
	if (skipGreenBlueStack)
	{
		// Collects the small debris
		turn1Motor(100, 227, RIGHT);
		moveSimple(100, 100, 600, RELDEG);
		turn1Motor(100, 18, RIGHT);

		// Goes to the water connection
		moveSuper(100, 100, 600, 15, 100, 0.004, 0.0005, 0.001, true, false, false, RELDEG);
		moveSenseSuper(100, 100, 100, 50, BLACK, 0.005, 0.0005, 0.001, 3, false, false, true, COLOR);
		resetRelative();
		moveSenseSimple(40, -40, BLACK, 2, COLOR);
		lineFollow(70, 30, 750, 55, 0.3, 0.6, 80, 2, RELDEG);
		resetRelative();
		startTask(liftDown);
		startTask(clawBackDown);

		// Puts debris in the collection area
		moveSenseSuper(30, 30, 30, 30, RED, 0.004, 0.0005, 0.001, 2, false, false, false, COLOR);
		moveSuper(100, 100, 1120, 30, 15, 0.004, 0.0005, 0.001, true, true, true, RELDEG);
		startTask(clawWater);
		moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
		turn1Motor(100, 80, RIGHT);
	}
	else
	{
		turn1Motor(100, 230, RIGHT);
		moveSimple(100, 100, 1560, RELDEG);
		
		// Goes to the stacks of 2
		moveArm(100, 100, 100, 0.7, LIFT, RELDEG);
		startTask(liftUp500Delayed);
		moveSimple(-80, -80, 250, RELDEG);
		turn2Motor(100, 110);
		moveSimpleNone(-100, -100, 1500, TIME);
		sleep(100);

		moveSimpleAcc(50, 50, 922, 0.2, RELDEG);
		turn2Motor(20, -91);
		moveSenseSimple(40, 40, GREEN, 3, COLOR);

		// Makes the stack of 4 in the blue area
		moveSimpleAcc(20, 20, 250, 0.2, RELDEG);
		moveSimpleAcc(-30, -30, 140, 0.2, RELDEG);
		moveArm(100, 50, 248, 0.3, LIFT, RELDEG);
		moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
		setArmSpeed(CLAW, -100);
		moveArm(-50, 20, 161, 0.1, LIFT, RELDEG);
		moveSimpleAcc(20, 20, 130, 0.15, RELDEG);
		sleep(200);
		moveArm(60, 30, 30, 0.3, LIFT, RELDEG);
		moveArmAbs(100, 10, 330, 0.7, CLAW);
		moveArm(-100, -100, 1000, 0.25, LIFT, TIME);
		moveSimple(-50, -50, 130, RELDEG);
		turn2Motor(25, -182);
		moveSimpleAcc(-50, -50, 230, 0.2, RELDEG);
		getColor(1);
		sleep(50);

		// Pulls the stack over to the green area if it the base is green
		int sensed1 = getColor(1);
		sleep(50);
		int sensed2 = getColor(1);
		sleep(50);
		if (getColor(1)==GREEN || sensed1==GREEN || sensed2==GREEN)
		{
			moveArm(100, 100, 1000, 0.01, LIFT, TIME);
			moveSimple(15, 15, 380, RELDEG);
			moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
			moveSimple(100, 100, 110, RELDEG);
		}
		else
		{
			moveSimple(100, 100, 490, RELDEG);
		}
		turn2Motor(100, -90);
		moveSimpleNone(-100, -100, 1600, TIME);
		sleep(100);
		
		// Brings the debris to the collection area
		turn1Motor(100, 90, LEFT);
		moveSimple(-100, -100, 2650, RELDEG);
		moveSimple(100, 100, 300, RELDEG);
		turn1Motor(100, 90, RIGHT);
		moveSimpleNone(-100, -100, 1000, TIME);
		startTask(clawBackDown);
		sleep(100);

		// Does the other water connection
		moveSimple(100, 100, 375, RELDEG);
		turn2Motor(25, -90);
		startTask(liftDown);
		moveSenseSimple(-20, -20, RED, 2, COLOR);
		sleep(100);
		moveSimpleAcc(100, 100, 640, 0.2, RELDEG);
		moveArm(100, 100, 1000, 0.01, CLAW, TIME);
	}
}