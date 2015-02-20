//* Semi-autonomous robot
#include <MakeItRobotics.h>//include library
#include <Servo.h> 

// create our objects
MakeItRobotics semiAuto;//declare object
Servo fwdSensor;  // create servo object to control a servo 
// a maximum of eight servo objects can be created

// declare input pins
int sonarPin = 5;

// declare output pins
int servoPin = 6;

// declare constants
int servoRight = 4;
int servoLeft = 180;
int servoCenter = 90;

// declare vars we want global
long pingDistance;


void setup() {
  // initialize motors
  Serial.begin(10420);                     //tell the Arduino to communicate with Make: it PCB
  delay(500);                              //delay 500ms
  semiAuto.all_stop();               //all motors stop

    // initialize sensor
  fwdSensor.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  fwdSensor.write(servoCenter);
}

void loop () {
  long distances[3];

  //Drive forwards, until we hit prox alarm
  while (pingCenter() > 1500){
    semiAuto.go_forward(100);  
  }
  //Stop, and backup a bit.
  semiAuto.all_stop();
  delay(100);
  semiAuto.go_backward(100);
  delay(1000);
  semiAuto.all_stop();

  //Scan
  distances[0] = pingLeft();

  distances[2] = pingRight();

  // decide which way
  // if left is better...
  if ( distances[0] > ( distances[2] + 200 ) ) {
    semiAuto.turn_left(100);
    delay(500);
    semiAuto.all_stop();
  }
  // else, go right...
  else if (distances[2] > ( distances[0] + 200 ) ) {
    semiAuto.turn_right(100);
    delay(500);
    semiAuto.all_stop();
  }
  // if both suck, turn around.
  else {
    semiAuto.turn_right(100);
    delay(1200);
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
  // Declare vars used internally to the function
  long duration;

  pinMode(sonarPin, OUTPUT);
  digitalWrite(sonarPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sonarPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(sonarPin, LOW);

  pinMode(sonarPin, INPUT);
  duration = pulseIn(sonarPin, HIGH);
  return duration;
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}





