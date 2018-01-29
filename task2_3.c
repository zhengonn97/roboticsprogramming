/*
 Robotics Programming Task Sheet 2
 Zheng Onn Ng's solo 45 work 
 7th February 2017
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "simpletools.h"
#include "abdrive.h"

//Global Variables
int currentpos = 0; 
int destination = 0;
int traveldist;

  // a LED flash of P26 will indicate a swap
  void signal1(){
    high(26);
    pause(2000);
    low(26);
  }
      
  
  int* bubblesort(int* arr, int arrlen) {
    
    bool swapped;
    int n = arrlen;
    int i,temp;
    
    
    for (int c = 0 ; c < n; c++){
    swapped = false;
    
    for (int d = 0 ; d < n - c - 1; d++)
    {
      if (arr[d] > arr[d+1])
      { 
        temp       = arr[d];        // swap of elements
        arr[d]   = arr[d+1];
        arr[d+1] = temp;
        
        //this part of code checks the position of the robot, compares with the required destination, moves accordingly, then signals a swap if needed.
        destination = d+1;
        if (destination >= currentpos) { 
        traveldist = (destination - currentpos) * 65;         
        drive_goto(traveldist, traveldist); 
        currentpos = destination;
        signal1();
      } else if (destination < currentpos) {    
        traveldist = (currentpos - destination) * 65; 
        drive_goto(-traveldist, -traveldist); 
        currentpos = destination; 
        signal1();
      }         
        swapped = true;
      }
    }
    if (!swapped ) {           //algorithm stopped when a full iteration without swaps occurs
       destination = n/2;
       if (destination >= currentpos) {  
       traveldist = (destination - currentpos) * 65;
       drive_goto(traveldist , traveldist);
       drive_goto(-25,26);
       } else {
         traveldist = (currentpos - destination) * 65;
         drive_goto(-traveldist, -traveldist);
         drive_goto(-25,26);
       }         
       }
  }   
}         
  
  int main() {
    
    //hard coded values of elements (change as required)
    int i = 5;
    int *no_of_ele = malloc(sizeof(int) * i);
    *no_of_ele = 35;
    *(no_of_ele + 1) = 33;
    *(no_of_ele + 2) = 14;
    *(no_of_ele + 3) = 27;
    *(no_of_ele + 4) = 10;
    
    bubblesort(no_of_ele, i);
    free(no_of_ele);
    
    return 0;
  }
 
    