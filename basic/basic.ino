#include <SPI.h>
#include <SeeedTouchScreen.h>
#include <TFTv2.h>
#include <SoftwareSerial.h>

/******************************************************************************/
/*                                                                            */
/* FS Basic (FakeSoft Basic)                                                  */
/* This is my attempt two write a BASIC interactive interpreter for the       */
/* Arduino, as a learning exercise. Based loosely on MS Basic for the COCO3   */
/*                                                                            */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/* Uses the SeeedStudio TFT touch screen, and SD sheild                       */
/* For now, serial connection for the keyboard as well.                       */
/*                                                                            */
/******************************************************************************/

void setup() { 
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  TFT_BL_ON;              // turn on the background light
  Tft.TFTinit();
  Tft.fillScreen();
}

/*----------------------------------------------------------------------------*/

void loop() {
  char keypress;

  keypress=getChar();

  handleBuffer(keypress);
  
  printChar( keypress );


  
}

/*----------------------------------------------------------------------------*/

void interpretBuffer(char buffer[255]);

/*----------------------------------------------------------------------------*/

void handleBuffer(char inKey){
  static char commandBuffer[255];
  static int bufferIndex;
  
  commandBuffer[bufferIndex++]= inKey;
  if (bufferIndex > 255) {
    bufferIndex=0;
  }
  if ( inKey == 13 ){
    interpretBuffer (commandBuffer);
  }

  return; 
}

/*----------------------------------------------------------------------------*/
char getChar() {
  int incomingByte;   // for incoming serial data
  char inChar;       // for casting
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    inChar = incomingByte;
    return incomingByte;
  }
}

/*----------------------------------------------------------------------------*/

static void printChar(char prChar) {
  static int xPos, yPos;  

  // say what you got, and some screen control logic:
  if (prChar == 13 ){
    xPos=0;
    yPos=yPos+10;
  }
  if (prChar < 32 || prChar > 126){
    return;
  }
  else {
  Tft.drawChar(prChar, xPos,yPos,1,YELLOW);
  }
  if (xPos>220){
    xPos=-10;
    yPos=yPos+10;
  }
  if (yPos>310){
    xPos=-10;
    yPos=0;
    Tft.fillScreen();
  }
  xPos=xPos + 10;
  return;
}
