//Set up liquid crystal
#include <LiquidCrystal.h> //Load LCD library
LiquidCrystal LCD(10,9,5,4,3,2); //LCD objet

//Set up ultrasound sensor
int trigPin = 13; //Sensor for trigger pin
int echoPin = 11; //Sensor for echo pin
float pingTime; //Tine for pin to hit the target and return
float speedOfSound = 340.3; //Speed of sound in m/s
float targetDistance; //Variable to show the distance

void setup() {
  // start ultrasonic measurement
  Serial.begin(9600); //Turn on serial port
  pinMode(trigPin,OUTPUT); //Set trig Pin as output
  pinMode(echoPin, INPUT); //Set echo Pin as input
  //start LCD display
  LCD.begin(16,2); //size of the object -first column and then rows-
  LCD.setCursor(0,0); //set the cursor at upper left display
  LCD.print("Target distance: "); //print of the first line
}

void loop() {
  //Measure distance with the ultrasound sensor
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000); //delay
  digitalWrite(trigPin,HIGH); //set pin high
  delayMicroseconds(15);  //delay sending the wave
  digitalWrite(trigPin,LOW);

  pingTime = pulseIn(echoPin, HIGH); //measure ping time in echo
  pingTime = pingTime/1000000; //change to seconds
  targetDistance = speedOfSound*pingTime; //Calculate the distance using the speed of time
  targetDistance = targetDistance*50; //only one trip and change meters to cm

  //Display results on the serial, useful for debugging
  Serial.print("pingtime: ");
  Serial.println(pingTime); //Display the pingTime
  Serial.print("targetDistance: ");
  Serial.println(targetDistance); //Display the distance

  //display results on the LCD
  LCD.setCursor(0,1); //set cursor on the second row
  LCD.print("               "); //print blanks
  LCD.setCursor(0,1); //Put cursor back to firs place on second row
  LCD.print(targetDistance); //print distance
  LCD.print(" cm");
  delay(250); //delay between measurements
}
