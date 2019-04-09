#define TILT 2
#define VCC 3
#define GND 4
//int pin_GND=4;
//int pin_VCC=3;
//int pin_TILT=2;
int pin_LED = 13;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(TILT,INPUT);
    pinMode(VCC,OUTPUT);
    pinMode(GND,OUTPUT);
    digitalWrite(VCC,HIGH);
    digitalWrite(GND,LOW);
    pinMode(pin_LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(TILT))
  {
    Serial.println("Tilt OFF"); // HIGH
    digitalWrite(pin_LED,LOW);
    delay(500);
  }
  else
  {
    Serial.println("Tilt ON"); // LOW
    digitalWrite(pin_LED,HIGH);
    delay(500);
  }
  delay(500);
}
