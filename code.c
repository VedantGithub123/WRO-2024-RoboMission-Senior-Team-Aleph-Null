void turnFromWallSquareRight()
{
    turn1MotorNoSettle(100, 50, LEFT);
    turn1MotorNoSettle(100, -49, RIGHT);
}

void turnFromWallSquareLeft()
{
    turn1MotorNoSettle(100, 50, RIGHT);
    turn1MotorNoSettle(100, -49, LEFT);
}

void end()
{
    moveSenseOneSensorNoSync(25, 30, 30, false, 3, BROWN, COLOR);

    if (startedClose){
        moveNoSyncAccParamWallSquare(23, 25, 30, 12, 339, false, RELDEG);
    }
    else
    {
        moveNoSyncAccParamWallSquare(23, 25, 30, 12, 334, false, RELDEG);
    }
    

	resetRelative();
    setSpeed(0, 0);
	turn1MotorNoSettle(30, 8, LEFT);

	moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    startTask(liftArmForFarGreenBlue2);


	turn1MotorNoSettle(30, -8, LEFT);
	moveSenseOneSensorNoSync(-100, -50, 50, false, 1, RED, COLOR);
    moveNoSyncAccParamWallSquare(-100, -50, 100, 20, 130, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
	turn1MotorNoSettle(100, 109, LEFT);

	moveSimpleWallSquare(-50, -50, 700, TIME);
    resetRelative();
    setSpeed(0, 0);

    // 2nd Block
    getGreen(4);
    resetRelative();
    moveNoSyncMinspeedParam(100, 100, 405, 0.4, 0.25, false, RELDEG);
    setSpeed(0, 0);

    int baseColor = BLUE;
    if (getGreen(4)>=getBlue(4) || getBlue(4)<getGreen(4)+2)
    {
        playSound(soundBeepBeep);
        baseColor = GREEN;
    }

    turn1MotorAccMinspeed(100, 20, 20, -95, 0.2, 0.2, true, LEFT);
    resetRelative();
	moveSenseOneSensorSimple(60, 60, 40, false, 1, BROWN, COLOR);
	resetRelative();
    moveNoSyncAccParam(30, 30, 60, 12, 232, true, RELDEG);
    moveArmAbsSimple(100, 360, LIFT);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);

 	turn1MotorNoSettle(30, -18, RIGHT);
	moveSimpleNoSettle(-20, -20, 45, RELDEG);
	turn1MotorNoSettle(30, -23, LEFT);
	moveSimpleNoSettle(20, 20, 52, RELDEG);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen-10, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(100);
    startTask(blocksLow);


    // Puts the stack away
    moveSenseOneSensorSimple(-100, -100, 50, false, 3, WHITE, COLOR);
    if (baseColor == GREEN)
    {
        moveNoSyncAccParam(-100, -100, 100, 100, 60, false, RELDEG);
    }
    else
    {
        moveNoSyncAccParam(-100, -100, 100, 100, 450, false, RELDEG);
    }

    turn1MotorAccMinspeed(100, 100, 40, -87, 0.4, 0.4, false, RIGHT);

	moveNoSyncAccParamWallSquare(-40, -40, 100, 100, 500, true, TIME);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimpleNoSettle(100, 100, 600, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(200);

    startTask(liftArmForFirstBlock);

    moveNoSyncParam(-100, -100, 50, 100, 200, 0.4, 0.4, false, RELDEG);
    turn1MotorAccMinspeed(100, 100, 100, -95, 0.4, 0.4, false, RIGHT);
    stopTask(liftArmForFirstBlock);
    startTask(liftArmBeforeBlocks);

    if (baseColor == GREEN)
    {
        moveNoSyncParam(-100, -100, 100, 100, 150, 0.4, 0.4, false, RELDEG);
    }
    else
    {
        moveNoSyncParam(-100, -100, 100, 100, 480, 0.4, 0.4, false, RELDEG);
    }

    moveSenseOneSensorSimple(-100, -100, 100, false, 3, BROWN, COLOR);

	turn1MotorAccMinspeed(100, 100, 100, -92, 0.4, 0.4, false, LEFT);
	moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 400, true, TIME);
    resetRelative();
    setSpeed(0, 0);
    stopTask(liftArmBeforeBlocks);

    // Does the water connection
    setArmSpeed(LIFT, 100);
    moveNoSyncMinspeedParam(100, 100, 910, 0.2, 0.2, true, RELDEG);
    resetRelative();
    turn2MotorAcc(30, 90, 0.2, 0.2);
    resetRelative();
    moveSenseOneSensor(-30, -30, 30, defaultAcc, defaultkP/2, defaultkD/2, true, 1, WHITE, COLOR);
    moveArmAbsSimple(100, armDegreeToDrop+20, LIFT);

    // Puts the debris away
    turn1MotorNoSettle(100, 48, LEFT);
	turn1MotorNoSettle(100, -61, RIGHT);

    moveNoSyncParam(100, 100, 20, 50, 400, 0.4, 0.4, false, RELDEG);
    turn1MotorAccMinspeed(100, 50, 50, 116, 0.4, 0.4, false, RIGHT);
    moveNoSyncParam(100, 100, 50, 50, 370, 0.4, 0.4, false, RELDEG);
    turn1MotorAccMinspeed(100, 50, 50, 95, 0.4, 0.4, false, RIGHT);
	moveSenseOneSensorSimple(100, 100, 50, false, 2, BLACK, COLOR);
    moveNoSyncParam(100, 100, 100, 50, 70, 0.4, 0.4, false, RELDEG);
    turn1MotorAccMinspeed(100, 50, 40, 78, 0.4, 0.4, false, LEFT);

    resetParameters();

	moveNoSyncAccParamWallSquare(40, 40, 12, 100, 400, false, RELDEG);
	moveSenseOneSensor(60, 60, 60, 0.4, 0, 0, false, 3, WHITE, COLOR);
	moveNoSyncAccParamWallSquare(80, 100, 100, 50, 950, false, RELDEG);
	resetRelative();
    setSpeed(0, 0);

    // Does the last water connection
    moveSimpleNoSettle(-100, -90, 600, RELDEG);
    turn1MotorNoSettle(100, 100, LEFT);
    moveSimpleWallSquare(-100, -100, 700, TIME);
    setSpeed(0, 0);
    resetRelative();
    setArmSpeed(LIFT, 100);
    moveNoSyncMinspeedParam(60, 60, 860, 0.2, 0.2, true, RELDEG);
	turn1MotorAcc(60, -94, 0.25, 0.2, RIGHT);
	moveNoSyncAccParamWallSquare(-100, -100, 70, 30, 250, false, RELDEG);
    moveSenseOneSensor(-30, -30, 30, 0.3, 0, 0, true, 1, WHITE, COLOR);
    setArmSpeed(LIFT, -100);
    sleep(300);
    setArmSpeed(LIFT, 0);
}

