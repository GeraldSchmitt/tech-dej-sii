#include <stdlib.h>
#include "myMemory.h"

#undef malloc
#undef free

void * my_malloc(size_t size) { return malloc(size); }

void my_free(void * ptr) { return free(ptr); }


