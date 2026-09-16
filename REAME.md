# Project Overview

The goal of this project is to develop an Autonomous Block Stacking and Sorting Robot to compete in the World Robot Olympiad Robomission Senior category (Competition rules here: <https://wro-association.org/wp-content/uploads/WRO-2024-RoboMission-Senior.pdf>). Our internationals robot uses a four-bar with a claw to collect blocks and stack them while holding them. The four-bar is conencted to other mechanisms used for the other missions. A video of the closing ceremony at the International Final can be found here: <https://youtu.be/36eRFVumAxo?t=8553>. Our team got mentioned :\)

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

## Function/Program Explanation

### `src/code`

### `src/headers`

### `src/scripts`

### `src/code_generation.c`

### `src/port_view.c`


### `src/run.c`
The `startedClose` variable determines which starting position the robot begins in. The `is115` variable determines whether the last stack the robot makes has 3 or 4 blocks.


## Robot Design Process

### National Robot

#### Capability Evaluation
TODO

#### Research / Reference Designs
TODO
RedRobots WRO 2017 Senior: <https://www.youtube.com/watch?v=WM4kiQZ2yXA>
ZERObotics WRO 2020 Senior: <https://www.youtube.com/watch?v=Uf6qEnMmhIk>

#### Block Collection and Stacking
TODO

#### Debris Collection
TODO

#### Water Connection Toggle
TODO

### International Robot

#### National Robot Reflection
TODO

#### Capability Evaluation
TODO

#### Research / Reference Designs
TODO
STORMS RMS 2024 Season: <https://www.instagram.com/p/C6bjOGdsalK/>

#### Block Collection and Stacking
TODO

#### Debris Collection
TODO

#### Water Connection Toggle
TODO


## Program Design Process

### Code Organization
TODO

### Function Design

### `src/scripts/misc_functions.c`

#### Motor Encoder Functions: `getTrueDegrees`, `getAbsDegrees`, `getRelDegrees`, `resetRelative`, `resetMotors`, etc.
TODO
The same design idea is used for the arm and claw motor encoders.

#### Speed Setting Functions: `setSpeed`, `setArmSpeed`
TODO

### `src/scripts/movement_functions.c`

#### Speed Planning: `motionProfile()`
TODO

#### Base Movement Functions: `move`, `moveAbs`, `moveSenseOneSensor`, etc.
TODO
The absolute movement equivalent calls the relative function to simplify the code.

#### Line Following: `lineFollowOneSensor`, `lineFollowOneSensorStopTwoSensor`, etc.
TODO

#### Line Squaring: `lineSquare`
TODO

#### Arm/Claw Functions: `moveArm`, `moveAbs`
TODO
The absolute movement equivalent calls the relative function to simplify the code.

### `src/scripts/sensing_functions.c`

#### Sensor Calibration: `getReflection`
TODO

### `src/scripts/simple_movement_functions.c`
The functions in this file call the functions in `src/scripts/movement_functions.c`. Since we don't want the user writing all the parameters that will likely not change, we keep default values which are used in the simple versions. The simple versions act as a wrapper to make a simpler interface.

### `src/code_generation.c`
We wanted a way to find the correct values for the motors to move and automatically generate the corresponding commands. To do this, we decided on a process where the user moves the robot on the mat, ensuring the wheels rotate. Then when a button is pressed, it will generate the command that corresponds with that movement. A handbook to use the code generation program is found in `references`

TODO

### `src/port_view.c`
Since we use calibrated sensor values in the code, we can't use the built-in port view to see and debug sensor readings. This program uses the sensing functions to display the calibrated values and others that aren't seen in the built-in port view.
