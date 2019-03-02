#include <stdio.h>
#include <stdlib.h>
#ifndef mymalloc

#define malloc( x ) mymalloc( x, __FILE__, __LINE__ )
#define free( x ) myfree( x, __FILE__, __LINE__ )
#define ArraySize 4096
static char mem[ArraySize];

void *mymalloc(size_t head);

void myfree(void *pointer);


#endif
