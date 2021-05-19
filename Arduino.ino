#include "NewPing.h"

#define TRIGGER_PIN 3
#define ECHO_PIN 2
#define BUZZ_PIN 7
#define LEDR_PIN 8

#define MAX_DISTANCE 100  

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
  int distance = sonar.ping_cm();
  
  if (distance <= 50 && distance >= 0) 
  {

    if(abs(distance-oldVal)<threshold){
        if(distance<=15){
            digitalWrite(BUZZ_PIN,HIGH);
            digitalWrite(LEDR_PIN,HIGH);
            delay(100);
            digitalWrite(BUZZ_PIN,LOW);
            digitalWrite(LEDR_PIN,LOW);
        }
    Serial.println(String(distance));
    }
    oldVal = distance;
  }
  delay(100);
}
