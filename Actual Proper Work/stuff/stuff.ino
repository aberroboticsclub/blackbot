#include <NewPing.h>
#include <Servo.h>

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

Servo ultrasonicServo1;
Servo ultrasonicServo;

char input;

int distance1 = 0; 
int distance = 0;
int bigDistance = 0;

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

void bStop() {
  digitalWrite(leftMotorForward , LOW);
  digitalWrite(leftMotorReverse , LOW);
  digitalWrite(rightMotorForward , LOW);
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
  abc();
  bigDistance = (distance + distance1);
  movingItNow();
}

void abc() {
  pingUltrasonic();
  pingUltrasonic1();
  //Serial.print("left : ");
  Serial.print(distance);
  Serial.print(" ,  ");
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

void movingItNow() {
  if (distance < 20) {
    left();
  }
  else if (distance1 < 20) {
    right();
  }
  else if (distance = 0) {
    forward();
  }
  else if (distance1 = 0) {
    forward();
  }
  else if ((bigDistance < 30) & (distance < 20) % (distance1 < 20)) {
    bStop();
    delay(200);
    if (distance1 > 20) {
      left();
      delay(500);
      forward();
    }
    else if (distance < 20) {
      right();
      delay(500);
      forward();
    }
    else {
      backward();
      delay(500);
      right();
    }
  }
  else {
    forward();
  }
}

