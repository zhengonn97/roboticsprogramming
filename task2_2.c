/*
 Robotics Programming Task Sheet 2
 Zheng Onn Ng's solo 45 work 
 7th February 2017
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//#include "simpletools.h" (to be included as necessary when running code on simpleide)

  // displays the array contents.
  void display(int *arr, int arrlen) {
    for (int k = 0; k < arrlen; k++) {
      printf("%i ",arr[k]);
    }
    printf("\n");
  }       
  
  int* bubblesort(int* arr, int arrlen) {
    
    bool swapped;
    int n = arrlen;
    int i,temp;
    
    printf("The intermediary steps are as follows:\n");
    display(arr, arrlen);
    
    for (int c = 0 ; c < ( n - 1 ); c++)
  {
    swapped = false;
    
    for (int d = 0 ; d < n - c - 1; d++)
    {
      if (arr[d] > arr[d+1])
      {
        temp       = arr[d];        //swap of elements
        arr[d]   = arr[d+1];
        arr[d+1] = temp;
        swapped = true;
      }
      display(arr,arrlen);         //each intermediary step after each iteration is shown
    }
    if (swapped = false)           //algorithm stopped when a full iteration without swaps occur
      break;
  }   
}  

  int main() {
    
    int i;
    printf("Enter number of elements: \n");
    scanf("%i", &i);
    
    int *no_of_ele = malloc(sizeof(int) * i);
    printf("Enter %i integers\n", i);

    for (int n = 0; n < i; n++) {
      scanf("%i", (no_of_ele + n));
    }
    bubblesort(no_of_ele, i);
    printf("Sorted list in ascending order: \n");
    display(no_of_ele, i);
    free(no_of_ele);
  }
 
    