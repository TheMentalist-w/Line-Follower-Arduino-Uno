#include <AFMotor.h>
#include "constants.h"

// Initial Values of Sensors
int IRSensorLeft = 0;
int IRSensorCenter = 0;
int IRSensorRight = 0;
unsigned long stopTime = 0;
bool USsensor = 0;
bool SoundSensor = 0;

// Output Devices Declaration
AF_DCMotor stroboscope(StroboscopePort);
AF_DCMotor speaker(SpeakerPort);
AF_DCMotor motorLeft(MotorLeftPort);
AF_DCMotor motorRight(MotorRightPort);

int measureDistance()
{
  digitalWrite(USTrig, HIGH);
  delayMicroseconds(AwaitTime);
  digitalWrite(USTrig, LOW);
  return pulseIn(USEcho, HIGH) / 58.00;
}

void goForward()
{
  stopTime = 0;
  motorLeft.setSpeed(MotorSpeed);
  motorRight.setSpeed(MotorSpeed);
  motorLeft.run(FORWARD);
  motorRight.run(FORWARD);
}

void goLeft()
{
  stopTime = 0;
  motorLeft.setSpeed(0);
  motorRight.setSpeed(MotorSpeed);
  motorLeft.run(RELEASE);
  motorRight.run(FORWARD);
}

void goRight()
{
  stopTime = 0;
  motorLeft.setSpeed(MotorSpeed);
  motorRight.setSpeed(0);
  motorLeft.run(FORWARD);
  motorRight.run(RELEASE);
}

void goBack()
{
  stopTime = 0;
  motorLeft.setSpeed(MotorSpeed);
  motorRight.setSpeed(MotorSpeed);
  motorLeft.run(BACKWARD);
  motorRight.run(BACKWARD);
}

void stop()
{
  if (stopTime > StopTimeTreshold)
  {
    motorLeft.setSpeed(0);
    motorRight.setSpeed(0);
    motorLeft.run(RELEASE);
    motorRight.run(RELEASE);
    checkSound();
  }
  else
    stopTime++;
}

void checkSound()
{
  speaker.run(RELEASE);
  stroboscope.run(RELEASE);

  SoundSensor = digitalRead(SoundSensorPort);
  if (SoundSensor)
  {
    speaker.run(FORWARD);
    stroboscope.run(FORWARD);
  }
}

void readSensors()
{
  IRSensorLeft = digitalRead(IRSensorLeftPort);
  IRSensorCenter = digitalRead(IRSensorCenterPort);
  IRSensorRight = digitalRead(IRSensorRightPort);
}

void chooseRoute()
{
  if (IRSensorCenter)
    goForward();
  else if (IRSensorLeft && !IRSensorRight)
    goLeft();
  else if (!IRSensorLeft && IRSensorRight)
    goRight();
  else:
    stop();
  // goBack();
}

void setup()
{
  // IR sensors
  pinMode(IRSensorLeftPort, INPUT);
  pinMode(IRSensorCenterPort, INPUT);
  pinMode(IRSensorRightPort, INPUT);

  // Ultrasonic sensor
  pinMode(USTrig, OUTPUT);
  pinMode(USEcho, INPUT);

  // Sound sensor
  pinMode(SoundSensorPort, INPUT);

  // Output config
  speaker.setSpeed(SpeakerSpeed);
  stroboscope.setSpeed(StroboscopeSpeed);

  // Serial setup
  Serial.begin(9600); //setting serial monitor at a default baund rate of 9600
  Serial.println("Let's follow that line!!!");
  delay(1000);
}

void loop()
{
  readSensors();
  chooseRoute();
}
