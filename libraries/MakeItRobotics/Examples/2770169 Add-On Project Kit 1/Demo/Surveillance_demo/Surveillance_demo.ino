//********************************************************************************
// * File Name          : Surveillance_demo.ino
// * Author             : RadioShack Corporation
// * Version            : V1.0
// * Date               : 2014/01/16
// * Description        : Cycle through the basic functions of the RadioShack Make: it surveillance robot
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
  1st action  -> forward 1 second   <-------------------------|          
  2nd action  -> backward 1 second                            |  
  3rd action  -> turn left 1 second                           |
  4th action  -> turn right 1 second                          |
  5th action  -> rotate platform clockwise 1 second           |
  6th action  -> rotate platform counterclockwise 1 second ---|   
*****************************************************************************/
#include <MakeItRobotics.h>  //include library
MakeItRobotics surveillance; //declare object
// **************************************************************************
// *                            Power Up Init.
// **************************************************************************
void setup() 
{
  Serial.begin(10420);      //tell the Arduino to communicate with Make: it PCB
  delay(500);               //delay 500ms
  surveillance.all_stop();  //all motors stop
}
// **************************************************************************
// *                            Main Loop 
// **************************************************************************
void loop() 
{          
    surveillance.go_forward(80);     //forward   
    delay(1000);                     //delay 1000ms
    surveillance.go_backward(80);    //backward
    delay(1000);                     //delay 1000ms
    surveillance.turn_left(80);      //turn left    
    delay(1000);                     //delay 1000ms
    surveillance.turn_right(80);     //turn right     
    delay(1000);                     //delay 1000ms
    surveillance.all_stop();         //all motors stop
    surveillance.surveillance_head_clockwise(45);  //rotate platform clockwise
    delay(1000);                     //delay 1000ms
    surveillance.surveillance_head_counterclockwise(45);  //rotate platform counterclockwise
    delay(1000);                     //delay 1000ms
    surveillance.all_stop();         //all motors stop
    delay(1000);                     //delay 1000ms
}                                    //actions repeat continuously until you turn off battery compartments
