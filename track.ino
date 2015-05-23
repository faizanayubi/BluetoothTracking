int sensor = 8;
void setup() {
  pinMode(sensor, INPUT);
  Serial.begin(9600);      //Begin Serial Communication
}

void loop() {
  int sensorState = digitalRead(sensor);
  Serial.println(sensorState); //Send IR Sensor value to computer
  delay(100);
}