void closeCode()
{
    // Collects the close red blocks
    startTask(armReset);
    sleep(300);
    moveSimpleNoSettle(30, 30, 90, RELDEG);
    turn1MotorNoSettle(100, -100, RIGHT);
    resetRelative();
    setSpeed(0, 0);
    moveArmSimple(-100, 700, LIFT, TIME);
    resetArmAbs(LIFT);
    startTask(liftArmForFirstBlock);
    stopTask(armReset);
    getReflection(3);

    moveSenseOneSensorNoSync(30, 30, 20, false, 3, 50, LESSREFL);
    moveNoSyncAccParamWallSquare(15, 15, 30, 15, 60, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(200);

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
    startTask(liftArmForFarGreenBlue);

    // Goes to the far red blocks
    moveSimpleNoSettle(-80, -100, 160, RELDEG);

    turn1MotorAccMinspeed(100, 100, 100, 56, 0.4, 0.4, false, RIGHT);

    moveNoSyncParam(100, 100, 100, 100, 1660, 0.25, 0.25, false, RELDEG);

    turn2MotorAccMinspeed(100, 100, 20, 162, 0.4, 0.4, true);
    getReflection(3);
    moveNoSyncAccParamWallSquare(-100, -100, -100, -100, 600, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);

    // Collects the far red blocks
    moveSenseOneSensorNoSync(30, 30, 20, false, 3, 50, LESSREFL);
    moveNoSyncAccParamWallSquare(20, 20, 30, 12, 43, false, RELDEG);
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
    sleep(250);

    // 2nd Block
    moveNoSyncAccParamWallSquare(30, 30, 15, 15, 145, false, RELDEG);
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
    moveNoSyncParam(-100, -100, 100, 100, 200, 0.4, 0.4, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    turn1MotorAccMinspeed(100, 100, 20, 95, 0.4, 0.4, false, RIGHT);

    moveNoSyncAccParamWallSquare(-40, -40, 20, 40, 900, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    moveNoSyncParam(70, 70, 30, 30, 810, 0.4, 0.4, false, RELDEG);

    turn1MotorAccMinspeed(50, 15, 15, 94, 0.4, 0.4, false, LEFT);

    moveSenseOneSensor(100, 100, 15, 0.4, 0, 0, false, 1, BLUE, COLOR);
    resetRelative();
    startTask(armDownToPlaceStack);
    moveNoSyncParam(100, 100, 100, 30, 370, 0.4, 0.2, true, RELDEG);
    resetRelative();

    startTask(openClawForPlacingStacks);
    sleep(100);
    moveNoSyncParam(-100, -100, 15, 15, 540, 0.25, 0.4, false, RELDEG);
    stopTask(openClawForPlacingStacks);
    startTask(liftArmForFirstBlock);
    turn1MotorAccMinspeed(50, 15, 15, -93, 0.4, 0.4, false, LEFT);

    moveNoSyncAccParamWallSquare(-100, -100, 15, 60, 1100, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    turn1MotorNoSettle(100, 50, LEFT);
    turn1MotorNoSettle(100, -50, RIGHT);

    // Collects the far yellow blocks
    moveSenseOneSensorNoSync(25, 20, 20, false, 3, BLACK, COLOR);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -60);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    sleep(300);

    // 2nd Block
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 74, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    sleep(200);

    // Gets the debris
    setArmSpeed(LIFT, 100);
    sleep(200);
    moveSenseOneSensor(100, 100, 20, 0.4, 0, 0, false, 2, BLUE, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(40, 40, 60, 20, 150, true, RELDEG);

    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(40, 160, LIFT);
    moveSimpleNoSettle(-80, -100, 295, RELDEG);
    turn1MotorNoSettle(100, 124, RIGHT);
    moveSimpleWallSquare(-60, -60, 900, TIME);
    setSpeed(0, 0);
    resetRelative();

    setArmSpeed(LIFT, 100);
    moveSimpleNoSettle(100, 100, 1630, RELDEG);

    defaultkP = 0;
    moveNoSyncParam(-100, -100, 50, 100, 70, 0.4, 0.4, false, RELDEG);
    startTask(liftArmBeforeBlocksDelay);
    turn1MotorAccMinspeed(100, 100, 100, -164, 0.4, 0.4, false, RIGHT);
    moveNoSyncParamWallSquare(-100, -100, 100, 100, 750, 0.4, 0.4, false, TIME);
    resetRelative();
    setSpeed(0, 0);
    resetParameters();

    // Collects the close yellow blocks
    turn1MotorNoSettle(100, 42, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);
    moveSenseOneSensorNoSync(-15, -15, 15, false, 3, RED, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 430, false, RELDEG);
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
    sleep(250);

    // 2nd Block
    moveNoSyncAccParamWallSquare(30, 30, 20, 20, 151, false, RELDEG);
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
    moveNoSyncAccParamWallSquare(-60, -100, 20, 20, 470, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    turn1Motor(100, 113, RIGHT);
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 700, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimpleNoSettle(100, 100, 6000, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(200);

    startTask(liftArmForFirstBlock);

    // Collects to the close blue/green blocks
    moveNoSyncAccParamWallSquare(-100, -100, 100, 100, 800, false, TIME);
    resetRelative();
    setSpeed(0, 0);
    setArmSpeed(LIFT, 0);

    turn1MotorNoSettle(100, 48, LEFT);
    turn1MotorNoSettle(100, -52, RIGHT);

    moveSenseOneSensorNoSync(20, 20, 20, false, 3, BLACK, COLOR);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -60);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    sleep(300);

    // 2nd Block
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 74, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    startTask(liftArmForFarGreenBlue);

    // Goes to the last green/blue blocks
    turn1MotorNoSettle(100, 90, RIGHT);
    moveSimpleWallSquare(-100, -100, 700, TIME);
    resetRelative();
    setSpeed(0, 0);
    moveNoSyncMinspeedParam(100, 100, 1540, 2, 2, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    getReflection(3);
    turn1MotorNoSettle(100, -294, LEFT);
    end();
}

void farCode()
{
    // Goes to the far red blocks
    startTask(armReset);
    sleep(500);
    moveSimpleNoSettle(30, 30, 90, RELDEG);
    turn1MotorNoSettle(100, -103, RIGHT);
    resetRelative();
    setSpeed(0, 0);
    moveArmSimple(-100, 700, LIFT, TIME);
    resetArmAbs(LIFT);
    startTask(liftArmForFirstBlock);
    stopTask(armReset);

    resetRelative();
    moveSenseOneSensorNoSync(30, 25, 20, false, 3, 50, LESSREFL);
    resetRelative();
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 75, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    // Collects the far red blocks
    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(150);

    // 2nd Block
    moveNoSyncAccParamWallSquare(30, 30, 15, 15, 150, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimpleNoSettle(15, 15, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);

    // Goes to close red blocks
    moveSimpleNoSettle(-60, -100, 300, RELDEG);

    turn1MotorAccMinspeed(100, 50, 100, 64, 0.4, 0.4, false, RIGHT);

    moveNoSyncParam(100, 100, 100, 100, 1750, 0.25, 0.25, false, RELDEG);

    turn2MotorAccMinspeed(100, 100, 20, 162, 0.4, 0.4, true);
    moveNoSyncAccParamWallSquare(-100, -100, -20, -100, 800, true, TIME);
    setSpeed(0, 0);
    resetRelative();

    turnFromWallSquareRight();

    moveSenseOneSensorNoSync(30, 30, 20, false, 3, 50, LESSREFL);
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 36, false, RELDEG);
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
    startTask(liftArmBeforeBlocks);
    sleep(250);

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

    // Puts the red stack away
    resetRelative();
    moveNoSyncParam(-38, -50, 20, 20, 520, 0.4, 0.4, true, RELDEG);
    turn1Motor(100, 116, RIGHT);
    moveSimpleWallSquare(-100, -100, 800, TIME);
    resetRelative();
    setSpeed(0, 0);

    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimpleNoSettle(100, 100, 610, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(100);

    startTask(liftArmForFirstBlock);
    moveSimpleWallSquare(-100, -100, 900, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Collects the close yellow blocks
    turnFromWallSquareRight();
    moveSenseOneSensorNoSync(-20, -20, 20, false, 3, RED, COLOR);
    moveNoSyncAccParamWallSquare(20, 20, 20, 20, 456, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(150);

    // 2nd Block
    moveNoSyncAccParamWallSquare(30, 30, 15, 15, 145, false, RELDEG);
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
    

    // Goes to the far yellow blocks
    turn1MotorAccMinspeed(100, 50, 50, 98, 0.4, 0.4, false, RIGHT);
    turn2MotorAccMinspeed(40, 40, 20, -159, 0.4, 0.4, true);

    moveNoSyncAccParam(-100, -100, 50, 50, 1570, false, RELDEG);
    getReflection(3);
    moveNoSyncAccParamWallSquare(-50, -50, 50, 50, 500, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Collects the far yellow blocks
    turnFromWallSquareRight();
    moveSenseOneSensorNoSync(30, 30, 30, false, 3, 50, LESSREFL);
    moveNoSyncAccParamWallSquare(20, 20, 20, 20, 410, false, RELDEG);
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
    sleep(250);

    // 2nd Block
    moveNoSyncAccParamWallSquare(40, 40, 30, 30, 150, false, RELDEG);
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

    // Puts the yellow stack away
    moveSimple(-42, -50, 200, RELDEG);
    turn1Motor(100, 85, RIGHT);
    stopTask(liftArmBeforeBlocks);
    startTask(armDownToPlaceStack);
    moveSimpleNoSettle(100, 100, 450, RELDEG);

    startTask(openClawForPlacingStacks);
    sleep(100);
    startTask(liftArmForFirstBlock);

    moveNoSyncAccParamWallSquare(-100, -90, 100, 100, 900, false, TIME);
    resetRelative();
    setSpeed(0, 0);

    // Collects the far green/blue blocks
    turn1MotorNoSettle(100, 57, LEFT);
    turn1MotorNoSettle(100, -55, RIGHT);
    moveSenseOneSensorNoSync(25, 20, 20, false, 3, BLACK, COLOR);
    resetRelative();
    setSpeed(0, 0);

    setArmSpeed(CLAW, -100);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
    sleep(300);

    // 2nd Block
    moveNoSyncAccParamWallSquare(20, 20, 30, 20, 74, false, RELDEG);
    resetRelative();
    setSpeed(0, 0);

    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);

    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
    startTask(closeClaw);
    moveSimple(20, 20, 30, RELDEG);
    setArmSpeed(CLAW, -100);
    setArmSpeed(LIFT, 100);
    sleep(350);


    // Collects the debris
    moveSenseOneSensor(100, 100, 20, 0.4, 0, 0, false, 2, BLUE, COLOR);
    resetRelative();
    moveNoSyncAccParamWallSquare(40, 40, 60, 20, 170, true, RELDEG);
    resetRelative();
    setSpeed(0, 0);
    moveArmAbsSimple(40, 160, LIFT);
    moveSimpleNoSettle(-80, -100, 305, RELDEG);
    turn1MotorNoSettle(100, 127, RIGHT);
    moveSimpleWallSquare(-40, -40, 1200, TIME);
    setSpeed(0, 0);
    resetRelative();
    setArmSpeed(LIFT, 100);

    // Goes to the last green/blue blocks
    moveNoSyncParam(100, 100, 20, 12, 1530, 0.3, 0.3, true, RELDEG);
    startTask(liftArmBeforeBlocksDelay);
    moveNoSyncParam(-100, -100, 12, 50, 1400, 0.3, 0.4, false, RELDEG);
	moveNoSyncAccParamWallSquare(-50, -50, 50, 50, 400, true, TIME);
    resetRelative();
    turn1MotorNoSettle(100, 98, RIGHT);
    getReflection(3);
    moveNoSyncParamWallSquare(100, 100, 50, 30, 1300, 0.4, 0.4, false, RELDEG);

    end();


}