/*Task 1.1 
Pair 45
Zheng Onn and Pierre
*/
 
#include "simpletools.h"    
#include "abdrive.h"                  

char str1[] = "FAKE";
char x;
char chrx;    
  
  int turnleft()
  {
    drive_goto(-26,25);
  }
      
   int A()
  {
    drive_goto(-21,21);
    drive_goto(100,100);
    drive_goto(42,-42);
    drive_goto(50,50);
    drive_goto(31,-30);
    drive_goto(61.8,61.8);
    drive_goto(52,-51);
    drive_goto(61.8,61.8);
    drive_goto(21,-21);
    drive_goto(50,50);
    drive_goto(-21,21);
  }
  
  int E()
  {
    turnleft();
    drive_goto(100,100);
    drive_goto(26,-26);
    drive_goto(50,50);
    drive_goto(52,-51);
    drive_goto(50,50);
    turnleft();
    drive_goto(50,50);
    turnleft();
    drive_goto(25,25);
    drive_goto(52,-51);
    drive_goto(25,25);
    turnleft();
    drive_goto(50,50);
    drive_goto(-27,25);
    drive_goto(50,50);
  }
  
  int F()
  {
    turnleft();
    drive_goto(100,100);
    drive_goto(25,-26);
    drive_goto(50,50);
    drive_goto(52,-51);
    drive_goto(50,50);
    turnleft();
    drive_goto(40,40);
    turnleft();
    drive_goto(25,25);
    drive_goto(52,-51);
    drive_goto(25,25);
    turnleft();
    drive_goto(60,60);
    drive_goto(-27,25);
  }   
  
  int H()
  {
    turnleft();
    drive_goto(100,100);
    drive_goto(52,-51);
    drive_goto(50,50);
    turnleft();
    drive_goto(35,35);
    turnleft();
    drive_goto(50,50);
    drive_goto(52,-51);
    drive_goto(100,100);
    turnleft();
  }
  int I()
  {
    drive_goto(30,30);
    turnleft();
    drive_goto(100,100);
    turnleft();
    drive_goto(30,30);
    drive_goto(52,-51);
    drive_goto(60,60);
    drive_goto(51,-52);
    drive_goto(30,30);
    drive_goto(-27,25);
    drive_goto(100,100);
    turnleft();
    drive_goto(30,30);
  }
  int K()
  {
    turnleft();
    drive_goto(100,100);
    drive_goto(52,-51);
    drive_goto(50,50);
    drive_goto(-39,39);
    drive_goto(70.71,70.71);
    drive_goto(52,-51);
    drive_goto(70.71,70.71);
    turnleft();
    drive_goto(70.71,70.71);
    drive_goto(-13,13);
  }
  int L()
  {
    turnleft();
    drive_goto(100,100);
    drive_goto(52,-51);
    drive_goto(100,100);
    drive_goto(-27,25);
    drive_goto(80,80);
  }        
  int space()
  {
    drive_goto(15,15);
  }    
  int drawLetter(chrx)
  {
    switch(chrx)
    {
      case 'A' : 
        A();
        break;
      
      case 'E': 
        E();
        break;
        
      case 'F' :
        F();
        break;
      
      case 'H' :
        H();
        break;
      
      case 'I' :
        I();
        break;
        
      case 'K' : 
        K();
        break;
        
      case 'L' :
        L();
        break;
     }
     
     space();
   }     
   
     
 int main()                                    
{
  for(int i = 0; i < strlen(str1); i++) {
    drawLetter(str1[i]);
  }
              
 }   