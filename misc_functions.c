// Function to get the modulo value of two numbers (remainder of x/y)
float mod(float x, float y)
{
	// The function finds how many of x goes into y and uses that to get the answer
	float cur = x/y;
	cur -= (int) cur;
	cur *= y;
	if (cur<0){
		cur += y;
	}
	return cur;
}

// Function to get the true degrees of each motor
float getTrueDegrees(int m)
{
	if (m)
	{
		return getMotorEncoder(right)*1;
	}
	return getMotorEncoder(left)*-0.99;
}

// Function to get the absolute degrees of each motor, based on the absolute baseline
float getAbsDegrees(int m)
{
	if (m)
	{
		return getTrueDegrees(m)-absoluteRight;
	}
	return getTrueDegrees(m)-absoluteLeft;
}

// Function to get the relative degrees of each motor, based on the relative baseling
float getRelDegrees(int m)
{
	if (m)
	{
		return getAbsDegrees(m) - relativeBaseRight;
	}
	return getAbsDegrees(m) - relativeBaseLeft;
}

// Function to reset the motors based on the relative baseline
void resetRelative()
{
	relativeBaseLeft = getAbsDegrees(LEFT);
	relativeBaseRight = getAbsDegrees(RIGHT);
}

// Function to reset the motors based on the absolute baseline
void resetMotors()
{
    absoluteLeft = getTrueDegrees(LEFT);
	absoluteRight = getTrueDegrees(RIGHT);
    relativeBaseLeft = 0;
	relativeBaseRight = 0;
}

// Sets the speed of the drivetrain
void setSpeed(float lSpeed, float rSpeed)
{
	// This part scales the speeds so the highest one is 100
	if (lSpeed>100){
		rSpeed *= 100/lSpeed;
		lSpeed = 100;
	}else if (lSpeed<-100){
		rSpeed *= -100/lSpeed;
		lSpeed = -100;
	}
	if (rSpeed>100){
		lSpeed *= 100/rSpeed;
		rSpeed = 100;
	}else if (rSpeed<-100){
		lSpeed *= -100/rSpeed;
		rSpeed = -100;
	}

	// This part scales the speeds since the speeds plateau from 80-100 power
	if (lSpeed<97){
		lSpeed = 85.0/97.0*lSpeed;
	}else{
		lSpeed = (lSpeed-97.0)*5.0+85.0;
	}
	if (rSpeed<97){
		rSpeed = 85.0/97.0*rSpeed;
	}else{
		rSpeed = (rSpeed-97.0)*5.0+85.0;
	}

    setMotorSpeed(left, lSpeed*-1);
	setMotorSpeed(right, rSpeed);
}

// Function to set the x value for odometry
void resetX(float newX)
{
	xPos = newX;
}

// Function to set the y calue for odometry
void resetY(float newY)
{
	yPos = newY;
}

// Function to set the angle for odometry
void resetAngle(float newAngle)
{
	angle = newAngle;
}

// Function to convert the degrees of the motor into cm
float cmFromDeg(float deg)
{
	return deg/360*wheelDiam*PI;
}

// Function to convert cm travelled into degrees on the driving motor
float degFromCM(float cm)
{
	return cm/wheelDiam/PI*360.0;
}

// Finds the different of two angles, different between 0 and 182 is -178
float angleDiff(float angle1, float angle2)
{
	if (fabs(angle1-angle2)==180.0)
	{
		return 180.0;
	}
	return sgn(mod(angle1-angle2, 360)-180)*180-(mod(angle1-angle2, 360)-180);
}

// Function to convert the angle to turn into cm the robot has to turn
float cmFromAngle(float turn)
{
	return turn/360.0*PI*wheelDist;
}

// Function to convert the cm each motor moved into an angle
float angleFromCM(float angle)
{
	return angle/wheelDist/PI*360.0;
}

