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

char input;

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

void bStop() {
  digitalWrite(leftMotorForward , LOW);
  digitalWrite(leftMotorReverse , LOW);
  digitalWrite(rightMotorForward , LOW);
  digitalWrite(rightMotorReverse , LOW);
}

void setup() {
  Serial.begin(9600);
  //pinMode (myMotor , OUTPUT);
  pinMode (leftMotorForward , OUTPUT);
  pinMode (leftMotorReverse , OUTPUT);
  pinMode (rightMotorForward , OUTPUT);
  pinMode (rightMotorReverse , OUTPUT); 
}

void loop() {
  if (Serial.available()) {
    input = Serial.read();

    switch(input) {

      case 'w':
        forward();

        break;

      case 'a':
        left();

        break;

      case 's':
        backward();

        break;

      case 'd':
        right();
        break;

      case 'q':
      bStop();  
    }
  }
}

