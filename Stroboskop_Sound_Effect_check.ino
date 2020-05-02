#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() 
{
  motor1.setSpeed(255);
  motor1.run(RELEASE);
  motor2.setSpeed(255);
  motor2.run(RELEASE);
  delay(5000);
}

void loop() 
{
  uint8_t i;
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor1.setSpeed(255); 
  motor2.setSpeed(255); 
}
