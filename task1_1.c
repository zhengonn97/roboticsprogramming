/*
Task 1.1 
Pair 45
Zheng Onn and Pierre 
*/
#include "simpletools.h"                      
#include "abdrive.h"

int main()                                    
{
  int oneMticks = 308;
  // draws a square
  for( int i = 0 ; i < 4 ; i++){ 
  drive_goto(oneMticks,oneMticks);
  drive_goto(26,-26);
}
      
}
