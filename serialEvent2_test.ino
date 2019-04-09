int pin_num[8]={13,12,11,10,9,8,7,6};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("o: LED >> .... x: LED <<\n");
  pinMode(pin_num[8],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  char data;                      // ** loop함수 이용하여 반복
//  if(Serial.available()>0)  
//  {
//    data=Serial.read();
////    Serial.print(data);
//    if(data=='o'){
//      digitalWrite(pin_num[0],HIGH);
//      delay(1000);
//      Serial.print("o...LED ON\n");
//      }
//    else if(data=='x'){
//      digitalWrite(pin_num[0],LOW);
//      delay(1000);
//      Serial.print("x...LED OFF\n");
//      }
//  }
}

void serialEvent()
{
  char data; // 문자열을 저장하는 구조체(?)
  data=Serial.read();          // ** serialEvent() 함수 이용하여 한번만 실행
  //Serial.print(data);
  char data2;
  char data3;
 while(data=='o')
  {
    Serial.print("o:LED >>>\n");
     for(int i=0;i<8;i++)
     {
      digitalWrite(pin_num[i],HIGH);
      delay(200);
      digitalWrite(pin_num[i],LOW);
      delay(200);
      
      data2=Serial.read();
      if(data2=='x')
     {
      while(data2=='x'){
      Serial.print("x:LED <<<\n");
      for(int i=7;i>=0;i--)
     {
      digitalWrite(pin_num[i],HIGH);
      delay(200);
      digitalWrite(pin_num[i],LOW);
      delay(200);
      data3=Serial.read();
      if(data3=='o')
      data2=data3;
      
     }
     
     }
     }
    }
  }
}
  
