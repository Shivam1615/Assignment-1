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
char *Array[50];
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

/*
 *Test Case C: Randomly choose between a 1 byte malloc() or free()ing a 1 byte pointer > do this until you have allocated 50 times
 *  - Keep track of each operation so that you eventually malloc() 50 bytes, in total
    > if you have already allocated 50 times, disregard the random and just free() on each iteration
    - Keep track of each operation so that you eventually free() all pointers
    > don't allow a free() if you have no pointers to free()
 */

int malloctracker = 0;
char *ArrayC[50];
int mallocTotal;
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

    
/*
 * Test Case D: Randomly choose between a randomly-sized malloc() or free()ing a pointer – do this many times (see below)
 * - Keep track of each malloc so that all mallocs do not exceed your total memory capacity - Keep track of each operation so that you eventually malloc() 50 times
 * - Keep track of each operation so that you eventually free() all pointers
 * - Choose a random allocation size between 1 and 64 bytes
 */


    
malloctracker = 0;
char *ArrayD[50];
mallocTotal=0;;
while(mallocTotal<50){
        int pick = rand()%2;
        int randSize=(rand()%64)+1;
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
    
/*
 *Test Case E:  
 *
 */

/*int a;
int b = 0;
int c = 0;
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
*/

char *array[30];
int tracker = 0;
int a = 0;
while(a < 75){
        int MallocOrFree = rand() % 2;
        int Random = (rand() % 500) + 1;
        if(MallocOrFree == 0){
                char *pointer = malloc(Random);
                array[a] = pointer;
                tracker++;
                a++;
        }else if(MallocOrFree == 1 && tracker > 0){
                free(array[tracker-1]);
                tracker--;
        }
}
        while(tracker > 0){
                free(array[tracker-1]);
                tracker--;
        }


/*
 *Test Case F:
 *
 */


        
return 0;
}
