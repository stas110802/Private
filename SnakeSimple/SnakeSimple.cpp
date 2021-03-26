#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void setCursor(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

bool gameOver = false;// должна быть в классе Snake  ! { bag } upd: глобальные переменный говно

class Snake
{
protected:
	
	void SetGameOver(bool value) { gameOver = value; }
private:
	const int width = 6;
	const int height = 6;

	char s;

	int x = width / 2;
	int	y = height / 2;

	int	fruitX = rand() % (width - 2) +1;
	int	fruitY = rand() % (height - 2)+1;

	int	score = 0;

	int tailX[600];
	int	tailY[600];

	int nTail = 0;

	 enum  eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };// enumDirection [ алфавит с направлениями ]

	 eDirection dir = STOP;

	void GamePause()
	{
		while (!_kbhit() || (_kbhit() && _getch() == 'p'))// пауза пока не нажали клавишу ( кроме 'p' ) 
		{
			DrawPauseMenu();
		}
		system("cls");// pause end (enter display)
	}
public:
	bool GetGameOver() { return gameOver; }

	void FileReader(int i, string temp3)
	{
		string temp1{ "D:\\WORLD PROGRAMMING\\Programming\\C++\\SnakeSimple\\PauseTemp\\" };
		string temp2{ ".txt" };
		string line;
		temp1 = temp1 + temp3 + char(i) + temp2;// конкотенация
		ifstream in(temp1); // окрываем файл для чтения

		if (in.is_open())
		{
			while (getline(in, line))
			{
				cout << line << endl;
			}
		}
		in.close();     // закрываем файл
	}

	void Draw()
	{
		for (int i = 0; i < width ; i++)
			cout << "#";
		cout << endl;

		for (int i = 0; i < height-2; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j == 0 || j == width - 1)
					cout << "#";
				
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

					if (i == y && j == x)
						cout << "O";
					else if (i == fruitY && j == fruitX)
						cout << "F";
					else if (!print)
						cout << " ";
				}
			}
			cout << endl;
		}

		for (int i = 0; i < width; i++)
			cout << "#";
		cout << endl;
		cout << "Score:" << score << endl;
	}

	void DrawPauseMenu()
	{
		system("cls");
		
		for (int i = 49; i < 58; i++)
		{
			FileReader(i, "");
			Sleep(500);
			setCursor(0, 0);
			
		}		
	}

	void Input()
	{		
		if (_kbhit())
		{
			switch (_getch())
			{
				case 'a':
					if (dir != RIGHT)
						dir = LEFT;					
					break;
				case 'd':
					if (dir != LEFT)
						dir = RIGHT;					
					break;
				case 'w':
					if (dir != DOWN)
						dir = UP;					
					break;
				case 's':
					if (dir != UP)
						dir = DOWN;					
					break;
				case 'x':
					gameOver = true;
					break;
				case 'p':
					GamePause();
					break;
				}
		}
		
	}
	void Logic()
	{		
		int tX = x;
		int tY = y;
		int tempX ;
		int tempY ;

		for (int i = 0; i < nTail; i++) // 3
		{
			// запоминаем
			tempX = tailX[i];
			tempY = tailY[i];
			// инициализируем
			tailX[i] = tX;
			tailY[i] = tY;
			// делаем шаг
			tX = tempX;
			tY = tempY;
			
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
		// проверка на ширину [ left or right side ] (  не пересекли ли мы поле  )
		if (x >= width ) x = 0;
		else if (x < 0) x = width -2;
		// проверка на высоту [ up or down side ] (  не пересекли ли мы поле  )
		if (y >= height) y = 0;
		else if (y < 0) y = height -2;
		// проверка не врезались ли мы в хвост [ tail ]
		for (int i = 0; i < nTail; i++)
			if (tailX[i] == x && tailY[i] == y)
				gameOver = true;
		// проверка не сьели ли мы фрукт [ fruit ]
		if (x == fruitX && y == fruitY)
		{
			score += 1;
			fruitX = rand() % (width-2)+1;
			fruitY = rand() % (height-2)+1;
			nTail++;
		}
	}

};

class GameMenu : Snake
{
private:
	int i = 49;
	bool turnEnd = false;
public:

	void Print()
	{
		FileReader(i, "menu");
		system("cls");
	}
	void Logic()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
			{
				if (i != 49)
				{
					i--;
					Print();
				}
				
				break;
			}
			case 's':
			{
				if (i != 52)
				{
					i++;
					Print();				
				}
				
				break;
			}
			case 'f': {
				if (i == 49)
				{// START
					turnEnd = true;
				}
				if (i == 50)
				{// SAVE
					
					turnEnd = true;
				}
				if (i == 51)
				{// INFO
					InfoAboutGame();
					//turnEnd = true;
				}
				if (i == 52)
				{// EXIT
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

	void PrintGameOver()
	{
		system("cls");
		FileReader(49, "game");
	}

	void InfoAboutGame()
	{
		system("cls");
		FileReader(49, "info");

		while (!_kbhit()) { }
	}
};

int main()
{
	srand(time(NULL));
	Snake snake;//
	GameMenu menu;//
	system("Color D");

	while (!menu.GetTurnEnd())
	{
		setCursor(0, 0);
		menu.Print();
		menu.Logic();
	}

	while (!snake.GetGameOver())
	{
		setCursor(0, 0);
		snake.Draw();
		snake.Input();
		snake.Logic();
		Sleep(200);
	}
	menu.PrintGameOver();

	return 0;
}