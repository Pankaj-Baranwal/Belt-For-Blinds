#include <SoftwareSerial.h>
SoftwareSerial mySerial(1, 0);

#define irLedPin 4
#define irSensorPin 5


String data = 0;
boolean sendReading = false;
int counter = 0;

void setup()
{
    Serial.begin(9600);
    mySerial.begin(9600)
    pinMode(13, OUTPUT);
    pinMode(irSensorPin, INPUT);
    pinMode(irLedPin, OUTPUT);
    delay(100);
}
void loop()
{
  if(!sendReading){
   if(Serial.available() > 0)
     {
        data = Serial.readString();
        Serial.print(data);
        Serial.print("\n");
        int value = data.toInt();
        if(value>=10 && value<100){
          sendReading = true;
          digitalWrite(13, HIGH);
        }
        else if(data == 0){
          sendReading = false;
          digitalWrite(13, LOW);
        }
     }
  }else{
    
  }
}
