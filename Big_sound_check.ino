#include "constants.h"

bool is_on = false;

void setup()
{
  //Setting the pin to input for reading data
  pinMode(SoundSensorPort, INPUT);
  Serial.begin(9600);
  Serial.println("Big sound checking started !!");
}

void loop()
{
  //Reading data from sensor and storing in variable
  int data = digitalRead(SoundSensorPort);

  if (data == 1)
    // 1 is sent from sensor when loud noise is detected
    if (is_on == true)
    {
      // If led is on then turn it off
      Serial.println("off");
      is_on = false;
    }
    else
    {
      // else if led is off then turn it on
      Serial.println("on");
      is_on = true;
    }
  delay(10);
}
