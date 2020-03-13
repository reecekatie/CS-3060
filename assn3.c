/*Kaitlyn Reece Spring 2020 CS 3060 Assignment 3
 * /* Promise of Originality
I promise that this source code file has, in its entirety, been
written by myself and by no other person or persons. If at any time an
exact copy of this source code is found to be used by another person in
this term, I understand that both myself and the student that submitted
the copy will receive a zero on this assignment.
*/






#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct numbers{
    int* data;
    int length;
    int* results;
    //int finalLength;
};

void *mult(void *p){
    int product;
    struct numbers* numptr;
    int *answers = (int*) malloc(sizeof(int) * 33);
    numptr = (struct numbers*) p;

    for(int i = 0; i <= numptr->length; i = i+3){
        product = numptr -> data [i] * numptr -> data[i+1] * numptr -> data[i+2];
        answers[i/3] = product;
    }

    numptr->results = answers;
    return(NULL);
    
}

int main(int argc, char * argv[]) {
         	
  printf("Assignment 3 by Kaitlyn Reece\n");
  FILE *fp = NULL;
  if (argc > 1){
    fp = fopen(argv[1], "r");
      if (fp == NULL){
      printf("Cannot open");
      }
  }
      else{
          fp = stdin;
          }
        
    int nums[99];
    int count = 0;
   while(3 == fscanf(fp,"%d %d %d", &nums[count], &nums[count+1], &nums[count+2])){ 
     count= count+3;
    }
  
    pthread_t child_thread;
    struct numbers child_data;
    child_data.data = nums;
    child_data.length = count;
    pthread_create(&child_thread, NULL, mult, (void*) &child_data);
    
    pthread_join(child_thread, NULL);
    
    for(int i = 0; i < count; i = i+3){
	    printf("The product of %d, %d, and %d is %d\n", nums[i], nums[i+1], nums[i+2], child_data.results[i/3]);
    }
    
    return 0;
}
