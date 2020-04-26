#define TRIG 7 // Trigger Pin of Ultrasonic Sensor
#define ECHO 6 // Echo Pin of Ultrasonic Sensor

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600); // Starting Serial Terminal
}

float measure(){
  long times;
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  times = pulseIn(ECHO, HIGH);
  return times / 58.00;
}

void loop() {
   Serial.print(measure());
   Serial.println();
   delay(1000);
}
