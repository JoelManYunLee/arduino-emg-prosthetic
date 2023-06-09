#include <Servo.h>

Servo myservo;
const int buttonPin = 2;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
    pinMode(buttonPin, INPUT); // Set pin 2 to take the input from the button
    myservo.attach(9);
    Serial.begin(9600); // Initialize the serial monitor    
}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState); // Print the state of the button to the serial monitor

  // check if the pushbutton is pressed
  if (buttonState == HIGH) {
    // Close the claw
    myservo.write(180);
  } else {
    // Return to base position
    myservo.write(90);
  }
}