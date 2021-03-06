#include <Servo.h> 
Servo myservo; 
int pos; 
int pot=0;
int tempPin = 1;
int valtemp;

const int buttonPin = 8;   
const int ledPin = 13;     
int ledState = HIGH;       
int buttonState;            
int lastButtonState = LOW;   
long lastDebounceTime = 0; 
long debounceDelay = 50;    
void setup()
{
  Serial.begin(9600);
  pinMode(pot,INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, ledState); 
  myservo.attach(5);
}

void loop()
{
  BOUNCE();
  if (ledState==HIGH)
  {
    Serial.println("manual");
    pos=analogRead(pot);
    pos=map(pos,0,1023,0,180);
    myservo.write(pos);
    Serial.print(pos);
  }
  else
  {
    Serial.println("auto");
     autocontrol();
     
  }
  
}
void BOUNCE()
{
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading != buttonState) 
    {
      buttonState = reading;
      if (buttonState == HIGH) 
      {
        ledState = !ledState;
      }
    }
  }
  digitalWrite(ledPin, ledState);
  lastButtonState = reading;
}


void autocontrol()
{
  valtemp = analogRead(tempPin);
     float mv = ( valtemp/1024.0)*5000; 
     float cel = mv/10;
     Serial.print(cel);
    cel=map(cel,30,125,0,179);
      myservo.write(cel);
      Serial.println(cel);
}

