/*
 Robotics Programming Task Sheet 2
 Zheng Onn Ng's solo 45 work
 7th February 2017
*/

#include <stdio.h>
#include "simpletools.h"
#include "abdrive.h"

//Declaration of variables
void TOH(int, char, char, char);

//constant move distances to reach each peg
const int UNIT1 = 100; 
const int UNIT2 = 200; 
const int UNIT3 = 300; 

//this function will signal to take an item from the current peg
void signalMove() {
  high(26);
  pause(2000);
  low(26);
}

//this function will signal to put the item taken onto the current peg
void signalHere() {
  drive_goto(104,-104);
}

int main()
{
  
    int num;
    char initialpeg;
    
    //hard coded values of number of disks and initial peg (change as required)
    num = 3;
    initialpeg = 'A';
    
    switch(initialpeg) 
    {
      case 'A' :
      TOH(num, 'A', 'C', 'B');
      break;
      
      case 'B' :
      TOH(num, 'B', 'C', 'A');
      break;
      
      case 'C' :
      TOH(num, 'C', 'A', 'B');
      break;
    }
    drive_speed(104,-104);  //signals end of algorithm
    return 0;
}

void TOH(int num, char frompeg, char topeg, char auxpeg)
{
    //checks and compares the current peg and required peg to move to, then moves accordingly, signalling moving of the disks.
    if (num == 1)
    {
        switch(frompeg) {
          case 'A' :
          drive_goto(UNIT3, UNIT3);
          signalMove();
          break;
          
          case 'B' :
          drive_goto(UNIT2, UNIT2);
          signalMove();
          break;

          case 'C' :
          drive_goto(UNIT1, UNIT1);
          signalMove();
          break;
        }

        switch(topeg) {
          case 'A' :
          if (frompeg == 'C') {
            drive_goto(UNIT2, UNIT2);
            signalHere();
            drive_goto(-UNIT3, -UNIT3);
          } else {
            drive_goto(UNIT1, UNIT1);
            signalHere();
            drive_goto(-UNIT3, -UNIT3);
          } break;

          case 'B' :
          if (frompeg == 'A') {
            drive_goto(-UNIT1, -UNIT1);
            signalHere();
            drive_goto(-UNIT2, -UNIT2);
          } else {
            drive_goto(UNIT1, UNIT1);
            signalHere();
            drive_goto(-UNIT2, -UNIT2);
          } break;

          case 'C' :
          if (frompeg == 'B') {
            drive_goto(-UNIT1, -UNIT1);
            signalHere();
            drive_goto(-UNIT1,-UNIT1);
          } else {
            drive_goto(-UNIT2, -UNIT2);
            signalHere();
            drive_goto(-UNIT1,-UNIT1);
          } break;
        }
    } else {
    TOH(num - 1, frompeg, auxpeg, topeg);
      switch(frompeg) {
          case 'A' :
          drive_goto(UNIT3, UNIT3);
          signalMove();
          break;
          
          case 'B' :
          drive_goto(UNIT2, UNIT2);
          signalMove();
          break;

          case 'C' :
          drive_goto(UNIT1, UNIT1);
          signalMove();
          break;
        }

      switch(topeg) {
          case 'A' :
          if (frompeg == 'C') {
            drive_goto(UNIT2, UNIT2);
            signalHere();
            drive_goto(-UNIT3, -UNIT3);
          } else {
            drive_goto(UNIT1, UNIT1);
            signalHere();
            drive_goto(-UNIT3, -UNIT3);
          } break;

          case 'B' :
          if (frompeg == 'A') {
            drive_goto(-UNIT1, -UNIT1);
            signalHere();
            drive_goto(-UNIT2, -UNIT2);
          } else {
            drive_goto(UNIT1, UNIT1);
            signalHere();
            drive_goto(-UNIT2, -UNIT2);
          } break;

          case 'C' :
          if (frompeg == 'B') {
            drive_goto(-UNIT1, -UNIT1);
            signalHere();
            drive_goto(-UNIT1,-UNIT1);
          } else {
            drive_goto(-UNIT2, -UNIT2);
            signalHere();
            drive_goto(-UNIT1,-UNIT1);
          } break;
        }
    TOH(num - 1, auxpeg, topeg, frompeg);
  }    
}

