# Project Overview

The goal of this project is to develop an Autonomous Block Stacking and Sorting Robot to compete in the World Robot Olympiad Robomission Senior category (Competition rules here: <https://wro-association.org/wp-content/uploads/WRO-2024-RoboMission-Senior.pdf>). Our internationals robot uses a four-bar with a claw to collect blocks and stack them while holding them. The four-bar is conencted to other mechanisms used for the other missions. A video of the closing ceremony at the International Final can be found here: <https://youtu.be/36eRFVumAxo?t=8553>. Our team got mentioned :\)

Note that I call the file that you donwload to the robot the "executable", although it really isn't

## Getting Started

Robot is built with EV3 LEGO Mindstorms. The robot designs can be found in `build` and can be opened using Studio 2.0

Install ROBOTC for LEGO MINDSTORMS at: <https://www.robotc.net/>. Set up RobotC onto the EV3 Hub by downloading the firmware through the RobotC software.

Ensure Git is installed and setup to work with he repository

Clone the project repository to your local machine and navigate into the directory:
```
git clone https://github.com/VedantGithub123/WRO-2024-RoboMission-Senior-Team-Aleph-Null.git
cd WRO-2024-RoboMission-Senior-Team-Aleph-Null
```

## Repository Structure

The `main` branch is the organized working branch. Below is an overview of the folder structure for the `main` branch of this repository
```
WRO-2024-RoboMission-Senior-Team-Aleph-Null/
├── archive/
│   ├── second-day-challenge-programs/
│   └── surprise-challenge-programs/
├── build/
│   ├── international-robot/
│   └── national-robot/
├── media/
│   ├── international-robot/
│   └── national-robot/
├── references/
├── src/
│   ├── code/
│   ├── headers/
│   ├── scripts/
│   ├── code_generation.c
│   ├── port_view.c
│   ├── scripts/
│   └── run.c
└── README.md
```

### Folder Descriptions

`archive/`: Contains unused programs

&emsp;&emsp;`second-day-challenge-programs/`: Code for practice second-day challenges

&emsp;&emsp;`surprise-challenge-programs/`: Code for practice surprise challenges

`build/`: Contains files relating to the physical construction of the robot

&emsp;&emsp;`international-robot/`: Contains build files for the international robot design

&emsp;&emsp;&emsp;&emsp;`design.io`: CAD of the international robot

&emsp;&emsp;`national-robot/`: Contains build files for the national robot design

&emsp;&emsp;&emsp;&emsp;`design.io`: CAD of the national robot

`media/`: Contains videos, photos, and renders of the robot

&emsp;&emsp;`international-robot/`: Media of the international robot

&emsp;&emsp;`national-robot/`: Media of the national robot

`references/`: Contains reference documents to use the code

`src/`: Contains all source code

&emsp;&emsp;`code`: Functions containing commands, subsections of the executable

&emsp;&emsp;`headers`: Header files used, stores port setup

&emsp;&emsp;`scripts`: Functions that `code` uses

&emsp;&emsp;`code_generation.c`: Code generation script, executable program, must be downloaded to the EV3 hub using RobotC

&emsp;&emsp;`port_view.c`: Displays calibrated sensor readings, executable program, must be downloaded to the EV3 hub using RobotC

&emsp;&emsp;`run.c`: Final run, executable program, must be downloaded to the EV3 hub using RobotC

`README.md`: Project repository documentation

## Function/Program Overview

### `src/code`

#### `code.c`
This file contains three functions to split up the code. Depending on which side the robot starts on, there are two seperate programs. Then a common ending is defined.

#### `tasks.c`
This contains all functions that are to be run in parallel with the main program. RobotC uses tasks to do this, hence the name.

### `src/headers`

#### `ports_setup.h`
The configuration for the EV3 ports in in this file

### `src/scripts`

#### `misc_functions.c`
This contains miscallaneous functions such as `mod` and motor encoder measurement and resetting functions. It also contains an array used to convert a number into the corresponding color name.

#### `movement_functions.c`
This contains functions for robot and arm movement, such as regular movement, line following, line squaring, etc. Important functions are covered below:

- `motionProfile`: Given the current state of a motor, determines the speed it should move at
- `move`: Relative movement functions
- `lineFollowOneSensor`: Line following function with one sensor for distance
- `lineSquare`: Line squaring function for time
- `moveArmAbs`: Moves an arm to an absolute position

#### `sensing_functions.c`
This contains functions to interact with the sensors. Functions for calibrated sensor reflection, raw sensor reflection, blue reflection, green reflection, and color detection are found here.

#### `setup.c`
This contains variables used for setup. Calibration and constants are defined here. It acts as a centralized place to change these values if a sensor changes. Some variables are defines to increase code readability.

#### `simple_movement_functions.c`
The functions here act as wrappers for the regular movement functions. Users will normally use these for simplicity.

### `src/code_generation.c`
This program is an executable that will generate the code based on how the user moves the robot. When the program is ran, it will move the arms and claw to reset them to their baseline values. Then there are multiple pages that can be rotated with the left and right buttons. Depending on which page you are on, what button you press, and how the motors have moved since the last command, the program will write the corresponding command to the debug stream, which you can see afterwards by connecting the robot to the laptop. A reference booklet can be found in `references`

### `src/port_view.c`
This program is an executable that will show the sensor values and allow the user to move the arms. When the program is ran, it will move the arms and claw to reset them to their baseline values. Then the screen displays the sensed color from the sensors facing th ground. The middle button is used to toggle what shows on the screen, The toggle is done by using a Finite State Machine. It can also display the motor readings or the reflection values for the sensors. It uses the calibrated sensor values.

### `src/run.c`
This program is the executable for the actual robot run. The `startedClose` variable determines which starting position the robot begins in. The `is115` variable determines whether the last stack the robot makes has 3 or 4 blocks.


## Robot Design Process

### National Robot

#### Capability Evaluation
We started by discussing the capabilties we wanted for the robot. The robot needs to drive forward and turn quickly. It must be able to sense colors on the mat. It must be able to collect/hold blocks, ideally multiple at a time. It must be able to flip the water connection mission.

#### Research / Reference Designs
One team that we looked at was RedRobots WRO 2017 Senior: <https://www.youtube.com/watch?v=WM4kiQZ2yXA>. Their robot uses a claw with a four-bar to lift blocks. It also has a latch that activates when pulled by a string when the four-bar lifts up fully. We noticed similarities between their challenge and hours, so we decided that going with a claw design to stack blocks would work. Our claw design uses theirs as a reference, but is modified to be able to pick up a total of four blocks at one: two columns of two. Additionally, we used the string method of transferring motion for a rear claw, as it allows for flexible routing.

Another team that we looked at was ZERObotics WRO 2020 Senior: <https://www.youtube.com/watch?v=Uf6qEnMmhIk>. The component of their robot was the rack gear, which extended on either side of the robot. We saw a use case for this to gather all four red and yellow blocks at once: the claw grabs the middle two and the rack gear extends to grab the other two and centers them.

#### Block Collection
Based on our research, we wanted to use a claw-based design. However, the stacks would be too high to store inside the robot, and stacking one at a time would be too slow. This meant that we need a way to collect multiple blocks at one. We can make a claw to collect two blocks at once, but then there would be two more that are difficult to access. This brings us to the rack gear. If we can collect those blocks with the rack gear while lifting the blocks in the claw, then we can collect four blocks at once, which is efficient. Thus, we would have two blocks in the claw and two on the ground in the rack gear prongs. We need the rack gear to be open when the four-bar is down, and closed when it is up. It must also move independently of the claw. Thus, we geared it to the four-bar.

#### Block Stacking
To stack the blocks, our robot must make two stacks of two and place one on top of the other. This is inherent to the claw and four-bar design used for block collection. To place the stacks in the correct area, we needed another way to move the stacks once they were created, which is why we added a claw on the back of the robot that can pull the stack. This rear claw is connected to the four-bar with a string, so it grabs the stack when the four-bar is lowered.

#### Debris Collection
To manipulate the scatterred debris around the map, we had to have some part of our robot push them with a concave surface since there were not extra motors. Luckily, the rack gear used for block collection had prongs on the front that acted as an area to keep the debris. Additionally, since the rack gear could widen, we can grab debris that is hard to access.

#### Water Connection Toggle
We did not want to add any additional mechanisms to the robot, so we decided to add an extension to the claw. This extension goes into the opening, and as the claw opens the water connection gets toggled.

### International Robot

#### National Robot Reflection
The biggest limitation with the Nationals robot was that it could only score between 101 - 113 points and depended on luck. Additionally, the robot takes a long time to align itself when collecting blocks or placing stacks, which increases the time of the run, reducing time for the surprise challenge. Finally, it cannot make stacks of one, it only makes 2-wide stacks and must split them.

#### Capability Evaluation
For our Internationals robot, we wanted to be able to pick up blocks while gliding along the wall, since it will allow us to align easier and faster. Additionally, the robot should be able to make single stacks. It should also be able to sense the block color so that the score is not dependent on luck. The target point score for this robot is 115, which is three full stacks of blocks.

#### Research / Reference Designs
Many videos online followed a similar robot design, where a robot has an offset collection mechanism to colelct and store blocks. The robot we analyzed the most was from team STORMS RMS 2024 Season: <https://www.instagram.com/p/C6bjOGdsalK/>. Specifically, we noted their claw shape, which allows the blocks to automatically align and also releases the blocks without vertical motion of the container.

#### Block Collection and Stacking
Both the collection and stacking happen simulataneously. It allows for faster stacking. The collection process involves placing the stacked blocks onto the new block. Then the claw moves down to collect the new stack. We based this process on various reference videos. However, this process had some issues. First, when the blocks are placed onto the new block, they tilt slightly, so the claw can't close again. To solve this, we added angled pieces onto the claw to align the blocks. Additionally, the width of the claw also impacts the grip of the claw, so we had to change the claw width to better grab the blocks. Finally, the claw had to be offset so that the claw aligned with the blocks when the robot was against the wall.

#### Debris Collection
Since we didn't have the rack gear on this robot, we need replacement prongs. We just extended the sides of the robot forwards, creating a concave front. Other than that, it acts the same as the previous robot design.

#### Water Connection Toggle
Since the claw also changes, toggling the water connection would also need to be changed. The claw was already too large to be used for the water connection. This meant that we needed to add another mechanism on the back of the robot. Toggling could be done with a stick that moves up and down, so we added one that was connected to the four-bar with a string.


## Program Design Process

### Code Organization
The goal of the code organization to to make sure that it is easy for the user to operate. We want the functions to have minimal parameters while keeping the option for customizability. Additionally, the main scripts should be organized in one area so that the user does not have to move back and forth between files. 

### Function Design

### `src/scripts/misc_functions.c`

#### Motor Encoder Functions: `getTrueDegrees`, `getAbsDegrees`, `getRelDegrees`, `resetRelative`, `resetMotors`, etc.
We wanted to make our own motor encoder function wrappers so that we could get more control of how motor encoder measuring is done. Sometimes, the robot might move a bit before the encoders are reset, or the robot settles slightly off before resetting the encoders. These small differences aren't accounted for since the encoders are reset. These things can add up, since the robot has no idea its off. To fix this, we asked how the robot can know how off it is from what its target is. Our solution is to use a relative baseline. The relative degrees are calculated as the different between the current absolute degrees and the relative baseline. When the relative degrees are reset, we just change the relative baseline to the current absolute degrees. What this allows us to do is modify the relative baseline directly. After a movement such as moving the left motor for X degrees, the left motor may have moves X+2 degrees. Instead of directly resetting it, we just add X degrees to the relative baseline, so the robot still knows it is 2 degrees off of what it should be. This error can then be accounted for with the synched motors in the next movement command.

For some reason we have three different values: true, absolute, and relative degrees. I think it is because each motor might measure distance travelled slightly differently, which is what getTrueDegrees fixes. Then absolute degrees is treated as absolute with relative being treated as relative to the absolute. The same design idea is used for the arm and claw motor encoders.

#### Speed Setting Functions: `setSpeed`, `setArmSpeed`
Since the EV3 motor speed does not change linearly with the target speed, we wanted to scale it so that it does. These two functions do that by scaling the provided speed differently based on the target speed. Sometimes the function might be called with speeds greater than 100. Since we care more about the relative speed of the each motor, both left and right motors are scaled down to within the bounds.

### `src/scripts/movement_functions.c`
Disclaimer: The speed planning and base movement functions descriptions may not perfectly match the code. This is because the documentation was written two years afterwards. However, it serves as enough baseline to understand what the functions are doing. Some things that could have been overlooked are specific edge cases.

#### Speed Planning: `motionProfile()`
This function models a speed motion profile depending on the motor position, time, and other parameters. It had many iterations and required extensive design. It evolved through multiple interations. Note that we are not using PIDs for reaching the target motor position. Also, the acceleration rate and deceleration rates can differ. This is because syncing the motors is more important:
- Double-quadratic acceleration/deceleration
- Time-based acceleration
- Linear deceleration
- Settling and not settling parameters
- Variable starting and ending speeds

##### Double-Quadratic Acceleration/Deceleration
In hindsight, I don't know why we did this. Turns out it worked fine (mostly) but it was too annoying to work with if we wanted to continue adding features. The acceleration component of this involved two quadratics, where one was flipped upside-down and stiched together to make an s-shape. The same is done for the deceleration. If the motor starts behind the starting position, then it the speed should be the minimum speed. If it is an an acceleration/deceleration region, it should follow those curves. If it is a cruising region, it should move at the maximum speed. If it crosses the target position, it should move backwards at the minimum speed. If it is within a threshold of the target, the speed is set to zero. The speed-position graph look like so:

<img width="1000" alt="image" src="https://github.com/user-attachments/assets/0cb927b4-5c6d-4521-a102-17800b755fc9" />

##### Time-based Acceleration
Having a speed calculated from distance has its own issues. For example, if one motor starts moving first, its speed will be higher which keeps compounding. Additionally, we don't know what the velocity-time graph looks like, making it hard to see if it actually limits acceleration. To solve this, we know we want the acceleration to be constant, so `speed = acceleration*position + minimum speed`. The minimum speed is not completely necessary, but we decided to include it to make sure no motor starts at a later time. Note that using this acceleration means our new speed-position graph looks like the following (Note that the accleration appears to have a square root relationship, this is because the linear relationship is with the speed and time, not position. Integrating, substituting, and isolating for position gives a square root relationship):

<img width="1000" alt="image" src="https://github.com/user-attachments/assets/96c22b8a-62eb-4278-aa03-885ac498539e" />

##### Linear Deceleration
We felt that the older deceleration was too annoying, so we made it simpler by keeping the speed proportional to the remaining distance. There wasn't any noticeable change in performance. The new position-distance graph is shown below:

<img width="1000" alt="image" src="https://github.com/user-attachments/assets/4819925c-6565-401f-895f-0f13ca7ddd93" />


##### Settling and Not Settling Parameters
Sometimes, we want movements to chain together with the next ones to make the run smoother. However, the reversing during an overshoot can't do that. That is why we added another parameter to determine whether or not the robot should move forwards or backwards at the minimum speed after the target. It also determines whether the motors will be set to 0 power. The position-distance graph without settling is shown below:

<img width="1000" alt="image" src="https://github.com/user-attachments/assets/c5890464-0d65-49a0-930b-eedcd0b3e69f" />


##### Variable Starting and Ending Speeds
This is arguably the biggest iteration for this function as it required a whole redesign. Its not very efficient to slow down to the minimum speed when chaining movements together, we want it to be fast. But the starting and ending speed should be able to differ. What is we want to come in with a slow speed, cruise at a medium speed, and then speed up before chaining into the next movement. Or vice versa, where we start fast and end slow. If we are accelerating without time, we need to consider many different edge cases. However, since we will never do that, I will not write it here (Basically, find the intersection points between three lines: starting line, cruising line, deceleration line. Based on what order these intersection points appear, you have different edge cases). Lets consider the relevant cases:

Note: I will refer to the acceleration/decceleration that the robot starts with as "acceleration". The one the robot ends with is "deceleration"

`Case 1: Acceleration > 0, Deceleration < 0`
This means that we want to limit speed to that it is always below the acceleration line, cruising speed, and deceleration speed. This is a trapezoid-like profile.

`Case 2: Acceleration < 0, Deceleration < 0`
To ensure our acceleration constraints are met, we know that the speed would be decreasing and above the cruising speed at the start, so it must be below the larger one so that it starts following the acceleration line, but then switches to the cruising speed to make sure the speed is as fast as possible. To ensure we meet our deceleration constraints, we take the smallest speed from the previously calculated one and the deceleration line. This means that one the robot is at the threshold where it can start decelerating, it should.

`Case 3: Acceleration > 0, Deceleration > 0`
Same as case 2, but in the reverse direction. We first ensure the speed is below both acceleration and cruising so that it doesn't exceed the cruising speed when cruising. Then we take the max of that and the deceleration, so that it can reach the target speed.

`Case 4: Acceleration < 0, Deceleration > 0`
Since we always want to be above the cruising speed here, we just take the maximum of the acceleration speed, the cruising speed, and the deceleration speed.

##### Future Considerations
When the speed is proportional to the remaining distance, it actually follows an exponential relationship with time, which is not ideal when limiting movement. Instead, a square root relationship with distance will give a linear relationship with time. However, this makes the different starting and stopping speeds implementation significantly more complicated. We can derive the expression based on the input parameters below:

`x' = a*t + b` --> `x = 1/2*a*t^2 + b*t + x_0`

`x'^2 = a^2*t^2 + 2*a*t*b + b^2`

`(x'^2)/(2*a) = 1/2*a*t^2 + b*t + b^2/(2*a) = x - x_0 + b^2/(2*a)`

`x'^2 = 2*a*(x-x_0) + b^2 - C`

`x' = sqrt(2*a*(x - x_0) + b^2)`

Using this relationship should give better performance. I have not tested it though. If the robot it moving for time, it should still use a linear relationship.

#### Base Movement Functions: `move`, `moveAbs`, `moveSenseOneSensor`, etc.
We want these functions to be able to do any movement. This section will only talk about the relative move function. The others work identically other than the stopping condition. However, since they use sensing to stop, there is no deceleration. The absolute movement equivalent calls the relative function to simplify the code. We can think of the function being split up into a few sections:
- Setup: Ensures all inputs are the correct signs and don't conflict with each other
- Exit Condition: The conditions to exit the loop, either distance, sensing , and/or time
- Motion Profile: Calls the motion profile function for the motors, ensures that the speeds, acceleration rate, and deceleration rate are scaled according to the speed ratio between the motors to maintain a constant speed ratio throughout the movement
- Motor Sync: This adds a PD loop onto how out of sync the motors are. Initially the error was `L_distance_travelled/L_distance - R_distance_travelled/R_distance`. However, this meant that the error would get smaller if the target distance is large. Instead, we can use speed: `L_distance_travelled/L_speed - R_distance_travelled/R_speed`. Note that this would have a smaller error if the speed is large. Instead, we can try multiplying by both speeds: `L_distance_travelled*R_speed - R_distance_travelled*L_speed`. But this would overcount the speed impact since we multiplied both speeds. Thus, we can divide by the average speed to get `(L_distance_travelled*R_speed - R_distance_travelled*L_speed)/(R_speed + L_speed)` However, if one of the motors speed is 0, it is already at the target, so moving is is kind of useless.
- End Conditions: Based on the ending parameters, the motors should keep moving or stop and the motor encoders need to be reset

#### Line Following: `lineFollowOneSensor`, `lineFollowOneSensorStopTwoSensor`, etc.
All line following functions work the same as the movement functions. However, the steering depends on sensor values instead of the motor differences. For one sensor line following, the error is the difference between the sensor reflection value and the threshold. For two sensor line following, the error is the difference between the left and right sensor reflection values. These are standard line following functions.

#### Line Squaring: `lineSquare`
The line squaring algorithm uses a PID loop on each motor and associated sensor individually. However, the integral term can have a lot of wind-up, decreasing the performance of the line squaring. To mitigate this, we decrease the integral term by 10 percent every loop. Additionally, when the sensor crosses the target value, the integral should act in the opposite direction, so we multiply it by -0.5.

#### Arm/Claw Functions: `moveArm`, `moveAbs`
This is basically just following the motion profile. It is the same as the drivetrain movement without syncing motors.The absolute movement equivalent calls the relative function to simplify the code.

### `src/scripts/sensing_functions.c`

#### Sensor Calibration: `getReflection`
Since different sensors can provide different readings, we want a way to standardize them. We want the measured reflection when the sensor sees white to be 100 and 0 when black. If we know the raw values of the sensor for white and black, we can scale and shift the range so it lies in the target range. This is what the `getReflection` function does.

### `src/scripts/simple_movement_functions.c`
The functions in this file call the functions in `src/scripts/movement_functions.c`. Since we don't want the user writing all the parameters that will likely not change, we keep default values which are used in the simple versions. The simple versions act as a wrapper to make a simpler interface.

### `src/code_generation.c`
We wanted a way to find the correct values for the motors to move and automatically generate the corresponding commands. To do this, we decided on a process where the user moves the robot on the mat, ensuring the wheels rotate. Then when a button is pressed, it will generate the command that corresponds with that movement. A handbook to use the code generation program is found in `references`

We wanted the following capabilities:
- Move straight forward/backward for distance
- Turn right/left
- Line follow for distance
- Move until sensor value
- Line square
- Move claw/four-bar absolutely

Since we know that the motor distance values won't be perfect (499 degrees on left motor and 501 on right motor), we need a way to round these values and determine the correct ones. First we check if the robot should move straight, depending on how close the two measured distances are to each other. Then we check if one is 0, which acts as a one-motor turn. It also checks if one motor moves in the opposite direction, which acts as a two-motor turn. For both turns, we need to check if they are close to a multiple of 90 degree turns since those are more common. If none of these conditions are met, then it assumes the movement was a curve and sets the measured values. Similar processes are used for sensing-based movement. In sensing-based movement, the sensor readings when a button is pressed determines the threshold. For line following and line squaring, different buttons are used for different configurations. The speed and threshold settings work the same as regular movement.

### `src/port_view.c`
Since we use calibrated sensor values in the code, we can't use the built-in port view to see and debug sensor readings. This program uses the sensing functions to display the calibrated values and others that aren't seen in the built-in port view.
