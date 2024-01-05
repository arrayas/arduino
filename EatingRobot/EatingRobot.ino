/*
 * Cartboard eating Robot
 * Author: GoldScrew
 * Email: goldscrewdiy@gmail.com
 * Description: It's using HC-SR04 (Detect food by distance <= 5 cm) and Server (to open and close the mouth)
 */

/* Modified by 
 *  Manuel Arrayás
 *  manuel.arrayas@gmail.com
 *  09-05-2022
 */
 
#include "HC-SR04/SR04.h" // Library for the sensor
#include <Servo.h>  
#define SERVO_PIN 9 // Set pin 9 for servo
#define LED 6 // Set pin 6 for led

// HC-SR04 ultrasonic sensor
const int trig = 3;     // trig of HC-SR04
const int echo = 2;     // echo of HC-SR04

// Servo
Servo mouthServo;


void setup()
{
  // Serial connection with baudrate 960
  Serial.begin(9600);
  
  // Send signal with TRIG
  pinMode(trig, OUTPUT);
  
  // Receive signal with ECHO
  pinMode(echo, INPUT);

  // Mouth Server
  mouthServo.attach(SERVO_PIN);
  mouthServo.write(90);

  // LED
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}
void loop()
{
  /* Duration */
  unsigned long duration;
  int distance; //Distance

  /* Send signal from TRIG pin */
  digitalWrite(trig, 0); //Stop trig pin
  delayMicroseconds(2); //Delay 2 micro seconds
  digitalWrite(trig, 1); //Send signal from TRIG pin
  delayMicroseconds(10); //Delay 10 micro seconds
  digitalWrite(trig, 0); //Stop trig pin
  
  /* Measure HIGH pulse width at ECHO pin */
  duration = pulseIn(echo, HIGH);

  //Calculate distance
  distance = int(duration/2/29.412);

  if(distance <= 5)
  {
    //Print distance
    Serial.println("the distance is less than 5 cm");

    for (int i = 0; i <= 10; i++) {
    digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(50);                       // wait for a second
    digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
    delay(50);
    }
    // LED on
    digitalWrite(LED, HIGH);
    
    // Start open mouth
    mouthServo.write(0);

    // Delay
    delay(1200);
    
  } else {

    //Print distance
    Serial.println("the distance is more than 5 cm");

    // LED on
    digitalWrite(LED, LOW);
    
    // Close the mouth
    mouthServo.write(90);  
  }
  
  // Delay
  delay(200);
}
