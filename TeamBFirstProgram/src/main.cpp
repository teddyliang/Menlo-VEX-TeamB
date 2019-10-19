// To complete the VEXcode V5 Text project upgrade process, please follow the
// steps below.
// 
// 1. You can use the Robot Configuration window to recreate your V5 devices
//   - including any motors, sensors, 3-wire devices, and controllers.
// 
// 2. All previous code located in main.cpp has now been commented out. You
//   will need to migrate this code to the new "int main" structure created
//   below and keep in mind any new device names you may have set from the
//   Robot Configuration window. 
// 
// If you would like to go back to your original project, a complete backup
// of your original (pre-upgraded) project was created in a backup folder
// inside of this project's folder.

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// RightBack            motor         1               
// RightMiddle          motor         2               
// LeftBack             motor         3               
// LeftMiddle           motor         4               
// RightIntake          motor         5               
// LeftIntake           motor         6               
// LiftArm              motor         7               
// Ramp                 motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int inTakeSpeed = 50;
double rampMovementTime = 0.7;
int topSpeed = 50;
int liftIntakesSpeed = 20;
// A global instance of vex::brain used for printing to the V5 brain screen

// define your global instances of motors and other devices here

vex::controller Controller1 = vex::controller();

void moveRampUp()
{
    Ramp.rotateFor(rampMovementTime,timeUnits::sec,topSpeed,velocityUnits::pct);
    task::sleep(20);
    return;
}

void moveRampDown()
{
    Ramp.rotateFor(rampMovementTime,timeUnits::sec,-topSpeed,velocityUnits::pct);
    task::sleep(20);
    return;
}

void spinIntakes()
{
    RightIntake.spin(directionType::fwd, inTakeSpeed,velocityUnits::pct);
    LeftIntake.spin(directionType::fwd, -inTakeSpeed,velocityUnits::pct);
    task::sleep(20);
    return;
}

void stopIntakes()
{
    RightIntake.spin(directionType::fwd, 0,velocityUnits::pct);
    LeftIntake.spin(directionType::fwd, 0,velocityUnits::pct);
    task::sleep(20);
    return;
}

void moveIntakesUp()
{
    if (Controller1.ButtonUp.pressing())
    {
        LiftArm.rotateFor(liftIntakesSpeed, timeUnits::sec, topSpeed, velocityUnits::pct);
        task::sleep(20);
    }
    return;
}

void moveIntakesDown()
{

    if (Controller1.ButtonDown.pressing())
    {
      LiftArm.rotateFor(liftIntakesSpeed, timeUnits::sec, -topSpeed, velocityUnits::pct);
      task::sleep(20);
    }
    return;
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  Controller1.ButtonL1.pressed(moveRampUp);
  Controller1.ButtonL2.pressed(moveRampDown);
  Controller1.ButtonUp.pressed(moveIntakesUp);
  Controller1.ButtonDown.pressed(moveIntakesDown);
  Controller1.ButtonR1.pressed(spinIntakes);
  Controller1.ButtonR2.pressed(stopIntakes);

  
  while(true)
  {
    LeftBack.spin(directionType::fwd, -(Controller1.Axis3.value()),velocityUnits::pct);
    LeftMiddle.spin(directionType::fwd, -(Controller1.Axis3.value()),velocityUnits::pct);

    RightBack.spin(directionType::fwd, (Controller1.Axis2.value()),velocityUnits::pct);
    RightMiddle.spin(directionType::fwd, (Controller1.Axis2.value()),velocityUnits::pct);
    task::sleep(20);
  }
}