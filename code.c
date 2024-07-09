void code()
{
    // Collects the close red blocks
    startTask(armReset);

    moveSimple(30, 30, 90, RELDEG);
    turn1Motor(100, -95, RIGHT);
    resetRelative();
    setSpeed(0, 0);
    moveArmSimple(-100, 700, LIFT, TIME);
    resetArmAbs(LIFT);
    resetArm(LIFT);
    startTask(liftArmBeforeBlocks);
    stopTask(armReset);


    
    moveNoSyncAccParam(50, 50, 20, 50, 125, false, RELDEG);
    moveSenseOneSensorSimple(50, 50, 50, false, 3, BROWN, COLOR);
    moveNoSyncAccParam(50, 50, 50, 20, 85, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveSimple(12, 12, 60, RELDEG);
    moveArmAbsSimple(100, 330, LIFT);
    startTask(armDownForRed);
    moveSimple(-20, -20, 90, RELDEG);
    resetArm(CLAW);
    moveArmAbsSimple(100, -270, CLAW);
    
    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);
    sleep(240);

    moveSimple(100, 100, 200, RELDEG);
    moveSimple(20, 20, 40, RELDEG);

    moveArmAbsSimple(100, 330, LIFT);
    startTask(armDownForRed);
    moveSimple(-20, -20, 90, RELDEG);
    resetArm(CLAW);
    moveArmAbsSimple(100, -270, CLAW);
    
    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);



    // Goes to the far red blocks
    moveSimple(-100, -100, 150, RELDEG);

    turn1MotorAccMinspeed(100, 50, 100, 44, 0.4, 0.4, false, RIGHT)

    moveNoSyncParam(100, 100, 50, 100, 1700, 0.25, 0.25, false, RELDEG);

    turn2MotorAccMinspeed(100, 100, 50, 147, 0.4, 0.4, false);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -50, 500, true, TIME);
    setSpeed(0, 0);
    sleep(50);
    resetRelative();

    turn1Motor(100, 50, LEFT);
    turn1Motor(100, -60, RIGHT);

    moveSenseOneSensor(50, 50, 50, 0.4, 0, 0, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(50, 50, 50, 20, 85, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    // Collects the far red blocks

    resetArm(CLAW);
    moveSimple(12, 12, 60, RELDEG);
    moveArmAbsSimple(100, 330, LIFT);
    startTask(armDownForRed);
    moveSimple(-20, -20, 90, RELDEG);
    resetArm(CLAW);
    moveArmAbsSimple(100, -270, CLAW);
    
    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);
    sleep(240);

    moveSimple(100, 100, 200, RELDEG);
    moveSimple(20, 20, 40, RELDEG);

    moveArmAbsSimple(100, 330, LIFT);
    startTask(armDownForRed);
    moveSimple(-20, -20, 90, RELDEG);
    resetArm(CLAW);
    moveArmAbsSimple(100, -270, CLAW);
    
    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);
    sleep(240);

    moveSimple(-100, -100, 100, RELDEG);

    // Puts the red stack away
    
    turn1Motor(100, 100, RIGHT);
    moveSimpleWallSquare(-100, -100, 600, TIME);
    resetRelative();
    setSpeed(0, 0);
    
    moveNoSyncParam(100, 100, 50, 100, 650, 0.25, 0.25, false, RELDEG);
    turn1MotorAccMinspeed(100, 100, 100, 85, 0.4, 0.4, false, LEFT);
    moveSenseOneSensor(50, 50, 100, 0.4, 0, 0, true, 1, WHITE, COLOR);
    resetRelative();
    startTask(armDownToPlaceStack);
    moveSimple(-20, -20, 38, RELDEG);

    
    resetArm(CLAW);


    startTask(openClaw);
    sleep(200);
    moveNoSyncParam(-100, -100, 50, 100, 500, 0.25, 0.25, false, RELDEG);
    startTask(liftArmBeforeBlocks);
    turn1MotorAccMinspeed(100, 100, 100, -80, 0.4, 0.4, false, LEFT);

    moveNoSyncAccParamWallSquare(-100, -100, -100, -20, 1300, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Collects the far yellow blocks

    turn1Motor(100, 50, LEFT);
    turn1Motor(100, -54, RIGHT);
    return;

    moveSenseOneSensor(50, 50, 50, 0.4, 0, 0, false, 3, RED, COLOR);
    moveNoSyncAccParamWallSquare(50, 50, 50, 20, 235, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, 330, LIFT);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    moveSimple(12, 12, 45, RELDEG);
    moveSimple(-30, -30, 73, RELDEG);

    resetArm(CLAW);
    moveArmAbsSimple(100, -270, CLAW);
    
    moveArmAbsSimple(100, 5, LIFT);
    
    moveSimple(12, 12, 25, RELDEG);

    moveArmSimple(-100, 100, LIFT, TIME);
    setArmSpeed(CLAW, -100);
    sleep(400);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    for (int i=0; i<1; i++){
        moveSimple(31, 30, 215, RELDEG);

        moveArmAbsSimple(100, 330, LIFT);
        moveArmAbsSimple(100, armDegreeToPick, LIFT);

        moveSimple(12, 12, 45, RELDEG);
        moveSimple(-20, -20, 80, RELDEG);

        resetArm(CLAW);

        moveArmAbsSimple(100, armDegreeToDrop, LIFT);
        moveArmAbsSimple(100, -270, CLAW);
        
        moveArmAbsSimple(100, 5, LIFT);
        
        moveSimple(12, 12, 35, RELDEG);

        moveArmSimple(-100, 100, LIFT, TIME);
        setArmSpeed(CLAW, -100);
        sleep(400);
    }

    // Collects the debris and goes to the close yellow blocks
    moveArmSimple(100, 1000, LIFT, TIME);
    moveSenseOneSensor(30, 30, 20, 0.4, 0, 0, false, 2, BLUE, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(100, 100, 30, 20, 150, true, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, 100, LIFT);
    moveSimple(-80, -80, 250, RELDEG);
    turn1Motor(100, 111, RIGHT);
    moveSimpleWallSquare(-50, -50, 1000, TIME);
    resetRelative();
    setSpeed(0, 0);
    moveNoSyncMinspeedParam(100, 100, 1500, 0.2, 0.2, true, RELDEG);
    moveArmAbsSimple(100, 300, LIFT);
    
    turn1Motor(100, -180, RIGHT);
    moveArmAbsSimple(100, 150, LIFT);
    moveSimpleWallSquare(-100, -100, 800, TIME);
    resetRelative();
    setSpeed(0, 0);

    
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    turn1Motor(100, 50, LEFT);
    turn1Motor(100, -55, RIGHT);

    moveSenseOneSensor(50, 50, 50, 0.4, 0, 0, false, 3, RED, COLOR);
    moveNoSyncAccParamWallSquare(50, 50, 50, 20, 270, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    // Collects the close yellow blocks

    moveArmAbsSimple(100, 330, LIFT);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    moveSimple(12, 12, 45, RELDEG);
    moveSimple(-20, -20, 80, RELDEG);

    resetArm(CLAW);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, -270, CLAW);
    
    moveArmAbsSimple(100, 5, LIFT);
    
    moveSimple(12, 12, 25, RELDEG);

    moveArmSimple(-100, 100, LIFT, TIME);
    setArmSpeed(CLAW, -100);
    sleep(400);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    for (int i=0; i<1; i++){
        moveSimple(31, 30, 215, RELDEG);

        moveArmAbsSimple(100, 330, LIFT);
        moveArmAbsSimple(100, armDegreeToPick, LIFT);

        moveSimple(12, 12, 45, RELDEG);
        moveSimple(-20, -20, 80, RELDEG);

        resetArm(CLAW);

        moveArmAbsSimple(100, armDegreeToDrop, LIFT);
        moveArmAbsSimple(100, -270, CLAW);
        
        moveArmAbsSimple(100, 5, LIFT);
        
        moveSimple(12, 12, 35, RELDEG);

        moveArmSimple(-100, 100, LIFT, TIME);
        setArmSpeed(CLAW, -100);
        sleep(400);
        moveArmAbsSimple(100, armDegreeToPick, LIFT);
    }

    // Puts the stack in the yellow area

    moveSimple(-100, -100, 390, RELDEG);
    
    turn1Motor(100, 90, RIGHT);

    moveSimple(100, 100, 380, RELDEG);

    moveArmAbsSimple(100, 55, LIFT);
    
    resetArm(CLAW);

    moveArmAbsSimple(100, -270, CLAW);

    moveArmAbsSimple(100, 150, LIFT);

    // Goes to the close blue/green blocks

    moveSimpleWallSquare(-100, -100, 1000, TIME);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(LIFT, 0);

    turn1Motor(100, 50, LEFT);
    turn1Motor(100, -56, RIGHT);

    resetArm(LIFT);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    moveNoSyncAccParamWallSquare(50, 50, 50, 20, 480, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    // Collects the close blue.green blocks
    moveArmAbsSimple(100, 330, LIFT);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    moveSimple(12, 12, 60, RELDEG);
    moveSimple(-30, -30, 80, RELDEG);

    resetArm(CLAW);
    moveArmAbsSimple(100, -270, CLAW);
    
    moveArmAbsSimple(100, 5, LIFT);
    
    moveSimple(12, 12, 25, RELDEG);

    moveArmSimple(-100, 100, LIFT, TIME);
    setArmSpeed(CLAW, -100);
    sleep(400);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    for (int i=0; i<1; i++){
        moveSimple(33, 30, 215, RELDEG);

        moveArmAbsSimple(100, 330, LIFT);
        moveArmAbsSimple(100, armDegreeToPick, LIFT);

        moveSimple(12, 12, 45, RELDEG);
        moveSimple(-20, -20, 80, RELDEG);

        resetArm(CLAW);

        moveArmAbsSimple(100, armDegreeToDrop, LIFT);
        moveArmAbsSimple(100, -270, CLAW);
        
        moveArmAbsSimple(100, 5, LIFT);
        
        moveSimple(12, 12, 35, RELDEG);

        moveArmSimple(-100, 100, LIFT, TIME);
        setArmSpeed(CLAW, -100);
        sleep(400);
    }

    moveArmAbsSimple(100, 100, LIFT);

    // Goes to the water connection
    turn1Motor(100, 100, RIGHT);
    moveSimpleWallSquare(-50, -50, 1000, TIME);
    resetRelative();
    setSpeed(0, 0);
    moveNoSyncMinspeedParam(100, 100, 1350, 0.2, 0.2, true, RELDEG);
    turn1Motor(100, 87, RIGHT);


    // Water connection
    moveNoSyncAccParam(-100, -100, 20, 100, 400, false, RELDEG);
    moveSenseOneSensorSimple(-30, -30, 100, true, 3, RED, COLOR);
    moveSimple(30, 30, 100, RELDEG);
    turn1Motor(100, -90, LEFT);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 20, 300, false, RELDEG);
    setSpeed(0, 0);
    resetRelative();

    moveArm(100, 100, 30, 800, 0.4, 0.4, true, LIFT, TIME);

    moveSimple(40, 40, 900, RELDEG);
    turn2Motor(20, 90);
    moveSenseOneSensorSimple(-50, -50, 30, true, 1, WHITE, COLOR);

    moveArm(-100, 50, 50, 1000, 0.4, 0.4, true, LIFT, TIME);
    resetArm(LIFT);
    moveArmAbsSimple(100, 100, LIFT);

    // Collects the last green/blue blocks
    
    turn1Motor(50, 45, LEFT);
    turn1Motor(50, -45, RIGHT);
    moveArm(100, 100, 30, 800, 0.4, 0.4, true, LIFT, TIME);
    moveSimple(40, 40, 130, RELDEG);

    turn1Motor(50, 90, RIGHT);
    turn1Motor(50, -94, RIGHT);
    
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    moveSimple(50, 50, 240, RELDEG);


    moveArmAbsSimple(100, 330, LIFT);
    moveArmAbsSimple(100, armDegreeToPick+15, LIFT);

    moveSimple(12, 12, 45, RELDEG);
    moveSimple(-20, -20, 80, RELDEG);

    resetArm(CLAW);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, -270, CLAW);
    
    moveArmAbsSimple(100, 5, LIFT);
    
    moveSimple(12, 12, 35, RELDEG);

    moveArmSimple(-100, 100, LIFT, TIME);
    setArmSpeed(CLAW, -100);
    sleep(400);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    moveSimple(30, 34, 235, RELDEG);

    moveArmAbsSimple(100, 330, LIFT);
    moveArmAbsSimple(100, armDegreeToPick+15, LIFT);

    moveSimple(12, 12, 45, RELDEG);
    moveSimple(-20, -20, 80, RELDEG);

    resetArm(CLAW);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, -270, CLAW);
    
    moveArmAbsSimple(100, 5, LIFT);
    
    moveSimple(12, 12, 35, RELDEG);

    moveArmSimple(-100, 100, LIFT, TIME);
    setArmSpeed(CLAW, -100);
    sleep(400);

    moveArmSimple(100, 1000, LIFT, TIME);

    // Puts the last stack away

    turn1Motor(100, 155, RIGHT);
    moveNoSyncAccParam(40, 40, 20, 100, 1000, false, RELDEG);
    moveSenseOneSensorSimple(40, 40, 100, true, 2, BLACK, COLOR);

    moveNoSyncAccParam(30, -10, 20, 100, 100, false, RELDEG);
    moveSenseOneSensor(30, -10, 20, 0.4, 0, 0, true, 2, BLACK, COLOR);

    lineFollowTwoSensorStopOneSensor(50, 50, 0.4, 0.3, 20, true, 2, 3, 1, BLACK, COLOR);

    if (0)
    {
        moveSimple(-100, -100, 780, RELDEG);
    }
    else
    {
        moveSimple(-100, -100, 1130, RELDEG);
    }

    turn1Motor(100, 90, LEFT);
    moveSimple(100, 100, 30, RELDEG);

    moveArmAbsSimple(100, 55, LIFT);
    
    resetArm(CLAW);

    moveArmAbsSimple(100, -220, CLAW);
    

    setArmSpeed(LIFT, 50);

   moveArmAbsSimple(100, 110, LIFT);
    // Pushes the debris
    moveSimpleWallSquare(-100, -100, 1500, TIME);
    setSpeed(0, 0);
    sleep(50);
    resetRelative();
    turn1Motor(100, 60, RIGHT);
    moveSenseOneSensor(50, 50, 50, 0.4, 0, 0, true, 3, BLACK, COLOR);
    turn1Motor(100, 30, RIGHT);
    moveSenseOneSensor(50, 50, 50, 0.4, 0, 0, true, 2, RED, COLOR);
    turn1Motor(80, 62, RIGHT);
    turn1Motor(80, 40, LEFT);
    moveSimple(100, 100, 900, RELDEG);

    moveSimple(-100, -100, 500, RELDEG);
    turn1Motor(100, -90, RIGHT);
    moveSimpleWallSquare(-100, -100, 200, TIME);
    setSpeed(0, 0);
    sleep(50);
    resetRelative();
    moveSimple(100, 100, 795, RELDEG);
    turn1Motor(80, -89, RIGHT);
    moveArm(100, 100, 30, 800, 0.4, 0.4, true, LIFT, TIME);
    moveSenseOneSensor(-50, -50, 50, 0.4, 0, 0, true, 1, WHITE, COLOR);
    moveArm(-100, 50, 50, 1000, 0.4, 0.4, true, LIFT, TIME);
    resetArm(LIFT);
    moveArmAbsSimple(100, 100, LIFT);

}

