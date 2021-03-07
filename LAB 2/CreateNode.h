#include <stdio.h>
#include <stdlib.h>

List* CreateNode(const int SIZE)
{
	List* mainValue = NULL;// девственный обьект, который будем возвращать
	List* value = NULL;// обьект с которым будем работать
// адресс value == адрессу fV
	mainValue = (List *)malloc(sizeof(List));
	value = mainValue;// обьединяем адресса
// инициализация 1 обьекта	
	value->pNext = NULL;
	printf("Node[0] = ");
	scanf("%d", &value->data);
//заполнение односвязного списка
	for (int i = 1; i < SIZE; i++)
	{
		value->pNext = (List *)malloc(sizeof(List));
		value = value->pNext;// переход к следующему обьекту {временный обьект} = {новый обьект под который мы выделили память}
		value->pNext = NULL;
		printf("Node[%d] = ", i);
		scanf("%d", &value->data);
	}
	
	return mainValue;
}
