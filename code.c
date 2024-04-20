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

void code()
{
	// Lifts up the lift and closes the claw to reset them in the same position
	setArmSpeed(CLAW, -100);
	setArmSpeed(LIFT, -100);

    // Go to the other side if the robot started far
    if (!startedClose)
    {
        turn1Motor(100, 51, LEFT);
        moveSimpleAcc(100, 100, 1920, 0.5, RELDEG);
        turn2Motor(100, 128);
    }

    // Goes to the first 4 blocks
    moveSimpleNone(-100, -100, 1000, TIME); // Very first wall square

	// Resets the lift and claw
	resetMotorEncoder(d);
	setArmSpeed(CLAW, 0);
	resetMotorEncoder(a);
	setArmSpeed(LIFT, 0);
    sleep(50);

	//Goes to the black line
    moveSimpleAcc(100, 100, 290, 0.25, RELDEG);
    turn1Motor(100, 90.5, LEFT);
	resetRelative();
	moveSenseSuper(100, 100, 30, 100, BLACK, 0.005, 0.0005, 0.001, 3, true, false, false, COLOR);

	// After going to the black line, goes forward and turns
	moveSuper(100, 100, 168, 100, 15, 0.003, 0.0005, 0.001, false, true, true, RELDEG);
    turn2Motor(50, 89.5);

	// Positions itself for picking the blocks with a line square while moving the lift and claw
    startTask(liftDown);
    startTask(clawReady);
	moveSimple(40, 40, 20, RELDEG);
	lineSquare(50, 48, 2, 3, -0.4, -50, 1000);
	setSpeed(0, 0);
	sleep(100);

	// Collects the first 4 blocks
	resetRelative();
    moveSimpleAcc(30, 30, 95, 0.15, RELDEG); // Moves forward so the claw is in the right spot
	
	// Grabs the blocks with the claw
	stopTask(clawReady);
    setArmSpeed(CLAW, -100);
	sleep(500);

    moveSimple(100, 100, 65, RELDEG); // Goes forward after using the claw so the rack gear is positioned

	// Closes the rack gear to collect the outside blocks
    moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
    moveArm(100, 100, 50, 0.01, LIFT, RELDEG);
    moveSimple(100, 100, 70, RELDEG);
    moveArm(-100, -100, 500, 0.01, LIFT, TIME);

	// Goes to the yellow area
	turn1Motor(100, -55, LEFT);
	turn1Motor(100, -55, RIGHT);
	lineSquare(53, 48, 2, 3, -0.45, -50, 700); // Line squares to stay straight
	resetRelative();
	moveSimpleAcc(-70, -70, 660, 0.2, RELDEG);

	// Stacks the first 4 blocks
	moveArm(60, 30, clawDegree-10, 0.3, LIFT, RELDEG); // Brings the claw down just above the blocks
	resetRelative();
	moveSimpleAcc(-15, -15, 115, 0.1, RELDEG); // Backs up so the blocks in the claw are on top of the other blocks
	moveArm(60, 30, 30, 0.3, LIFT, RELDEG); // Brings the claw down so the blocks are resting on each other

	// Releases the blocks and moves backwards while the lift is moving up
	moveArmAbs(100, 100, 310, 0.7, CLAW);
	moveSimpleAcc(-100, -100, 92, 0.2, RELDEG);
	startTask(liftUp1000);

    // Goes to the next 4 blocks
	
	// Turns to line square
	turn2Motor(50, -90);
	moveSenseSimple(-20, -20, BLACK, 3, COLOR);
    lineSquare(50, 50, 2, 3, -0.4, -75, 700);
	resetRelative();

	// Positions to collect the next blocks
    moveSimpleAcc(50, 50, 140, 0.17, RELDEG);
    turn1Motor(100, 89, RIGHT);
	stopTask(liftUp1000);
    startTask(liftDown);
    moveSimpleAcc(-50, -50, 30, 0.2, RELDEG);

	// Line squares so that the robot is in the same position
	lineSquare(50, 53, 2, 3, -0.4, -50, 1000);
	setSpeed(0, 0);
	sleep(50);

	// Collects the next 4 blocks

	// Moves so the claw is aligned with the blocks
	resetRelative();
    moveSimpleAcc(30, 30, 103, 0.15, RELDEG);
	stopTask(liftDown);

	// Closes the claw to grab the blocks
    setArmSpeed(CLAW, -100);
	sleep(500);

	// Moves forward so the rack gear is aligned
    moveSimple(100, 100, 62, RELDEG);

	// Closes the rack gear to collect the other blocks
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
    moveArm(100, 100, 50, 0.01, LIFT, RELDEG);
    moveSimple(100, 100, 70, RELDEG);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);

	// Positions for stacking the next 4 blocks

	// Goes to the line and line squares so the position is consistent
	moveSimple(-100, -100, 130, RELDEG);
	turn1Motor(100, -90, RIGHT);
	moveSenseSimple(-20, -20, BLACK, 3, COLOR);
	lineSquare(50, 52, 2, 3, -0.5, -50, 500);

	// Moves forward and turns so the sensors are good for line following
	moveSimpleAcc(50, 50, 40, 0.1, RELDEG);
	turn2motor(30, 90);

	// Makes the second stack of blocks
	startTask(readyLiftForPicking);
	sleep(500);
	resetRelative();
	moveSimpleAcc(-15, -15, 109, 0.1, RELDEG); // Moves back so the blocks are in the right spot
	moveArm(60, 30, 30, 0.3, LIFT, RELDEG); // Brings the claw down so the blocks rest on each other

	// Releases the blocks
	moveArmAbs(100, 100, 230, 0.7, CLAW);
	moveArm(100, 100, 500, 0.3, LIFT, TIME); // Brings the lift down to collect the 2 stacks of 2
	setArmSpeed(CLAW, -100);
	sleep(500);

	// After grabbing the new stacks, lift up so that the stacks clear the stacks in the yellow area
	moveArm(-50, 20, 210, 0.1, LIFT, RELDEG); 

    // Goes to the first stack of blocks

	// Positions for line following
    if (getReflection(2)<50)
	{
        moveSenseSimple(0, 100, 40, 2, GREATREFL);
    }
	else
	{
        moveSenseSimple(100, 0, 60, 2, LESSREFL);
    }
	lineFollow(30, 30, 250, 50, 0.1, 0.6, 100, 2, RELDEG); // Line follows a bit to become stright
	resetRelative();
	moveSenseSimple(20, 20, YELLOW, 3, COLOR); // Goes to the yellow area

	// Makes the stacks of 4
	moveArm(-100, -100, 1000, 0.25, LIFT, TIME); // Grabs the other stacks with the rack gear
	moveSimple(-13, -13, 93, RELDEG); // Pulls them to the yellow area
	moveArm(50, 30, 85, 0.3, LIFT, RELDEG); // Lowers the lift a little to release them

	moveSimple(-25, -25, 67, RELDEG); // Moves back so the second stacks are on top of the first stacks
	moveArm(50, 50, 40, 0.2, LIFT, RELDEG); // Lowers the claw so the new stacks rest on the old ones

	moveArmAbs(100, 10, 300, 0.7, CLAW); // Release the blocks
	moveArm(-50, 50, 70, 0.3, LIFT, RELDEG); // Lift up a little so the prongs on the claw don't make the stack fall

	// Move backwards until the line while the lift is going up
	startTask(liftUp500Delayed);
    moveSenseSimple(-50, -50, BLACK, 3, COLOR);

	// Collects the green/blue blocks if they are there
	if (!startedClose)
	{
		lineSquare(50, 52, 2, 3, 0.4, 50, 700); // Line squares for consistency

		// Maneuvering to get the the right position for picking the blocks
		turn1Motor(100, 150, LEFT);
		turn1Motor(100, -30, RIGHT);
		moveSimple(100, 100, 20, RELDEG);

		// Moves the lift in position and line squares so the robot is straight
		startTask(liftDown);
		lineSquare(50, 50, 2, 3, -0.4, -50, 700);
		setSpeed(0, 0);
		sleep(100);
		resetRelative();

		// Moves forward and grabs the blocks with the claw
		moveSimpleAcc(30, 30, 100, 0.15, RELDEG);
		stopTask(clawReady);
		setArmSpeed(CLAW, -100);
		sleep(500);

		// Position for the debris while the lift is moving up
		startTask(liftUp1000)
		moveSimpleAcc(30, 30, 80, 0.15, RELDEG);
		turn1Motor(50, -91.5, LEFT);
	}
	else
	{
		// If the blocks are not there position for picking up the debris
		moveSimpleNone(-50, -50, 1000, TIME); // Wall squares
		sleep(100);
		moveSimple(100, 100, 210, RELDEG);
		turn1Motor(100, 92, LEFT);
	}

    // Collects the two debris on the left side
	moveSenseSimple(-25, -25, BLACK, 2, COLOR); // Goes back until black to be in the same position
	
	// Goes forward and turns so the rack gear is aligned with the debris
	moveSimpleAcc(100, 100, 557, 0.2, RELDEG);
	turn2Motor(50, 58);

	// Uses the rack gear to collect the debris
	moveArm(100, 100, 82, 0.3, LIFT, RELDEG);
	moveSimple(100, 100, 240, RELDEG);
	setArmSpeed(LIFT, -30);
	// startTask(liftUp500);

	// Turns and wall squares
	moveSimpleAcc(30, -22, 710, 0.15, RELDEG);
	setArmSpeed(LIFT, 0);
	moveArm(100, 100, 52, 0.3, LIFT, RELDEG); // Opens the rack gear so the debris does not get hit when the robot wall squares
	moveSimpleNone(-30, -30, 1000, TIME);
	sleep(50);

    // Moves the red stack over

	// Closes the rack gear while going forward so the debris is on the opposite side
	moveSimpleAcc(100, 100, 1625, 0.2, RELDEG);

	// Opens the rack gear so the debris doesn't move while moving back
	moveArm(100, 100, 94, 0.3, LIFT, RELDEG);
	startTask(liftUp500Delayed);

	// Moves back and turns so the robot is in line with the red stack
	moveSimpleAcc(-100, -100, 565, 0.2, RELDEG);
	turn1Motor(50, -95, RIGHT);

	// Moves back for sensing and grabs the red stack with the lift
    moveSenseSimple(-30, -30, RED, 2, COLOR);
	moveSimple(-30, -30, 100, RELDEG);
    moveArm(100, 100, 1000, 0.01, LIFT, TIME);

	// If skipping the green/blue stack and there are blocks in the claw, put them down in the rack gear
	if (skipGreenBlueStack && !startedClose)
	{
		startTask(clawBackDown);
	}

	// Moves forward with the red stack so it is in the red area
	moveSenseSimple(15, 15, BLUE, 2, COLOR);
    moveSimple(15, 15, 160, RELDEG);

	// Releases the stack and turns to catch the line
    moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
	turn1Motor(100, 153, RIGHT);

    // Goes to the the spot for the close green/blue blocks

	// Moves forward until a little after the sensor sees the black line
	moveSuper(100, 100, 300, 15, 100, 0.004, 0.0003, 0.001, true, false, false, RELDEG);
	moveSenseSuper(100, 100, 100, 100, BLACK, 0.005, 0.0003, 0.001, 3, false, false, false, COLOR);
	moveSuper(100, 100, 215, 100, 15, 0.004, 0.0003, 0.001, false, true, true, RELDEG);

	// Turns to catch the line for line following
	moveSenseSimple(-40, 40, 40, 2, LESSREFL);
	lineFollow(70, 30, 820, 50, 0.2, -0.33, 60, 2, RELDEG); // Line follows
	resetRelative();

	// Moves until black and moves back to position for grabbing the next blocks and/or releasing them
	moveSenseSimple(30, 30, BLACK, 3, COLOR);
    sleep(100);

    // Collects the green/blue blocks if they are there
	if (startedClose)
    {
		moveSimpleAcc(-100, -100, 380, 0.15, RELDEG);
		turn1Motor(50, -93, RIGHT);
		if(skipGreenBlueStack) // Collects with rack gear if not stacking
		{
			moveSimpleAcc(60, 60, 35, 0.2, RELDEG);
			lineSquare(50, 50, 2, 3, -0.4, -50, 500); // Line squares for consistency

			// Opens the rack gear, moves forward, and closes the rack gear to grab the blocks
			moveArm(100, 100, 150, 0.01, LIFT, RELDEG);
			resetRelative();
			moveSimpleAcc(100, 100, 220, 0.2, RELDEG);
			moveArm(-100, -100, 500, 0.01, LIFT, TIME);
		}
		else // Collects with claw if stacking
		{
			// Line squares for consistency while getting the lift ready
			moveSimpleAcc(60, 60, 35, 0.2, RELDEG);
			startTask(liftDown);
			lineSquare(50, 50, 2, 3, -0.4, -50, 1000);
			setSpeed(0, 0);
			sleep(100);
			resetRelative();

			// Moves forward and grabs the blocks with the claw
			moveSimpleAcc(30, 30, 105, 0.15, RELDEG);
			stopTask(clawReady);
			setArmSpeed(CLAW, -100);
			sleep(500);
			moveArm(-100, -100, 1000, 0.01, LIFT, TIME); // Lifts up the lift
		}
	}

	if (skipGreenBlueStack)
	{
		// Positions the robot differently whether or not it picked up the close blocks
		if (startedClose)
		{
			turn1Motor(-100, -20, RIGHT);
			turn1Motor(-100, -20, LEFT);
		}
		else
		{
			moveSimpleAcc(-100, -100, 350, 0.15, RELDEG);
			turn1Motor(50, -92, RIGHT);
			// turn1Motor(100, -72, RIGHT);
			// turn1Motor(100, 19.5, LEFT);
		}

		// Moves backwards until it sees the white in fornt of the green and back a little more
		moveSuper(-100, -100, 300, 15, 100, 0.004, 0.0003, 0.001, true, false, false, RELDEG);
		moveSenseSuper(-100, -100, 100, 100, WHITE, 0.005, 0.0003, 0.001, 2, false, false, false, COLOR);
		moveSuper(-100, -100, 165, 100, 100, 0.004, 0.0003, 0.001, false, false, false, RELDEG);

		// Without stopping release the blocks and wall square
		startTask(releaseBlocks);
		startTask(clawBackDown);
		moveSuper(-100, -85, 1000, 100, 15, 0.004, 0, 0, false, true, true, TIME);
	}
	else
	{ // If there is a stack of 4
		// Collects the final green/blue blocks

		// Goes to the other side of the mat
		if (!startedClose)
		{
			turn1Motor(50, -92.5, RIGHT);
		}
		moveSuper(-100, -100, 990, 15, 100, 0.006, 0.0005, 0.001, true, false, false, RELDEG);
		moveSuper(-50, -50, 1500, 50, 12, 0.004, 0.0005, 0.001, false, true, true, TIME);
		sleep(100);

		// Moves forward and turns to get the last blocks
		moveSimple(100, 100, 50, RELDEG);
		turn1Motor(50, 90.5, RIGHT);

		// Moves forward until red and then degrees
		startTask(readyLiftForGreenBlue);
		moveSuper(100, 100, 180, 15, 50, 0.004, 0.0003, 0.001, true, false, false, RELDEG);
		moveSenseSuper(100, 100, 50, 50, RED, 0.005, 0.0003, 0.001, 2, false, false, false, COLOR);
		moveSuper(100, 100, 410, 50, 15, 0.002, 0.0003, 0.001, false, true, true, RELDEG);

		// Grabs the last blocks with the rack gear
		moveArm(-100, -100, 500, 0.01, LIFT, TIME);

		// Makes 2 stacks of 2 in the blue area

		// Moves back and wall squares
		moveSimpleAcc(-100, -100, 950, 0.2, RELDEG);
		turn1Motor(100, -90, RIGHT);
		moveSimpleNone(-100, -100, 500, TIME);
		sleep(100);

		// Goes forward to the blue area
		startTask(readyLiftForPicking2);
		moveSimpleAcc(50, 50, 700, 0.2, RELDEG);

		// Moves back so the blocks are on top of the bottom ones
		moveSimple(-15, -15, 104, RELDEG);
		sleep(200);

		// Lowers the blocks in the claw so they rest on the other ones
		moveArm(60, 30, 30, 0.3, LIFT, RELDEG);

		// Releases the blocks and wall squarea
		moveArmAbs(100, 100, waterClawDegree, 0.7, CLAW);
		moveArm(-100, 100, 70, 0.3, LIFT, RELDEG);
		startTask(liftUp500Delayed);
		moveSimpleNone(-100, -100, 1500, TIME);
		sleep(100);
	}

    // Collects the debris and does the water connection

	// Turns and moves forward a bit after seeing red
	turn1Motor(100, 90, RIGHT);
	moveSuper(100, 100, 135, 15, 50, 0.004, 0.0005, 0.001, true, false, false, RELDEG);
	moveSenseSuper(100, 100, 50, 50, RED, 0.005, 0.0005, 0.001, 2, false, false, false, COLOR);
	moveSuper(100, 100, 162, 50, 15, 0.004, 0.0005, 0.001, false, true, true, RELDEG);

	// Wall squares and moves forward to align with the water connection
	turn2Motor(50, 90);
	moveSimpleNone(-100, -100, 1000, TIME);
	sleep(100);
	moveSimpleAcc(100, 100, 569, 0.2, RELDEG);
	turn2Motor(30, -90);

	// Goes to the water connection differently if not making the stack of 4
	if(skipGreenBlueStack)
	{
		// Opens the rack gear a little and then more later to push the blocks out of the way
		moveArm(100, 50, 75, 0.3, LIFT, RELDEG);
		moveSimpleAcc(100, 100, 216, 0.2, RELDEG); // Goes forward until the blocks
		moveArm(50, 50, 1000, 0.01, LIFT, TIME); // Pushes them away while lowering the claw
		moveSimpleAcc(100, 100, 90, 0.2, RELDEG);
	}
	else
	{
		// Lowers the lift while moving forward since the blocks are gone
		startTask(liftDown);
		sleep(300);
		moveSimpleAcc(100, 100, 321, 0.2, RELDEG);
	}

	// Does the water connection
	startTask(clawWater);
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);

	// Different endings if not making the stack of 4
	if (skipGreenBlueStack)
	{
		// Collects the small debris
		turn1Motor(-100, -10, LEFT);
		turn1Motor(100, 220, RIGHT);
		moveSimple(100, 100, 530, RELDEG);
		turn2Motor(50, -20);

		// Goes to the water connection

		// Moves until black and then turns to align with the line
		moveSuper(100, 100, 400, 15, 40, 0.004, 0.0005, 0.001, true, true, false, RELDEG);
		moveSenseSuper(40, 40, 40, 40, BLACK, 0.005, 0.0005, 0.001, 3, false, false, true, COLOR);
		resetRelative();
		startTask(debrisLiftOpenClose); // Opens and closes the lift while turning
		moveSenseSimple(30, -20, BLACK, 2, COLOR);

		// Line follows to straighten the robot
		lineFollow(40, 30, 940, 40, 0.3, 0.25, 45, 2, RELDEG);
		resetRelative();
		startTask(liftDown);
		startTask(clawBackDown);

		// Puts debris in the collection area
		moveSenseSuper(30, 30, 30, 30, RED, 0.004, 0.0005, 0.001, 2, false, false, false, COLOR);
		if (!consistentLastWater)
		{
			moveSuper(50, 49.8, 1123, 30, 15, 0.004, 0.0005, 0.001, true, true, true, RELDEG);
			// turn1Motor(100, 10, LEFT);
		}
		else
		{
			moveSuper(100, 100, 1070, 30, 15, 0.004, 0.0005, 0.001, true, true, true, RELDEG);
			moveSimple(-100, -100, 130, RELDEG);
			startTask(liftUp1000);
			turn1Motor(100, -90, RIGHT);
			moveSimpleNone(-100, -100, 700, TIME);
			sleep(100);
			moveSimple(100, 100, 375, RELDEG);
			turn2Motor(25, -90);
			startTask(liftDown);
			sleep(500);
			moveSimple(100, 100, 370, RELDEG);
		}

		startTask(clawWater);
		stopTask(liftDown);
		moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
		turn1Motor(100, 70, RIGHT);
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
