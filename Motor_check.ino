#include <AFMotor.h>
#include "constants.h"

AF_DCMotor motorLeft(MotorLeftPort);
AF_DCMotor motorRight(MotorRightPort);

void setup()
{
  //Set initial speed of the motor & stop
  motorLeft.setSpeed(200);
  motorLeft.run(RELEASE);

  motorRight.setSpeed(200);
  motorRight.run(RELEASE);
}

void loop()
{
  uint8_t i;

  // Turn on motor
  motorLeft.run(FORWARD);
  motorRight.run(FORWARD);

  // Accelerate from zero to maximum speed
  for (i = 0; i < MotorSpeed; i++)
  {
    motorLeft.setSpeed(i);
    motorRight.setSpeed(i);
    delay(10);
  }

  delay(10000);
}
