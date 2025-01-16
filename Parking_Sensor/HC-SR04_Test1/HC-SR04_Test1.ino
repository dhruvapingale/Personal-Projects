const int trigPin = 12;
const int echoPin = 11;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.print("Ultrasound Sensor activated...");

}

void loop() {
  // put your main code here, to run repeatedly:
 // I'm putting the loop code here until it cooperates
   // Clear the Prox Sensor
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  // Send the trigger signal
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  // Send the echo signal, calculate the distance
  duration = pulseIn(echoPin,HIGH);
  distance = (.0343*duration)/2;
  // Print the distance
  Serial.print('\n');
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("cm");
  Serial.print('\n');
}
