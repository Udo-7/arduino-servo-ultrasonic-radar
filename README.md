# Arduino Servo-Mounted Ultrasonic Radar

An HC-SR04 ultrasonic sensor mounted on a servo that sweeps from 15° to 165° and back, measuring the distance at each angle and sending the readings to the computer over serial.

## Hardware
- Arduino board
- HC-SR04 ultrasonic sensor
- Servo motor

## Pins
TRIG: 10, ECHO: 11, Servo: 9

## Usage
Upload the sketch in the Arduino IDE and open the Serial Monitor at 9600 baud. Each line is `angle,distance.`, with the distance in cm.
