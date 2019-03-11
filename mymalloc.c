#include "mymalloc.h"
#include <stdio.h>

void* mymalloc(size_t memSize, char *variable, size_t line1){
        char* ptr =&mem[0];
        char* position;
        if(mem[ArraySize-1]!='0'){// The last byte of the array checks to see if the function was initalized
                InitilizeFunction();
        }
        if(memSize<1){// you can't malloc 0 bytes

                fprintf( stderr, "You can't malloc 0 bytes\n");
                return NULL;
        }
        while(ptr<=&mem[ArraySize-1]){// goes through the array looking for free space for the user data
                //This if checks for metadata with free space and enough data space
                if((((metadata*)(ptr))->free=='e')&((metadata*)(ptr))->datasize>=memSize){
                        printf("malloced\n");
                        position=ptr+sizeof(metadata);
                        int oldSize=((metadata*)(ptr))->datasize;
                        ((metadata*)(ptr))->free='u';
                        //if there isn't enough space for more metadata the pointer is just returned
                        if( ((metadata*)(ptr))->datasize<=memSize+sizeof(metadata)){
                                return (void*)position;
                        }else{
                                ((metadata*)(ptr))->datasize=memSize;
                        }
                        if(position+memSize>=&mem[ArraySize-1]){
                                return (void*)position;
                        }
                        char *newMetaData=position+memSize;// new metadata to represent the remaining free space
                        ((metadata*)(newMetaData))->datasize=oldSize-memSize-sizeof(metadata*);
                        ((metadata*)(newMetaData))->free='e';

                        return (void*)position;
                }
                ptr=ptr+sizeof(metadata)+((metadata*)(ptr))->datasize;// jumps from metadata to metadata
        }
        if(ptr>=&mem[ArraySize]){//if no space was found it will return NULL

                fprintf( stderr, "no space for user data, returned NULL\n");
                return NULL;
        }
}

void myfree(void* memAddr, char *variable2, size_t line2){

        char *ptr=(char*)memAddr;
        ptr=ptr-sizeof(metadata);

        if(memAddr==NULL){

                fprintf( stderr, "You can't free a NULL pointer\n");

                return;
        }

        if( (ptr)<&mem[0] || (ptr)>&mem[ArraySize-1]){//if ptr is out of bonds of the array it isn't a malloced pointer

                fprintf( stderr, "This isn't a pointer\n");


                return;
        }

        if( ((metadata*)(ptr))->free!='u'){

                fprintf( stderr, "This address wasn't malloced\n");

                return;
        }else{//The metadata holding memAddr is set to free space
                printf("freed\n");
                ((metadata*)(ptr))->free='e';
        }

        char *nextData=ptr+sizeof(metadata)+((metadata*)(ptr))->datasize;
        // checks to see if the next metadata block is free. If it is they are combined inorder to save space

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

	//The first metadata is placed into the array representing all the free space
        metadata *start= (metadata*)(&mem[0]);
        start->free = 'e';
        start->datasize = ArraySize-sizeof(metadata)-1;
	return;       


}
