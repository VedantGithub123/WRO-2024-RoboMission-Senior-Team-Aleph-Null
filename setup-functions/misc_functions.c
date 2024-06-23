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
		return getMotorEncoder(right)*358.0/360.0;
	}
	return getMotorEncoder(left)*-1;
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

// Resets the arm degrees based on the relative baseline
void resetArm(int port)
{
    if (port==CLAW)
    {
        relativeBaseClaw = getMotorEncoder(claw);
    }
    else
    {
        relativeBaseLift = getMotorEncoder(lift);
    }
}

// Gets the relative degree value of the arm
float getArmDegrees(int port)
{
    if (port==CLAW)
    {
        return (getMotorEncoder(claw)-relativeBaseClaw);
    }
    return (getMotorEncoder(lift)-relativeBaseLift);
}

// Gets the absolute degree value of the arm
float getArmDegreesAbs(int port)
{
	if (port==CLAW)
    {
        return getMotorEncoder(claw);
    }
    return getMotorEncoder(lift);
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
    setMotorSpeed((port==CLAW) ? claw : lift, speed);
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
