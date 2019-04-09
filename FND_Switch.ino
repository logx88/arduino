int pin_FND_DATA[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int pin_FND_SEL[2] = {1, 0};
uint8_t FND_data[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27,
0x7F, 0x6F};
uint8_t FND_sel_data[2] = {0x3E, 0x3D };
int pin_switch=4;
int pin_led=3;
int cnt=0;
int a=0;




 void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<8; i++)
  {
    pinMode(pin_FND_DATA[i], OUTPUT);
  }
for(int i=0; i<2; i++)
  {
    pinMode(pin_FND_SEL[i], OUTPUT);
  }
    pinMode(pin_switch,INPUT_PULLUP);
    pinMode(pin_led,OUTPUT);
 }


void loop() {
  FND_sel_out(FND_sel_data[1]);
     
        if(digitalRead(pin_switch))
        { 
          FND_data_out(FND_data[cnt]);
          delay(300);
          cnt++;
          if(cnt>9)
          {
            cnt=0;   
          }
        }
 
}


void FND_data_out(uint8_t data)
{
  int i;
  for(i=0; i<8; i++) {
    digitalWrite(pin_FND_DATA[i], (data>>i) & 0x1);
  }
}

void FND_sel_out(uint8_t data)
{
  digitalWrite(pin_FND_SEL[0],LOW);
}
void FND_sel_out(uint8_t data)
{
  digitalWrite(pin_FND_SEL[1],LOW);
}
