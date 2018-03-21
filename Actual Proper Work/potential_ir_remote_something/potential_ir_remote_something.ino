int sensorpin = A1; /*right*/
int val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(sensorpin);
  Serial.println(val);
  delay(400);
}

/*A0 isnt as reliable as A1, and the 'val' increases as the distnace increases, displaying a 
 positive correlation.
 */
