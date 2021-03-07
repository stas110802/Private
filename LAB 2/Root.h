#include <stdio.h>
//#include <stdlib.h>

List* Root(List* value)
{
	while (value->pNext != NULL)
	{
		value = value->pNext;
	}

	return value;
}