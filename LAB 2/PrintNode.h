#include <stdio.h>
//#include <stdlib.h>

void PrintNode(List* list)
{
	//List* temp = list;// создаем временный обьект и передаем ему данные основного(адр)
	
	while (list)//printf("%d %d ", temp->data, temp->pNext->data);
	{
		printf("%d\t", list->data);
		list = list->pNext;// переход к следующему обьекту
	}
	
	printf("\n");
}