using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor RightBack;
extern motor RightMiddle;
extern motor LeftBack;
extern motor LeftMiddle;
extern motor RightIntake;
extern motor LeftIntake;
extern motor LiftArm;
extern motor Ramp;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );