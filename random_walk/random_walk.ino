//********************************************************************************
// * File Name          : linefollow
// * Author             : RadioShack Corporation
// * Version            : V1.0
// * Date               : 2014/01/16
// * Description        : Optical sensors send feedback to PCB 
// *                      to make the robot follow a black line on a white background.
// ********************************************************************************
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ********************************************************************************

#include <MakeItRobotics.h>//include library
MakeItRobotics steps;//declare object
// **************************************************************************
// *                            Power Up Initial
// **************************************************************************
void setup() 
{ 
  Serial.begin(10420);                     //tell the Arduino to communicate with Make: it PCB
  delay(500);                              //delay 500ms
  steps.line_following_setup();   //initialize the status of line following robot
  steps.all_stop();               //all motors stop
}
// **************************************************************************
// *                            Main Loop 
// **************************************************************************
void loop() 
{  
  
  /************************************************************************
     Make Robot Move
     if action1 is not equal to action2, then change motor status
     if action1 is equal to action2, then do nothing
  *************************************************************************/
  steps.go_forward(100);
  delay(1000);
  steps.turn_left(100);
  delay(250);
  steps.turn_right(100);
  delay(250);
}

