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
int rainSensor = A0;
const int sensorMin = 0;     // sensor min
const int sensorMax = 1024; // sensor max
 
/* ------------------ */

void setup() {
  Serial.begin(9600);
  dht.begin(); 
}
 
void loop() {
 
 // Luz
  value = analogRead(pinLuz);                
  luz = map(value, 1023, 0, 0, 100);
  Serial.print("Intensidad de luz: ");
  Serial.print(luz, DEC);
  Serial.println("%");
 
 
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
 
 // Lluvia
  int sensorVal = analogRead(rainSensor);
  int range = map(sensorVal, sensorMin, sensorMax, 0, 3); 
  int value = map(sensorVal, sensorMin, sensorMax, 100, 0);
  
 switch (range) { 
  case 0:    // Sensor getting wet
   Serial.println("Lluvia fuerte");
   Serial.print("Cantidad de lluvia: ");
   Serial.print(value,DEC);
   Serial.println("%");
   break;
  case 1:    // Sensor getting wet
   Serial.println("Lluvia suave");
   Serial.print("Cantidad de lluvia: ");
   Serial.print(value,DEC);
   Serial.println("%");
   break;
  case 2:    
   Serial.println("No llueve");
   Serial.print("Cantidad de lluvia: ");
   Serial.print(value,DEC);
   Serial.println("%");
   break;
 }  
  
 
}
