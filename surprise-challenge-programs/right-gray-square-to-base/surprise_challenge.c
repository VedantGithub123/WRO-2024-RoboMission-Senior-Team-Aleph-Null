void surpriseChallenge(){
  // Add the following code after the wall square before the first water connection
  startTask(liftArmforFirstBlock);
  turn1MotorAccMinspeed(50, 50, 50, 90, 0.4, 0.4, false, RIGHT);
  moveSenseOneSensorSimple(-20, -20, 50, false, 1, RED, COLOR);
  moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 26, defaultAcc, defaultAcc, true, RELDEG);
  turn1MotorAccMinspeed(60, 60, 100, -90, 0.4, 0.4, false, RIGHT);
  moveNoSyncAccParamWallSquare(-80, -80, 100, 100, 500, true, TIME);
  resetRelative();
  setSpeed(0, 0);
  moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 600, defaultAcc, defaultAcc, true, RELDEG);
  moveNoSyncParam(20, 20, defaultMinspeed, defaultMinspeed, 150, defaultAcc, defaultAcc, true, RELDEG);
  sleep(100);
  setArmSpeed(CLAW, -100);
  sleep(400);
  startTask(liftArmForFirstBlock);
  turn1MotorAccMinspeed(100, 100, 100, -10, 0.4, 0.4, false, RIGHT);
  moveNoSyncAccParamWallSquare(-80, -80, 100, 100, 1000, true, TIME);
  if (startedClose == false){
    turn1MotorAccMinspeed(100, 20, 20, 90, 0.4, 0.4, true, LEFT);
    moveNoSyncParam(20, 20, defaultMinspeed, defaultMinspeed, 50, defaultAcc, defaultAcc, true, RELDEG);
    moveArmSimple(100, 300, CLAW, TIME);
    setArmSpeed(CLAW, 0);
    moveNoSyncParam(-20, -20, defaultMinspeed, defaultMinspeed, 50, defaultAcc, defaultAcc, true, RELDEG);
    turn1MotorAccMinspeed(100, 100, 100, -90, 0.4, 0.4, false, LEFT);
    moveNoSyncAccParamWallSquare(-80, -80, 100, 100, 500, true, TIME);
    resetRelative();
  }


  // Add the following code at the very end of the program
  if (startedClose == true){
  	turn1MotorAccMinspeed(100, 100, 100, 30, 0.4, 0.4, false, LEFT);
   	moveNoSyncParam(100, 100, defaultMinspeed, defaultMinspeed, 650, defaultAcc, defaultAcc, true, RELDEG);
   	moveArmSimple(100, 300, CLAW, TIME);
  }
}
	