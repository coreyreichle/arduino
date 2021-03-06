//********************************************************************************
// * File Name          : Catapult_demo.ino
// * Author             : RadioShack Corporation
// * Version            : V1.0
// * Date               : 2014/01/16
// * Description        : Cycle through the basic functions of the RadioShack Make: it catapult robot
// ********************************************************************************
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, see http://www.gnu.org/licenses/
//
/*****************************************************************************
  1st action  -> forward 1 second   <----------------------------|
  2nd action  -> backward 1 second                               | 
  3rd action  -> turn left  1 second                             |
  4th action  -> turn right 1 second                             |
  5th action  -> rotate catapult base clockwise 1 second         |
  6th action  -> rotate catapult base counterclockwise 1 second  |
  7th action  -> pull catapult arm back 1 second                 |
  8th action  -> launch catapult arm 1 second--------------------|
*****************************************************************************/
#include <MakeItRobotics.h>  //include library
MakeItRobotics catapult;     //declare object
// **************************************************************************
// *                            Power Up Init.
// **************************************************************************
void setup() 
{
  Serial.begin(10420);   //tells the Arduino where to send data
  delay(500);           //delay 500ms
  catapult.all_stop();  //all motors stop
}
// **************************************************************************
// *                            Main Loop 
// **************************************************************************
void loop() 
{       
  catapult.go_forward(60);       //forward
  delay(1000);                   //delay 1000ms
  catapult.go_backward(60);      //backward
  delay(1000);                   //delay 1000ms       
  catapult.turn_left(60);        //turn left  
  delay(1000);                   //delay 1000ms
  catapult.turn_right(60);       //turn right   
  delay(1000);                   //delay 1000ms
  catapult.all_stop();           //all motors stop
  catapult.catapult_head_clockwise(80);  //rotate catapult base clockwise
  delay(1000);                   //delay 1000ms
  catapult.catapult_head_counterclockwise(80);  //rotate base counterclockwise
  delay(1000);                   //delay 1000ms
  catapult.all_stop();           //all motors stop
  catapult.catapult_head_throw(255);  //throw
  delay(1000);                   //delay 1000ms
  catapult.catapult_head_pull(60);  //pull catapult arm back
  delay(1000);                   //delay 1000ms
  catapult.all_stop();           //all motor stop
  delay(1000);                   //delay 1000ms    
}                                //actions repeat continuously until you turn off battery compartments
