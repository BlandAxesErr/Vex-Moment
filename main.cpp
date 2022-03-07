/*----------------------------------------------------------------------------*/
/* */
/* Module: main.cpp */
/* Author: VEX */
/* Created: Thu Sep 26 2019 */
/* Description: Clawbot Competition Template */
/* */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name] [Type] [Port(s)]
// Controller1 controller
// Drivetrain drivetrain 1, 10, D
// ClawMotor motor 3
// ArmMotor motor 8
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

vex::motor        RightMotor  = vex::motor(vex::PORT1, ratio18_1, false);
vex::motor        LeftMotor =   vex::motor(vex::PORT2, ratio18_1, true);
vex::motor        ConveyorMotor = vex::motor(vex::PORT3, ratio18_1, true);
vex::motor        GrabMotor =   vex::motor(vex::PORT4, ratio18_1, true);
vex::controller   Controller1 = vex::controller();
vex::drivetrain   drivetrain  = vex::drivetrain(LeftMotor, RightMotor, 319.19, 295, 40, mm, 1);
vex::competition  Competition;

// A global instance of competition

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/* Pre-Autonomous Functions */
/* */
/* You may want to perform some actions before the competition starts. */
/* Do them in the following function. You must return from this function */
/* or the autonomous and usercontrol tasks will not be started. This */
/* function is only called once after the V5 has been powered on and */
/* not every time that the robot is disabled. */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
// Initializing Robot Configuration. DO NOT REMOVE!
vexcodeInit();

}

void autonomous(void) {
// ..........................................................................
// moves forward to grab the MG and move it between the NMGs and the balance, releasing it
Drivetrain.driveFor(forward, 600, mm);
  GrabMotor.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
  wait(300, msec);
  GrabMotor.stop();
  Drivetrain.driveFor(reverse, 200, mm);
  Drivetrain.turn(left);
  wait(1400, msec);
  Drivetrain.stop();
  Drivetrain.driveFor(reverse,590, mm);
  //even though it says turning right this ia the leftward turn before it pushes the MG to the final location
  Drivetrain.turn(right);
  wait(1600, msec);    
  Drivetrain.driveFor(forward, 700, mm);
  // this is the grabbing "function"; wait time and direction are subjective
  GrabMotor.spin(vex::directionType::rev, 75, vex::velocityUnits::pct);
  wait(250, msec);
  GrabMotor.stop();

//goes to grab the bottom NMG and brings it into territory
Drivetrain.driveFor(reverse, 510, mm);
Drivetrain.turn(right);
wait(1450, msec);
Drivetrain.driveFor(forward, 1050, mm);
GrabMotor.spin(vex::directionType::fwd, 75, vex::velocityUnits::pct);
wait(300, msec);
GrabMotor.stop();
Drivetrain.driveFor(reverse, 1100, mm);

// ..........................................................................
}

/*---------------------------------------------------------------------------*/
/* */
/* User Control Task */
/* */
/* This task is used to control your robot during the user control phase of */
/* a VEX Competition. */
/* */
/* You must modify the code to add your own robot specific commands here. */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
// User control code here, inside the loop
while (1) {
// This is the main execution loop for the user control program.
// Each time through the loop your program should update motor + servo
// values based on feedback from the joysticks.

// ........................................................................
// Insert user code here. This is where you use the joystick values to
// update your motors, etc.
// ........................................................................

wait(20, msec); // Sleep the task for a short amount of time to
// prevent wasted resources.
}
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
// Set up callbacks for autonomous and driver control periods.
Competition.autonomous(autonomous);
Competition.drivercontrol(usercontrol);

// Run the pre-autonomous function.
pre_auton();

// Prevent main from exiting with an infinite loop.
while (true) {
wait(100, msec);
}
}
