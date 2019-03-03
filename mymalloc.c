#include "mymalloc.h"

void* mymalloc(size_t memSize){



}

void* free(void* memAddr){



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
