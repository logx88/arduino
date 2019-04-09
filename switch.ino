int pin_switch[3]={10,9,8};
int pin_led[3]={13,12,11};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<3;i++)
  pinMode(pin_led[i],OUTPUT);
  for(int j=0;j<3;j++)
  pinMode(pin_switch[j],INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  
    if(digitalRead(pin_switch[0]))
    {
      digitalWrite(pin_led[0],HIGH);
    }
    else
      digitalWrite(pin_led[0],LOW);
    if(digitalRead(pin_switch[1]))
    {
      digitalWrite(pin_led[1],HIGH);
    }
    else
      digitalWrite(pin_led[1],LOW);
      if(digitalRead(pin_switch[2]))
    {
      digitalWrite(pin_led[2],HIGH);
    }
    else
      digitalWrite(pin_led[2],LOW);
}
