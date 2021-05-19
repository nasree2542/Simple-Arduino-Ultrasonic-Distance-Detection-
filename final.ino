// This uses Serial Monitor to display Range Finder distance readings

// Include NewPing Library
#include "NewPing.h"

// Hook up HC-SR04 with Trig to Arduino Pin 9, Echo to Arduino pin 10
#define TRIGGER_PIN 3
#define ECHO_PIN 2
#define LED_PIN 7
#define LEDR_PIN 8

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 100  

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;
int oldVal,threshold=10;
int minthreshold=5;
void setup() 
{
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  // Send ping, get distance in cm
  int distance = sonar.ping_cm();
  
  // Send results to Serial Monitor
  //Serial.print("Distance = ");

  
  if (distance >= 50 || distance <= 2) 
  {
    //Serial.println("Out of range");
    
  }
  else 
  {
    //Serial.print(distance);
    //Serial.println(" cm");
    if(abs(distance-oldVal)<threshold){
    //Serial.println("ALERT");
    if(distance<=15){
    digitalWrite(LED_PIN,HIGH);
    digitalWrite(LEDR_PIN,HIGH);
    delay(100);
    digitalWrite(LED_PIN,LOW);
    digitalWrite(LEDR_PIN,LOW);
    }
    Serial.println(String(distance));
    }
    

    //Serial.println(String(0) + "," + String(distance));
    oldVal = distance;
  }
  delay(100);
}
