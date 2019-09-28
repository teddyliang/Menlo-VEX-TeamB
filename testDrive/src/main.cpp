/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       teddy                                                     */
/*    Created:      Sat Sep 21 2019                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;
vex::motor leftMotor = (vex::PORT1, true);
vex::motor rightMotor = (vex::PORT2, true);
vex::motor backMotor = (vex::PORT3, true);
vex::motor frontMotor = (vex::PORT4, true);


// define your global instances of motors and other devices here


int main() 
{
  //make left and right motors go forward
  //leftMotor.spin(directionType::fwd, 50, velocityUnits::pct);
  //rightMotor.spin(directionType::fwd, 50, velocityUnits::pct);

  //wait 3 seconds
  //task::sleep(3000);

  //stop the motors
  //leftMotor.stop(brakeType::coast);
  //rightMotor.stop(brakeType::coast);

  //make forward and back motors go forward
  backMotor.spin(directionType::fwd, 50, velocityUnits::pct);
  frontMotor.spin(directionType::fwd, 50, velocityUnits::pct);

  //wait 3 seconds
  task::sleep(3000);

  //stop the motors
  backMotor.stop(brakeType::coast);
  frontMotor.stop(brakeType::coast);

}

