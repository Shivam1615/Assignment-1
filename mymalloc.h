#include <stdlib.h>
#include <time.h>
#define malloc( x ) mymalloc( x, __FILE__, __LINE__ )
#define free( x ) myfree( x, __FILE__, __LINE__ )
#define ArraySize 4096

typedef struct metadata{
char free;
short int datasize;
} metadata;

struct timevalue{
long value1;
long value2;
};

static char mem[ArraySize];

void *mymalloc(size_t head, char *variable, size_t line1);

void myfree(void *pointer, char *variable2, size_t line2);

void InitilizeFunction();
