#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h> // for the console to work correctly

int main()
{
	char key;
	char gameSpace[10][21];
	int i;
	int x = 10, y = 5;
	int ox, oy;
	int ax = 5, ay = 3;
	int apple = 0;
	srand(time(NULL));
	do
	{
		// ----------------------------------GAME SPACE----------------------------------------------
		sprintf(gameSpace[0],  "####################"); // up border
		for( int i = 1; i < 9; i++)
		{
			sprintf(gameSpace[i] ,"#                  #"); // middle
		}

		sprintf(gameSpace[9],  "####################"); // down border
		// --------------------------------------DOG AND APPLE----------------------------------------
		gameSpace[y][x] = '@'; // DOG
		gameSpace[ay][ax] = '*'; // APPLE
		system("cls"); // CLEAR
		// ----------------------------------INPUT----------------------------------------------------
		for ( i = 0; i < 10; i++ )
		{
			fprintf(stdout,"%s\n", gameSpace[i]);
		}
		fprintf(stdout, "Apple: %d\n", apple);
		key = getch(); // ws - height, ad - width
		ox = x;
		oy = y;
		// ----------------------------------KEY-------------------------------------------------------
		if (key == 'w')
		{
		 	y--;
		}
		if (key == 's')
		{
			y++;
		}
		if (key == 'a')
		{

		 	x--;
		}
		if (key == 'd')
		{
		 	x++;
		}
		if (gameSpace[y][x] == '#') // border space (lock)
		{
			x = ox;
			y = oy;
		}
		if ( (x == ax) && (y == ay) ) // random apple place
		{
			ax = rand() * 1.0 / RAND_MAX * 18 + 1;
			ay = rand() * 1.0 / RAND_MAX * 8 + 1;
			apple++;
		}
	} while(key != 'e' && apple != 3); // exit
	// ------------------------------------------------------------------------------------------------
	if (apple == 3)
	{
		system("cls");
		fprintf(stdout, "You ate too many apples, so your body could not stand and you died");

	}
	return 0;
}
