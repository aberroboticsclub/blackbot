#include <NewPing.h>
#include <Servo.h>

#define lmf 5
#define lmr 9
#define rmf 6
#define rmr 10

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

int i = 0;
int distance1 = 0;
int distance = 0;
int bigDistance = 0;

void forward() {
  digitalWrite(lmf , HIGH);
  digitalWrite(lmr , LOW);
  digitalWrite(rmf , HIGH);
  digitalWrite(rmr , LOW);
}

void backward() {
  digitalWrite(lmf , LOW);
  digitalWrite(lmr , HIGH);
  digitalWrite(rmf , LOW);
  digitalWrite(rmr , HIGH);
}

void left() {
  digitalWrite(lmf , HIGH);
  digitalWrite(lmr , LOW);
  digitalWrite(rmf , LOW);
  digitalWrite(rmr , HIGH);
}

void right() {
  digitalWrite(lmf , LOW);
  digitalWrite(lmr , HIGH);
  digitalWrite(rmf , HIGH);
  digitalWrite(rmr , LOW);
}

void bStop() {
  digitalWrite(lmf, LOW);
  digitalWrite(lmr , LOW);
  digitalWrite(rmf , LOW);
  digitalWrite(rmr , LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode (lmf , OUTPUT);
  pinMode (lmr , OUTPUT);
  pinMode (rmf , OUTPUT);
  pinMode (rmr , OUTPUT);
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
  if ((distance < 20) && (distance1 < 20)) {
    backward();
    delay(500);
    right();
    delay(250);
    pingUltrasonic();
    left();
    delay(500);
    pingUltrasonic1();
    right();
    delay(250);
      if (distance < distance1) {
        left();
        delay(500);
        forward(); 
      }
      else if (distance > distance1) {
        right();
        delay(500);
        forward();
      }
      else {
        bStop();
      }
    abc();
  }
    else if (distance1 < 20) {
      right();
      delay(750);
  }
    else if (distance < 20) {
      left();
      delay(750);
  }
}
