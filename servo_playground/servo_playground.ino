/*******************************************************************************
 * This is a sample servo controller.  It has two commands:  M and D.
 * 1-9,0 moves the servo into input *10 degrees (ie, 2 moves it to 20 degrees)
 * d and D delays for one second
 * S sweeps the servo forwards (0 to 100)
 * s sweeps the servo backwards (100 to 0)
 *******************************************************************************/

#include <SoftwareSerial.h>
#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 

int pos = 0;    // variable to store the servo position 

void setup() 
{ 
  myservo.attach(9);         // attaches the servo on pin 9 to the servo object 
  int stepPin = 13;          // setup the stepper pin
  pinMode(stepPin, OUTPUT);
  digitalWrite(stepPin, LOW);
  Serial.begin(9600);        // opens serial port, sets data rate to 9600 bps
  myservo.write(4);          // starting in bottom position
} 


void loop() 
{
  int stepPin = 13;
  
  char pos;
  pos = getChar();
  if (pos != '\0'){
    positionServo(pos);
    //beep(stepPin);
  }
  delay(500);
}

/*----------------------------------------------------------------------------*/
void beep (int stepPin)
{
  digitalWrite(stepPin, HIGH);
  delay(50);
  digitalWrite(stepPin, LOW);
}

/*----------------------------------------------------------------------------*/
void positionServo( char command ){
  Serial.write("Executing:");
  Serial.write(command);
  Serial.write('\n');
  switch (command) {
  case '1':
    //do something when var equals 1
    myservo.write(10);
    break;
  case '2':
    //do something when var equals 2
    myservo.write(20);
    break;
  case '3':
    //do something when var equals 1
    myservo.write(30);
    break;
  case '4':
    //do something when var equals 2
    myservo.write(40);
    break;
  case '5':
    //do something when var equals 2
    myservo.write(50);
    break;
  case '6':
    //do something when var equals 2
    myservo.write(60);
    break;
  case '7':
    //do something when var equals 2
    myservo.write(70);
    break;
  case '8':
    //do something when var equals 2
    myservo.write(80);
    break;
  case '9':
    //do something when var equals 2
    myservo.write(90);
    break;
  case '0':
    //do something when var equals 2
    myservo.write(100);
    break;
  case 'D':
    //do something when var equals 2
    delay(1000);
    break;
  case 'd':
    //do something when var equals 2
    delay(1000);
    break;
  case 's':
    for (int x=4; x<100; x++){
    myservo.write(x);
    delay(10);
    }
    break;
  case 'S':
    for (int x=100; x>5; x--){
    myservo.write(x);
    delay(10);
    }
    break;
  case 'b':
    beep(13);
    break;
  default: 
    myservo.write(5);
    // if nothing else matches, do the default
    // default is optional
  }
  return;
}

/*----------------------------------------------------------------------------*/
int getChar() {
  int incomingByte;   // for incoming serial data
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    return incomingByte;
  }
}


