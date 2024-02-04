// Function that has the code for the close starting loop
void loop1CloseStart()
{
    // Gets into position to collect the blocks on the close side
    moveArmAbs(100, 5, 620, 0.01, LIFT);
    moveArmAbs(50, 5, 450, 0.01, CLAW);
    turn1Motor(50, -50, LEFT);
    turn1Motor(50, -56, RIGHT);
    moveSimple(50, 50, 100, RELDEG);
    moveSenseSimple(30, 30, RED, 3, COLOR);
    moveSimple(-50, -50, 30, RELDEG);

    // Moves the claw to slide the red blocks to the left side
    moveArmAbs(30, 5, 150, 0.01, CLAW);
    moveArmAbs(50, 5, 450, 0.01, CLAW);

    // Goes and does the same thing to the second red block
    moveSimple(50, 50, 182, RELDEG);
    moveArmAbs(30, 5, 150, 0.01, CLAW);
    moveArmAbs(50, 5, 450, 0.01, CLAW);

    // Collects the yellow blocks
    moveSimple(50, 50, 480, RELDEG);
    moveArmAbs(100, 15, 520, 0.01, LIFT);
    moveArm(100, 15, 700, 0.01, CLAW, TIME);

    // Moves to the yellow area
    moveSimple(-50, -50, 345, RELDEG);
    turn1Motor(50, 95, RIGHT);
    moveSimple(-50, -50, 800, TIME);
    moveSimple(50, 50, 367, RELDEG);
    lineFollowSimple(20, 333, 50, 1, 2, RELDEG);
    moveSimple(50, 50, 233, RELDEG);

    // Lifts the red and yellow block in the front and stacks them on top of the ones in the back
    moveArmAbs(100, 15, 920, 0.01, LIFT);
    moveSimple(-50, -50, 100, RELDEG);
    moveArmAbs(70, 15, 450, 0.01, CLAW);

    // Line follows to the first debris
    moveSenseSimple(-50, -50, BLACK, 3, COLOR);
    turn2Motor(25, 100);
    // While line following, also sense the two blocks
    lineFollowSense(50, 15, BLACK, 50, 0.02, -0.4, -25, 1, 2, COLOR);
    turn1Motor(50, -90, LEFT);
    moveSimple(-50, -50, 1000, TIME);
    moveSimple(50, 50, 1200, RELDEG);

    // Goes the the water connection
    turn1Motor(50, -90, RIGHT);
    moveArmAbs(100, 15, 1740, 0.01, LIFT);
    moveSimple(50, 50, 652, RELDEG);
    moveSenseSimple(15, 15, WHITE, 2, COLOR); // Goes until white for consistency

    // Uses the claw to do the water connection
    moveSimple(-50, -50, 200, RELDEG);
    moveArmAbs(100, 15, 740, 0.01, LIFT);
    moveArmAbs(70, 15, 200, 0.01, CLAW);
    moveSimple(50, 50, 110, RELDEG);
    moveArmAbs(100, 15, 1500, 0.01, LIFT);
    turn1Motor(50, 20, LEFT);
    turn1Motor(50, -20, LEFT);
    turn2Motor(25, -90);

    // Collects the other debris
    moveSimple(50, 50, 185, RELDEG);
    turn2Motor(25, -90);
    
    // Places the two debris near the other two debris
    moveSimple(50, 50, 700, RELDEG);
    turn1Motor(50, 60, LEFT);
    turn1Motor(50, 60, RIGHT);
    moveSimple(50, 50, 1100, RELDEG);

    // Gets into position for the red and yellow blocks on the far side
    moveSenseSimple(-50, -50, RED, 3, COLOR);
    turn1Motor(50, -90, LEFT);
    moveSimple(-100, -100, 800, TIME);
    moveArmAbs(100, 15, 620, 0.01, LIFT);
    moveArmAbs(70, 15, 450, 0.01, CLAW);
    turn1Motor(50, 42, LEFT);
    turn1Motor(50, -59, RIGHT);
    moveSenseSimple(30, 30, RED, 3, COLOR);

    // Collects the red blocks
    moveSimple(50, 50, 390, RELDEG);

    // Uses the claw to sort the yellow blocks
    moveArmAbs(50, 15, 100, 0.01, CLAW);
    moveArmAbs(70, 15, 450, 0.01, CLAW);
    moveSimple(50, 50, 182, RELDEG);
    moveArmAbs(50, 15, 170, 0.01, CLAW);
    moveArmAbs(70, 15, 450, 0.01, CLAW);
    moveSimple(50, 50, 180, RELDEG);

    // Grabs the blocks to make sure they don't move away
    moveArmAbs(100, 15, 520, 0.01, LIFT);
    moveArm(100, 15, 700, 0.01, CLAW, TIME);

    // Stacks the red and yellow blocks
    moveSimple(-50, -50, 105, RELDEG);
    turn1Motor(50, 98, RIGHT);
    moveArmAbs(100, 15, 940, 0.01, LIFT);
    moveSimple(-50, -50, 100, RELDEG);
    moveArmAbs(70, 15, 0, 0.01, CLAW);
    moveSimple(-50, -50, 1000, TIME);
    
    // Moves to the place where the other stack of red and yellow blocks are and stacks both stacks to get a stack of 4
    moveSimple(20, 20, 750, RELDEG);
    moveArmAbs(100, 15, 520, 0.01, LIFT);
    moveArm(100, 15, 2000, 0.01, CLAW, TIME);
    moveArmAbs(100, 15, 1380, 0.01, LIFT);
    moveSimple(-20, -20, 80, RELDEG);
    moveArmAbs(20, 15, 0, 0.01, CLAW);

    // Collects the next debris
    moveSimple(-50, -50, 2000, TIME);
    moveArmAbs(100, 15, 520, 0.01, LIFT);
    moveArmAbs(70, 15, 450, 0.01, CLAW);
    turn1Motor(50, 42, LEFT);
    turn1Motor(50, -59, RIGHT);
    moveSenseSimple(30, 30, GREEN, 3, COLOR);
    moveSimple(50, 50, 390, RELDEG);
    moveArm(100, 15, 1000, 0.01, CLAW, TIME);
    moveArmAbs(100, 15, 1300, 0.01, LIFT);

    // Pushes all the debris to a place near the starting area
    moveSimple(-50, -50, 190, RELDEG);
    turn1Motor(50, 98, RIGHT);
    moveSimple(-50, -50, 1000, TIME);
    moveSimple(50, 50, 1300, RELDEG);
    moveArmAbs(70, 15, 450, 0.01, CLAW);

    // Positions to move the red stack to the red area
    moveSimple(-50, -50, 400, RELDEG);
    moveArmAbs(100, 15, 520, 0.01, LIFT);
    turn2Motor(25, -90);
    moveSimple(30, 30, 145, RELDEG);

    // Moves the red stack over
    moveArm(100, 15, 1000, 0.01, CLAW, TIME);
    moveSimple(-10, -10, 295, RELDEG);
    moveArmAbs(70, 15, 450, 0.01, CLAW);

    // Maneuvers back to the debris
    moveSimple(-10, -10, 95, RELDEG);
    turn1Motor(50, -45, RIGHT);
    turn1Motor(50, 45, LEFT);
    moveArmAbs(100, 15, 1300, 0.01, LIFT);
    turn1Motor(50, 85, RIGHT);
    turn1Motor(50, 85, LEFT);
    moveSimple(50, 50, 400, RELDEG);

    // Pushes the debris into the collection area
    turn1Motor(50, -160, RIGHT);
    turn1Motor(50, -75, LEFT);
    moveSimple(50, 50, 1500, RELDEG);
    moveSimple(-50, -50, 500, RELDEG);

    // Positions the robot for the water connections
    turn1Motor(50, 95, LEFT);
    moveSimple(-50, -50, 1000, TIME);
    moveSimple(50, 50, 530, RELDEG);
    turn2Motor(25, -90);
    moveSenseSimple(15, 15, WHITE, 2, COLOR);

    // Does the other water connection
    moveSimple(-50, -50, 200, RELDEG);
    moveArmAbs(100, 15, 740, 0.01, LIFT);
    moveArmAbs(70, 15, 200, 0.01, CLAW);
    moveSimple(50, 50, 110, RELDEG);
    moveArmAbs(100, 15, 1500, 0.01, LIFT);
    turn1Motor(50, 20, LEFT);
    turn1Motor(50, -20, LEFT);





}