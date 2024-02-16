// Task to ready the arms for collecting the red and yellow blocks in parallel
task readyArmsRedYellow()
{
    moveArmAbs(100, 100, 820, 0.01, LIFT);
    moveArmAbs(50, 25, 445, 0.01, CLAW);
    stopTask(readyArmsRedYellow);
}

// Task to ready the arms for grabbing the front red and yellow blocks
task readyLiftForGrabbing()
{
    moveArmAbs(100, 100, 590, 0.01, LIFT);
    stopTask(readyLiftForGrabbing);
}

// Task to lift up the blocks in parallel
task readyLiftForDropping()
{
    moveArmAbs(100, 100, 1030, 0.01, LIFT);
    stopTask(readyLiftForDropping);
}

// Task to move the lift up in parallel so it does not hit the water connection
task readyLiftAboveWaterConnection()
{
    moveArmAbs(100, 100, 1300, 0.01, LIFT);
    stopTask(readyLiftAboveWaterConnection);
}

// Task to move the lift to the correct position for grabbing the red stask in parallel
task readyLiftForRed()
{
    moveArmAbs(100, 100, 600, 0.01, LIFT);
    stopTask(readyLiftForRed);
}

void slide()
{
    moveArmAbs(20, 20, 120, 0.01, CLAW);
    moveArmAbs(100, 30, 445, 0.01, CLAW);
}

