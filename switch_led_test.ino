int pin_switch=4;
int pin_led=3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //for(int i=0;i<3;i++)
  pinMode(pin_led,OUTPUT);
  //for(int j=0;j<3;j++)
  pinMode(pin_switch,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  
    if(digitalRead(pin_switch))
    {
      digitalWrite(pin_led,HIGH);
    }
    else
      digitalWrite(pin_led,LOW);

}
