int pin_FND_DATA[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int pin_FND_SEL[2] = {5, 4};//, 3, 2, 1, 0};
uint8_t FND_data[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27,
0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
uint8_t FND_sel_data[2] ={0x3E, 0x3D};//, 0x3B, 0x37, 0x2F, 0x1F };
int pin_switch=3;
int cnt_1=0;
int cnt_10=0;
int a=0,b=0,c=0;
void setup() {
  // put your setup code here, to run once:
  for(int i=0; i<8; i++)
  {
    pinMode(pin_FND_DATA[i], OUTPUT);
  }
for(int i=0; i<6; i++)
  {
    pinMode(pin_FND_SEL[i], OUTPUT);
  }
    pinMode(pin_switch,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    FND_sel_out(FND_sel_data[1]);
    FND_data_out(FND_data[b]);
    delay(10);
    FND_sel_out(FND_sel_data[0]);
    FND_data_out(FND_data[a]);
    delay(10);

    if(digitalRead((pin_switch)))
    {
      c=1;  
    }
    if(c==1&&!digitalRead((pin_switch)))
    {
      a++;
      c=0;
    }
    if(a==10)
    {
      a=0;
      b++;
    }
    if(b==10)
    {
      b=0;
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
  int i;
  for(i=0; i<2; i++)
  {
    digitalWrite(pin_FND_SEL[i], (data>>i) & 0x1);
  }
}
