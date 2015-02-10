#include <SPI.h>
#include <SeeedTouchScreen.h>
#include <TFTv2.h>
#include <SoftwareSerial.h>

/******************************************************************************/
/*                                                                            */
/* SeeedStudio TFT v2 touch sheild demo                                       */
/* A sample program to play with the TFT touch sheild.  It uses the serial    */
/* for input, and displays it on the TFT screen                               */
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

  Serial.print(keypress);
  printChar( keypress );

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

