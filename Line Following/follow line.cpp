#pragma region VEXCode Generated Robot Configuration
// Make sure all required headers are included.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>


#include "vex.h"

using namespace vex;

// Brain should be defined by default
brain Brain;


// START IQ MACROS
#define waitUntil(condition)                                                   \
  do {                                                                         \
    wait(5, msec);                                                             \
  } while (!(condition))

#define repeat(iterations)                                                     \
  for (int iterator = 0; iterator < iterations; iterator++)
// END IQ MACROS


// Robot configuration code.
colorsensor LeftColour = colorsensor(PORT5);
colorsensor RightColour = colorsensor(PORT12);
motor LeftDriveSmart = motor(PORT6, 1, false);
motor RightDriveSmart = motor(PORT1, 1, true);
gyro DrivetrainGyro = gyro(PORT4, true);
smartdrive Drivetrain = smartdrive(LeftDriveSmart, RightDriveSmart, DrivetrainGyro, 200);


bool vexcode_initial_drivetrain_calibration_completed = false;
void calibrateDrivetrain() {
  wait(200, msec);
  Brain.Screen.print("Calibrating");
  Brain.Screen.newLine();
  Brain.Screen.print("Gyro");
  DrivetrainGyro.calibrate();
  while (DrivetrainGyro.isCalibrating()) {
    wait(25, msec);
  }
  vexcode_initial_drivetrain_calibration_completed = true;
  // Clears the screen and returns the cursor to row 1, column 1.
  Brain.Screen.clearScreen();
  Brain.Screen.setCursor(1, 1);
}

#pragma endregion VEXcode Generated Robot Configuration
// Include the IQ Library
#include "vex.h"
  
// Allows for easier use of the VEX Library
using namespace vex;

// "when started" hat block
int whenStarted1() {
  while (true) {
    if (LeftColour.detects(colorType::none) && RightColour.detects(colorType::none)) {
      Drivetrain.drive(forward);
    }
    if (LeftColour.detects(colorType::none) && RightColour.detects(red)) {
      Drivetrain.turn(left);
    }
    if (LeftColour.detects(red) && RightColour.detects(colorType::none)) {
      Drivetrain.turn(right);
    }
  wait(20, msec);
  }
  return 0;
}


int main() {
  // Calibrate the Drivetrain Gyro
  calibrateDrivetrain();

  whenStarted1();
}