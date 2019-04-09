
#define switch1 3
int pin_FND_DATA[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int pin_FND_SEL[2] = {5, 4};//, 3, 2, 1, 0};
uint8_t FND_data[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27,
0x7F, 0x6F};
uint8_t FND_sel_data[2] ={0x3E, 0x3D};//, 0x3B, 0x37, 0x2F, 0x1F };
volatile int count =0;

void setup() {
  // put your setup code here, to run once:
  attachInterrupt(digitalPinToInterrupt(switch1),switch_ISR,FALLING); // 핀번호,호출 함수,rising(falling)
  
  for(int i=0;i<8;i++)
  pinMode(pin_FND_DATA[i],OUTPUT);
  for(int i=0;i<2;i++)
  pinMode(pin_FND_SEL[i],OUTPUT);
  
  pinMode(switch1,INPUT);

}

void loop() {
  if(count%2==0)
  {
    FND_sel_out(FND_sel_data[0]);
    for(int i=0;i<10;i++)
    {
      FND_data_out(FND_data[i]);
      delay(1000);
      while(count%2==1)
      {
       FND_sel_out(FND_sel_data[0]);
       FND_data_out(FND_data[i]); 
      }
    }
  }
}

void switch_ISR()
{
  count++;
  
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
