#include <Servo.h>

//Declaring constants
const int LED_PIN = 4;
const int ECHO_PIN = 11;
const int TRIG_PIN = 10;
const int GATE_PIN = 9;

//Declaring variables
long duration = 0;
float distance = 0;

//Declaring Objects
Servo boomgate;

void setup() {
  //Starting serial monitor
  Serial.begin(9600);

  //Setting LED pin mode to output
  pinMode(LED_PIN,OUTPUT);
  
  //Setting boomgate pin to pin 9
  boomgate.attach(GATE_PIN);
  
  //Setting boom gate angle to zero degree
  boomgate.write(0);
}

void loop() {
  //Triggering trigger pin
  digitalWrite(TRIG_PIN,HIGH);
  digitalWrite(TRIG_PIN,LOW);

  //Reading pulse duration from echo pin
  duration = pulseIn(ECHO_PIN,HIGH);

  //Calculating distance from pulse duration
  distance = duration*(0.03432/2);

  //Opening boom gate when the car is <30 from the sensor
  if(distance<30)
  {
    boomgate.write(90);
    digitalWrite(LED_PIN, HIGH);
  }else{
    digitalWrite(LED_PIN, LOW);
    delay(300);
    boomgate.write(0);
  }

  //Printing the distance
  Serial.print(distance);
  Serial.println(" cm");
}
