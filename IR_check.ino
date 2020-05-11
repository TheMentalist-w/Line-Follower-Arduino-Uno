#include "constants.h"

// Initial Values of Sensor
int sensor = 0;

void setup()
{
  pinMode(IRSensorCenterPort, INPUT);
  //setting serial monitor at a default baund rate of 9600
  Serial.begin(9600);
  delay(500);
  Serial.println("IR checking started !!");
  delay(1000);
}
void loop()
{
  sensor = digitalRead(IRSensorCenterPort);
  Serial.print(sensor); //1 - black, 0 - white
  Serial.print("\t");
  delay(1000);
}
