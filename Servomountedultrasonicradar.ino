#include  <Servo.h>
// Define pins for Sensor
const int trigPin = 10;
const int echoPin = 11;
// Define variables for distance measurement
long duration;
int distance;
// Create Servo object
Servo myServo;




void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); // Sets trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echopin as an Input
Serial.begin(9600); // Starts serial communication
myServo.attach(9); // Defines pin 9 for servo
}

void loop() {
  // put your main code here, to run repeatedly:
  // Sweep from 15 to 165 degrees
for(int angle = 15; angle <= 165; angle += 1){
myServo.write(angle);
delay(30); // Gives time for servo to reach position

distance = calculateDistance();

// Output parameters 
Serial.print(angle);
Serial.print(",");
Serial.print(distance);
Serial.println(".");
}
// Sweep back from 165 to 15 degrees
for (int angle = 165; angle>= 15; angle -= 1){
myServo.write(angle);
delay(30);
distance = calculateDistance();

Serial.print(angle);
Serial.print(",");
Serial.print(distance);
Serial.println(".");
}
}
// Function to calculate distance measured by HC-SR04
int calculateDistance() {
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Send a 10ms pulse to trigger pin
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Read echo pin duration in ms
duration = pulseIn(echoPin, HIGH);

// Calculate distance in cm (Speed of sound = 0.034 cm/us)
distance = duration*0.034/2;
return distance;
}
