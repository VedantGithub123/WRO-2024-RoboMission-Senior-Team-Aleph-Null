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
	moveArm(60, 20, 159, 0.3, LIFT, RELDEG);
	stopTask(readyLiftForPicking);
}

task readyLiftForPicking2()
{
	moveArm(60, 20, 157, 0.3, LIFT, RELDEG);
	stopTask(readyLiftForPicking);
}

task clawReady()
{
	moveArmAbs(100, 30, 300, 0.3, CLAW);
	stopTask(clawReady);
}

task readyLiftForGreenBlue()
{
	moveArm(100, 100, 124, 0.3, LIFT, RELDEG);
	stopTask(readyLiftForGreenBlue);
}

void code()
{
    // Go to the other side if the robot started far
    if (!startedClose)
    {
        turn1Motor(100, 51, LEFT);
        moveSimpleAcc(100, 100, 1920, 0.5, RELDEG);
        turn2Motor(100, 128);

    }

	// ------------------------------------------------------------------------------//

    // Goes to the first 4 blocks
    moveSimpleNone(-100, -100, 1000, TIME);
    sleep(100);
    moveSimpleAcc(100, 100, 290, 0.25, RELDEG);
    turn1Motor(100, 90, LEFT);
	resetRelative();
	moveSenseSuper(100, 100, 30, 100, BLACK, 0.005, 0.0005, 0.001, 3, true, false, false, COLOR);
	moveSuper(100, 100, 170, 100, 15, 0.004, 0.0005, 0.001, false, true, true, RELDEG);
    turn2Motor(20, 89);
    startTask(liftDown);
    startTask(clawReady);
	sleep(300);

	// ------------------------------------------------------------------------------//

	// Collects the first 4 blocks
	resetRelative();
	moveSenseSuper(30, 30, 10, 30, WHITE, 0.005, 0.0005, 0.001, 3, true, false, false, COLOR);
	moveSenseSuper(30, 30, 30, 30, 60, 0.005, 0.0005, 0.001, 3, false, false, false, LESSREFL);
	moveSuper(30, 30, 12, 30, 15, 0.004, 0.0005, 0.001, true, true, true, RELDEG);
	stopTask(clawReady);
    moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
    setArmSpeed(CLAW, -100);
	sleep(100);
    moveSimple(100, 100, 75, RELDEG);
    moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
    moveArm(100, 100, 50, 0.01, LIFT, RELDEG);
    moveSimple(100, 100, 70, RELDEG);
    moveArm(-100, -100, 500, 0.01, LIFT, TIME);

	// ------------------------------------------------------------------------------//

	// Goes to the yellow area
	turn1Motor(100, -55, LEFT);
	turn1Motor(100, -58, RIGHT);
	lineSquare(50, 50, 2, 3, -0.4, -75, 1000);
	moveSimple(-70, -70, 680, RELDEG);

	// ------------------------------------------------------------------------------//

	// Stacks the first 4 blocks
	moveArm(60, 20, 160, 0.3, LIFT, RELDEG);
	moveSimple(-15, -15, 100, RELDEG);
    sleep(200);
	moveArmAbs(100, 100, 310, 0.7, CLAW);
	moveSimpleAcc(-100, -100, 100, 0.2, RELDEG);
	startTask(liftUp1000);

	// ------------------------------------------------------------------------------//

    // Goes to the next 4 blocks
	turn2Motor(50, -90);
    lineSquare(50, 50, 2, 3, -0.45, -65, 1000);
    moveSimpleAcc(50, 50, 150, 0.17, RELDEG);
    turn1Motor(100, 90, RIGHT);
	stopTask(liftUp1000);
    startTask(liftDown);
    moveSimpleAcc(-50, -50, 30, 0.2, RELDEG);
	sleep(300);

	// ------------------------------------------------------------------------------//

	// Collects the next 4 blocks
	moveSenseSuper(30, 30, 10, 30, WHITE, 0.005, 0.0005, 0.001, 3, true, false, false, COLOR);
	moveSenseSuper(30, 30, 30, 30, 65, 0.005, 0.0005, 0.001, 3, false, false, false, LESSREFL);
	moveSuper(50, 50, 8, 30, 15, 0.004, 0.0005, 0.001, true, true, true, RELDEG);
	stopTask(liftDown);
    moveArm(-100, -100, 1000, 0.7, CLAW, TIME);
    setArmSpeed(CLAW, -100);
	sleep(100)
    moveSimple(100, 100, 72, RELDEG);
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
    moveArm(100, 100, 50, 0.01, LIFT, RELDEG);
    moveSimple(100, 100, 70, RELDEG);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);

	// ------------------------------------------------------------------------------//

	// Positions for stacking the next 4 blocks
	moveSimple(-100, -100, 140, RELDEG);
	turn1Motor(100, -90, RIGHT);
	moveSenseSimple(-30, -30, BLACK, 3, COLOR);
	lineSquare(50, 50, 2, 3, -0.5, -75, 1000);
	moveSimpleAcc(100, 100, 210, 0.2, RELDEG);
	turn2Motor(30, 90);
	moveSimpleNone(-50, -50, 1500, TIME);
	sleep(100);

	// ------------------------------------------------------------------------------//

	// Stacks the next 4 blocks
	startTask(readyLiftForPicking)
	moveSimpleAcc(50, 50, 260, 0.2, RELDEG);
	moveSimple(-15, -15, 109, RELDEG);
	sleep(200);
	moveArmAbs(100, 100, 230, 0.7, CLAW);
	moveArm(100, 100, 86, 0.3, LIFT, RELDEG);
    moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
	setArmSpeed(CLAW, -100);
	moveArm(-50, 20, 175, 0.1, LIFT, RELDEG);

	// ------------------------------------------------------------------------------//

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

	// ------------------------------------------------------------------------------//

	// Makes the stacks of 4
	moveArm(-100, -100, 1000, 0.25, LIFT, TIME);
	moveSimple(-13, -13, 83, RELDEG);
	moveArm(50, 20, 123, 0.3, LIFT, RELDEG);
	moveSimple(-25, -25, 47, RELDEG);
	sleep(200);
	moveArmAbs(100, 10, 300, 0.7, CLAW);
	moveArm(-50, 50, 60, 0.3, LIFT, RELDEG);
	startTask(liftUp500Delayed);
    moveSenseSimple(-80, -80, BLACK, 3, COLOR);

	// ------------------------------------------------------------------------------//

   // Collects the green/blue blocks if they are there
   if (!startedClose)
   {
		lineSquare(50, 50, 2, 3, 0.5, 55, 1000);
		moveSimple(100, 100, 100, RELDEG);
		turn1Motor(100, 167, LEFT);
		turn1Motor(100, -10, RIGHT);
		moveArm(100, 100, 1000, 0.01, LIFT, TIME);
		moveSenseSimple(15, 15, WHITE, 3, COLOR);
		moveSenseSimple(15, 15, 55, 3, LESSREFL);
		moveSimple(100, 100, 30, RELDEG);
		moveArm(-100, 50, 18, 0.3, LIFT, RELDEG);
		moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
		setArmSpeed(CLAW, -100);
		moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
		turn1Motor(100, -180, LEFT);
   }

	// ------------------------------------------------------------------------------//

    // Collects the two debris on the left side
    moveSimpleNone(-100, -100, 1000, TIME);
	sleep(100);
	moveSimple(100, 100, 254, RELDEG);
	turn1Motor(100, 90, LEFT);
	moveSenseSimple(-40, -40, BLACK, 2, COLOR);
	moveSimple(100, 100, 613, RELDEG);
	turn2Motor(50, 60);
	moveArm(100, 100, 42, 0.3, LIFT, RELDEG);
	moveSimple(100, 100, 240, RELDEG);
	moveSimple(60, -44, 680, RELDEG);
	moveSimpleNone(-100, -100, 1000, TIME);
	sleep(100);


	// ------------------------------------------------------------------------------//

    // Moves the red stack over
	moveSimple(100, 100, 1550, RELDEG);
	moveSimple(-100, -100, 475, RELDEG);
	turn1Motor(100, -89, RIGHT);
    moveSenseSimple(-40, -40, RED, 1, COLOR);
    moveArm(100, 100, 1000, 0.01, LIFT, TIME);
    moveSimple(15, 15, 300, RELDEG);
    moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
	turn1Motor(100, 158, RIGHT);

	// ------------------------------------------------------------------------------//

    // Goes to the the spot for the close green/blue blocks
    moveSimple(100, 100, 400, RELDEG);
	moveSenseSimple(50, 50, BLACK, 3, COLOR);
    moveSimple(100, 100, 225, RELDEG);
	moveSenseSimple(0, 100, BLACK, 2, COLOR);
	lineFollow(30, 30, 820, 50, 0.1, -0.6, -100, 2, RELDEG);
	resetRelative();
	moveSenseSimple(30, 30, BLACK, 3, COLOR);
    sleep(200);
	moveSimple(-100, -100, 400, RELDEG);
	turn1Motor(50, -90.5, RIGHT);

	// ------------------------------------------------------------------------------//

    // Collects the green/blue blocks if they are there
	if (startedClose)
    {
		startTask(liftDown);
		sleep(500);
		moveSuper(30, 30, 35, 15, 30, 0.004, 0.0005, 0.001, true, false, false, RELDEG);
		moveSenseSuper(30, 30, 30, 30, WHITE, 0.005, 0.0005, 0.001, 3, false, false, false, COLOR);
		moveSenseSuper(30, 30, 30, 30, 60, 0.005, 0.0005, 0.001, 3, false, false, false, LESSREFL);
		moveSuper(30, 30, 12, 30, 15, 0.004, 0.0005, 0.001, true, true, true, RELDEG);
		stopTask(clawReady);
		moveArm(-100, 100, 1500, 0.7, CLAW, TIME);
		setArmSpeed(CLAW, -100);
		sleep(100);
        moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
    }

	// ------------------------------------------------------------------------------//

    // Collects the final green/blue blocks
	moveSuper(-100, -100, 1000, 15, 100, 0.006, 0.0005, 0.001, true, false, false, RELDEG);
	moveSuper(-100, -100, 900, 50, 12, 0.004, 0.0005, 0.001, false, true, true, TIME);
	sleep(100);
	moveSimple(100, 100, 65, RELDEG);
	turn1Motor(100, 92, RIGHT);
	startTask(readyLiftForGreenBlue);
	moveSuper(100, 100, 180, 15, 50, 0.004, 0.0005, 0.001, true, true, false, RELDEG);
	moveSenseSuper(50, 50, 50, 50, RED, 0.005, 0.0005, 0.001, 2, false, false, false, COLOR);
	moveSuper(100, 100, 410, 50, 15, 0.004, 0.0005, 0.001, true, true, true, RELDEG);
    moveArm(-100, -100, 500, 0.01, LIFT, TIME);

	// ------------------------------------------------------------------------------//

    // Makes 2 stacks of 2 in the blue area
	moveSimpleAcc(-100, -100, 950, 0.2, RELDEG);
	turn1Motor(100, -90, RIGHT);
	moveSimpleNone(-100, -100, 500, TIME);
	sleep(100);
	startTask(readyLiftForPicking2);
	moveSimpleAcc(50, 50, 700, 0.2, RELDEG);
	moveSimple(-15, -15, 102, RELDEG);
	sleep(200);
	moveArmAbs(100, 100, 275, 0.7, CLAW);
    moveArm(-100, 100, 70, 0.3, LIFT, RELDEG);
	startTask(liftUp500Delayed);
	moveSimpleNone(-100, -100, 1500, TIME);
	sleep(100);

	// ------------------------------------------------------------------------------//

    // Collects the debris and does the water connection
	turn1Motor(100, 90, RIGHT);
	moveSuper(100, 100, 300, 15, 50, 0.004, 0.0005, 0.001, true, true, false, RELDEG);
	moveSenseSuper(50, 50, 50, 50, RED, 0.005, 0.0005, 0.001, 2, false, false, false, COLOR);
	moveSuper(100, 100, 165, 50, 15, 0.004, 0.0005, 0.001, true, true, true, RELDEG);
	turn2Motor(50, 90);
	moveSimpleNone(-100, -100, 1000, TIME);
	sleep(100);
	moveSimpleAcc(50, 50, 600, 0.2, RELDEG);
	turn2Motor(20, -90);
	startTask(liftDown);
	moveSimpleAcc(50, 50, 324, 0.2, RELDEG);
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
	turn1Motor(100, 230, RIGHT);
	moveSimple(100, 100, 1600, RELDEG);

	// ------------------------------------------------------------------------------//

	// Goes to the stacks of 2
	moveArm(100, 100, 100, 0.7, LIFT, RELDEG);
	startTask(liftUp500Delayed);
	moveSimple(-80, -80, 150, RELDEG);
	moveSimpleNone(-30, -100, 2500, TIME);
	sleep(100);
	moveSimpleAcc(50, 50, 930, 0.2, RELDEG);
	turn2Motor(20, -90);
    moveSenseSimple(40, 40, GREEN, 3, COLOR);

	// ------------------------------------------------------------------------------//

	// Makes the stack of 4 in the blue area
	moveSimpleAcc(20, 20, 255, 0.2, RELDEG);
	moveSimpleAcc(-30, -30, 140, 0.2, RELDEG);
	moveArm(100, 50, 248, 0.3, LIFT, RELDEG);
	moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
	setArmSpeed(CLAW, -100);
	moveArm(-50, 20, 144, 0.1, LIFT, RELDEG);
	moveSimpleAcc(30, 30, 124, 0.2, RELDEG);
	sleep(200);
	moveArmAbs(100, 10, 275, 0.7, CLAW);
	moveArm(-100, -100, 1000, 0.25, LIFT, TIME);
	moveSimple(-50, -50, 130, RELDEG);
	turn2Motor(25, -184);
	moveSimpleAcc(-50, -50, 260, 0.2, RELDEG);
	getColor(1);
	sleep(50);
	// ------------------------------------------------------------------------------//

    // Pulls the stack over to the green area if it the base is green
	if (getColor(1)==GREEN)
	{
		moveArm(100, 100, 1000, 0.01, LIFT, TIME);
		moveSimple(15, 15, 420, RELDEG);
		moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
		moveSimple(100, 100, 100, RELDEG);
	}
	else
	{
		moveSimple(100, 100, 450, RELDEG);
	}
	turn2Motor(25, -90);
	moveSimpleNone(-100, -100, 1600, TIME);
	sleep(100);

	// ------------------------------------------------------------------------------//

    // Brings the debris to the collection area
	turn1Motor(100, 90, LEFT);
	moveSimple(-100, -100, 2650, RELDEG);
	moveSimple(100, 100, 130, RELDEG);
	turn1Motor(100, 90, RIGHT);
	moveSimpleNone(-100, -100, 1000, TIME);
	sleep(100);

	// ------------------------------------------------------------------------------//

    // Does the other water connection
	moveSimple(100, 100, 370, RELDEG);
	turn2Motor(25, -90);
	startTask(liftDown);
	moveSenseSimple(-20, -20, RED, 2, COLOR);
	moveSimple(100, 100, 634, RELDEG);
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
	turn1Motor(100, 80, RIGHT);
}
