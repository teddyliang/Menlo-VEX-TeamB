#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftBack = motor(PORT1, ratio18_1, false);
motor LeftMiddle = motor(PORT2, ratio18_1, false);
motor RightBack = motor(PORT3, ratio18_1, false);
motor RightMiddle = motor(PORT4, ratio18_1, false);
motor RightIntake = motor(PORT5, ratio18_1, false);
motor LeftIntake = motor(PORT6, ratio18_1, false);
motor LiftArm = motor(PORT7, ratio18_1, false);
motor Ramp = motor(PORT8, ratio18_1, false);
controller Controller1 = controller(primary);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}