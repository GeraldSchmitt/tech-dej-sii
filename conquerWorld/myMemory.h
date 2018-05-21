#ifndef CONQUERWORLD_MYMEMORY_H_
#define CONQUERWORLD_MYMEMORY_H_

#include "umock_c_prod.h"

#define malloc(size) my_malloc(size)
#define free(ptr) my_free(ptr)

MOCKABLE_FUNCTION(, void *, my_malloc, size_t, size);
MOCKABLE_FUNCTION(, void, my_free, void *, ptr);


#endif /* CONQUERWORLD_MYMEMORY_H_ */
