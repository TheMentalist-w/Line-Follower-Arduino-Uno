#include <AFMotor.h>
#include "constants.h"

// Initial Values of Sensors
bool IRSensorLeft = false;
bool IRSensorCenter = false;
bool IRSensorRight = false;
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
  motorLeft.setSpeed(MotorSpeed);
  motorRight.setSpeed(MotorSpeed);
  motorLeft.run(FORWARD);
  motorRight.run(FORWARD);
}

void goLeft()
{
  motorLeft.setSpeed(0);
  motorRight.setSpeed(MotorSpeed);
  motorLeft.run(RELEASE);
  motorRight.run(FORWARD);
}

void goRight()
{
  motorLeft.setSpeed(MotorSpeed);
  motorRight.setSpeed(0);
  motorLeft.run(FORWARD);
  motorRight.run(RELEASE);
}

void goBack()
{
  motorLeft.setSpeed(MotorSpeed);
  motorRight.setSpeed(255);
  motorLeft.run(BACKWARD);
  motorRight.run(BACKWARD);
}

void playSound()
{
  speaker.run(FORWARD);
}

void muteSound()
{
  speaker.run(RELEASE);
}

void startFlashing()
{
  stroboscope.run(FORWARD);
}

void stopFlashing()
{
  stroboscope.run(RELEASE);
}

void readSensors()
{
  IRSensorLeft = digitalRead(IRSensorLeftPort) > IRTreshold;
  IRSensorCenter = digitalRead(IRSensorCenterPort) > IRTreshold;
  IRSensorRight = digitalRead(IRSensorRightPort) > IRTreshold;
  USsensor = measureDistance() > USTreshold;
  SoundSensor = digitalRead(SoundSensorPort) > SoundTreshold;
}

void chooseRoute()
{
  if (USsensor)
    if (IRSensorCenter)
      goForward();
    else if (IRSensorLeft && !IRSensorRight)
      goLeft();
    else if (!IRSensorLeft && IRSensorRight)
      goRight();
    else
      goBack();
  else
    playSound();
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
  delay(1000);
}
