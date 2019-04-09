void setup() {
  // put your setup code here, to run once:
  unsigned char bit=0xff;
  Serial.begin(9600);

  Serial.println("3bit Clear");
  bit&=~(0x1<<3);
  Serial.println(bit,BIN);
  Serial.println("7bit & 4bit clear");
  bit &= ~((0x1<<6)|(0x1<<4));
  Serial.println(bit,BIN);
  Serial.println("6Bit Set");
  bit |=(0x1 <<6);
  Serial.println(bit,BIN);

  Serial.println("5Bit detecting");
  if(bit&(0x1<<5))
  {
    Serial.println("true");
  }
  else
  {
    Serial.println("False");
  }
  Serial.println("3Bit detecting");
  bit&(0x1<<3)?Serial.println("3bit True"):Serial.println("3bit False");
//  switch(bit&(0x1<<3))
//  {
//    case 0: 
//    Serial.println("False");
//    break;
//    case 1: 
//    Serial.println("True");
//    break;
//  }

  bit^=(0x1<<4);
  Serial.println("4bit Invert1");
  Serial.println(bit,BIN);
  bit^=(0x1<<4);
  Serial.println("4bit Invert2");
  Serial.println(bit,BIN);
}

void loop() {
  // put your main code here, to run repeatedly:

}