void newCode()
{
    // Collects the close red blocks
    startTask(armReset);

    moveSimple(30, 30, 90, RELDEG);
    turn1Motor(100, -100, RIGHT);
    resetRelative();
    setSpeed(0, 0);
    moveArmSimple(-100, 700, LIFT, TIME);
    resetArmAbs(LIFT);
    startTask(liftArmForFirstBlock);
    stopTask(armReset);

    moveSenseOneSensorNoSync(30, 30, 20, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(15, 15, 30, 15, 50, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);
    sleep(240);

    // 2nd Block
    moveNoSyncAccParamWallSquare(40, 40, 20, 20, 145, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);

    // Goes to the far red blocks
    moveSimple(-100, -100, 150, RELDEG);

    turn1MotorAccMinspeed(100, 50, 100, 44, 0.4, 0.4, false, RIGHT)

    moveNoSyncParam(100, 100, 100, 100, 1700, 0.25, 0.25, false, RELDEG);

    turn2MotorAccMinspeed(100, 100, 20, 152, 0.4, 0.4, true);
    moveNoSyncAccParamWallSquare(-100, -100, -20, -50, 800, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);

    // Collects the far red blocks
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 40, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);
    sleep(240);

    // 2nd Block
    moveNoSyncAccParamWallSquare(40, 40, 20, 20, 132, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);

    // Puts the red stack away
    moveSimple(-100, -100, 100, RELDEG);
    
    turn1Motor(100, 95, RIGHT);
    moveSimpleWallSquare(-100, -100, 600, TIME);
    resetRelative();
    setSpeed(0, 0);
    
    moveNoSyncParam(100, 100, 20, 20, 830, 0.25, 0.25, false, RELDEG);

    turn1MotorAccMinspeed(100, 20, 20, 89, 0.4, 0.4, false, LEFT);

    moveSenseOneSensor(50, 50, 20, 0.4, 0, 0, false, 1, BLUE, COLOR);
    resetRelative();
    startTask(armDownToPlaceStack);
    moveNoSyncParam(50, 50, 50, 20, 365, 0.25, 0.25, true, RELDEG);
    resetRelative();

    startTask(openClawForPlacingStacks);
    sleep(200);
    moveNoSyncParam(-100, -100, 20, 20, 500, 0.25, 0.25, false, RELDEG);
    stopTask(openClawForPlacingStacks);
    startTask(liftArmForFirstBlock);
    turn1MotorAccMinspeed(100, 20, 20, -85, 0.4, 0.4, false, LEFT);

    moveNoSyncAccParamWallSquare(-100, -100, 20, 20, 1300, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);

    // Collects the far yellow blocks
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, RED, COLOR);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 250, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);
    sleep(240);

    // 2nd Block
    moveNoSyncAccParamWallSquare(40, 40, 20, 20, 137, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    setArmSpeed(LIFT, 100);

    // Gets the debris
    moveSenseOneSensor(100, 100, 20, 0.4, 0, 0, false, 2, BLUE, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(100, 100, 100, 20, 150, true, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, 160, LIFT);
    moveSimple(-80, -80, 250, RELDEG);
    turn1Motor(100, 111, RIGHT);
    moveSimpleWallSquare(-40, -40, 900, TIME);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(LIFT, 100);
    moveNoSyncMinspeedParam(100, 100, 1700, 0.2, 0.2, true, RELDEG);
    moveSimple(-100, -100, 200, RELDEG);
    
    startTask(liftArmBeforeBlocks);
    turn1Motor(100, -163, RIGHT);
    moveSimpleWallSquare(-40, -40, 1200, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Collects the close yellow blocks
    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, RED, COLOR);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 220, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 20, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);
    sleep(240);

    // 2nd Block
    moveNoSyncAccParamWallSquare(30, 30, 20, 20, 150, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 20, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);

    // Puts the yellow stack away
    moveNoSyncAccParamWallSquare(-100, -100, 20, 20, 360, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    
    turn1Motor(100, 92, RIGHT);

    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimple(100, 100, 400, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(200);

    startTask(liftArmForFirstBlock);

    // Collects to the close blue/green blocks

    moveSimpleWallSquare(-100, -100, 1000, TIME);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(LIFT, 0);

    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 490, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);
    sleep(240);

    // 2nd Block
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, BLACK, COLOR);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 25, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);

    // Goes to the last green/blue blocks
    turn1Motor(100, 100, RIGHT);
    moveSimpleWallSquare(-100, -100, 700, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Collects the last green/blue blocks
    moveNoSyncMinspeedParam(100, 100, 1615, 0.2, 0.2, true, RELDEG);
    turn1Motor(100, -280, LEFT);
	moveSenseOneSensorNoSync(50, 50, 20, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(50, 50, 50, 20, 325, false, RELDEG);
	resetRelative();
    setSpeed(0, 0);
	turn1Motor(30, 5, LEFT);

	moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);
    sleep(240);

	moveSenseOneSensorNoSync(-50, -50, 20, false, 1, RED, COLOR);
    moveNoSyncAccParamWallSquare(-50, -50, 50, 20, 90, true, RELDEG);
	turn1Motor(100, 92, LEFT);

	moveSimpleWallSquare(-100, -100, 700, TIME);
    resetRelative();
    setSpeed(0, 0);

    // 2nd Block
	moveSimple(40, 40, 410, RELDEG);
	turn1Motor(50, 270, LEFT);

	moveSenseOneSensorSimple(30, 30, 20, false, 1, BROWN, COLOR);
	resetRelative();
    moveNoSyncAccParam(30, 30, 30, 20, 85, true, RELDEG);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);

    // Puts the stack away
    moveSenseOneSensorSimple(-50, -50, 20, false, 3, RED, COLOR);
    if (GREEN == GREEN)
    {
        moveNoSyncAccParam(-50, -50, 50, 20, 150, true, RELDEG);
    }
    else
    {
        moveNoSyncAccParam(-50, -50, 50, 20, 320, true, RELDEG);
    }
    
	turn1Motor(100, -90, RIGHT);

    moveSimpleWallSquare(-100, -100, 700, TIME);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimple(100, 100, 600, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(200);

    startTask(liftArmForFirstBlock);

    // Goes to the water connection
    moveSimpleWallSquare(-100, -100, 1000, TIME);
    resetRelative();
    setSpeed(0, 0);
    
	turn1Motor(100, 93, LEFT);
    moveSenseOneSensorSimple(-50, -50, 20, false, 3, RED, COLOR);
    moveNoSyncAccParam(-50, -50, 50, 20, 400, true, RELDEG);
    
	turn1Motor(100, -90, LEFT);
    moveSimpleWallSquare(-50, -50, 500, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Does the water connection
    stopTask(liftArmForFirstBlock);
    setArmSpeed(LIFT, 100);
    moveSimple(40, 40, 895, RELDEG);
    resetRelative();
    turn2Motor(20, 89);
    resetRelative();
    moveSenseOneSensorSimple(-30, -30, 30, true, 1, WHITE, COLOR);
    moveArmAbsSimple(100, 190, LIFT);

    // Puts the debris away
    turn1Motor(100, 45, LEFT);
	turn1Motor(100, -45, RIGHT);
	moveSimple(100, 100, 200, RELDEG);
	turn1Motor(100, 120, RIGHT);
	moveSimple(100, 100, 300, RELDEG);
	turn1Motor(100, 40, RIGHT);
	moveSimple(100, 100, 500, RELDEG);
	turn1Motor(50, 36, LEFT);
	moveNoSyncAccParamWallSquare(60, 60, 12, 100, 400, false, RELDEG);
	moveSenseOneSensor(100, 100, 100, 0.4, 0, 0, false, 2, RED, COLOR);
	moveNoSyncAccParamWallSquare(60, 100, 12, 100, 1350, false, RELDEG);
	resetRelative();
    setSpeed(0, 0);

    // Does the last water connection
    moveSimple(-100, -100, 600, RELDEG);
    turn1Motor(100, 90, LEFT);
    moveSimpleWallSquare(-100, -100, 800, TIME);
    setSpeed(0, 0);
    sleep(50);
    resetRelative();
    moveSimple(100, 100, 795, RELDEG);
    turn1Motor(80, -89, RIGHT);
    moveArm(100, 100, 30, 800, 0.4, 0.4, true, LIFT, TIME);
    moveSenseOneSensor(-50, -50, 50, 0.4, 0, 0, true, 1, WHITE, COLOR);
    moveArm(-100, 50, 50, 1000, 0.4, 0.4, true, LIFT, TIME);
    resetArm(LIFT);
    moveArmAbsSimple(100, 100, LIFT);
}