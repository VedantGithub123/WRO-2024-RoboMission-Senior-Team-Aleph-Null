

void code()
{
//     // Collects the close red blocks
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
    
    moveArmSimple(-100, 300, LIFT, TIME);
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
    
    moveArmSimple(-100, 300, LIFT, TIME);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);
    sleep(240);



    // moveSimple(12, 12, 45, RELDEG);
    // moveSimple(-30, -30, 70, RELDEG);

    // moveArmAbsSimple(100, -270, CLAW);
    
    // moveArmAbsSimple(100, 5, LIFT);
    
    // moveSimple(12, 12, 25, RELDEG);

    // moveArmSimple(-100, 100, LIFT, TIME);
    // setArmSpeed(CLAW, -100);
    // sleep(400);
    // moveArmAbsSimple(100, armDegreeToPick, LIFT);

    // for (int i=0; i<1; i++){
    //     moveSimple(33, 30, 215, RELDEG);

    //     moveArmAbsSimple(100, 330, LIFT);
    //     moveArmAbsSimple(100, armDegreeToPick, LIFT);

    //     moveSimple(12, 12, 45, RELDEG);
    //     moveSimple(-20, -20, 80, RELDEG);

    //     resetArm(CLAW);

    //     moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    //     moveArmAbsSimple(100, -270, CLAW);
        
    //     moveArmAbsSimple(100, 5, LIFT);
        
    //     moveSimple(12, 12, 35, RELDEG);

    //     moveArmSimple(-100, 100, LIFT, TIME);
    //     setArmSpeed(CLAW, -100);
    //     sleep(400);
    //     moveArmAbsSimple(100, armDegreeToPick, LIFT);
    // }
    return;

    // Goes to the far red blocks
    moveSimple(-50, -50, 150, RELDEG);

    turn1Motor(100, 46, RIGHT);

    moveNoSyncMinspeedParam(100, 100, 2000, 0.25, 0.25, true, RELDEG);
    turn2Motor(100, 135);

    moveSimpleWallSquare(-50, -50, 800, TIME);
    setSpeed(0, 0);
    sleep(50);
    resetRelative();

    turn1Motor(100, 50, LEFT);
    turn1Motor(100, -60, RIGHT);

    moveSenseOneSensor(50, 50, 50, 0.4, 0, 0, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(50, 50, 50, 20, 85, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    clearTimer(T1);
    // Collects the far red blocks

    resetArm(CLAW);

    moveArmAbsSimple(100, 330, LIFT);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

    moveSimple(12, 12, 45, RELDEG);
    moveSimple(-20, -20, 90, RELDEG);

    resetArm(CLAW);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, -270, CLAW);
    
    moveArmAbsSimple(100, 5, LIFT);
    
    moveSimple(12, 12, 35, RELDEG);

    moveArmSimple(-100, 100, LIFT, TIME);
    setArmSpeed(CLAW, -100);
    sleep(400);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

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
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    moveSimple(-100, -100, 100, RELDEG);

    // Puts the red stack away
    
    turn1Motor(100, 100, RIGHT);
    moveSimpleWallSquare(-50, -50, 1000, TIME);
    resetRelative();
    setSpeed(0, 0);
    
    moveSimple(100, 100, 720, RELDEG);
    turn1Motor(100, 85, LEFT);
    moveSenseOneSensor(50, 50, 50, 0.4, 0, 0, true, 1, WHITE, COLOR);
    moveSimple(-20, -20, 38, RELDEG);
    moveArmAbsSimple(100, 55, LIFT);
    
    resetArm(CLAW);

    moveArmAbsSimple(100, -270, CLAW);
    

    moveSimple(-100, -100, 500, RELDEG);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    turn1Motor(100, -90, LEFT);

    moveSimpleWallSquare(-100, -100, 1300, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Collects the far yellow blocks

    turn1Motor(100, 50, LEFT);
    turn1Motor(100, -54, RIGHT);

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

