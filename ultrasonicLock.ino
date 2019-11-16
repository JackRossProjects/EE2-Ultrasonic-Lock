#include <Servo.h>
int servoPin = 3;
Servo Servo1;
int LED1 = 13;
int LED2 = 12;
const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
int counter = 0;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   Servo1.attach(servoPin); 
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
}

void loop() {
   long duration, inches, cm;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   digitalWrite(LED1,HIGH);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
   if (inches < 4) {
     counter += 1;
   }
   if (counter > 15) {
    Serial.print("UNLOCK");
    // Make servo go to 0 degrees
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH); 
    // Make servo go to 180 degrees 
    Servo1.write(180); 
    delay(1000); 
   }
   Serial.print(inches);
   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   delay(100);
}


long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
