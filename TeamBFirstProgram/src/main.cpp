/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       teddy                                                     */
/*    Created:      Sat Sep 21 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "config.h"

using namespace vex;
int inTakeSpeed = 50;
int rampMovementTime = 1;
int topSpeed = 100;
int liftIntakesSpeed = 100;
// A global instance of vex::brain used for printing to the V5 brain screen

// define your global instances of motors and other devices here

void moveRampUp()
{
    ramp.rotateFor(rampMovementTime,timeUnits::sec,topSpeed,velocityUnits::pct);
    task::sleep(20);
    return;
}

void moveRampDown()
{
    ramp.rotateFor(rampMovementTime,timeUnits::sec,-topSpeed,velocityUnits::pct);
    task::sleep(20);
    return;
}

void spinIntakes()
{
    rightIntake.spin(directionType::fwd, inTakeSpeed,velocityUnits::pct);
    leftIntake.spin(directionType::fwd, -inTakeSpeed,velocityUnits::pct);
    task::sleep(20);
    return;
}

void stopIntakes()
{
    rightIntake.spin(directionType::fwd, 0,velocityUnits::pct);
    leftIntake.spin(directionType::fwd, 0,velocityUnits::pct);
    task::sleep(20);
    return;
}

void moveIntakesUp()
{
    liftArm.rotateFor(liftIntakesSpeed, timeUnits::sec, topSpeed, velocityUnits::pct);
    task::sleep(20);
    return;
}

void moveIntakesDown()
{
    liftArm.rotateFor(liftIntakesSpeed, timeUnits::sec, -topSpeed, velocityUnits::pct);
    task::sleep(20);
    return;
}

int main() 
{
  Controller1.ButtonL1.pressed(moveRampUp);
  Controller1.ButtonL2.pressed(moveRampDown);
  Controller1.ButtonUp.pressed(moveIntakesUp);
  Controller1.ButtonDown.pressed(moveIntakesDown);
  Controller1.ButtonR1.pressed(spinIntakes);
  Controller1.ButtonR2.pressed(stopIntakes);
  while(true)
  {
    //
    leftBackMotor.spin(directionType::fwd, -(Controller1.Axis3.value()),velocityUnits::pct);
    leftMiddleMotor.spin(directionType::fwd, -(Controller1.Axis3.value()),velocityUnits::pct);

    rightBackMotor.spin(directionType::fwd, (Controller1.Axis2.value()),velocityUnits::pct);
    rightMiddleMotor.spin(directionType::fwd, (Controller1.Axis2.value()),velocityUnits::pct);
    task::sleep(20);
  }
}


