#include <PLab_IRremote.h>
#include <PLab_IRremoteInt.h>
#include <PLab_PushButton.h>
#include <ZumoMotors.h>
#include <Pushbutton.h>

ZumoMotors motors;

const int echoPin = 2;
const int triggerPin = 3;

Pushbutton button(ZUMO_BUTTON);

const int recieverPin = 6;


IRrecv irrecv(recieverPin);
decode_results results;

void setup()
{
  irrecv.enableIRIn(); // Start the receiver
  
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
}

void loop()
{
//  if (irrecv.decode(&results))
//  {
//    switch(results.value) {
//      case IR_2:
//        motors.setSpeeds(400, 400);
//        delay(500);
//        motors.setSpeeds(0,0);
//      break;
//      case IR_5:
//        motors.setSpeeds(-400, -400);
//        delay(500);
//        motors.setSpeeds(0,0);
//      break;
//      case IR_4:
//        motors.setSpeeds(-200, 200);
//        delay(250);
//        motors.setSpeeds(0,0);
//      break;
//      case IR_6:
//        motors.setSpeeds(200, -200);
//        delay(250);
//        motors.setSpeeds(0,0);
//      break;
//    }
//    irrecv.resume();
//  }
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
  if(duration >= 1000){
    motors.setSpeeds(105,100);
    delay(250);
    motors.setSpeeds(0,0);
  }else{
    motors.setSpeeds(200,-200);
    delay(250);
  
  }
}


//
//
//#include <ZumoMotors.h>
//#include <Pushbutton.h>
//
//ZumoMotors motors;
//
//const int echoPin = 2;
//const int triggerPin = 3;
//
//void setup(){
//  Serial.begin(9600);
//  pinMode(triggerPin, OUTPUT);
//  pinMode(echoPin, INPUT);
//  
//  
//  
//}
//void loop(){
//  
//  // Gjør ekkokallet
//  digitalWrite(triggerPin, LOW);
//  delayMicroseconds(2);
//   
//  digitalWrite(triggerPin, HIGH);
//  delayMicroseconds(10);
//   
//  digitalWrite(triggerPin, LOW);
//  // Mål hvor lang tid det tar før ekkoet kommer tilbake
//  long duration = pulseIn(echoPin, HIGH);
//  // Regn ut avstanden
//  int distance = duration * 0.00017;  
//  
//  //DISTANCE er avstanden!
//  if(duration >= 2000){
//    motors.setSpeeds(105,100);
//    delay(250);
//    motors.setSpeeds(0,0);
//  }else{
//    motors.setSpeeds(200,-200);
//    delay(250);
//  }
//}
//        
