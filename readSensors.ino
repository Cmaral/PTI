#include <DHT.h>
 
// Variables sensor de humedad y temperatura
#define DHTPIN 2
#define DHTTYPE DHT11
int i = 0;
float h = 0;
float t = 0;
float f = 0;
float hif = 0;
float hic = 0;

// Variables sensor de luz
int pinLuz = 3; 
int value = 0; 
int luz = 0;

DHT dht(DHTPIN, DHTTYPE);

// Variables sensor de lluvia
int pinLluvia = A0;
const int sensorMin = 0;     // sensor min
const int sensorMax = 1024; // sensor max
 
/* ------------------ */

void setup() {
  Serial.begin(9600);
  dht.begin(); 
}
 
void loop() {

  delay(3000);
 
 // Luz
  value = analogRead(pinLuz);                
  luz = map(value, 1023, 0, 0, 100);
  
 
 
 // Temperatura y humedad
  h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);
 
  /*if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("DHT Sensor error");
    return;
  }*/
 
  hif = dht.computeHeatIndex(f, h);
  hic = dht.computeHeatIndex(t, h, false);
  
 // Lluvia
  int sensorVal = analogRead(pinLluvia);
  int range = map(sensorVal, sensorMin, sensorMax, 0, 3); 
  int value = map(sensorVal, sensorMin, sensorMax, 100, 0);

  t=t-3;
  hic = hic-3;
  // Luz
  Serial.println(luz, DEC);
  delay(1000);
  // Humedad
  Serial.println(h);
  delay(1000);
  // Temperatura
  Serial.println(t);
  delay(1000);
  // Indice de calor
  Serial.println(hic);
  delay(1000);
 //  Lluvia
  Serial.println(value,DEC);
  delay(1000);

 
}
