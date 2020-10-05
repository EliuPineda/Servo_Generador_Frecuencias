#include <ESP32Servo.h>
#include <M5StickC.h>
#include "AXP192.h"

Servo myservo;  // create servo object to control a servo
// 16 servo objects can be created on the ESP32
 
int pos = 0;    // variable to store the servo position
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33 
int servoPin = 26;


int amplitud = 12; // Grados
int frecuencia = 5; // Hz
int resolucion = amplitud; //Grados
float dellay =  1000*resolucion/(amplitud*2*frecuencia);
 
void setup() {
  Serial.begin(115200);
  M5.begin();
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);    // standard 50 hz servo
  myservo.attach(servoPin, 500, 2400); // attaches the servo on pin 18 to the servo object
  // using default min/max of 1000us and 2000us
  // different servos may require different min/max settings
  // for an accurate 0 to 180 sweep
}
 
void loop() {
 
  //for (pos = 0; pos <= amplitud; pos += resolucion) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
  myservo.write(amplitud);    // tell servo to go to position in variable 'pos'
    //Serial.println(pos);
  delay(dellay);             // waits 15ms for the servo to reach the position
  //}
  
  //for (pos = amplitud; pos >= 0; pos -= resolucion) { // goes from 180 degrees to 0 degrees
  myservo.write(0);    // tell servo to go to position in variable 'pos'
  Serial.println(dellay);
  delay(dellay);             // waits 15ms for the servo to reach the position
  //}
}
