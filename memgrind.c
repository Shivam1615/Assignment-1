#include<stdio.h>
#include"mymalloc.h"

int main(int argc, char **argv){

InitilizeFunction();

/*
 *Test Case 1: A: malloc() 1 byte and immediately free it - do this 150 times
 *
 */
int i;
while(i < 150){
char *pointer = malloc(1);
free(pointer);
i++;
}

/*
 *Test Case 2: malloc() 1 byte, store the pointer in an array - do this 150 times.
 *Once you've malloc()ed 50 byte chunks, then free() the 50 1 byte pointers one by one.
 */
int j = 0;
int k = 0;
int l = 0;
while(j < 3){
int *Array[50];
while(k < 50){
char *pointer2 = malloc(1);
Array[k] = pointer2;
k++;
}
while(l < 50){
free(Array[l]);
l++;
}
j++;
}



return 0;
}
