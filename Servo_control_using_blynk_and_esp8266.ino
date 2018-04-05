/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 *
 * This example shows how to use ESP8266 Shield via Software Serial
 * (on Uno, Nano...) to connect your project to Blynk.
 *
 * Note: Ensure a stable serial connection to ESP8266!
 *       Firmware version 1.0.0 (AT v0.22) or later is needed.
 *       Set ESP baud rate to 9600. Connect to AT console and call:
 *           AT+UART_DEF=9600,8,1,0,0
 *       In general, Soft Serial is unstable.
 *       It is highly recommended to switch to Hard Serial.
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 * Feel free to apply it to any other example. It's simple!
 *
 **************************************************************/
//#define BLYNK_DEBUG
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266_SoftSer.h>
#include <BlynkSimpleShieldEsp8266_SoftSer.h>

// Set ESP8266 Serial object
#include <SoftwareSerial.h>
#include <Servo.h>
SoftwareSerial EspSerial(2, 3); // RX, TX

ESP8266 wifi(EspSerial);
int x;
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "f3968d870947491882da229f12fe3941";
Servo servo;
const int gasPin = A0;
void setup()
{
  // Set console baud rate
  Serial.begin(9600);
  delay(10);
  // Set ESP8266 baud rate
  // 9600 is recommended for Software Serial
  EspSerial.begin(9600);
  delay(100);

  Blynk.begin(auth, wifi, "Preshy", "preshy@1");
  delay(100);
  servo.attach(5);
}
BLYNK_WRITE(V9)
{ 
  
  x=param.asInt();
   int val;
 val =map( x,0,1023,0,180);
  servo.write(val);
  Serial.println(val);
  delay(10);
  
}

void loop()
{
  
  blynk_run();
  
}

void blynk_run()

{ Blynk.run();
}

void blynk_gas_aquire()
{ 
  Serial.println(analogRead(gasPin));
}


