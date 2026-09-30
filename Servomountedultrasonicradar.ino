#include <Servo.h>

// Hardware Pin Configurations
const int trigPin = 10;
const int echoPin = 11;
const int servoPin = 9;

Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  // 1. Sweep forward from 15 to 165 degrees
  for (int angle = 15; angle <= 165; angle++) {
    takeRadarReading(angle);
  }
  
  // 2. Sweep backward from 165 to 15 degrees
  for (int angle = 165; angle >= 15; angle--) {
    takeRadarReading(angle);
  }
}

// Function that handles moving, measuring, and reporting data
void takeRadarReading(int angle) {
  myServo.write(angle);
  delay(30); // Gives time for servo to reach position
  
  int distance = calculateDistance();

  // Send data to the computer (Format: Angle,Distance.)
  Serial.print(angle);
  Serial.print(",");
  Serial.print(distance);
  Serial.println(".");
}

// Function to calculate distance using the HC-SR04 ultrasonic sensor
int calculateDistance() {
  // Clear the trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send a 10-microsecond sonic pulse to trigger pin
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure how long it took for the echo to bounce back
  long duration = pulseIn(echoPin, HIGH);

  // Convert time into distance (cm) based on the speed of sound
  return duration * 0.034 / 2;
}