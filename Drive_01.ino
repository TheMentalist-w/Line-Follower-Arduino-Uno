// IR Sensor
#define IRsensor1 A0      //left
#define IRsensor2 A1      //middle
#define IRsensor3 A2      //right

// Initial Values of Sensors
int sensors[3] = {0, 0, 0};

int error = 0;

void setup(){
  pinMode(IRsensor1, INPUT);
  pinMode(IRsensor2, INPUT);
  pinMode(IRsensor3, INPUT);
  
  Serial.begin(9600);                     //setting serial monitor at a default baund rate of 9600
  delay(500);
  Serial.println("Started !!");
  delay(1000);
}

// Reading values of IRsensors
void readSensors(){
  sensors[0] = digitalRead(IRsensor1);
  sensors[1] = digitalRead(IRsensor2);
  sensors[2] = digitalRead(IRsensor3);
}

// Checking the right route
void chooseRoute(){
  if(sensors[0] == 0 and sensors[1] == 0 and sensors[2] == 0){      //no line detected - stop condition
    error = 10;
  }
  else if(sensors[0] == 1 and sensors[1] == 0 and sensors[2] == 0){   //turn left
    error = -2;
  }
  else if((sensors[0] == 0 and sensors[1] == 1 and sensors[2] == 0) or (sensors[0] == 1 and sensors[1] == 1 and sensors[2] == 1)){   //go forward
    error = 0;
  }
  else if(sensors[0] == 0 and sensors[1] == 0 and sensors[2] == 1){   //turn right
    error = 2;
  }
  else if(sensors[0] == 1 and sensors[1] == 1 and sensors[2] == 0){   //slight turn left
    error = -1;
  }
  else if(sensors[0] == 0 and sensors[1] == 1 and sensors[2] == 1){   //slight turn right
    error = 1;
  }
}

void loop(){
  readSensors();
  chooseRoute();

  Serial.println(error);
  
  delay(1000);

}
