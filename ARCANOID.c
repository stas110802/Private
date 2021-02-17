w#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

#define height 25
#define width 65

typedef struct
{
        int  x; // width
        int  y; // height
        int  z; // widht boolka
} TPboolka;

typedef struct
{
        float x;
        float y;
        int ix;
        int iy;
        float alpha;
        float speed;
}TPball;

char gameSpace[height][width + 1];
TPboolka boolka;
TPball ball;
int hit = 0;
int hitMax = 0;

void init(); // 104
void show(); // 134
void initBoolka(); // 155
void putBoolka(); // 162
void moveBoolka(int x); // 170
void setCursor(int x, int y); // 96
void initBall(); // 184
void putBall(); // 192
void moveBall(float x, float y); // 197
void autoMoveBall(); // 205

int main()
{

        BOOL run = FALSE;
        char key;
        initBoolka();
        initBall();
        do
        {
                setCursor(0, 0);

                if (run)
                {
                        autoMoveBall();
                }
                if (ball.iy > height)
                {
                        run = FALSE;
                        if (hit > hitMax)
                        {
                                hitMax = hit;
                        }
                        hit = 0;
                }
                init();
                putBoolka();
                putBall();
                show();

                if(GetKeyState('A') < 0)
                {
                        moveBoolka ( boolka.x - 1);
                }

                if(GetKeyState('D') < 0)
                {
                        moveBoolka ( boolka.x + 1);
                }
                if(GetKeyState('W') < 0)
                {
                        run = TRUE;
                }
                if (!run)
                {
                        moveBall(boolka.x  + boolka.z / 2, boolka.y - 1 ); // start position ball + boolka
                }
                Sleep(20);
        } while (GetKeyState('E') >= 0);
        return 0;
}

void setCursor(int x, int y)
{
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void init()
{
        for (int i = 0; i < width; i++)
        {
                gameSpace[0][i] = '#';
        }
        gameSpace[0][width] = '\0';

        strncpy(gameSpace[1], gameSpace[0], width + 1);
        for (int i = 1; i < width-1; i++)
        {
                gameSpace[1][i] = ' ';
        }

        for (int i = 1; i < height; i++)
        {
                strncpy(gameSpace[i], gameSpace[1], width + 1);
        }

        for (int i = 6; i < 21; i++) // ####### #######
        {
                gameSpace[10][i] = '#';
        }

        for (int i = 45; i < 60; i++)
        {
                gameSpace[10][i] = '#'; // ####### #######
        }
}

void show()
{
        for (int i = 0; i < height; i++)
        {
                fprintf(stdout, "%s", gameSpace[i]);
                if (i == 3)
                {
                        fprintf(stdout, "     Hit  %i     ", hit);
                }
                if (i == 4)
                {
                        fprintf(stdout, "     Max %i       ", hitMax);
                }
                if (i < height - 1)
                {
                        fprintf(stdout, "\n");
                }
        }

}

void initBoolka()
{
        boolka.z = 7;
        boolka.x = (width - boolka.z) / 2;
        boolka.y = (height - 1);
}

void putBoolka()
{
        for(int i = boolka.x; i < (boolka.x + boolka.z);  i++)
        {
                gameSpace[boolka.y][i] = '@';
        }
}

void moveBoolka(int x)
{
        boolka.x = x;
        if (boolka.x < 1)
        {
                boolka.x = 1;
        }

        if (boolka.x + boolka.z >= width)
        {
                boolka.x = width - 1 - boolka.z;
        }
}

void initBall()
{
        moveBall(2, 2);
        ball.alpha = -1;
        ball.speed = 0.5;

}

void putBall()
{
        gameSpace[ball.iy][ball.ix] = '*';
}

void moveBall(float x, float y)
{
        ball.x = x;
        ball.y = y;
        ball.ix = (int)round(ball.x); // optimization putBall ^_^
        ball.iy = (int)round(ball.y);
}

void autoMoveBall()
{
        if (ball.alpha < 0)
        {
                ball.alpha += M_PI*2;
        }
        if (ball.alpha > M_PI*2)
        {
                ball.alpha -= M_PI*2;
        }
        TPball bl = ball;
        moveBall( ball.x + cos(ball.alpha) * ball.speed,
                  ball.y + sin(ball.alpha) * ball.speed );

        if ( (gameSpace[ball.iy][ball.ix] == '#') || (gameSpace[ball.iy][ball.ix] == '@') )
        {
                if (gameSpace[ball.iy][ball.ix] == '@')
                {
                        hit++;
                }
                if (ball.x != bl.ix && ball.y != bl.iy)
                {
                        if (gameSpace[bl.iy][ball.ix] == gameSpace[ball.iy][bl.ix])
                        {
                                bl.alpha = bl.alpha + M_PI;
                        }
                        else
                        {
                                if (gameSpace[bl.iy][ball.ix] == '#')
                                {
                                        bl.alpha = (M_PI*2 - bl.alpha) + M_PI;
                                }
                                else
                                {
                                        bl.alpha = (M_PI*2 - bl.alpha);
                                }
                        }
                }
                else if (ball.iy == ball.iy)
                {
                        bl.alpha = (2*M_PI - bl.alpha) + M_PI;
                }
                else
                {
                        bl.alpha = (2*M_PI - bl.alpha);
                }
                ball = bl;
                autoMoveBall;
        }
}
