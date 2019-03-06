#include "mymalloc.h"

void* mymalloc(size_t memSize, char *variable, size_t line1){
        char* ptr =&mem[0];
        char* position;

        while(ptr<=&mem[ArraySize-1]){

                if((((metadata*)(ptr))->free=='e')&((metadata*)(ptr))->datasize>=memSize){
                        printf("malloced\n");
                        position=ptr+sizeof(metadata);
                        int oldSize=((metadata*)(ptr))->datasize;
                        ((metadata*)(ptr))->free='u';
                        if( ((metadata*)(ptr))->datasize<=memSize+sizeof(metadata)){

                                return (void*)position;

                        }else{
                                ((metadata*)(ptr))->datasize=memSize;
                        }

                        if(position+memSize>=&mem[ArraySize-1]){
                                return (void*)position;
                        }

                        char *newMetaData=position+memSize;
                        ((metadata*)(newMetaData))->datasize=oldSize-memSize-sizeof(metadata*);
                        ((metadata*)(newMetaData))->free='e';

                        return (void*)position;
                }
                ptr=ptr+sizeof(metadata)+((metadata*)(ptr))->datasize;
        }
        if(ptr>=&mem[ArraySize]){

                printf("NULL\n");
                return NULL;
        }
}

void myfree(void* memAddr, char *variable2, size_t line2){

        char *ptr=(char*)memAddr;
        ptr=ptr-sizeof(metadata);

        if( (ptr)<&mem[0] || (ptr)>&mem[ArraySize-1]){
                printf("Thats not a pointer");
        }

        if(memAddr==NULL){
                printf("Can't free NULL pointer\n");
                return;
        }else if( ((metadata*)(ptr))->free!='u'){
                printf("This address wasn't malloced\n");
                return;
        }else{
                printf("freed\n");
                ((metadata*)(ptr))->free='e';
        }

        char *nextData=ptr+sizeof(metadata)+((metadata*)(ptr))->datasize;
        if( ((metadata*)(nextData))->free=='e'){

                ((metadata*)(ptr))->datasize+=(sizeof(metadata)+((metadata*)(nextData))->datasize);
                return;
        }
        return;
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
}
