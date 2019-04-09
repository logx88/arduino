void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial Test!!");
  Serial.print("ECHO >> ");
}

void loop() {
  // put your main code here, to run repeatedly:
  char data='a'; // pc에서 들어온 문자 데이터를 저장할 변수
  if(Serial.available()>0)
  {
    data=Serial.read();
    Serial.print(data);
  }
}
