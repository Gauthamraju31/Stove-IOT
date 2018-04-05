//#define BLYNK_DEBUG
#define BLYNK_PRINT Serial    
#include <ESP8266_SoftSer.h>
#include <BlynkSimpleShieldEsp8266_SoftSer.h>

// Set ESP8266 Serial object
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

ESP8266 wifi(EspSerial);
int x,y=LOW;
int tempPin = 1;
int valtemp;

char auth[] = "f3968d870947491882da229f12fe3941";
Servo servo;

void setup()
{
  
  Serial.begin(9600);
  delay(10);
  
  EspSerial.begin(9600);
  delay(100);

  Blynk.begin(auth, wifi, "Preshy", "preshy@1");
  delay(100);
  servo.attach(5);
}


void loop()
{
  
  blynk_run();
  
  blynk_lm35();
}
  


void blynk_run()

{ Blynk.run();
}

void blynk_lm35()
{
  valtemp = analogRead(tempPin);
float mv = ( valtemp/1024.0)*5000; 
float cel = mv/10;

Blynk.virtualWrite(V5,cel);
}

  BLYNK_WRITE(V9)
{ 
  x=param.asInt();
   int val;
   
  switch(val)
  {
    case 0:
       servo.write(0);
       Serial.println(val);
    case 1:
        servo.write(60);
        Serial.println(val);
    case 2:
         servo.write(120);
         Serial.println(val);
    case 3:
         servo.write(180);
         Serial.println(val);
  }
 
  delay(10);
  
}
   BLYNK_WRITE(V0)
{ 
  
  y=param.asInt();
  Serial.print(y);
  
}
