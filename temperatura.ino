#include <DHT.h>
 

#define DHTPIN 2
#define DHTTYPE DHT11
int i = 0;

DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(9600);
  dht.begin();
 
}
 
void loop() {
  delay(3000); // 3 segundos
 
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
 
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("DHT Sensor error");
    return;
  }
 
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  if(i != 0) {
    Serial.print("Humedad: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.print("°C     ");
    Serial.print("Índice de calor: ");
    Serial.print(hic);
    Serial.print("°C");
    Serial.print("\n");
  }
  else ++i;
 
}
