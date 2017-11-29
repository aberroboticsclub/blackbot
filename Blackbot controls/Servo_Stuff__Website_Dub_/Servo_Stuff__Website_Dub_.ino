#include <NewPing.h>
/*#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>*/

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

/*MDNSResponder mdns;

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

ESP8266WebServer server(80);

String webPage = ""

int Esp8266 RX_pin = 8;

int Esp8266 TX_pin = 11;*/

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


void pingUltrasonic() {
  distance = sonar.ping_cm();
  delay(100);
}

void pingUltrasonic1() {
    distance1 = sonar1.ping_cm();
    delay(100);
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
  /* webPage += "<h1>ESP8266 Web Server</h1>
   *  <p>Socket #1 <a href=\"socket1On\"><button>ON</button></a>
   *  &nbsp;<a href=\"socket1Off\"><button>OFF</button></a></p>";
  webPage += "<p>Socket #2 
  <a href=\"socket2On\"><button>ON</button></a>
  &nbsp;<a href=\"socket2Off\"><button>OFF</button></a></p>";
  
  pinMode(gpio0_pin, OUTPUT);
  digitalWrite(gpio0_pin, LOW);
  pinMode(gpio2_pin, OUTPUT);
  digitalWrite(gpio2_pin, LOW);
 
 delay(1000);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    }

Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
if (mdns.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }
*/
void loop() {
  pingUltrasonic();
  pingUltrasonic1();
  Serial.print(distance);
  Serial.println(distance1);
//server.handleClient();
}


