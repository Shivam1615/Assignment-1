#include "mymalloc.h"

void* mymalloc(size_t memSize, char *variable, size_t line1){
        char* ptr =&mem[0];
        char* position;


        while(ptr<=&mem[ArraySize-1]){

                if((((metadata*)(ptr))->free==0)&((metadata*)(ptr))->datasize>=memSize){
                        printf("malloced");
                        int oldSize=((metadata*)(ptr))->datasize;
                        ((metadata*)(ptr))->free=1;
                        ((metadata*)(ptr))->datasize=memSize;
                        position=ptr+sizeof(metadata);

                        printf(" %d ",oldSize);

                        if(position+memSize>=&mem[ArraySize-1]){

                                return (void*)position;

                        }
                        char *newMetaData=position+memSize;
                        ((metadata*)(newMetaData))->datasize=oldSize-memSize-sizeof(metadata*);
                        ((metadata*)(newMetaData))->free=0;

                        return (void*)position;
                }
                ptr=ptr+sizeof(metadata)+((metadata*)(ptr))->datasize;
        }
        if(ptr>=&mem[ArraySize]){
                printf("NULL");


        }

}


void free(void* memAddr, char *variable2, size_t line2){



}

void InitilizeFunction(){

        int i;
        for(i = 0; i < ArraySize; i++ ){

                mem[i] = '0';
        }

        metadata *start= (metadata*)&mem[0];
        start->free = 0;
        start->datasize = 4096-sizeof(metadata);

}
