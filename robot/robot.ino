#include <MotorDriver.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 
const int pingPin = 7;        //Sonar pin


void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  motordriver.init();
  motordriver.setSpeed(200,MOTORB);
  motordriver.setSpeed(200,MOTORA);
}

void loop(){
  long scans[3];
  
  //Scan left
  scans[0]= scan(0);
  delay(100);
  //Scan center
  scans[1]= scan(1);
  delay(100);
  //scan right
  scans[2]= scan(2);
  delay(100);
  
  //Pick best direction
  if (( scans[0] > scans[2] ) && ( scans[0] > scans[2] )) {
    // go left
    motordriver.goLeft();
    delay(2000);
    motordriver.stop();
  }
  else
    if (( scans[1] > scans[0] ) && ( scans[1] > scans[2] )) {
      //go forwards
      motordriver.goForward();
    }
    else
      if (( scans[2] > scans[0] ) && ( scans[2] > scans[1] )) {
        //turn right
        motordriver.goRight();
        delay(2000);
        motordriver.stop();
      }
  //drive forward until obstacle
}  

long scan( int pos) {
  int scanPositions[3] = { 
    5,50,100    };
  myservo.write(scanPositions[pos]);              // tell servo to go to position in variable 'pos' 
  delay(250);                       // waits 15ms for the servo to reach the position 
  return sonar();
}



long sonar (){
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, cm;
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  //  Serial.print(inches);
  //  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
  return cm;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}


