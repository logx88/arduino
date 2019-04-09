#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8,7); // 13rs,12rw,11e,10~7:D4~7
 // int pin_LCD_CTRL[3]={13,12,11};
 // int pin_LCD_DATA[4]={10,9,8,7};
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
//  lcd.print("hello!");
//  
//  lcd.setCursor(0,1);
//  lcd.print("EdgeILAB");
//  delay(5000);
  //lcd.clear();
  //lcd.setCursor(0,0);
  //lcd.print("IOT");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  String buffer;
  if(Serial.available()>0)
  {
    buffer=Serial.readString();
  }
  if(buffer !="")
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(buffer);
  }
}
