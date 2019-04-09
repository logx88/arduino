int pin_LED[1]={13};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin_LED[0],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
//void serialEvent()
//{
//  char data;
//  data=Serial.read();
//  Serial.print(data);
//}
void serialEvent()
{
  char data; // 문자열을 저장하는 구조체(?)
  data=Serial.read();
  if(data=='o')
  {
    digitalWrite(pin_LED[0],HIGH);
    Serial.println(data);
  }
  else if(data=='x')
  {
    digitalWrite(pin_LED[0],LOW);
    Serial.println(data);
  }
 
}
