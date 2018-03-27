#include <stdlib.h>
#include <stdio.h>

#include "conquerWorld/conquerWorld.h"

int main(int argc, char** argv)
{
	printf("Welcome to the techdej\n");
	int foo = frobnicate();
	printf("frobnicate returned %d\n", foo);
	return 0;
}
