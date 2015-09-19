//Set up ultrasound sensor
int trigPin = 13; //Sensor for trigger pin
int echoPin = 11; //Sensor for echo pin
float pingTime; //Tine for pin to hit the target and return
float speedOfSound = 340.3; //Speed of sound in m/s
float targetDistance;

void setup() {
  //Start ultrasonic measurement
  Serial.begin(9600); //Turn on serial port
  pinMode(trigPin,OUTPUT); //Set trig Pin as output
  pinMode(echoPin, INPUT); //Set echo Pin as input
}

void loop() {
  //Measure distance with the ultrasound sensor
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2000); //delay
  digitalWrite(trigPin,HIGH); //set pin high
  delayMicroseconds(15);  //delay sending the wave
  digitalWrite(trigPin,LOW);
  delayMicroseconds(10);

  pingTime = pulseIn(echoPin, HIGH); //measure ping time in echo
  pingTime = pingTime/1000000; //change to seconds
  targetDistance = speedOfSound*pingTime;
  targetDistance = targetDistance*50; //only one trip and change meters to cm

  //display results on the serial
  Serial.println(targetDistance); //Print the result on the serial port
  delay(100); //delay to response
}
