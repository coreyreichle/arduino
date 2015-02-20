//* Semi-autonomous robot
//* Code taken from a few places, ie the PING))) sensor from Parrallax's example code,
//* particularly.
//* All other code Copyright (c) 2015 by Corey Reichle.  Released under the GPL ver 3, where
//* applicable.

#include <MakeItRobotics.h>//include library
#include <Servo.h> 

// create our objects
MakeItRobotics semiAuto;//declare object
Servo fwdSensor;  // create servo object to control a servo 
// a maximum of eight servo objects can be created

// declare data pins
int sonarPin = 5;
int servoPin = 6;

// declare constants
int servoRight = 4;
int servoLeft = 180;
int servoCenter = 90;
int turnSpeed  = 200;
int driveSpeed = 500;

// declare vars we want global

void setup() {
                                                // initialize motors
  Serial.begin(10420);                          //tell the Arduino to communicate with Make: it PCB
  delay(500);                                   //delay 500ms
  semiAuto.all_stop();                          //all motors stop

                                                // initialize sensor
  fwdSensor.attach(servoPin);                   // attaches the servo on pin 9 to the servo object
  fwdSensor.write(servoCenter);
}

void loop () {
  long distances[3];

                                                //Drive forwards, until we hit prox alarm
  while (pingCenter() > 1000){
    semiAuto.go_forward(driveSpeed);  
  }
                                                //Stop, and backup a bit.
  semiAuto.all_stop();
  delay(100);
  semiAuto.go_backward(driveSpeed);
  delay(1000);
  semiAuto.all_stop();

                                                //Scan
                                                
  distances[1] = pingRight();
  distances[2] = pingLeft();
                                                // decide which way
                                                // if left is better...
  if ( distances[1] > distances[2] ) {
    semiAuto.turn_right(turnSpeed);
    delay(500);
    semiAuto.all_stop();
  }
  else
                                               // else, go right...
    if (distances[2] > distances[1] ) {
    semiAuto.turn_left(turnSpeed);
    delay(500);
    semiAuto.all_stop();
  }

}

long pingLeft () {
  long  distance;
                                               //turn the servo left
  fwdSensor.write(servoLeft);
                                               //return the distance
  distance = ping();
  delay(200);
  return distance;
}

long pingCenter () {
  long  distance;
                                               //Turn the servo center
  fwdSensor.write(servoCenter);
                                               //Return the ping time
  distance = ping();
  delay(200);
  return distance;
}

long pingRight () {
  long  distance;
                                               //Turn the right
  fwdSensor.write(servoRight);
                                               //Return the ping time
  distance = ping();
  delay(200);
  return distance;
}

long ping () {
  long duration;
                                               // Send out ping
  pinMode(sonarPin, OUTPUT);
  digitalWrite(sonarPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sonarPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(sonarPin, LOW);
                                               // Read ping duration
  pinMode(sonarPin, INPUT);
  duration = pulseIn(sonarPin, HIGH);
                                               // Return the ping
  return duration;
}
