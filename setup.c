// Any global variables are declared here

#define max2(a, b) (a>b) ? a : b

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

const int black1 = 8; 							// Globally defines the black value for the color sensor in port 1
const int white1 = 52; 							// Globally defines the white value for the color sensor in port 1
const int black2 = 7; 							// Globally defines the black value for the color sensor in port 2
const int white2 = 45; 							// Globally defines the white value for the color sensor in port 2
const int black3 = 7; 							// Globally defines the black value for the color sensor in port 3
const int white3 = 44; 							// Globally defines the white value for the color sensor in port 3
const int black4 = 0; 							// Globally defines the black value for the color sensor in port 4
const int white4 = 100; 						// Globally defines the white value for the color sensor in port 4

const float wheelDiam = 6.3;					// Defines the diameter of the wheel for absolute positioning
const float wheelDist = 16.8;					// Defines the distance between the wheels for the angle measurement

const int LEFT = 0;								// Defines the left port for the encoder functions
const int RIGHT = 1;							// Defines the right port for the encoder functions
const int LIFT = 2;                            // Defines a value for
const int CLAW = 3;

float relativeBaseLeft = 0;						// Defines the baseline for relative movement left motor
float relativeBaseRight = 0;					// Defines the baseline for relative movement right motor
float absoluteLeft = 0;							// Defines the baseline for absolute movement left motor
float absoluteRight = 0;						// Defines the baseline for absolute movement right motor
float relativeBaseA = 0;                        // Defines the baseline for relative movement port a
float relativeBaseD = 0;                        // Defines the baseline for relative movement port d
// No baseline for true movement for odometry since that is the built-in baseline

float xPos = 0;									// Defines the x position of the robot in centimeters
float yPos = 0;									// Defines the y position of the robot in centimeters
float angle = 0;								// Defines the angle of the robot in degrees

float prevLeft = 0;								// Used to store the previous true measurement for the left motor
float prevRight = 0;							// Used to store the previous true measurement for the right motor
bool isRunning = true;							// Used to stop the task after the run is done
