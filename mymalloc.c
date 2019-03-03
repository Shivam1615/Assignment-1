#include "mymalloc.h"

void* mymalloc(size_t memSize, char *variable, size_t line1){



}

void* free(void* memAddr, char *variable2, size_t line2){



}

void InitilizeFunction(){

int i;
for(i = 0; i < ArraySize; i++ ){

        mem[i] = '0';
}

struct metadata start;
start->free = 0;
start->datasize = 4096-sizeof(metadata);
mem[0] = start;

}
