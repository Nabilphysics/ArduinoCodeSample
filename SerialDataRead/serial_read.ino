//Written by :https://www.github.com/Nabilphysics/ArduinoCodeSample
//https://www.nabilbd.com   , https://www.linkedin.com/in/nabilphysics/
#include <SoftwareSerial.h>

SoftwareSerial softwareSerial(9, 11); // RX, TX

String receivedStringData = "";
int i = 0;
int k = 0;
String startData = "K";
String endData = "G";

void setup() {
  Serial.begin(115200);
  softwareSerial.begin(115200);
  softwareSerial.println("Experimental Code ...... ");
  delay(2000);
}

void loop() {
    while(Serial.available() > 0){
      char inputData = Serial.read();
      String inputString = String(inputData);
      
      if(inputString.startsWith(startData)){ // Match The Sensor Header Data and start reading to avoid corrupted data
        i = 0; 
      }

    receivedStringData = receivedStringData + inputString;
    i = i + 1;
    
    if(inputString.startsWith(endData)){
      k = i;
    }
    
    if(i == k){
      softwareSerial.print("Total Data: ");softwareSerial.println(receivedStringData);
      receivedStringData = "";
      Serial.flush();
    }
    
  } 
}


