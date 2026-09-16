//close side
startTask(liftArmBeforeBlocks);
moveSenseOneSensorNoSync(20, 20, 20, false, 3, BLACK, COLOR);
moveNoSyncAccParamWallSquare(20, 20, 30, 20, 28, false, RELDEG);
resetRelative();
setSpeed(0, 0);

stopTask(liftArmBeforeBlocks);
moveArmAbsSimple(100, armDegreeToDrop, LIFT);
moveArmAbsSimple(100, clawDegreeOpen, CLAW);

moveArmAbsSimple(100, armDegreeForFirst, LIFT);
startTask(closeClaw);
moveSimple(20, 20, 30, RELDEG);
setArmSpeed(CLAW, -100);

//far side
moveSenseOneSensorNoSync(20, 20, 20, false, 3, BLACK, COLOR);
moveNoSyncAccParamWallSquare(20, 20, 30, 20, 28, false, RELDEG);
resetRelative();
setSpeed(0, 0);

stopTask(liftArmBeforeBlocks);
moveArmAbsSimple(100, armDegreeToDrop, LIFT);
moveArmAbsSimple(100, clawDegreeOpen, CLAW);

moveArmAbsSimple(100, armDegreeForFirst, LIFT);
startTask(closeClaw);
moveSimple(20, 20, 30, RELDEG);
setArmSpeed(CLAW, -100);
moveSimple(-20, -20, 370, RELDEG);
setArmSpeed(CLAW, -100);
startTask(liftArmBeforeBlocks);