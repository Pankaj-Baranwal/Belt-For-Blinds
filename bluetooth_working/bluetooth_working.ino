#include <SharpIR.h>

//#include <SoftwareSerial.h>
#define irSensorPin A4       // IR sensor on this pin

int i = 0;
int x = 50;
int x_init = 0;

String data = 0;
boolean sendReading = false;
int counter = 0;

SharpIR sharp(irSensorPin, 25, 93, 20150);

//int irRead(int readPin, int triggerPin); //function prototype

void setup()
{
    Serial.begin(9600);
//    mySerial.begin(9600);
//    pinMode(ultraSoundSignal,OUTPUT);
//  pinMode(irSensorPin, INPUT);
//  pinMode(irSensorPin, OUTPUT);
  delay(100);
}
void loop()
{
//  if(!sendReading){
//   if(Serial.available() > 0)
//     {
//        data = Serial.readString();
//        Serial.print(data);
//        Serial.print("\n");
//        int value = data.toInt();
//        if(value>=10 && value<100){
//          sendReading = true;
////          digitalWrite(13, HIGH);
//        }
//        else if(data == 0){
//          sendReading = false;
//        }
//     }
//  }else{
//    int value = data.toInt();
//    if(counter < value){
          x_init = x;
          x = sharp.distance();
          if (x<20 && x_init>20){
          counter = counter + 1;
          Serial.print('#');
          Serial.print(counter); //display the results
          Serial.print('~');
          delay(50);
          }
//          mySerial.println(millis());
//    }else{
//      counter = 0;
//      sendReading = false;
//    }
}

int irRead(int readPin, int triggerPin)
{
  int halfPeriod = 13; //one period at 38.5khZ is aproximately 26 microseconds
  int cycles = 38; //26 microseconds * 38 is more or less 1 millisecond
  int i;
  for (i=0; i <=cycles; i++)
  {
    digitalWrite(triggerPin, HIGH); 
    delayMicroseconds(halfPeriod);
    digitalWrite(triggerPin, LOW); 
    delayMicroseconds(halfPeriod - 1);     // - 1 to make up for digitaWrite overhead    
  }
  return digitalRead(readPin);
}
//
//unsigned long ping()
//{ 
//  pinMode(ultraSoundSignal, OUTPUT); // Switch signalpin to output
//  digitalWrite(ultraSoundSignal, LOW); // Send low pulse
//  delayMicroseconds(2); // Wait for 2 microseconds
//  digitalWrite(ultraSoundSignal, HIGH); // Send high pulse
//  delayMicroseconds(5); // Wait for 5 microseconds
//  digitalWrite(ultraSoundSignal, LOW); // Holdoff
//  pinMode(ultraSoundSignal, INPUT); // Switch signalpin to input
//  digitalWrite(ultraSoundSignal, HIGH); // Turn on pullup resistor
//  // please note that pulseIn has a 1sec timeout, which may
//  // not be desirable. Depending on your sensor specs, you
//  // can likely bound the time like this -- marcmerlin
//  // echo = pulseIn(ultraSoundSignal, HIGH, 38000)
//  echo = pulseIn(ultraSoundSignal, HIGH); //Listen for echo
//  ultrasoundValue = (echo / 58.138) * .39; //convert to CM then to inches
//  return ultrasoundValue;
//}
