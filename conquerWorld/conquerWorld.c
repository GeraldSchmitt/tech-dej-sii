#include <stdlib.h>
#include <stdio.h>

#include "conquerWorld.h"
#include "azure_c_shared_utility/httpapi.h"

int frobnicate()
{
	HTTP_HANDLE handle;
	HTTPAPI_RESULT res = HTTPAPI_Init();
	if (res == HTTPAPI_OK)
	{
		printf("Init success!\n");
		
		HTTPAPI_Deinit();
		return 43;
	}
	else
	{
		printf("Init fail...\n");
		return 0;
	}
	return 43;
}
