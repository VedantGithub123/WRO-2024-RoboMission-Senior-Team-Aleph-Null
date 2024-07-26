void supriseChallenge()
{
    // For the right water connection, replace the moving forward and turn after the wall square to the following lines
    moveNoSyncMinspeedParam(100, 100, 828, 0.2, 0.2, true, RELDEG);
    resetRelative();
    turn1MotorAcc(50, 90, 0.2, 0.2, LEFT);

    // For the right Water connection, replace the two turns and the first 3 chained movements after the water connection 
    // with the following lines
    turn1MotorNoSettle(100, 125, LEFT);
	
    moveNoSyncParam(100, 100, 20, 50, 300, 0.4, 0.4, false, RELDEG);
    turn1MotorAccMinspeed(100, 50, 50, 125, 0.4, 0.4, false, RIGHT);
    moveNoSyncParam(100, 100, 50, 50, 390, 0.4, 0.4, false, RELDEG);

    // For the left water connection replace the moving forward and turn after the wall square to the following lines
    moveNoSyncMinspeedParam(100, 100, 780, 0.2, 0.2, true, RELDEG);
	turn2MotorAcc(30, 91.5, 0.2, 0.2);
}