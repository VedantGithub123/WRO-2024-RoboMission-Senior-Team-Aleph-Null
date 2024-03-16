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
	moveArm(60, 20, 157, 0.3, LIFT, RELDEG);
	stopTask(readyLiftForPicking);
}

task readyLiftForPicking2()
{
	moveArm(60, 20, 161, 0.3, LIFT, RELDEG);
	stopTask(readyLiftForPicking);
}

task clawReady()
{
	moveArmAbs(100, 50, 300, 0.7, CLAW);
	stopTask(clawReady);
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
	moveSimpleAcc(100, 100, 300, 0.25, RELDEG);
	turn1Motor(50, 90, LEFT);
	moveSimpleAcc(100, 100, 300, 0.25, RELDEG);
	moveSenseSimple(25, 25, BLACK, 2, COLOR);
	moveSimpleAcc(100, 100, 192, 0.25, RELDEG);
	turn2Motor(20, 90);
	startTask(liftDown);
	startTask(clawReady);
	
	// ------------------------------------------------------------------------------//
	
	// Collects the first 4 blocks
	moveSenseSimple(15, 15, WHITE, 3, COLOR);
	moveSenseSimple(15, 15, 55, 3, LESSREFL);
   	moveSimple(100, 100, 50, RELDEG);
	moveArm(-100, 50, 25, 0.3, LIFT, RELDEG);
   	moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
	setArmSpeed(CLAW, -100);
   	moveSimple(100, 100, 55, RELDEG);
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
   	moveArm(100, 100, 50, 0.01, LIFT, RELDEG);
   	moveSimple(100, 100, 70, RELDEG);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);

	// ------------------------------------------------------------------------------//
	
	// Goes to the yellow area
	turn1Motor(100, -55, LEFT);
	turn1Motor(100, -55, RIGHT);
	lineSquare(50, 50, 2, 3, -0.5, -55, 700);
	moveSimple(-70, -70, 700, RELDEG);

	// ------------------------------------------------------------------------------//
	
	// Stacks the first 4 blocks
	moveArm(60, 20, 161, 0.3, LIFT, RELDEG);
	moveSimple(-15, -15, 83, RELDEG);
    sleep(200);
	moveArmAbs(100, 100, 300, 0.7, CLAW);
	moveSimple(-100, -100, 150, RELDEG);
	startTask(liftUp1000);
	moveSenseSimple(-100, -100, BLACK, 3, COLOR);

	// ------------------------------------------------------------------------------//
	
    // Goes to the next 4 blocks
    turn1Motor(100, 125, RIGHT);
	turn1Motor(100, 30, LEFT);
	lineFollow(30, 30, 320, 50, 0.1, 0.6, 100, 2, RELDEG);
	moveSenseSimple(20, 20, RED, 2, COLOR);
	moveSimpleAcc(-50, -50, 460, 0.25, RELDEG);
	turn2Motor(20, -91);
	startTask(liftDown);
	moveSimple(-50, -50, 50, RELDEG);

	// ------------------------------------------------------------------------------//
	
	// Collects the next 4 blocks
	moveSenseSimple(15, 15, WHITE, 3, COLOR);
	moveSenseSimple(15, 15, 55, 3, LESSREFL);
    moveSimple(100, 100, 40, RELDEG);
	moveArm(-100, 50, 28, 0.3, LIFT, RELDEG);
    moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
	setArmSpeed(CLAW, -100);
    moveSimple(100, 100, 52, RELDEG);
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
    moveArm(100, 100, 50, 0.01, LIFT, RELDEG);
    moveSimple(100, 100, 70, RELDEG);
	moveArm(-100, -100, 500, 0.01, LIFT, TIME);
	
	// ------------------------------------------------------------------------------//
	
	// Positions for stacking the next 4 blocks
	moveSimple(-100, -100, 120, RELDEG);
	turn1Motor(100, -90, RIGHT);
	moveSenseSimple(-30, -30, BLACK, 3, COLOR);
	lineSquare(50, 50, 2, 3, -0.5, -55, 1000);
	moveSimple(100, 100, 165, RELDEG);
	turn2Motor(50, 90);
	moveSimpleNone(-100, -100, 1000, TIME);
	sleep(100);
	
	// ------------------------------------------------------------------------------//
	
	// Stacks the next 4 blocks
	startTask(readyLiftForPicking)
	moveSimpleAcc(50, 50, 280, 0.2, RELDEG);
	moveSimple(-15, -15, 105, RELDEG);
	sleep(200);
	moveArmAbs(100, 100, 230, 0.7, CLAW);
	moveArm(100, 100, 94, 0.3, LIFT, RELDEG);
    moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
	setArmSpeed(CLAW, -100);
	moveArm(-50, 20, 175, 0.1, LIFT, RELDEG);

	// ------------------------------------------------------------------------------//
	
    // Goes to the first stack of blocks
    turn1Motor(100, 59, LEFT);
	turn1Motor(100, 59, RIGHT);
    if (getReflection(2)<50){
        moveSenseSimple(0, 100, 40, 2, GREATREFL);
    }else{
        moveSenseSimple(100, 0, 60, 2, LESSREFL);
    }
	lineFollow(30, 30, 200, 50, 0.1, 0.6, 100, 2, RELDEG);
	moveSenseSimple(25, 25, YELLOW, 3, COLOR);
	
	// ------------------------------------------------------------------------------//
	
	// Makes the stacks of 4
	moveArm(-100, -100, 1000, 0.25, LIFT, TIME);
	moveSimple(-13, -13, 85, RELDEG);
	moveArm(50, 20, 114, 0.3, LIFT, RELDEG);
	moveSimple(-25, -25, 59, RELDEG);
	sleep(200);
	moveArmAbs(100, 10, 300, 0.7, CLAW);
	moveArm(-100, 100, 60, 0.3, LIFT, RELDEG);
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
	moveSenseSimple(-20, -20, BLACK, 2, COLOR);
	moveSimple(100, 100, 613, RELDEG);
	turn2Motor(25, 60);
	moveArm(100, 100, 34, 0.3, LIFT, RELDEG);
	moveSimple(100, 100, 240, RELDEG);
    moveArm(-100, -100, 500, 0.01, LIFT, TIME);
	moveSimple(30, -24, 680, RELDEG);
	moveSimpleNone(-100, -100, 1000, TIME);
	sleep(100);
	
	// ------------------------------------------------------------------------------//
	
    // Moves the red stack over
	moveSimple(100, 100, 1550, RELDEG);
	moveArm(100, 100, 94, 0.3, LIFT, RELDEG);
	startTask(liftUp500Delayed);
	moveSimple(-100, -100, 480, RELDEG);
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
	moveSenseSimple(30, 30, BLACK, 3, COLOR);
    sleep(200);
	moveSimple(-100, -100, 400, RELDEG);
	turn1Motor(50, -90.5, RIGHT);

	// ------------------------------------------------------------------------------//
	
    // Collects the green/blue blocks if they are there
	if (startedClose)
    {
		moveSimple(30, 30, 20, RELDEG);
		moveArm(100, 100, 1000, 0.01, LIFT, TIME);
        moveSenseSimple(15, 15, WHITE, 3, COLOR);
	    moveSenseSimple(15, 15, 55, 3, LESSREFL);
        moveSimple(100, 100, 30, RELDEG);
        moveArm(-100, 50, 18, 0.3, LIFT, RELDEG);
        moveArm(-100, 100, 1000, 0.7, CLAW, TIME);
		setArmSpeed(CLAW, -100);
        moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
    }
	
	// ------------------------------------------------------------------------------//
	
    // Collects the final green/blue blocks
	moveSimple(-100, -100, 1500, TIME);
	moveSimpleNone(-50, -50, 1000, TIME);
	sleep(100);
	moveSimple(100, 100, 60, RELDEG);
	turn1Motor(100, 90, RIGHT);
	moveSimpleAcc(100, 100, 180, 0.25, RELDEG);
	moveSenseSimple(30, 30, RED, 2, COLOR);
	moveArm(100, 100, 124, 0.3, LIFT, RELDEG);
	moveSimpleAcc(100, 100, 410, 0.2, RELDEG);
    moveArm(-100, -100, 500, 0.01, LIFT, TIME);

	// ------------------------------------------------------------------------------//
	
    // Makes 2 stacks of 2 in the blue area
	moveSimpleAcc(-100, -100, 950, 0.2, RELDEG);
	turn1Motor(100, -90, RIGHT);
	moveSimpleNone(-100, -100, 500, TIME);
	sleep(100);
	startTask(readyLiftForPicking2)
	moveSimpleAcc(50, 50, 510, 0.2, RELDEG);
	moveSimple(-15, -15, 110, RELDEG);
	sleep(200);
	moveArmAbs(100, 100, 300, 0.7, CLAW);
    moveArm(-100, 100, 70, 0.3, LIFT, RELDEG);
	moveSimpleAcc(30, 30, 300, 0.2, RELDEG);
	startTask(liftUp500Delayed);
	moveSimpleNone(-100, -100, 1500, TIME);
	sleep(100);

	// ------------------------------------------------------------------------------//
	
    // Collects the debris and does the water connection
	turn1Motor(100, 90, RIGHT);
	moveSimple(100, 100, 698, RELDEG);
	turn2Motor(50, 90);
	moveSimpleNone(-100, -100, 1000, TIME);
	sleep(100);
	moveSimpleAcc(50, 50, 570, 0.2, RELDEG);
	turn2Motor(20, -90);
	startTask(liftDown);
	moveSimpleAcc(50, 50, 324, 0.2, RELDEG);
	moveArm(-100, -100, 1000, 0.01, LIFT, TIME);
	turn1Motor(100, 230, RIGHT);
	moveSimple(100, 100, 1761, RELDEG);
	
	// ------------------------------------------------------------------------------//
	
	// Goes to the stacks of 2
	moveSimpleNone(-30, -100, 2000, TIME);
	moveSimpleAcc(50, 50, 905, 0.2, RELDEG);
	turn2Motor(20, -90);
    moveSenseSimple(15, 15, GREEN, 3, COLOR);

	// ------------------------------------------------------------------------------//
	
	// Makes the stack of 4 in the blue area
	
	// ------------------------------------------------------------------------------//

    // Pulls the stack over to the green area if it the base is green

	// ------------------------------------------------------------------------------//
	
    // Brings the debris to the collection area

}
