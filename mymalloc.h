#include <stdlib.h>
#ifndef mymalloc

#define malloc( x ) mymalloc( x, __FILE__, __LINE__ )
#define free( x ) myfree( x, __FILE__, __LINE__ )
#define ArraySize 4096

int storage = 0;

typedef struct metadata{
int free;
int datasize;
} metadata;


static char mem[ArraySize];

void *mymalloc(size_t head, char *variable, size_t line1);

void myfree(void *pointer, char *variable2, size_t line2);

void InitilizeFunction();


#endif
