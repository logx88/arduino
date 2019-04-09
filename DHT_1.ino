#include <DHT.h>
#define DHT_TYPE DHT11

int pin_DHT=3;
int pin_VCC=4;
int pin_GND=2;
DHT dht(pin_DHT,DHT_TYPE);
void setup() {
  // put your setup code here, to run once:
  dht.begin();
  Serial.begin(9600);
  pinMode(pin_VCC,OUTPUT);
  pinMode(pin_GND,OUTPUT);
  //pinMode(pin_DHT,INPUT);
  digitalWrite(pin_VCC,HIGH);
  digitalWrite(pin_GND,LOW);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
 delay(1000);
float t = dht.readTemperature(); // read the Temperature
float h = dht.readHumidity(); // read the Humidity
Serial.print("Temperature:");
Serial.print(t);
Serial.print("[C]  ");
Serial.print("Humidity:");
Serial.print(h);
Serial.print("%\n");
// check for error (isnan : is not a number)
if(isnan(t) || isnan(h)) {
Serial.println("Failed to read from DHT sensor!");
return;
}
  
}
