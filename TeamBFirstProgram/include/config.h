vex::brain Brain;
vex::motor leftBackMotor(vex::PORT1,true);
vex::motor leftMiddleMotor(vex::PORT2,true);
vex::motor rightBackMotor(vex::PORT3,true);
vex::motor rightMiddleMotor(vex::PORT4,true);
<<<<<<< HEAD
vex::motor rightIntake(vex::PORT5,true);
vex::motor leftIntake(vex::PORT6,true);
vex::motor liftArm(vex::PORT7,true);
vex::motor ramp(vex::PORT8,true);
=======
vex::motor leftIntakeMotor(vex::PORT5);
vex::motor rightIntakeMotor(vex::PORT6, true);
>>>>>>> 2736be9dc7a038b347fadf12cef5f21b424d5042
vex::controller Controller1 = vex::controller();
