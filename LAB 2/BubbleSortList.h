//#include <stdio.h>
//#include <stdlib.h>

void BubbleSortList(List * list) 
{
	List * temp = NULL;
    
	if (list != NULL) // если список не пустой
	{
		while (list->pNext != NULL)// идем до тех пора пока p не пустой 
		{
		    	temp = list->pNext;// temp - это следующий обьект

			do 
			{
				if (list->data > temp->data) // если 1 елемент больше 2
				{// меняем их местами
				    int value = temp->data;
				    temp->data = list->data;
				    list->data = value;
				}

				temp = temp->pNext;// шаг вперед для temp
		    	} while (temp != NULL);

		    	list = list->pNext;
			/* шаг вперед для list,
			   тоесть следующий do{}while будет начиная со 2 обьекта,
			   потом с 3 и так далее
			 */
		}
 	}
}
