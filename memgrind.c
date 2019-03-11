#include<stdio.h>
#include<stdlib.h>
#include"mymalloc.h"
#include<time.h>

int main(int argc, char **argv){

/*
 *  *  *Test Case A:  malloc() 1 byte and immediately free it - do this 150 times
 *   *   *
 *    *    */

printf("-----------TEST CASE A--------\n");
int q;
double sum = 0;
double average = 0;
for(q = 0; q < 100; q++){
struct timevalue start, end;
gettimeofday(&start, NULL);
int i;
while(i < 150){
        char *pointer = malloc(1);
        free(pointer);
        i++;
}
gettimeofday(&end, NULL);
double seconds = (end.value1 - start.value1);
double microseconds = ((seconds * 1000000) + end.value2) - (start.value2);
sum+=microseconds;
}
average = sum/100;
printf("This program ran in about %.2f  microseconds\n", average);


/*
 *  *  *Test Case B: malloc() 1 byte, store the pointer in an array - do this 150 times.
 *   *   *Once you've malloc()ed 50 byte chunks, then free() the 50 1 byte pointers one by one.
 *    *    */

printf("-----------TEST CASE B---------\n");
int j = 0;
sum = 0;
average = 0;
for(q = 0; q < 100; q++){
struct timevalue start, end;
gettimeofday(&start, NULL);
while(j < 3){
        char *Array[50];
        int k = 0;
        int l = 0;
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
gettimeofday(&end, NULL);

double seconds = (end.value1 - start.value1);
double microseconds = ((seconds * 1000000) + end.value2) - (start.value2);
sum+=microseconds;
}
average = sum/100;
printf("This program ran in about %.2f microseconds\n", average);

/*
 *  *  *Test Case C: Randomly choose between a 1 byte malloc() or free()ing a 1 byte pointer > do this until you have allocated 50 times
 *   *   *  - Keep track of each operation so that you eventually malloc() 50 bytes, in total
 *    *       > if you have already allocated 50 times, disregard the random and just free() on each iteration
 *     *           - Keep track of each operation so that you eventually free() all pointers
 *      *               > don't allow a free() if you have no pointers to free()
 *       *                */

printf("-----------TEST CASE C-----------\n");
sum = 0;
average = 0;
for(q = 0; q < 100; q++){
struct timevalue start, end;
gettimeofday(&start, NULL);
int malloctracker = 0;
char *ArrayC[50];
int mallocTotal=0;
while(mallocTotal<50){
        int pick = rand()%2;
        if(pick==0){
                char *pointer=malloc(1);
                ArrayC[malloctracker]=pointer;
                mallocTotal++;
                malloctracker++;

        }
        if( (pick==1)&&(malloctracker>0)){
                free(ArrayC[malloctracker-1]);
                malloctracker--;

        }

}
while(malloctracker>0){

        free(ArrayC[malloctracker-1]);
        malloctracker--;


}

gettimeofday(&end, NULL);
double seconds = (end.value1 - start.value1);
double microseconds = ((seconds * 1000000) + end.value2) - (start.value2);
sum+=microseconds;
}
average = sum/100;
printf("This program ran in about %.2f microseconds\n", average);

/*
 *  *  * Test Case D: Randomly choose between a randomly-sized malloc() or free()ing a pointer – do this many times (see below)
 *   *   * - Keep track of each malloc so that all mallocs do not exceed your total memory capacity - Keep track of each operation so that you eventually malloc() 50 times
 *    *    * - Keep track of each operation so that you eventually free() all pointers
 *     *     * - Choose a random allocation size between 1 and 64 bytes
 *      *      */

printf("-----------TEST CASE D---------\n");
sum = 0;
average = 0;
struct timevalue start, end;
gettimeofday(&start, NULL);
for(q = 0; q < 100; q++){
InitilizeFunction();
int malloctracker = 0;
char *ArrayD[50];
int mallocTotal=0;
while(mallocTotal<50){
        int pick = rand()%2;
        int randSize=(rand()%63)+1;
        if(pick==0){
                char *pointer=malloc(randSize);
                ArrayD[malloctracker]=pointer;
                mallocTotal++;
                malloctracker++;
        }
        if( (pick==1)&&(malloctracker>0)){
                free(ArrayD[malloctracker-1]);
                malloctracker--;

        }

}
while(malloctracker>0){

        free(ArrayD[malloctracker-1]);
        malloctracker--;

}
gettimeofday(&end, NULL);
double seconds = (end.value1 - start.value1);
double microseconds = ((seconds * 1000000) + end.value2) - (start.value2);
sum+=microseconds;
}

average = sum/100;
printf("This program ran in about %.2f microseconds\n", average);

//work load E:
printf("-----------Test Case E---------\n");
sum = 0;
average = 0;
for(q = 0; q < 100; q++){
struct timevalue start, end;
gettimeofday(&start, NULL);

int b = 0;
int c = 0;
int a;
char *array[800];
for(a = 0; a < 5; a++){
        for(b = 0; b < 20; b++){
                char *pointer = malloc(20);
                array[b] = pointer;
        }
        for(c = 0; c < 20; c++){
                free(array[c]);
        }
}
gettimeofday(&end, NULL);
double seconds = (end.value1 - start.value1);
double microseconds = ((seconds * 1000000) + end.value2) - (start.value2);
sum+=microseconds;
}
average = sum/100;
printf("This program ran in about %.2f microseconds\n", average);

//work load F:

printf("-----------TEST CASE F----------\n");

sum = 0;
average = 0;
for(q = 0; q < 100; q++){
InitilizeFunction();
struct timevalue start, end;
gettimeofday(&start, NULL);
int malloctracker = 0;
char *ArrayE[100];
int mallocTotal=0;
while(mallocTotal<100){
        int pick = rand()%2;
        int randSize=(rand()%170)+1;
        if(pick==0){
	
                char *pointer=malloc(randSize);
                ArrayE[malloctracker]=pointer;
                mallocTotal++;
                malloctracker++;

        }
        if((pick==1)&&(malloctracker>0)){
                free(ArrayE[malloctracker-1]);
                malloctracker--;

        }
}
while(malloctracker>0){

        free(ArrayE[malloctracker-1]);
        malloctracker--;
}
gettimeofday(&end, NULL);
double seconds = (end.value1 - start.value1);
double microseconds = ((seconds * 1000000) + end.value2) - (start.value2);
sum+=microseconds;
}
average = sum/100;
printf("This program ran in about %.2f microseconds\n", average);

        return 0;
}
