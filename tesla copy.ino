#include <Servo.h>

 

Servo myservo;

 

int echoPin = 11;// these define each of the ports on the arduino and sensor

int trigPin = 12;

int IN1 = 4;

int IN2 = 5;

int IN3 = 9;

int IN4 = 10;

 

float duration_us, distance_cm; // float makes each appear as decimals rather than whole numbers

 

void setup()

{

  myservo.attach(3);

  Serial.begin (9600);

  pinMode (trigPin, OUTPUT);// establishes trigpin on the hc sensor as an output

  pinMode (echoPin, INPUT);// establishes echopin as an input

  pinMode(IN1, OUTPUT);// makes in1-4 outputs

  pinMode(IN2, OUTPUT);

  pinMode(IN3, OUTPUT);

  pinMode(IN4, OUTPUT);

}

 

void loop(){

 

  myservo.write(60);

  delay(200);

 

  myservo.write(120);

  delay(200);

 

  digitalWrite(trigPin, HIGH);//triggers the hc sensor to send out a pulse

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

 

  duration_us = pulseIn(echoPin, HIGH);

  distance_cm = 0.017 * duration_us; // distance formula

 

  Serial.print("distance: "); // prints on the serial monitor the distance of the object that the sensor is detecting

  Serial.print(distance_cm);

  Serial.println(" cm");

  delay(50);

 

  if (distance_cm > 50.0) { //Stop

    digitalWrite(IN1, LOW);

    digitalWrite(IN2, LOW);

    digitalWrite(IN3, LOW);

    digitalWrite(IN4, LOW);

    delay(100);

  } else if (distance_cm <= 10) { //Back up

      digitalWrite(IN1, LOW);

      digitalWrite(IN2, HIGH);

      digitalWrite(IN3, HIGH);

      digitalWrite(IN4, LOW);

    delay(100);

  } else if (distance_cm <= 15) { //stop

      digitalWrite(IN1, LOW);

      digitalWrite(IN2, LOW);

      digitalWrite(IN3, LOW);

      digitalWrite(IN4, LOW);

      delay(100);

  } else if (distance_cm <= 50){ // GO

      digitalWrite(IN1, HIGH);

      digitalWrite(IN2, LOW);

      digitalWrite(IN3, LOW);

      digitalWrite(IN4, HIGH);

      delay(100);

// HIGH LOW HIGH LOW = TURN LEFT
// LOW HIGH HIGH LOW = GO BACK
// LOW HIGH LOW HIGH = TURN RIGHT
// HIGH LOW LOW HIGH = GO FORWARD

}}
