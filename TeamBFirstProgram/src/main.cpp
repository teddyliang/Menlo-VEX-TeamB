// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBack             motor         1               
// LeftMiddle           motor         2               
// RightBack            motor         3               
// RightMiddle          motor         4               
// RightIntake          motor         5               
// LeftIntake           motor         6               
// LiftArm              motor         7               
// Ramp                 motor         8               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBack             motor         1               
// LeftMiddle           motor         2               
// RightBack            motor         3               
// RightMiddle          motor         4               
// RightIntake          motor         5               
// LeftIntake           motor         6               
// LiftArm              motor         7               
// Ramp                 motor         8               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBack             motor         1               
// LeftMiddle           motor         2               
// RightBack            motor         3               
// RightMiddle          motor         4               
// RightIntake          motor         5               
// LeftIntake           motor         6               
// LiftArm              motor         7               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBack             motor         1               
// LeftMiddle           motor         2               
// RightBack            motor         3               
// RightMiddle          motor         4               
// RightIntake          motor         5               
// LeftIntake           motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBack             motor         1               
// LeftMiddle           motor         2               
// RightBack            motor         3               
// RightMiddle          motor         4               
// RightIntake          motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBack             motor         1               
// LeftMiddle           motor         2               
// RightBack            motor         3               
// RightMiddle          motor         4               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBack             motor         1               
// LeftMiddle           motor         2               
// RightBack            motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBack             motor         1               
// LeftMiddle           motor         2               
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftBack             motor         1               
// ---- END VEXCODE CONFIGURED DEVICES ----
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
int liftIntakesSpeed = 10;
bool slowMode = false;
vex::directionType reverse = vex::directionType::rev;
vex::directionType forward = vex::directionType::fwd;
// A global instance of vex::brain used for printing to the V5 brain screen

// define your global instances of motors and other devices here


void moveRampUp()
{
  Ramp.spinFor(1, timeUnits::sec, topSpeed,velocityUnits::pct);
  return;
}

void moveRampDown()
{
  Ramp.spinFor(1, timeUnits::sec, -topSpeed,velocityUnits::pct);
  return;
}
void moveRamp()
{
    if (Controller1.ButtonL1.pressing())
    {
      Ramp.spin(forward);
    } 
    else if (Controller1.ButtonL2.pressing())
    {
      Ramp.spin(reverse);
    }
    else
    {
      Ramp.stop();
    }

}

void spinIntakes()
{
    RightIntake.spin(directionType::fwd, -inTakeSpeed,velocityUnits::pct);
    LeftIntake.spin(directionType::fwd, inTakeSpeed,velocityUnits::pct);
    task::sleep(20);
    return;
}

void stopIntakes()
{
    slowMode = false;
    RightIntake.spin(directionType::fwd, 0,velocityUnits::pct);
    LeftIntake.spin(directionType::fwd, 0,velocityUnits::pct);
    task::sleep(20);
    return;
}

void reverseIntakes()
{
    slowMode = true;
    RightIntake.spin(directionType::rev, -inTakeSpeed/10,velocityUnits::pct);
    LeftIntake.spin(directionType::rev, inTakeSpeed/10,velocityUnits::pct);
    task::sleep(20);
    return;
}

// void dumpStack()
// {
//   RightIntake.spin(directionType::rev, -inTakeSpeed/10,velocityUnits::pct);
//   LeftIntake.spin(directionType::rev, inTakeSpeed/10,velocityUnits::pct);

//   LeftBack.spinFor(4, timeUnits::sec, topSpeed,velocityUnits::pct);
//   LeftMiddle.spinFor(4, timeUnits::sec, topSpeed,velocityUnits::pct);

//   // LeftBack.spin(directionType::fwd, topSpeed,velocityUnits::pct);
//   // LeftMiddle.spin(directionType::fwd, topSpeed,velocityUnits::pct);

//   LeftBack.spinFor(4, timeUnits::sec, -topSpeed,velocityUnits::pct);
//   LeftMiddle.spinFor(4, timeUnits::sec,- topSpeed,velocityUnits::pct);

//   // RightBack.spin(directionType::fwd, -topSpeed,velocityUnits::pct);
//   // RightMiddle.spin(directionType::fwd, -topSpeed,velocityUnits::pct);
//   task::sleep(5);
//   return;
// }

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  while(true)
  {

    if (Controller1.ButtonUp.pressing())
    {
      LiftArm.spin(forward);
    } 
    else if (Controller1.ButtonDown.pressing())
    {
      LiftArm.spin(reverse);
    }
    else
    {
      LiftArm.stop();
    }

    Controller1.ButtonL1.pressed(moveRampUp);
    Controller1.ButtonL2.pressed(moveRampDown);

    Controller1.ButtonX.pressed(spinIntakes);
    Controller1.ButtonY.pressed(stopIntakes);
    Controller1.ButtonB.pressed(reverseIntakes);

    if(!slowMode)
    {
      LeftBack.spin(directionType::fwd, (Controller1.Axis3.value()),velocityUnits::pct);
      LeftMiddle.spin(directionType::fwd, (Controller1.Axis3.value()),velocityUnits::pct);

      RightBack.spin(directionType::fwd, -(Controller1.Axis2.value()),velocityUnits::pct);
      RightMiddle.spin(directionType::fwd, -(Controller1.Axis2.value()),velocityUnits::pct);
      task::sleep(20);
    }
    else
    {
      LeftBack.spin(directionType::fwd, (Controller1.Axis3.value()/5),velocityUnits::pct);
      LeftMiddle.spin(directionType::fwd, (Controller1.Axis3.value()/5),velocityUnits::pct);

      RightBack.spin(directionType::fwd, -(Controller1.Axis2.value()/5),velocityUnits::pct);
      RightMiddle.spin(directionType::fwd, -(Controller1.Axis2.value()/5),velocityUnits::pct);
      task::sleep(20);
    }
  }
}