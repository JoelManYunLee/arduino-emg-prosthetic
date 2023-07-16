#include <Servo.h>

Servo myservo;

bool closed = false;
int angle = 0;
//const int sampleSize = 20;
//int sample[sampleSize];

// int threshold = 100;
// int buffer = 200;
// unsigned long startBuffer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);
  // myservo.attach(9);
}

void loop() {
  //BUFFER CODE
  // // put your main code here, to run repeatedly:
  // int reading = analogRead(A0);
  // Serial.println(reading);

  // if(reading > threshold){
  //   if(!closed){
  //     closed = true;
  //     startBuffer = millis();
  //     //myservo.detach();
  //   }
  //   else if(millis() - startBuffer >= buffer){
  //     myservo.attach(9);
  //     angle = 90;
  //     myservo.write(angle);
  //     digitalWrite(2, HIGH);
  //     //myservo.detach();
  //   }
  // }
  
  // else {
  //   if (closed) {
  //     closed = false;
  //     startBuffer = millis();
  //   } 
    
  //   else if (millis() - startBuffer >= buffer) {
  //     angle = 0;
  //     myservo.write(angle);
  //     digitalWrite(2, LOW);
  //     //myservo.detach();    
  //   }
  // }

  // Serial.println(closed);
  // delay(10);

  //WORKING CODE BEFORE
  int reading = analogRead(A0);
  Serial.println(reading);
 if (reading > 100 && closed == false) {
    myservo.attach(9);
    angle = 0;
    myservo.write(angle);
    digitalWrite(2, HIGH);
    closed = true;
    delay(500);
    myservo.detach();
  }
  else if (reading > 100 && closed == true) {
    myservo.attach(9);
    angle = 90;
    myservo.write(angle);
    digitalWrite(2, LOW);
    closed = false;
    delay(500);
    myservo.detach();
  }
  //CONTINUOUS
  else if (reading < 100 && closed == true ) {
    myservo.attach(9);
    myservo.write(0);
  }
    //SEPARATE BATTERY TEST
    // myservo.attach(9);
    // myservo.write(180);
    // delay(1000); 
  
    // myservo.write(0);
    // delay(1000); 

}



// int averageCalculator(int values[], int length) {
//   int sum = 0;
//   for (int i = 0; i < length; i++) {
//     sum += values[i];
//   }
//   return sum / length;
// }
