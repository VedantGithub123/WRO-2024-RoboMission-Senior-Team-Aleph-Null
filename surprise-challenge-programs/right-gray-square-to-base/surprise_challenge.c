void surpriseChallenge(){
		//add this after first water question
		startTask(openClaw);
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 40, defaultAcc, defaultAcc, true, RIGHT);
		turn1MotorAccMinspeed(40, defaultMinspeed, defaultMinspeed, 40, defaultAcc, defaultAcc, true, LEFT);
    resetArmAbs(LIFT);
    startTask(liftArmForFirstBlock);
    moveNoSyncParam(80, 80, 80, 30, 240, 0.4, 0.2, true, RELDEG);
    setArmSpeed(CLAW, -100);
    startTask(liftArmBeforeBlocks);
    sleep(150);
}



##################################################
moveNoSyncParam(27, 50, defaultMinspeed, defaultMinspeed, 302, defaultAcc, defaultAcc, true, RELDEG);
moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, -300, defaultAcc, defaultAcc, CLAW);
moveArmAbs(50, defaultArmMinspeed, defaultArmMinspeed, 156, defaultAcc, defaultAcc, LIFT);
moveNoSyncParam(-50, -50, defaultMinspeed, defaultMinspeed, 344, defaultAcc, defaultAcc, true, RELDEG);
