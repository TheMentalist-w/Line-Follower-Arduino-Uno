#include <AFMotor.h>

AF_DCMotor motor1(3);
AF_DCMotor motor2(4);

void setup() 
{
  //Set initial speed of the motor & stop
  motor1.setSpeed(200);
  motor1.run(RELEASE);

  motor2.setSpeed(200);
  motor2.run(RELEASE);
}

void loop() 
{
  uint8_t i;

  // Turn on motor
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  
  // Accelerate from zero to maximum speed
  for (i=0; i<255; i++) 
  {
    motor1.setSpeed(i);
    motor2.setSpeed(i);  
    delay(10);
  }

  delay(10000);
}
