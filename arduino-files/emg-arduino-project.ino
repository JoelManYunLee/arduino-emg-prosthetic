#include <Servo.h>

Servo myservo;

bool closed = false;
int angle = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(A0);
  Serial.println(reading);

  if (reading > 100 && closed == false)
  {
    myservo.attach(9);
    angle = 90;
    myservo.write(angle);
    digitalWrite(2, HIGH);
    closed = true;
    delay(500);
    myservo.detach();
  }
  else if (reading > 100 && closed == true)
  {
    myservo.attach(9);
    angle = 0;
    myservo.write(0);
    digitalWrite(2, LOW);
    closed = false;
    delay(500);
    myservo.detach();
  }
  else 
  {
    myservo.attach(9);
    Serial.println(angle);
    myservo.write(angle);
    delay(500);
    myservo.detach();
  }
}
