#include <MsTimer2.h>

#include <TimerOne.h>

int pin_echo=4;
int pin_trig=3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin_echo,INPUT);
  pinMode(pin_trig,OUTPUT);
  //digitalWrite(pin_echo,
  Timer1.initialize(500000);
  Timer1.attachInterrupt(TimerISR);
  MsTimer2::set(700,Timer2ISR);
  MsTimer2::start();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
void TimerISR()
{
  float distance;
  
  digitalWrite(pin_trig, LOW);
  delayMicroseconds(10); // 10마이크로 세크
  digitalWrite(pin_trig, HIGH); // 10us동안 HIGH 유지

  distance=pulseIn(pin_echo,HIGH) / 58.2;

  Serial.print(distance);
  Serial.println("cm");

}
void Timer2ISR()
{
  Serial.println("Timer2 Interrupt");
}
