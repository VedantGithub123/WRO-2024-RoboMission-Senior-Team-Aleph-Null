task armReset()
{
    setArmSpeed(LIFT, 100);
    sleep(400);
    setArmSpeed(LIFT, 0);
    moveArmSimple(100, 700, CLAW, TIME);
    resetArmAbs(CLAW);
    moveArmAbsSimple(100, clawDegreeOpen+10, CLAW);
}

task liftArmBeforeBlocks()
{
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
}

task liftArmBeforeBlocksDelay()
{
    sleep(300);
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
}

task liftArmForFirstBlock()
{
    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
}

task liftArmForFarGreenBlue()
{
    moveArmAbsSimple(100, armDegreeToPick-10, LIFT);
}

task liftArmForFarGreenBlue2()
{
    moveArmAbsSimple(100, armDegreeToPick+8, LIFT);
}

task liftArmForFarGreenBlueStartingFar()
{
    moveArmAbsSimple(100, armDegreeToPick-15, LIFT);
}

task armDownToPlaceStack()
{
    moveArmAbsSimple(100, 55, LIFT);
}

task openClaw()
{
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);
}

task openClawForPlacingStacks()
{
    moveArmAbs(100, 100, 30, clawDegreeOpen+50, 0.4, 0.4, CLAW);
}

task resetGreenBlue()
{
    moveArmAbsSimple(100, 55, LIFT);
    setArmSpeed(CLAW, 100);
    sleep(200);
    setArmSpeed(CLAW, -100);
    sleep(300);
    moveArmSimple(100, 1000, LIFT, TIME);
}

task closeClaw()
{
    setArmSpeed(CLAW, -10);
    sleep(200);
    setArmSpeed(CLAW, -100);
}

task blocksLow()
{
    moveArmAbsSimple(100, 105, LIFT);
}