# Belt for Blinds

An android application which takes as input the distance data from an **Ultrasonic sensor** connected to an Arduino board.  
The data is transmitted over Bluetooth and the application processes the data to output as speech a suitable message so that the visually impaired can find their way around.  
Here is a video demonstration: https://www.youtube.com/watch?v=nyt1adewqL4

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.  
Clone this project. `git clone https://github.com/Pankaj-Baranwal/Belt-For-Blinds`
Open in **Android Studio**
The folder `bluetooth_working` contains the Arduino code for Ultrasonic sensor control which needs to be burnt on an Arduino board.

### Prerequisites

What things you need to install the software
- Arduino IDE
- Android Studio

## Deployment

* Connect Ultrasonic sensor (like HC-SR04 model) to Arduino using this guide: http://playground.arduino.cc/Main/UltrasonicSensor  
* Connect Bluetooth module to Arduino with primary RX and TX so that `Serial.print` command works.
* Run the installed app on an Android phone and connect to the Bluetooth module which has default name as HC-05.
