#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define w 100 // width
#define h 30 // height
// resolution

void init();
void show();
void newSnow();
void moveSnow();
void setCursor(int x, int y);

char res[h][w + 1]; // +1 для конца строки

int main()
{

        init();
        do
        {
                setCursor(0, 0);
                moveSnow();
                newSnow();
                show();
                Sleep(100);
        } while (GetKeyState(VK_ESCAPE) >= 0);

        return 0;
}

void init() // инициализация
{
        for (int i = 0; i < w; i++)
        {
                res[0][i] = ' ';
        }

        res[0][w] = '\0';

        for (int i = 1; i < h; i++)
        {
                sprintf(res[i], res[0]);
        }
}

void  show() // показ
{
        res[h-1][w-1] = '\0'; // заменяем посл. строку на символ переноса строки
        for (int i = 0; i < h; i++)
        {
                fprintf(stdout, "%s", res[i]);
        }

}

void newSnow()
{
        for (int i = 0; i < w; i++)
        {
                if (rand() % 12 == 1)
                {
                        res[0][i] = '*';
                }
        }
}

void moveSnow()
{
        int dx;
        for (int i = (h - 1); i >= 0; i--)
        {
                for (int j = 0; j < w ;j++)
                {
                        if (res[i][j] == '*')
                        {
                                res[i][j] = ' ';
                                dx = 0;
                                if (rand() % 10 < 1)
                                {
                                        dx++;
                                }
                                if (rand() % 10 < 1)
                                {
                                        dx--;
                                }
                                dx = dx + j;
                                if ((dx >= 0) && (dx < w) && ((i+1) < h))
                                {
                                        res[i+1][dx] = '*';
                                }
                        }
                }
        }
}

void setCursor(int x, int y)
{
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
