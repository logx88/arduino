void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial Test!!");
  Serial.print("ECHO >> ");
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
void serialEvent()
{
  char data;
  data=Serial.read();
  Serial.print(data);
}
//void serialEvent()
//{
//  String data; // 문자열을 저장하는 구조체(?)
//  data=Serial.readString();
//  Serial.println(data);
//}
