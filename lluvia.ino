int rainSensor = A0;
const int sensorMin = 0;     // sensor min
const int sensorMax = 1024;  // sensor max

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorVal = analogRead(rainSensor);
  int range = map(sensorVal, sensorMin, sensorMax, 0, 3); // map the sensor range (four options)
  int value = map(sensorVal, sensorMin, sensorMax, 100, 0);
 switch (range) { // range value
  case 0:    // Sensor getting wet
   Serial.println("Flood");
   Serial.print("Cantidad de lluvia: ");
   Serial.print(value,DEC);
   Serial.println("%");
   break;
  case 1:    // Sensor getting wet
   Serial.println("Rain Warning");
   Serial.print("Cantidad de lluvia: ");
   Serial.print(value,DEC);
   Serial.println("%");
   break;
  case 2:    
   Serial.println("Not Raining");
   Serial.print("Cantidad de lluvia: ");
   Serial.print(value,DEC);
   Serial.println("%");
   break;
 }  
  delay(750);
}



