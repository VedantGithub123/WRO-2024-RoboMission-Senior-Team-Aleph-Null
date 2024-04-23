void surpriseChallenge()
{
moveSimpleNone(-100, -100, 1000, TIME);
moveSimpleAcc(50, 50, 98, 0.2, RELDEG);
turn1Motor(50, 90, RIGHT);
moveSimpleAcc(50, 50, 160, 0.2, RELDEG);
moveSenseSimple(-20, -20, YELLOW, 2, COLOR);
moveSimpleAcc(50, 50, 697, 0.2, RELDEG);
moveSimpleAcc(50, 31, 12, 0.2, RELDEG);
moveArmAbs(60, 30, 48, 0.3, LIFT);
moveSimpleAcc(50, 50, 40, 0.2, RELDEG);
moveArmAbs(60, 30, -2, 0.3, LIFT);
moveSimpleAcc(-36, 50, 218, 0.2, RELDEG);
moveArmAbs(60, 30, 30, 0.3, LIFT);
sleep(100);
moveSimpleAcc(-100, -100, 100, 0.2, RELDEG);
turn1Motor(-90, -80, RIGHT);
moveSimpleAcc(-50, -50, 365, 0.2, RELDEG);
moveSenseSimple(-50, -50, YELLOW, 2, COLOR);
turn1Motor(-100, -95, RIGHT);
}