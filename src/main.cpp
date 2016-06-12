#include<Arduino.h>
#include<Servo.h>

Servo myServo;

// Initialize input and output ports
const int outPort = 9;
const int inPort = A0;

int potVal;
int angle;

// Setup the board to attach the controller to output port 9 PWN
void setup() {
  myServo.attach(9);

  Serial.begin(9600);
}

// Looping around just for the fun of it
void loop() {
  // Take in the value of potentiometer
  potVal = analogRead(inPort);
  Serial.print("Potential Val: ");
  Serial.print(potVal);

  // Map input range from 0->1023 received from potVal to output between 0->179 // degree in output pin
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print("Angle: ");
  Serial.println(angle);

  // Write the angle into the servo motor
  myServo.write(angle);
  delay(15);
}
