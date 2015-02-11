#include <ZumoMotors.h>
#include <Pushbutton.h>

ZumoMotors motors;

const int echoPin = 2;
const int triggerPin = 3;

void setup(){
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  
  
}
void loop(){
  
  // Gjør ekkokallet
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
   
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
   
  digitalWrite(triggerPin, LOW);
  // Mål hvor lang tid det tar før ekkoet kommer tilbake
  long duration = pulseIn(echoPin, HIGH);
  // Regn ut avstanden
  int distance = duration * 0.00017;  
  
  //DISTANCE er avstanden!
  if(duration >= 2000){
    motors.setSpeeds(105,100);
    delay(250);
    motors.setSpeeds(0,0);
  }else{
    motors.setSpeeds(200,-200);
    delay(250);
  }
}
