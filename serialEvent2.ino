int pin_num[1]={13};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin_num[0],OUTPUT);
  //Serial.println("Serial Test!!");
  //Serial.print("ECHO >> ");
}

void loop() {
  // put your main code here, to run repeatedly:
//  char data;
//  if(Serial.available()>0)  
//  {
//    data=Serial.read();
//    Serial.print(data);
//    if(data=='o'){
//      digitalWrite(pin_num[0],HIGH);
//      delay(1000);
//      }
//    else if(data=='x'){
//      digitalWrite(pin_num[0],LOW);
//      delay(1000);
//      }
//  }
}

void serialEvent()
{
  char data; // 문자열을 저장하는 구조체(?)
  data=Serial.read();
  Serial.print(data);
  
  if(data=='o'){
  digitalWrite(pin_num[0],HIGH);
  delay(1000);
  }
  else if(data=='x'){
  digitalWrite(pin_num[0],LOW);
  delay(1000);
  }
}
