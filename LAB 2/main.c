#include <stdio.h>
#include <stdlib.h>
#include "List.h"// структура
#include "CreateNode.h"//функция создание списка
#include "PrintNode.h"//функция вывода списка в консоль
#include "BubbleSortList.h"//функция сортировки
#include "Root.h"// возвращает корень (last elem)
#include "FreeList.h"// освобождение памяти

int main()
{
	int size;
	printf("Enter size: ");
	scanf("%d", &size);

  	List* list = CreateNode(size);
	printf("Before sort:\n");
	PrintNode(list);

	BubbleSortList(list);
	printf("After sort:\n");
	PrintNode(list);

	List* root = Root(list);// последний обьект в списке
	FreeList(list);
	//printf("After cleaning:\n");
	//PrintNode(list);

  	return 0;
}
