const int trigPin = 12;
const int echoPin = 11;
long duration;
int distance_cm;
int distance_in;
int distance_ft;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.print("Ultrasound Sensor activated...");

}

void loop() {
  // put your main code here, to run repeatedly:

  // Send the trigger signal
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  // Send the echo signal, calculate the distance
  duration = pulseIn(echoPin,HIGH);
  distance_cm = (.0343*duration)/2;
  distance_in = distance_cm/2.54;
  distance_ft = distance_in/12;
  // Print the distance
  Serial.print('\n');
  Serial.print("Distance: ");
  if (distance_in > 12){
    Serial.print(distance_ft);
    Serial.print(" ft ");
    Serial.print(distance_in-(12*distance_ft));
    Serial.print(" in");
  }
  else{
    Serial.print(distance_in);
    Serial.print(" in");
  }
  Serial.print('\n');
}
