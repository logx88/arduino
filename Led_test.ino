
int pin_LED[8]={13,12,11,10,9,8,7,6};

void setup() {
  // put your setup code here, to run once:
  for(int i=0;i<8;i++)
  {
    pinMode(pin_LED[i],OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<8;i++)
  {
    digitalWrite(pin_LED[i],HIGH);
    delay(1000);//1000ms = 1초
  }
  for(int i=0;i<8;i++)
  {
    digitalWrite(pin_LED[i],LOW);
    delay(1000);
  }
}