// Function that has the code for the close starting loop
void loop1CloseStart()
{

    // Gets into position to collect the blocks on the close side
    startTask(readyArmsRedYellow);
    turn1Motor(100, -48, LEFT);
    turn1Motor(100, -59, RIGHT);
    moveSimple(49, 50, 430, RELDEG);
    moveSenseSimple(20, 20, RED, 3, COLOR);
    moveSimple(-20, -20, 30, RELDEG);

    // Moves the claw to slide the red blocks to the left side
    slide();

    // Goes and does the same thing to the second red block
    moveSimple(30, 30, 182, RELDEG);
    slide();

    // Collects the yellow blocks
    startTask(readyLiftForGrabbing);
    move(30, 30, 8, 485, 0.3, 2, 10, RELDEG);
    moveArm(100, 100, 400, 0.01, CLAW, TIME);

    // Moves to the yellow area
    moveSenseSimple(-40, -43, RED, 3, COLOR);
    moveSimple(-60, -65, 240, RELDEG);
    turn1Motor(50, 102, RIGHT);
    moveSimpleNone(-100, -100, 600, TIME);
    startTask(readyLiftForDropping);
    moveSimple(40, 40, 800, RELDEG);

    // Lifts the red and yellow block in the front and stacks them on top of the ones in the back
    moveSimple(-20, -20, 100, RELDEG);
    moveArmAbs(100, 10, 450, 0.01, CLAW);

    // Line follows to the first debris
    moveSimple(-100, -100, 420, RELDEG);
    turn2Motor(100, 90);
    // While line following, also sense the two blocks
    lineFollowSense(50, 50, BLACK, 50, 0.02, -0.3, -20, 1, 2, COLOR);
    turn1Motor(100, -90, LEFT);
    moveSimpleNone(-100, -100, 600, TIME);
    startTask(readyLiftAboveWaterConnection);
    moveSimple(50, 50, 1200, RELDEG);

    // Goes the the water connection
    turn1Motor(50, -90, RIGHT);
    moveSimple(50, 50, 690, RELDEG);
    moveSenseSimple(25, 25, WHITE, 2, COLOR); // Goes until white for consistency

    // Uses the claw to do the water connection
    moveSimple(-50, -50, 180, RELDEG);
    moveArmAbs(100, 100, 960, 0.01, LIFT);
    moveArmAbs(100, 50, 200, 0.01, CLAW);
    moveSimple(30, 30, 90, RELDEG);
    moveArmAbs(100, 100, 1500, 0.01, LIFT);
    turn1Motor(60, 15, LEFT);
    turn1Motor(60, -15, LEFT);
    turn2Motor(30, -90);

    // Collects the other debris
    moveSimple(50, 50, 125, RELDEG);
    turn2Motor(50, -70);

    // Places the two debris near the other two debris
    moveSimple(100, 100, 650, RELDEG);
    turn1Motor(50, 23, RIGHT);
    moveSimple(100, 100, 1500, RELDEG);

    // Gets into position for the red and yellow blocks on the far side
    moveSimple(-100, -100, 1350, RELDEG);
    startTask(readyArmsRedYellow);
    turn1Motor(100, -90, LEFT);
    moveSimpleNone(-100, -100, 800, TIME);
    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -59, RIGHT);
    moveSenseSimple(50, 50, RED, 3, COLOR);

    // Collects the red blocks
    moveSimple(30, 30, 390, RELDEG);

    // Uses the claw to sort the yellow blocks
    slide();
    moveSimple(30, 30, 182, RELDEG);
    slide();
    startTask(readyLiftForGrabbing);
    move(30, 30, 8, 250, 0.3, 2, 10, RELDEG);

    // Grabs the blocks to make sure they don't move away
    moveArm(100, 100, 400, 0.01, CLAW, TIME);

    // Stacks the red and yellow blocks
    moveSenseSimple(-40, -47, YELLOW, 3, COLOR);
    moveSimple(-50, -59, 200, RELDEG);
    turn1Motor(50, 105, RIGHT);
    moveSimpleNone(-100, -100, 800, TIME);
    startTask(readyLiftForDropping);
    moveSimple(20, 20, 180, RELDEG);
    moveSimple(-20, -20, 100, RELDEG);
    moveArmAbs(70, 15, 0, 0.01, CLAW);

    // Moves to the place where the other stack of red and yellow blocks are and stacks both stacks to get a stack of 4
    moveSimple(20, 20, 670, RELDEG);
    moveArmAbs(100, 100, 570, 0.01, LIFT);
    moveArm(100, 100, 1000, 0.01, CLAW, TIME);
    moveArmAbs(100, 50, 1495, 0.01, LIFT);
    moveSimple(-20, -20, 85, RELDEG);
    sleep(300);
    moveArmAbs(50, 50, 450, 0.01, CLAW);

    // Collects the next debris
    moveSimpleNone(-100, -100, 1500, TIME);
    startTask(readyArmsRedYellow);
    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -59, RIGHT);
    moveSenseSimple(60, 60, GREEN, 3, COLOR);
    startTask(readyLiftForGrabbing);
    moveSimple(100, 100, 320, RELDEG);
    moveArm(100, 100, 500, 0.01, CLAW, TIME);
    startTask(readyLiftAboveWaterConnection);

    // Pushes all the debris to a place near the starting area
    moveSimple(-94, -100, 120, RELDEG);
    turn1Motor(100, 98, RIGHT);
    moveSimpleNone(-100, -100, 800, TIME);
    moveArmAbs(100, 100, 450, 0.01, CLAW);
    moveSimple(60, 60, 1050, RELDEG);
    // move(60, 60, 15, 1050, 0.3, 3, 15, RELDEG);

    // Positions to move the red stack to the red area
    turn1Motor(100, -90, LEFT);
    startTask(readyLiftForRed);
    sleep(300);
    moveSimple(30, 30, 120, RELDEG);
    moveSenseSimple(30, 30, RED, 2, COLOR);
    moveSimple(20, 20, 105, RELDEG);

    // Moves the red stack over
    moveArm(40, 40, 900, 0.01, CLAW, TIME);
    moveSimple(-10, -10, 265, RELDEG);
    moveArmAbs(70, 70, 450, 0.01, CLAW);

    // Pushes the debris into the collection area
    moveSimple(-10, -10, 95, RELDEG);
    turn1Motor(100, -45, RIGHT);
    moveSimple(100, 100, 300, RELDEG);
    turn1Motor(100, 108, LEFT);
    startTask(readyLiftAboveWaterConnection);
    moveSimple(100, 100, 700, RELDEG);
    turn1Motor(100, -125, RIGHT);

    // Positions for water connection
    moveSimpleNone(-100, -100, 400, TIME);
    moveSimple(70, 70, 550, RELDEG);
    turn2Motor(50, -90);
    moveSimple(70, 70, 300, RELDEG);
    moveSenseSimple(25, 25, WHITE, 2, COLOR);

    // Does the other water connection
    moveSimple(-50, -50, 180, RELDEG);
    moveArmAbs(100, 100, 960, 0.01, LIFT);
    moveArmAbs(100, 50, 200, 0.01, CLAW);
    moveSimple(30, 30, 90, RELDEG);
    moveArmAbs(100, 100, 1500, 0.01, LIFT);
    turn1Motor(60, 15, LEFT);
    turn1Motor(60, -15, LEFT);

}
