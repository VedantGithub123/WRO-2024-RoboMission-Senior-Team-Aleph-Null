task armReset()
{
    moveArmSimple(100, 600, LIFT, TIME);
    moveArmSimple(100, 500, CLAW, TIME);
    resetArmAbs(CLAW);
    moveArmAbsSimple(100, -270, CLAW);
}

task armDownForRed(){
    moveArmAbsSimple(100, armDegreeToDrop, LIFT);
}

task liftArmBeforeBlocks(){
    moveArmAbsSimple(100, armDegreeToPick, LIFT);
}