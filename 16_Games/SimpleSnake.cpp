#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>

using namespace std;

void setCursor(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


class Snake
{
protected:
	bool gameOver = false;
	void SetGameOver(bool value) { gameOver = value; }
private:
	const int width = 30;
	const int height = 20;

	int x = width / 2;
	int	y = height / 2;

	int	fruitX = rand() % width;
	int	fruitY = rand() % height;

	int	score = 0;

	int tailX[600];
	int	tailY[600];

	int nTail = 0;

	enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };

	eDirecton dir = STOP;

	void GamePause()
	{
		while (!_kbhit() || (_kbhit() && _getch() == 'p'))// пауза пока не нажали клавишу ( кроме 'p' ) 
		{
			DrawPauseMenu();
		}
		system("cls");
	}
public:
	bool GetGameOver() { return gameOver; }

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

	void DrawPauseMenu()
	{
		system("cls");

		for (int i = 49; i < 53; i++)
		{
			string temp1{"D:\\WORLD PROGRAMMING\\Programming\\C++\\SnakeSimple\\PauseTemp\\"};
			string temp2{".txt" };
			string line;
			temp1 = temp1 + char(i) + temp2;// конкотенация
			ifstream in(temp1); // окрываем файл для чтения
			
			if (in.is_open())
			{		
				while (getline(in, line))
				{
					cout << line << endl;
				}
			}
			in.close();     // закрываем файл
			Sleep(500);
			
		}
		
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

		if (x >= width) x = 0; else if (x < 0) x = width - 1;
		if (y >= height) y = 0; else if (y < 0) y = height - 1;

		for (int i = 0; i < nTail; i++)
			if (tailX[i] == x && tailY[i] == y)
				gameOver = true;

		if (x == fruitX && y == fruitY)
		{
			score += 1;
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
	int st = 1;
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
		Print(i);
	}

	void Print(int val)
	{
		system("cls");

		if (val == 1) i = 49;
		if (val == 2) i = 50;
		if (val == 3) i = 51;
		if (val == 4) i = 52;

		string temp1{ "D:\\WORLD PROGRAMMING\\Programming\\C++\\SnakeSimple\\PauseTemp\\menu" };
		string temp2{ ".txt" };
		string line;
		temp1 = temp1 + char(i) + temp2;// конкотенация
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
	void Logic()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'w':
			{
				if (st != 1)
				{
					st--;
					Print(st);
				}
				
				break;
			}
			case 's':
			{
				if (st != 4)
				{
					st++;
					Print(st);
					
				}
				
				break;
			}
			case 'f': {
				if (st == 1)
				{// START
					turnEnd = true;
				}
				if (st == 2)
				{// INFO
					turnEnd = true;
				}
				if (st == 3)
				{// SAVE
					turnEnd = true;
				}
				if (st == 4)
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
};

int main()
{
	Snake snake;//
	GameMenu menu;//
	system("Color D");

	while (!menu.GetTurnEnd())
	{
		setCursor(0, 0);
		menu.Print();
		menu.Logic();
		system("cls");
	}

	while (!snake.GetGameOver())
	{
		setCursor(0, 0);
		snake.Draw();
		snake.Input();
		snake.Logic();
		Sleep(30);
	}

	return 0;
}
