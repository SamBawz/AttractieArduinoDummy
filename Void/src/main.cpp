#include <Arduino.h>

int power;
bool start = false;
bool reverse = false;
char receiveVal;

int ldrPin = A0;

String SerieleCom = "";
bool startCommunication = false;

const char startChar = '#';
const char endChar = '%';

void runAttractionCommand(String command) {
String ackStatus = "ACK";

  //Snelheids instellingen
  if(command.equals("speed=0")) {
  }
  else if(command.equals("speed=1")) {
  }
  else if(command.equals("speed=2")) {
  }
  else if(command.equals("speed=3")) {
  }
  else if(command.equals("speed=4")) {
  }

  //Reverse commando
  else if(command.startsWith("reverse=")) {
    int index = command.indexOf('=');
    String letter = command.substring(index+1);
    letter.trim();
    if (letter.equals("F")) {
      reverse = false;
    }
    else if(letter.equals("T")) {
      reverse = true;
    }
  } 

  //Geef de ldr waarde door
  else if (command.equals("send")) {
    Serial.println(75);
  }

  else if(command.equals("power=")) {
     int index = command.indexOf('=');
     String letter = command.substring(index+1);
     letter.trim();
     if (letter.equals("F")) {
       start = false;
     }
     else if(letter.equals("T")) {
       start = true;
     }  
  }

  //Stuur de acknowledgement status
  else{
    String ackStatus = "NACK";
  }
  Serial.println(ackStatus);
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)  
  {           
    char readByte = Serial.read(); 
    //Start de attractie
    if(readByte == startChar)   {
      SerieleCom = "";
      startCommunication = true;
    }
    else if (startCommunication)
    {
      if(readByte == endChar){
        startCommunication = false;
        runAttractionCommand(SerieleCom);
      }
      else
      {
        SerieleCom += readByte;
      }
    }
  }   

  if (start) {

  }
}