// Function to find the distance between two points
float pointDist(float x1, float y1, float x2, float y2)
{
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

// Task to calculate where the robot is on the field
task odometry()
{
	while (isRunning)
	{
		float dLeft = getTrueDegrees(LEFT)-prevLeft;
		prevLeft = getTrueDegrees(LEFT);
		float dRight = getTrueDegrees(RIGHT)-prevRight;
		prevRight = getTrueDegrees(RIGHT);
		float angleCopy = angle;

		dLeft = (dLeft/360.0)*wheelDiam*PI;
		dRight = (dRight/360.0)*wheelDiam*PI;

		float dAngle = (dLeft-dRight)/(wheelDist*2.0*PI)*360.0;

		float dX;
		float dY;
		float dMiddle = (dLeft+dRight)/2.0;

		if (dAngle==0)
		{
			dX = 0;
			dY = dMiddle;
		}
		else
		{
			dY = 180*dMiddle*sinDegrees(dAngle)/PI/dAngle;
			dX = 180*dMiddle*(1-cosDegrees(dAngle))/PI/dAngle;
		}

		angleCopy = angleCopy-90;

		float dY2 = dX*cosDegrees(angleCopy)-dY*sinDegrees(angleCopy);
		float dX2 = dY*cosDegrees(angleCopy)+dX*sinDegrees(angleCopy);

		xPos+=dX2;
		yPos+=dY2;
		angle+=dAngle;
		angle = mod(angle, 360);

		displayCenteredBigTextLine(3, "(%0.2f, %0.2f)", xPos, yPos);
		displayCenteredBigTextLine(7, "Angle: %0.2f", angle);

		sleep(1);
	}
}

// Task to play music
task music()
{
	drawBmpfile(0, 0, "BSOD.rgf");

	playSoundFile("M1.rsf");
	sleep(5000);
	playSoundFile("M2.rsf");
	sleep(5000);
	playSoundFile("M3.rsf");
	sleep(5000);
	playSoundFile("M4.rsf");
	sleep(5000);
	playSoundFile("M5.rsf");
	sleep(5000);
	playSoundFile("M6.rsf");
	sleep(5000);
	playSoundFile("M7.rsf");
	sleep(5000);
	playSoundFile("M8.rsf");
	sleep(5000);
	playSoundFile("M9.rsf");
	sleep(5000);
	playSoundFile("M10.rsf");
	sleep(5000);
	playSoundFile("M11.rsf");
	sleep(5000);
	playSoundFile("M12.rsf");
	sleep(5000);
	playSoundFile("M13.rsf");
	sleep(5000);
	playSoundFile("M14.rsf");
	sleep(5000);
	playSoundFile("M15.rsf");
	sleep(5000);
}

// Resets the arm degrees based on the relative baseline
void resetArm(int port)
{
    if (port==2)
    {
        relativeBaseA = getMotorEncoder(a);
    }
    else
    {
        relativeBaseD = getMotorEncoder(d);
    }
}

// Gets the relative degree value of the arm
float getArmDegrees(int port)
{
    if (port==2)
    {
        return getMotorEncoder(a)-relativeBaseA;
    }
    return getMotorEncoder(d)-relativeBaseD;
}

// Gets the absolute degree value of the arm
float getArmDegreesAbs(int port)
{
	if (port==2)
    {
        return getMotorEncoder(a);
    }
    return getMotorEncoder(d);
}

// Sets the speed of the arm
void setArmSpeed(int port, float speed)
{
	// Works the same way at the setSpeed function
    if (speed>100){
		speed = 100;
	}else if (speed<-100){
		speed = -100;
	}
	if (speed<97){
		speed = 85.0/97.0*speed;
	}else{
		speed = (speed-97.0)*5.0+85.0;
	}
    setMotorSpeed((port==2) ? a : d, speed);
}

// Converts the color number into a string
const string getColourName[8] = {
	"NONE",
	"BLACK",
	"BLUE",
	"GREEN",
	"YELLOW",
	"RED",
	"WHITE",
	"BROWN"
};

// Converts the motor pnumber into a string
const string getMotorName[4] = {
	"LEFT",
	"RIGHT",
	"LIFT",
	"CLAW"
};
