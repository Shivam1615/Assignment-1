#include <stdio.h>
#include <stdlib.h>
#ifndef mymalloc

#define malloc( x ) mymalloc( x, __FILE__, __LINE__ )
#define free( x ) myfree( x, __FILE__, __LINE__ )

static char mem[4096];

void *mymalloc(size_t);

void myfree(void *);


#endif
