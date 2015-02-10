#include <SPI.h>
#include <SeeedTouchScreen.h>
#include <TFTv2.h>

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
}

/*----------------------------------------------------------------------------*/

char getChar() {
	int incomingByte;   // for incoming serial data
        char inChar;       // for casting
       if (Serial.available() > 0) {
   	// read the incoming byte:
      incomingByte = Serial.read();
      inChar = incomingByte;
      return inChar;
      }
}

/*----------------------------------------------------------------------------*/

static void printChar(char prChar) {
int xPos, yPos;  

                // say what you got:

                Tft.drawChar(prChar, xPos,yPos,1,YELLOW);
                if (xPos>220){
                  xPos=-10;
                  yPos=yPos+10;
                }
                if (yPos>310){
                  xPos=-10;
                  yPos=0;
                  Tft.fillScreen();
                }
                xPos=xPos+10;
                return;
        }

/*----------------------------------------------------------------------------*/

void loop() {
char keypress, commandBuffer[256];
int bufferIndex;


keypress=getChar();

commandBuffer[bufferIndex]= keypress;

printChar( keypress );

}
