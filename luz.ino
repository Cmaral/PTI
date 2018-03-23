int sensorPin = 3; 
int value = 0; 
int luz = 0;

void setup() {
  Serial.begin(9600); 
} 

void loop() {
  value = analogRead(sensorPin); 
               
  luz = map(value, 1023, 0, 0, 100);
  Serial.print("Intensidad de luz: ");
  Serial.print(luz, DEC);
  Serial.println("%");
  delay(1000); 
}
