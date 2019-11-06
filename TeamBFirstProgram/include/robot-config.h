using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor LeftBack;
extern motor LeftMiddle;
extern motor RightBack;
extern motor RightMiddle;
extern motor RightIntake;
extern motor LeftIntake;
extern motor LiftArm;
extern motor Ramp;
extern controller Controller1;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );