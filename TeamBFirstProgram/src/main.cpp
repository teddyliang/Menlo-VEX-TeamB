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

// A global instance of vex::brain used for printing to the V5 brain screen

// define your global instances of motors and other devices here


int main() 
{
  int armSpeedPct = 50; //the percent speed of the arm

  while(true)
  {
    //code for the wheels
    leftBackMotor.spin(directionType::fwd, (-Controller1.Axis4.value() - Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
    leftMiddleMotor.spin(directionType::fwd, (-Controller1.Axis4.value() - Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;

    rightBackMotor.spin(directionType::fwd, (-Controller1.Axis4.value() + Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;
    rightMiddleMotor.spin(directionType::fwd, (-Controller1.Axis4.value() + Controller1.Axis3.value())/2, velocityUnits::pct); //(Axis3+Axis4)/2;


    //code for the intake
    if (Controller1.ButtonR1.pressing()){
      leftIntakeMotor.spin(vex::directionType::fwd, armSpeedPct, vex::velocityUnits::pct);
      rightIntakeMotor.spin(vex::directionType::fwd, armSpeedPct, vex::velocityUnits::pct);
    } if (Controller1.ButtonR2.pressing()){
      leftIntakeMotor.spin(vex::directionType::rev, armSpeedPct, vex::velocityUnits::pct);
      rightIntakeMotor.spin(vex::directionType::rev, armSpeedPct, vex::velocityUnits::pct);
    } else {
      leftIntakeMotor.stop(vex::brakeType::brake);
      rightIntakeMotor.stop(vex::brakeType::brake);
    }
    task::sleep(20);
  }
}
