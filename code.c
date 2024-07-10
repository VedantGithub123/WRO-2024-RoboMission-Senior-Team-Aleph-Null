void closeCode()
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
    
    moveNoSyncParam(100, 100, 20, 20, 845, 0.25, 0.25, false, RELDEG);

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
    moveNoSyncMinspeedParam(100, 100, 1630, 0.2, 0.2, true, RELDEG);
    moveSimple(-100, -100, 70, RELDEG);
    
    startTask(liftArmBeforeBlocks);
    turn1Motor(100, -170, RIGHT);
    moveSimpleWallSquare(-40, -40, 700, TIME);
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
    startTask(liftArmForFarGreenBlue);

    // Goes to the last green/blue blocks
    turn1Motor(100, 100, RIGHT);
    moveSimpleWallSquare(-100, -100, 700, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Collects the last green/blue blocks
    moveNoSyncMinspeedParam(100, 100, 1615, 0.2, 0.2, true, RELDEG);
    turn1Motor(100, -280, LEFT);
	moveSenseOneSensorNoSync(50, 50, 20, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(47, 50, 50, 20, 325, false, RELDEG);
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

	moveSenseOneSensorNoSync(-50, -40, 20, false, 1, RED, COLOR);
    moveNoSyncAccParamWallSquare(-50, -40, 50, 20, 140, true, RELDEG);
	turn1Motor(100, 100, LEFT);

	moveSimpleWallSquare(-100, -100, 700, TIME);
    resetRelative();
    setSpeed(0, 0);

    // 2nd Block
    sleep(200);
    resetRelative();
	moveSimple(30, 30, 430, RELDEG);
    getGreen(4);
    sleep(300);

    int baseColor = BLUE;
    if ((getGreen(4)>=3 || getBlue(4)<=3) && getBlue(4)<getGreen(4)+1)
    {
        playSound(soundBeepBeep);
        baseColor = GREEN;
    }

    stoppingTime = 6000;
	turn1Motor(40, 270, LEFT);
    stoppingTime = 3000;

	moveSenseOneSensorSimple(30, 30, 20, false, 1, BROWN, COLOR);
	resetRelative();
    moveNoSyncAccParam(30, 30, 30, 12, 215, true, RELDEG);
    moveSimple(-20, -20, 85, RELDEG);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen-10, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);

    // Puts the stack away
    moveSenseOneSensorSimple(-100, -100, 20, false, 3, RED, COLOR);
    if (baseColor == GREEN)
    {
        moveNoSyncAccParam(-100, -100, 100, 20, 130, true, RELDEG);
    }
    else
    {
        moveNoSyncAccParam(-100, -100, 100, 20, 520, true, RELDEG);
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
    moveSenseOneSensorSimple(-100, -100, 20, false, 3, RED, COLOR);
    moveNoSyncAccParam(-100, -100, 50, 20, 370, true, RELDEG);
    
	turn1Motor(100, -90, LEFT);
    moveSimpleWallSquare(-100, -100, 400, TIME);
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
	turn1Motor(100, -50, RIGHT);
	moveSimple(100, 100, 250, RELDEG);
    turn1Motor(100, 95, RIGHT);
	moveSimple(100, 100, 230, RELDEG);
    turn1Motor(100, 90, RIGHT);
	moveSimple(100, 100, 750, RELDEG);
    turn1Motor(50, 70, LEFT);

	moveNoSyncAccParamWallSquare(40, 40, 12, 100, 400, false, RELDEG);
	moveSenseOneSensor(60, 60, 60, 0.4, 0, 0, false, 3, WHITE, COLOR);
	moveNoSyncAccParamWallSquare(80, 100, 100, 50, 950, false, RELDEG);
	resetRelative();
    setSpeed(0, 0);

    // Does the last water connection
    moveSimple(-100, -100, 600, RELDEG);
    turn1Motor(100, 90, LEFT);
    moveSimpleWallSquare(-100, -100, 800, TIME);
    setSpeed(0, 0);
    sleep(50);
    resetRelative();
    setArmSpeed(LIFT, 100);
    moveSimple(40, 40, 870, RELDEG);
    turn1Motor(50, -90, RIGHT);
    moveSenseOneSensor(-50, -50, 50, 0.4, 0, 0, true, 1, WHITE, COLOR);
    setArmSpeed(LIFT, -100);
    sleep(500);
    setArmSpeed(LIFT, 0);
}

void farCode()
{
    // Goes to the far red blocks
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
    moveNoSyncAccParamWallSquare(15, 15, 30, 15, 60, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    // Collects the far red blocks
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

    // Goes to close red blocks
    moveSimple(-100, -100, 150, RELDEG);

    turn1MotorAccMinspeed(100, 50, 100, 44, 0.4, 0.4, false, RIGHT);

    moveNoSyncParam(100, 100, 100, 100, 1700, 0.25, 0.25, false, RELDEG);

    turn2MotorAccMinspeed(100, 100, 20, 152, 0.4, 0.4, true);
    moveNoSyncAccParamWallSquare(-100, -100, -20, -50, 800, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);

    moveSenseOneSensorNoSync(30, 30, 20, false, 3, RED, COLOR);
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 40, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    // Collects the close red blocks
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
    moveSimple(-80, -80, 350, RELDEG);
    
   turn1Motor(100, 92, RIGHT);

    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimple(100, 100, 400, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(200);

    startTask(liftArmForFirstBlock);
    moveSimpleWallSquare(-100, -100, 1000, TIME);

    // Collects the close yellow blocks
    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);
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
    startTask(liftArmBeforeBlocks);

    // Goes the the far yellow blocks
    turn1Motor(100, 90, RIGHT);
    turn2Motor(40, -170);
    moveNoSyncAccParam(-100, -100, 20, 100, 1500, false, RELDEG);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 20, 400, false, TIME);
    resetRelative();
    setSpeed(0, 0);
    
    // Collects the far yellow blocks
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
    turn1Motor(50, 92, RIGHT);
    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimple(100, 100, 400, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(200);
    startTask(liftArmForFirstBlock);
    moveSimple(-40, -40, 100, RELDEG);
    turn1Motor(100, -15, RIGHT);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 20, 800, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Collects the far green/blue blocks
     turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 280, false, RELDEG);
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
    setArmSpeed(LIFT, 100);
    sleep(150);
    moveSimple(100, 100, 450, RELDEG);


    // Collects the debris
    moveArmAbsSimple(100, 160, LIFT);
    moveSimple(-80, -80, 250, RELDEG);
    turn1Motor(100, 111, RIGHT);
    moveSimpleWallSquare(-40, -40, 900, TIME);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(LIFT, 100);
    moveNoSyncMinspeedParam(100, 100, 1630, 0.2, 0.2, true, RELDEG);
    moveSimple(-100, -100, 70, RELDEG);
    
    startTask(liftArmBeforeBlocks);
    turn1Motor(100, -170, RIGHT);
    moveSimpleWallSquare(-40, -40, 700, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Goes to the last green/blue blocks
	turn1Motor(100, 52, LEFT);
	startTask(liftArmForFarGreenBlue);
	moveSimple(100, 100, 1400, RELDEG);
	turn1Motor(100, 130, LEFT);
	moveSimpleWallSquare(-100, -100, 1600, TIME);
    resetRelative();
    setSpeed(0, 0);
	turn1Motor(100, 42, RIGHT);
    turn1Motor(100, -55, LEFT);
}

