task armReset()
{
    moveArmSimple(100, 600, LIFT, TIME);
    moveArmSimple(100, 500, CLAW, TIME);
    resetArmAbs(CLAW);
    moveArmAbsSimple(100, clawDegreeOpen, CLAW);
}

task armDownForRed()
{
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
}

task liftArmBeforeBlocks()
{
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
}

task liftArmForFirstBlock()
{
    moveArmAbsSimple(100, armDegreeForFirst, LIFT);
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
    moveArmAbsSimple(100, clawDegreeOpen+50, CLAW);
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