#include "mymalloc.h"

void* mymalloc(size_t memSize, char *variable, size_t line1){
        char* ptr =&mem[0];
        while(ptr>=&mem[ArraySize]){
                if(((metadata)(*ptr)->free==0)&((metadata)(*ptr)->datasize>=memSize)){
                        (metadata)(*ptr)->free=1;
                        (metadata)(*ptr)->datasize=memSize;
                        return (void*)*ptr;
                }
                ptr=ptr+sizeof(metadata)+(metadata)(*ptr)->datasize;
        }
        metadata *data=(metadata*)ptr;
        start->free = 0;
        start->datasize = 4096-sizeof(metadata);


}

void* free(void* memAddr, char *variable2, size_t line2){



}

void InitilizeFunction(){

        int i;
        for(i = 0; i < ArraySize; i++ ){

                mem[i] = '0';
        }

        metadata *start= (metadata)&mem[0];
        start->free = 0;
        start->datasize = 4096-sizeof(metadata);

}
