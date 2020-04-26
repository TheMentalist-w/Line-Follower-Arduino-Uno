#define sensor 6 
boolean is_on = false;

void setup() {
  pinMode(sensor, INPUT); //Setting the pin to input for reading data
  Serial.begin (9600);
}

void loop() {

  int data = digitalRead(sensor); //Reading data from sensor and storing in variable

  if (data == 1) { // 1 is sent from sensor when loud noise is detected
    if (is_on == true) { // If led is on then turn it off
      Serial.println("off");
      is_on = false;
    }
    else { // else if led is off then turn it on
      Serial.println("on");
      is_on = true;
    }
  }
  delay(10);
}
