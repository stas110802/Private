//#include <stdio.h>
//#include <stdlib.h>

void FreeList(List* list)
{
   List* temp = NULL;

   while (list != NULL)
    {
       temp = list;
       list = list->pNext;
       free(temp);
    }
}