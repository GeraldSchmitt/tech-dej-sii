#include <stdlib.h>
#include <stdio.h>

#include "conquerWorld.h"
#include "myMemory.h"
#include "azure_c_shared_utility/httpapi.h"

int frobnicate()
{
	int ret;
	HTTP_HANDLE handle;
	HTTPAPI_RESULT res = HTTPAPI_Init();
	if (res == HTTPAPI_OK)
	{
		printf("Init success!\n");
		
		char * buffer = my_malloc(8);
		if (buffer != NULL)
		{
			printf("buffer allocated\n");
			// do stuff with buffer
			free(buffer);
			ret = 43;
		}
		else
		{
			printf("malloc failed\n");
			ret = 0;
		}

		HTTPAPI_Deinit();
	}
	else
	{
		printf("Init fail...\n");
		ret = 0;
	}
	return ret;
}
