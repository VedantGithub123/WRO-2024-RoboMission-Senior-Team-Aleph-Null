void code()
{

    moveNoSyncAccParam(50, 50, 12, 50, 500, false, RELDEG);
    turn1MotorAccMinspeed(50, 50, 50, 90, 0.4, 0.4, false, LEFT);
    // sleep(500);
    moveNoSyncAccParam(50, 50, 50, 50, 500, false, RELDEG);
    turn1MotorAccMinspeed(50, 50, 50, 90, 0.4, 0.4, false, LEFT);
    moveNoSyncAccParam(50, 50, 50, 50, 500, false, RELDEG);
    turn1MotorAccMinspeed(50, 50, 50, 90, 0.4, 0.4, false, LEFT);
    moveNoSyncAccParam(50, 50, 50, 50, 500, false, RELDEG);
    turn1MotorAccMinspeed(50, 50, 12, 90, 0.4, 0.4, true, LEFT);
    return;

	moveSimpleWallSquare(-30, -30, 500, TIME);
    resetRelative();
    sleep(50);

    moveArm(50, 50, 50, 800, 0.4, 0.4, true, LIFT, TIME);

    moveSimple(40, 40, 920, RELDEG);
    turn2Motor(20, 90);
    moveSimple(-40, -40, 780, RELDEG);

    moveArm(-100, 50, 50, 1000, 0.4, 0.4, true, LIFT, TIME);
    
    moveSimple(30, 30, 40, RELDEG);
    turn2Motor(26, 90);
    moveArm(100, 30, 30, 130, 0.4, 0.4, true, LIFT, TIME);
    moveSimple(40, 40, 60, RELDEG);

    turn1Motor(50, -90, RIGHT);
    moveSimple(-30, -30, 20, RELDEG);
    turn1Motor(50, 90, RIGHT);
    sleep(300);
}
