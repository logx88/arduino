int pin_GND = A0; // Ground pin
int pin_VCC = A1; // Power pin
int pin_CDS = A2; // Cds pin
int pin_LED[8] = {13,12,11,10,9,8,7,6};
void setup() {
  // put your setup code here, to run once:
  pinMode(pin_GND,OUTPUT);
  pinMode(pin_VCC,OUTPUT);
  pinMode(pin_CDS,INPUT);
  digitalWrite(pin_GND,LOW);
  digitalWrite(pin_VCC,HIGH);
  Serial.begin(9600);
  for(int i=0;i<8;i++)
  pinMode(pin_LED[i],OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc_data = analogRead(pin_CDS);
  Serial.print("CDS : ");
  Serial.println(adc_data);
  delay(500);
  for(int i=0;i<8;i++)
  digitalWrite(pin_LED[i],LOW);

  
  if(adc_data>=0&&adc_data<200)
  digitalWrite(pin_LED[0],HIGH);
  else if(adc_data>=200&&adc_data<400)
  { 
    for(int i=0;i<2;i++)
    digitalWrite(pin_LED[i],HIGH);
  }
  else if(adc_data>=400&&adc_data<600)
  { 
    for(int i=0;i<3;i++)
    digitalWrite(pin_LED[i],HIGH);
  }
  else if(adc_data>=600&&adc_data<700)
  { 
    for(int i=0;i<4;i++)
    digitalWrite(pin_LED[i],HIGH);
  }
  else if(adc_data>=700&&adc_data<800)
  { 
    for(int i=0;i<6;i++)
    digitalWrite(pin_LED[i],HIGH);
  }
  else if(adc_data>=800&&adc_data>1000)
  { 
    for(int i=0;i<7;i++)
    digitalWrite(pin_LED[i],HIGH);
  }
  else
  { 
    for(int i=0;i<8;i++)
    digitalWrite(pin_LED[i],HIGH);
  }
}
