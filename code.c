void end()
{
    moveSenseOneSensorNoSync(47, 50, 20, false, 3, RED, COLOR);
    moveSenseOneSensorNoSync(47, 50, 20, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(28, 30, 50, 15, 323, false, RELDEG);
	resetRelative();
    setSpeed(0, 0);
	turn1Motor(30, 8, LEFT);

	moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmForFarGreenBlue2);

	moveSenseOneSensorNoSync(-50, -40, 20, false, 1, RED, COLOR);
    moveNoSyncAccParamWallSquare(-50, -40, 50, 20, 125, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
	turn1Motor(100, 102, LEFT);

	moveSimpleWallSquare(-60, -60, 1100, TIME);
    resetRelative();
    setSpeed(0, 0);

    // 2nd Block
    sleep(100);
    resetRelative();
    moveNoSyncMinspeedParam(30, 30, 405, 0.15, 0.2, true, RELDEG);
    getGreen(4);
    sleep(100);

    int baseColor = BLUE;
    if (getGreen(4)>=getBlue(4) || getBlue(4)<getGreen(4)+2)
    {
        playSound(soundBeepBeep);
        baseColor = GREEN;
    }

    stoppingTime = 9000;
	turn1MotorAcc(60, 272, 0.15, 0.2, LEFT);
    stoppingTime = 3000;

    resetRelative();
	moveSenseOneSensorSimple(30, 30, 20, false, 1, BROWN, COLOR);
	resetRelative();
    moveNoSyncAccParam(30, 30, 30, 12, 215, true, RELDEG);
    moveSimple(-20, -20, 80, RELDEG);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen-10, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);

    // Puts the stack away
    moveSenseOneSensorSimple(-100, -100, 20, false, 3, WHITE, COLOR);
    if (baseColor == GREEN)
    {
        moveNoSyncAccParam(-100, -100, 100, 20, 120, true, RELDEG);
    }
    else
    {
        moveNoSyncAccParam(-100, -100, 100, 20, 470, true, RELDEG);
    }
    
	turn1Motor(100, -90, RIGHT);

    moveSimpleWallSquare(-100, -100, 700, TIME);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimple(100, 100, 600, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(100);

    startTask(liftArmForFirstBlock);

    // Goes to the water connection
    moveSimpleWallSquare(-100, -100, 1000, TIME);
    resetRelative();
    setSpeed(0, 0);
    
	turn1Motor(100, 93, LEFT);
    moveSenseOneSensorSimple(-100, -100, 20, false, 3, RED, COLOR);
    moveNoSyncAccParam(-100, -100, 100, 20, 370, true, RELDEG);
    
	turn1Motor(100, -90, LEFT);
    moveSimpleWallSquare(-100, -100, 400, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Does the water connection
    stopTask(liftArmForFirstBlock);
    setArmSpeed(LIFT, 100);
    moveSimple(40, 40, 900, RELDEG);
    resetRelative();
    turn2Motor(20, 89);
    resetRelative();
    moveSenseOneSensorSimple(-30, -30, 30, true, 1, WHITE, COLOR);
    moveArmAbsSimple(100, 190, LIFT);

    // Puts the debris away
    turn1Motor(100, 45, LEFT);
	turn1Motor(100, -50, RIGHT);

    moveNoSyncParam(100, 100, 20, 50, 250, 0.4, 0.4, false, RELDEG);
    turn1MotorAccMinspeed(100, 50, 50, 95, 0.4, 0.4, false, RIGHT);
    moveNoSyncParam(100, 100, 50, 50, 250, 0.4, 0.4, false, RELDEG);
    turn1MotorAccMinspeed(100, 50, 50, 90, 0.4, 0.4, false, RIGHT);
    moveNoSyncParam(100, 100, 50, 50, 750, 0.4, 0.4, false, RELDEG);
    turn1MotorAccMinspeed(100, 50, 40, 70, 0.4, 0.4, false, LEFT);

	moveNoSyncAccParamWallSquare(40, 40, 12, 100, 400, false, RELDEG);
	moveSenseOneSensor(60, 60, 60, 0.4, 0, 0, false, 3, WHITE, COLOR);
	moveNoSyncAccParamWallSquare(80, 100, 100, 50, 950, false, RELDEG);
	resetRelative();
    setSpeed(0, 0);

    // Does the last water connection
    moveSimple(-100, -90, 600, RELDEG);
    turn1Motor(100, 90, LEFT);
    moveSimpleWallSquare(-100, -100, 800, TIME);
    setSpeed(0, 0);
    sleep(50);
    resetRelative();
    setArmSpeed(LIFT, 100);
    moveNoSyncMinspeedParam(40, 40, 875, 0.2, 0.2, true, RELDEG);
	turn1MotorAcc(80, -90.5, 0.2, 0.2, RIGHT);
	moveNoSyncAccParamWallSquare(-50, -50, 12, 30, 250, false, RELDEG);
    moveSenseOneSensor(-30, -30, 30, 0.3, 0, 0, true, 1, WHITE, COLOR);
    setArmSpeed(LIFT, -100);
    sleep(500);
    setArmSpeed(LIFT, 0);
}

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
    moveNoSyncAccParamWallSquare(15, 15, 30, 15, 65, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(150);

    // 2nd Block
    moveNoSyncAccParamWallSquare(40, 40, 20, 20, 145, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
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
    startTask(liftArmBeforeBlocks);
    sleep(150);

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
    moveNoSyncParam(-100, -100, 100, 100, 100, 0.4, 0.4, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    
    turn1MotorAccMinspeed(100, 100, 20, 95, 0.4, 0.4, false, RIGHT);

    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 600, false, TIME);
    resetRelative();
    setSpeed(0, 0);
    
    moveNoSyncParam(100, 100, 100, 60, 845, 0.4, 0.4, false, RELDEG);

    turn1MotorAccMinspeed(100, 60, 60, 87, 0.4, 0.4, false, LEFT);

    moveSenseOneSensor(100, 100, 60, 0.4, 0, 0, false, 1, BLUE, COLOR);
    resetRelative();
    startTask(armDownToPlaceStack);
    moveNoSyncParam(100, 100, 100, 30, 370, 0.4, 0.2, true, RELDEG);
    resetRelative();

    startTask(openClawForPlacingStacks);
    sleep(100);
    moveNoSyncParam(-100, -100, 60, 60, 500, 0.25, 0.4, false, RELDEG);
    stopTask(openClawForPlacingStacks);
    startTask(liftArmForFirstBlock);
    turn1MotorAccMinspeed(100, 60, 60, -85, 0.4, 0.4, false, LEFT);

    moveNoSyncAccParamWallSquare(-100, -100, 60, 60, 900, false, TIME);
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
    startTask(liftArmBeforeBlocks);
    sleep(150);

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
    setArmSpeed(LIFT, 100);

    // Gets the debris
    moveSenseOneSensor(100, 100, 20, 0.4, 0, 0, false, 2, BLUE, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(100, 100, 100, 20, 150, true, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, 160, LIFT);
    moveSimple(-100, -100, 250, RELDEG);
    turn1Motor(100, 111, RIGHT);
    moveSimpleWallSquare(-40, -40, 900, TIME);

    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(LIFT, 100);
    moveNoSyncMinspeedParam(100, 100, 1630, 0.4, 0.4, true, RELDEG);
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
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 225, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 20, RELDEG);
    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(150);

    // 2nd Block
    moveNoSyncAccParamWallSquare(30, 30, 20, 20, 158, false, RELDEG);
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
    moveNoSyncAccParamWallSquare(-100, -100, 100, 20, 360, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    
    turn1Motor(100, 92, RIGHT);

    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimple(100, 100, 400, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(100);

    startTask(liftArmForFirstBlock);

    // Collects to the close blue/green blocks
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 800, false, TIME);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(LIFT, 0);

    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 490, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(150);

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
    startTask(liftArmForFarGreenBlue);

    // Goes to the last green/blue blocks
    turn1Motor(100, 100, RIGHT);
    moveSimpleWallSquare(-100, -100, 700, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Collects the last green/blue blocks
    moveNoSyncMinspeedParam(100, 100, 1615, 0.4, 0.4, true, RELDEG);
    turn1Motor(100, -283, LEFT);
    end();
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

    moveSenseOneSensorNoSync(20, 20, 20, false, 3, BROWN, COLOR);
    moveNoSyncAccParamWallSquare(15, 15, 20, 15, 75, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    // Collects the far red blocks
    setArmSpeed(CLAW, -100);
    sleep(200);
    startTask(liftArmBeforeBlocks);
    sleep(240);

    // 2nd Block
    moveNoSyncAccParamWallSquare(30, 30, 15, 15, 150, false, RELDEG);
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

    // Goes to close red blocks
    moveSimple(-100, -100, 300, RELDEG);

    turn1MotorAccMinspeed(100, 50, 100, 47, 0.4, 0.4, false, RIGHT);

    moveNoSyncParam(100, 100, 100, 100, 1800, 0.25, 0.25, false, RELDEG);

    turn2MotorAccMinspeed(100, 100, 20, 152, 0.4, 0.4, true);
    moveNoSyncAccParamWallSquare(-100, -100, -20, -50, 800, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);

    moveSimple(100, 100, 20, RELDEG);
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
    moveNoSyncParam(-70, -100, 20, 50, 420, 0.4, 0.4, false, RELDEG);
    turn1Motor(100, 115, RIGHT); 

    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimple(100, 100, 340, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(200);

    startTask(liftArmForFirstBlock);
    moveSimpleWallSquare(-100, -100, 1000, TIME);

    // Collects the close yellow blocks
    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, BROWN, COLOR);
    moveSenseOneSensorNoSync(30, 30, 30, false, 3, RED, COLOR);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 250, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    //sleep(200);
    startTask(liftArmBeforeBlocks);
    sleep(150);

    // 2nd Block
    moveNoSyncAccParamWallSquare(30, 30, 15, 15, 148, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    //sleep(100);
    startTask(liftArmBeforeBlocks);

    // Goes the the far yellow blocks
    turn1Motor(100, 90, RIGHT);
    turn2Motor(40, -170);
    moveNoSyncAccParam(-100, -100, 20, 50, 1500, false, RELDEG);
    moveNoSyncAccParamWallSquare(-50, -50, 50, 20, 400, false, TIME);
    resetRelative();
    setSpeed(0, 0);
    
    // Collects the far yellow blocks
    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, BROWN, COLOR);
    sleep(100);
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, RED, COLOR);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 225, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(15, 15, 20, RELDEG);
    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(150);

    // 2nd Block
    moveNoSyncAccParamWallSquare(30, 30, 20, 20, 155, false, RELDEG);
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
    turn1Motor(50, 95, RIGHT);
    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimple(100, 100, 400, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(100);
    startTask(liftArmForFirstBlock);
    moveSimple(-40, -40, 100, RELDEG);
    turn1Motor(100, -20, RIGHT);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 20, 800, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Collects the far green/blue blocks
    turn1Motor(100, 42, LEFT);
    turn1Motor(100, -55, RIGHT);
    moveSenseOneSensorNoSync(20, 20, 20, false, 3, BLACK, COLOR);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(liftArmBeforeBlocks);
    sleep(300);

    // 2nd Block
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 85, false, RELDEG);
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
    moveSimple(100, 100, 470, RELDEG);


    // Collects the debris
    moveArmAbsSimple(100, 160, LIFT);
    moveSimple(-80, -80, 270, RELDEG);
    turn1Motor(100, 108, RIGHT);
    moveSimpleWallSquare(-70, -70, 1200, TIME);
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
    turn1MotorAccMinspeed(100, 50, 50, 52, 0.4, 0.4, false, LEFT);
    moveNoSyncParam(100, 100, 20, 50, 1100, 0.4, 0.4, false, RELDEG);
    turn1MotorAccMinspeed(100, 50, 50, 130, 0.4, 0.4, false, LEFT);
    moveNoSyncParam(-100, -100, -20, -50, 850, 0.4, 0.4, false, RELDEG);
	moveNoSyncAccParamWallSquare(-50, -50, -20, -50, 1000, true, TIME);
    setSpeed(0, 0);
    resetRelative();
	turn1Motor(100, 42, RIGHT);
    turn1Motor(100, -55, LEFT);
    moveSimple(100, 100, 50, RELDEG);
    end();
}

