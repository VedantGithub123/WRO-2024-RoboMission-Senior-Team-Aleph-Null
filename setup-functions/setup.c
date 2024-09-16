// Any global variables are declared here

#define max2(a, b) ((a>b) ? a : b)
#define min2(a, b) ((a<b) ? a : b)

#define INFINITY 1000000.0						// Big number for no accelleration
#define RELDEG 0								// Moves for relative degrees
#define ABSDEG 1								// Moves for absolute degrees
#define RELCM 2									// Moves for relative cm
#define ABSCM 3									// Moves for absolute cm
#define TIME 4									// Moves for milliseconds
#define GREATREFL 5								// Moves until greater than certain reflection
#define LESSREFL 6								// Moves until less than certain reflection
#define COLOR 7									// Moves until the color sensor sees a certain color

#define NONE 0                                  // Defines the value representing each color
#define BLACK 1									// Defines the value representing each color
#define BLUE 2									// Defines the value representing each color
#define GREEN 3									// Defines the value representing each color
#define YELLOW 4								// Defines the value representing each color
#define RED 5 								    // Defines the value representing each color
#define WHITE 6									// Defines the value representing each color
#define BROWN 7                                 // Defines the value representing each color

const float black1 = 9; 						// Globally defines the black value for the color sensor in port 1
const float white1 = 80; 						// Globally defines the white value for the color sensor in port 1
const float mid1 = (black1+white1)/2.0;         // Globally defines the midpoint for the color sensor in port 1
const float black2 = 9; 						// Globally defines the black value for the color sensor in port 2
const float white2 = 75; 						// Globally defines the white value for the color sensor in port 2
const float mid2 = (black2+white2)/2.0;         // Globally defines the midpoint for the color sensor in port 1
const float black3 = 7; 						// Globally defines the black value for the color sensor in port 3
const float white3 = 60; 						// Globally defines the white value for the color sensor in port 3
const float mid3 = (black3+white3)/2.0;         // Globally defines the midpoint for the color sensor in port 1
const float black4 = 0; 						// Globally defines the black value for the color sensor in port 4
const float white4 = 100; 						// Globally defines the white value for the color sensor in port 4
const float mid4 = (black4+white4)/2.0;         // Globally defines the midpoint for the color sensor in port 1

const float wheelDiam = 6.24;					// Defines the diameter of the wheel for absolute positioning
const float wheelDist = 17.848;					// Defines the distance between the wheels for the angle measurement

const float maxVoltage = 8.3;                   // Defines the voltage of the battery at full charge
const float minVoltage = 7.2;                   // Defines the voltage of the battery at no charge

const float timeAccelRatio = 0.5;               // Defines the ratio between the time accel value to the degrees accel value
const float turnPIDScale = 0.3;                 // Defines the scale for the kP and kD is the motors move in opposite directions

const int LEFT = 0;								// Defines the left port for the encoder functions
const int RIGHT = 1;							// Defines the right port for the encoder functions
const int LIFT = 2;
const int CLAW = 3;

const float trueDefaultkP = 0.08/2.0;
const float trueDefaultkD = 0.1;
const float trueDefaultMinspeed = 15;
const float trueDefaultAcc = 0.4;
const float trueDefaultArmMinspeed = 30;

float defaultkP = trueDefaultkP;
float defaultkD = trueDefaultkD;
float defaultMinspeed = trueDefaultMinspeed;
float defaultAcc = trueDefaultAcc;
float defaultArmMinspeed = trueDefaultArmMinspeed;

const float armDegreeToPick = 240;
const float armDegreeToDrop = 175;
const float armDegreeForFirst = 93;
const float clawDegreeOpen = -245;

int stoppingTime = 3000;

float relativeBaseLeft = 0;						// Defines the baseline for relative movement left motor
float relativeBaseRight = 0;					// Defines the baseline for relative movement right motor
float absoluteLeft = 0;							// Defines the baseline for absolute movement left motor
float absoluteRight = 0;						// Defines the baseline for absolute movement right motor
float relativeBaseClaw = 0;                     // Defines the baseline for relative movement port a
float relativeBaseLift = 0;                     // Defines the baseline for relative movement port d
