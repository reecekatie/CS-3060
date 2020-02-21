//
//  main.c
//  assn4
//
//  Created by Katie Reece on 2/21/20.
//  Copyright © 2020 Katie Reece. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

struct numbers{
    int* data;
    int length;
    int* results;
    int finalLength;
};

void *mult(void *p){
    int product;
    struct numbers* numptr;
    int *answers = (int*) malloc(sizeof(int) * 5);
    numptr = (struct numbers*) p;
    for(int i = 0; i <= numptr->length; i = i+3){
        product = numptr -> data [i] * numptr -> data[i+1] * numptr -> data[i+2];
        answers[i/3] = product;
    }
    numptr->results = answers;
    return(NULL);
    
}

int main(int argc, char * argv[]) {
    
    
    int nums[] = {2, 3, 4, 12, 19, 17, 21, -3, -9, 103, 31, 211, 89, 0, 1023};
    pthread_t child_thread;
    struct numbers child_data;
    child_data.data =nums;
    child_data.length = 15;
    pthread_create(&child_thread, NULL, mult, (void*) &child_data);
    
    pthread_join(child_thread, NULL);
    
    for(int i = 0; i < child_data.length/3; i++){
        printf("%d\n", child_data.results[i]);
    }
    
    return 0;
}
    
    
    
    
    
    
    
    
    
    
    
    
    //printf("Commands entered: %d\n", argc);
    
//    for(int i = 0; i < argc; i++){
//       printf("arg#%d:%s\n", i, argv[i]);
//    }
//    FILE *fp = NULL;
//    if (argc >= 1){
//        fp = fopen("numbers.txt", "r");
//        if (fp == NULL){
//            printf("Cannot open");
//        }
//        else{
//            fp = stdin;
//        }
//    }
//    int n[3];
//    int totalCalc = 0;
//    while( 3 == fscanf(fp, "%d %d %d", &n[0], &n[1], &n[2])){
//        printf(" %d * %d * %d * = %d\n", n[0], n[1], n[2], n[0]*n[1]*n[2]);
//        totalCalc++;
//        }
//    printf("Number of calculations: %d\n", totalCalc);
//

