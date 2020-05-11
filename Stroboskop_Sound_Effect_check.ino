#include <AFMotor.h>
#include "constants.h"

AF_DCMotor stroboscope(StroboscopePort);
AF_DCMotor speaker(SpeakerPort);

void setup()
{
  motor1.setSpeed(StroboscopeSpeed);
  motor1.run(RELEASE);
  motor2.setSpeed(SpeakerSpeed);
  motor2.run(RELEASE);
  delay(5000);
}

void loop()
{
  uint8_t i;
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(StroboscopeSpeed);
  motor2.setSpeed(StroboscopePort);
}
