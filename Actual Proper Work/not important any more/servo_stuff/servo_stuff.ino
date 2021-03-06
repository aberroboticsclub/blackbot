#include <NewPing.h>

#define leftMotorForward 5
#define leftMotorReverse 9
#define rightMotorForward 6
#define rightMotorReverse 10

#define leftTriggerPin A3
#define leftEchoPin A2
#define rightTriggerPin 2
#define rightEchoPin 3

#define switchOne 7
#define switchTwo 4

NewPing sonar(rightTriggerPin , rightEchoPin , 400);
NewPing sonar1(leftTriggerPin , leftEchoPin , 400);

#include <Servo.h>
Servo ultrasonicServo1;
Servo ultrasonicServo;

int pos;

int distance1 = 0;

int distance = 0;

void forward() {
  digitalWrite(leftMotorForward , HIGH);
  digitalWrite(leftMotorReverse , LOW);
  digitalWrite(rightMotorForward , HIGH);
  digitalWrite(rightMotorReverse , LOW);
}

void backward() {
  digitalWrite(leftMotorForward , LOW);
  digitalWrite(leftMotorReverse , HIGH);
  digitalWrite(rightMotorForward , LOW);
  digitalWrite(rightMotorReverse , HIGH); 
}

void left() {
  digitalWrite(leftMotorForward , HIGH);
  digitalWrite(leftMotorReverse , LOW);
  digitalWrite(rightMotorForward , LOW);
  digitalWrite(rightMotorReverse , HIGH);
}

void right() {
  digitalWrite(leftMotorForward , LOW);
  digitalWrite(leftMotorReverse , HIGH);
  digitalWrite(rightMotorForward , HIGH);
  digitalWrite(rightMotorReverse , LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode (leftMotorForward , OUTPUT);
  pinMode (leftMotorReverse , OUTPUT);
  pinMode (rightMotorForward , OUTPUT);
  pinMode (rightMotorReverse , OUTPUT); 
  ultrasonicServo.attach(12);
  ultrasonicServo.write(900);
  ultrasonicServo1.attach(12);
  ultrasonicServo1.write(900);
}

void loop() {
  pingUltrasonic();
  pingUltrasonic1();
  Serial.print(distance);
  Serial.println(distance1);
}

void pingUltrasonic() {
  distance = sonar.ping_cm();
  delay(100);
}

void pingUltrasonic1() {
    distance1 = sonar1.ping_cm();
    delay(100);
}

