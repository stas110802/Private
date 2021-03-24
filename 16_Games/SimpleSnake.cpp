#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

class Snake 
{
protected:
	bool gameOver = false;
	bool SetGameOver(bool value) { gameOver = value; }
private:
	const int width = 30;
	const int height = 20;

	int x = width / 2,
		y = height / 2,
		fruitX = rand() % width,
		fruitY = rand() % height,
		score = 0;
	int tailX[100], tailY[100];
	int nTail;
	enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };

	eDirecton dir = STOP; 
public:
	bool GetGameOver() { return gameOver; }
	/*
	void Setup()
	{
		gameOver = false;
		dir = STOP;
		x = width / 2;
		y = height / 2;
		fruitX = rand() % width;
		fruitY = rand() % height;
		score = 0;
	}
	*/
	void Draw()
	{
		system("cls"); //system("clear");
		for (int i = 0; i < width + 2; i++)
			cout << "#";
		cout << endl;

		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == 0)
					cout << "#";
				if (i == y && j == x)
					cout << "O";
				else if (i == fruitY && j == fruitX)
					cout << "F";
				else
				{
					bool print = false;
					for (int k = 0; k < nTail; k++)
					{
						if (tailX[k] == j && tailY[k] == i)
						{
							cout << "o";
							print = true;
						}
					}
					if (!print)
						cout << " ";
				}


				if (j == width - 1)
					cout << "#";
			}
			cout << endl;
		}

		for (int i = 0; i < width + 2; i++)
			cout << "#";
		cout << endl;
		cout << "Score:" << score << endl;
	}
	void Input()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameOver = true;
				break;
			}
		}
	}
	void Logic()
	{
		int prevX = tailX[0];
		int prevY = tailY[0];
		int prev2X, prev2Y;
		tailX[0] = x;
		tailY[0] = y;

		for (int i = 1; i < nTail; i++)
		{
			prev2X = tailX[i];
			prev2Y = tailY[i];
			tailX[i] = prevX;
			tailY[i] = prevY;
			prevX = prev2X;
			prevY = prev2Y;
		}

		 switch (dir)
		 {
			 case LEFT:
			 {
				 x--;
				 break;
			 }
			 case RIGHT:
			 {
				 x++;
				 break;
			 }
			 case UP: 
			 {
				 y--;
				 break;
			 }
			 case DOWN: 
			 {
				 y++;
				 break;
			 }
			 default:
				 break;
		 }

		 if (x >= width) x = 0; else if (x < 0) x = width - 1;
		 if (y >= height) y = 0; else if (y < 0) y = height - 1;

		 for (int i = 0; i < nTail; i++)
			 if (tailX[i] == x && tailY[i] == y)
				 gameOver = true;

		 if (x == fruitX && y == fruitY)
		 {
			 score += 10;
			 fruitX = rand() % width;
			 fruitY = rand() % height;
			 nTail++;
		 }
	}

};

class GameMenu : Snake
{
private:
	int i = 1;
	bool turnEnd = false;
public:
	string dtr[6]
	{
		"###################",
		"#    > START      #",// 5
		"#      INFO       #",
		"#      SAVE       #",
		"#      EXIT       #",
		"###################"
	};
	void Print()
	{
		for (int i = 0; i < 6; i++)
		{
				cout << dtr[i] << endl;		
		}
	}
	void Logic()
	{
		if (_kbhit()) 
		{
			switch (_getch())
			{
			case 'w':
			{
				if (i != 1) 
				{
					dtr[i][5] = ' ';
					i--;
				}
				dtr[i][5] = '>';
				break;
			}
			case 's':
			{
				if (i != 4)
				{
					dtr[i][5] = ' ';
					i++;
				}
				dtr[i][5] = '>';
				break;
			}
			case 'f': {
				if (i == 1) {// START
					turnEnd = true;
				}
				if (i == 2) {// INFO
					turnEnd = true;
				}
				if (i == 3) {// SAVE
					turnEnd = true;
				}
				if (i == 4) {// EXIT
					SetGameOver(true);
					turnEnd = true;
				}
				break;
			}
			default:
				break;
			}
		}
	}
	bool GetTurnEnd() { return turnEnd; };
};

int main()
{
	Snake snake;
	GameMenu menu;
	//snake.Setup();
	
	while (!menu.GetTurnEnd())
	{
		menu.Print();
		menu.Logic();
		system("cls");
	}

	while (!snake.GetGameOver() )
	{
		snake.Draw();
		snake.Input();
		snake.Logic();
		Sleep(30);//sleep(10);
	}
	return 0;
}