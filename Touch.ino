long timer1 = 0, timer2 = 0;
int Touch_flag = 1;
int pin_TOUCH_D=A3;
int pin_LED=13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin_TOUCH_D, INPUT);
  pinMode(pin_LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pin_TOUCH_D))
  {
    timer1 = millis();
    // 16.6ms High read
    if((timer1 - timer2) < 18)
    {
      if(Touch_flag == 0)
        {
          Serial.println("Touch On");
          Touch_flag = 1;
          digitalWrite(pin_LED,HIGH);
        }
    }
     timer2 = timer1;
   }

   else
   {
  // always Low
      if((millis() - timer1) > 18)
        {
        if(Touch_flag)
          {
            // print "Touch Off"
            Serial.println("Touch Off");
            Touch_flag = 0;
            digitalWrite(pin_LED,LOW);
          }
        }
    }
   
}
