#include <Servo.h>

Servo myservo;

bool closed = false;
int angle = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A0);
  Serial.println(reading);

  if (reading > 500 && closed == false)
  {
    angle = 90;
    myservo.write(angle);
    digitalWrite(2, HIGH);
    closed = true;
    delay(500);
  }
  else if (reading > 500 && closed == true)
  {
    angle = 0;
    myservo.write(angle);
    digitalWrite(2, LOW);
    closed = false;
    delay(500);
  }
  else if (reading < 500)
  {
    myservo.write(angle);
  }
}
