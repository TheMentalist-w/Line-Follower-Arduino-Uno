#include "constants.h"

float measure()
{
  long times;
  digitalWrite(USTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(USTrig, LOW);
  times = pulseIn(USEcho, HIGH);
  return times / 58.00;
}

void setup()
{
  pinMode(USTrig, OUTPUT);
  pinMode(USEcho, INPUT);
  // Starting Serial Terminal
  Serial.begin(9600);
  Serial.print("Starting ultrasonic measure!!!\n");
}

void loop()
{
  Serial.print(measure());
  Serial.println();
  delay(1000);
}
