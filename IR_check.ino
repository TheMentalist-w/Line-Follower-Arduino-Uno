// IR Sensor
int sensor1 = 2;

// Initial Values of Sensor
int sensor = 0;

void setup()
{
  pinMode(sensor1, INPUT);
  
  Serial.begin(9600);                     //setting serial monitor at a default baund rate of 9600
  delay(500);
  Serial.println("Started !!");
  delay(1000);
}
void loop()
{
  sensor = digitalRead(sensor1);
  Serial.print(sensor);                   //1 - black, 0 - white
  Serial.print("\t");
  delay(1000);
}
