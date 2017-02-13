/*
 Robotics Programming Task Sheet 2
 Zheng Onn Ng's solo 45 work
 7th February 2017
*/

#include <stdio.h>
//#include "simpletools.h" (to be included as necessary when running code on simpleide)

//Declaration of variables
void TOH(int, char, char, char);

//Definition of stack structure used to track contents of each peg
struct stack {
    int stk[3];
    int top;
};
struct stack stackA, stackB, stackC;

//function that pushes an element to the top of a peg
void push(char disk, struct stack *s) {
    s->top = s->top + 1;
    s->stk[s->top] = disk;
}

//function to remove an element from the top of a peg
void pop(struct stack *s) {
    s->top = s->top - 1; 
}

//function to display the contents of a peg
void displaystack(struct stack *s, char whichpeg) {
    if (s->top == -1) {
        printf("\nPeg %c is empty\n", whichpeg);
        printf("\n");
        return;
    } else {
        printf("\nPeg %c contents are\n", whichpeg);
        for (int i = s->top; i>=0 ; i--) {
        printf("%d\n", s->stk[i]); }
        printf("\n");
    }
}

//takes in a character and returns the corresponding stack
struct stack *getstack(char x) {
    switch(x)
    {
        case 'A' :
        return &stackA;

        case 'B' :
        return &stackB;

        case 'C' :
        return &stackC;
    }
}

int main()
{
    stackA.top = -1;
    stackB.top = -1;
    stackC.top = -1;
    int num;
    char initialpeg;
    
    //input of data
    printf("Enter the number of disks: ");
    scanf("%d ", &num);
    printf("Enter the peg where disks are intially stacked (A,B,C) : ");
    scanf("%c ", &initialpeg);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    
    //setting contents of initial peg and calling TOH function with the right parameters
    switch(initialpeg) 
    {
      //TOH will aim to move contents in peg A --> peg C
      case 'A' :
      push(3, &stackA);
      push(2, &stackA);
      push(1, &stackA);
      TOH(num, 'A', 'C', 'B');
      break;
      
      //TOH will aim to move contents in peg B --> peg C
      case 'B' :
      push(3, &stackB);
      push(2, &stackB);
      push(1, &stackB);
      TOH(num, 'B', 'C', 'A');
      break;
      
      //TOH will aim to move contents in peg C --> peg A
      case 'C' :
      push(3, &stackC);
      push(2, &stackC);
      push(1, &stackC);
      TOH(num, 'C', 'A', 'B');
      break;
    }
    
    return 0;
}

void TOH(int num, char frompeg, char topeg, char auxpeg)
{
    //when theres a move required, push pop functions are called and then each pegs' contents are displayed
    if (num == 1)
    {
        printf("\nMove disk %d from peg %c to peg %c \n", num, frompeg, topeg);
        pop((getstack(frompeg)));
        push(num, getstack(topeg));
        displaystack(&stackA, 'A');
        displaystack(&stackB, 'B');
        displaystack(&stackC, 'C');
    } else {
        TOH(num - 1, frompeg, auxpeg, topeg);
        printf("\nMove disk %d from peg %c to peg %c \n", num, frompeg, topeg);
        pop((getstack(frompeg)));
        push(num, getstack(topeg));
        displaystack(&stackA, 'A');
        displaystack(&stackB, 'B');
        displaystack(&stackC, 'C');
        TOH(num - 1, auxpeg, topeg, frompeg);
    }    
}

