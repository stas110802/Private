#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

int isWall(char loc[][21], int a, int b)
{
    int Wall = 0;
    if (loc[b][a] == '#')
    {
        Wall = 1;
        return Wall;
    } else {Wall = 0;return Wall;}
}

void GameOver(int score)
{
    int i;
    char key;
    char game_over[10][21];
    do
    {
        sprintf(game_over[0], "###################");
        sprintf(game_over[1], "#   *THE LOOTER*  #");
        sprintf(game_over[2], "#                 #");
        sprintf(game_over[3], "#    GAME OVER    #");
        sprintf(game_over[4], "#   YOUR SCORE:   #");
        sprintf(game_over[5], "#        %d        #", score);
        sprintf(game_over[6], "#                 #");
        sprintf(game_over[7], "#                 #");
        sprintf(game_over[8], "#   (f - exit)    #");
        sprintf(game_over[9], "###################");

        system("cls");
        if (score >= 10) sprintf(game_over[5], "#        %d       #", score);
        if (score >= 100) sprintf(game_over[5],"#        %d      #", score);
        if (score >= 10)
        {
        sprintf(game_over[6], "#   CODE-REWARD:  #");
        sprintf(game_over[7], "#     BEGINED     #");
        }

        for (i = 0; i < 10; i++)
            printf("%s\n", game_over[i]);

        key = getch();

    }while(key != 'f');
    main();

}

void Reward()
{
    int i;
    int cmpo;
    char key;
    char reward[13][36];
    char code_reward[9] = "";
    char code[9] = "BEGINEND";
    system("cls");
    printf( "INPUT CODE-REWARD: \n" );
    fgets(code_reward, sizeof(code_reward), stdin);
    cmpo = strcmp(code,code_reward);

    if (cmpo == 0)
    {
        do
        {
        sprintf(reward[0], "        ,     \\    /      ,        ");
        sprintf(reward[1], "       / \\    )\\__/(     / \\       ");
        sprintf(reward[2], "      /   \\  (_\\  /_)   /   \\      ");
        sprintf(reward[3], " ____/_____\\__\\@  @/___/_____\\____ ");
        sprintf(reward[4], "|             |\\../|              |");
        sprintf(reward[5], "|              \\VV/               |");
        sprintf(reward[6], "|           BEGIN END             |");
        sprintf(reward[7], "|_________________________________|");
        sprintf(reward[8], " |    /\\ /      \\\\       \\ /\\    | ");
        sprintf(reward[9], " |  /   V        ))       V   \\  | ");
        sprintf(reward[10]," |/     `       //        '     \\| ");
        sprintf(reward[11]," `              V                '");
        sprintf(reward[12],"            (f - exit)            ");


        system("cls");
        for (i = 0; i < 13; i++)
            printf("%s\n", reward[i]);

        key = getch();

    }while(key != 'f');
    } else
    {
        printf( "Invalid reward code! " );
        getch();
    }
}

int GameMain()
{
    srand(time(NULL));
    char locate[12][21];
    char key;
    int xp = 10, yp = 5; // Начальные координаты игрока
    int ax = 5, ay = 3; // Начальные координаты ОЧКА
    int axo = 5 , ayo = 3; // КООРДИНАТЫ ДЛЯ ЗАПОМИНАНИЯ ОЧКА
    int ex = 9, ey = 2; // Начальные координаты врага
    int dx = 17, dy = 8; // Начальные координаты собаки
    int i;
    int score = 0;
    int oxp, oyp; // Координаты для запоминания позиции игрока
    int oxe, oye; // Координаты для запоминания позиции врага
    int oxd, oyd; // Координаты для запоминания позиции собаки
    int Wall; // Чтобы ОЧКА не было вместо стены
    int enemy_choice = 20, enemy_rand;
    int dog_walk = 10, dog_rand, dog_log = 3;
    int lives = 10;


    do
    {
        sprintf(locate[0], "###################");
        sprintf(locate[1], "#         #       #");
        sprintf(locate[2], "#         #       #");
        sprintf(locate[3], "#         #       #");
        sprintf(locate[4], "########  #       #");
        sprintf(locate[5], "#                 #");
        sprintf(locate[6], "#                 #");
        sprintf(locate[7], "#     # ###########");
        sprintf(locate[8], "#     #           #");
        sprintf(locate[9], "###################");
        sprintf(locate[10],"#SC:%d     HP:%d/13#", score, lives);
        sprintf(locate[11],"###################");

        if (score >= 10) sprintf(locate[10], "#SC:%d    HP:%d/13#", score, lives);
        if (score >= 100) sprintf(locate[10], "#SC:%d   HP:%d/13#", score, lives);

        // Объекты на карте
        locate[yp][xp] = '@'; // Player
        locate[ay][ax] = '*'; // ОЧКО
        locate[ey][ex] = 'E'; // Сосед
        locate[dy][dx] = 'S'; // СОБАКА

        system("cls");

        for (i = 0; i < 12; i++)
            printf("%s\n", locate[i]);

        key = getch();

        oxp = xp;
        oyp = yp;
        oxe = ex;
        oye = ey;
        oxd = dx;
        oyd = dy;
        if (locate[yp][xp] == locate[dy][dx])
            lives -= 2;

        if (locate[yp][xp] == locate[ey][ex])
            lives -= 3;



        // Управление игроком
        if (key == 'w') yp--;
        if (key == 's') yp++;
        if (key == 'a') xp--;
        if (key == 'd') xp++;



        // Логика врага (З.Ы. ОН НЕ ЛОГИЧЕН =))
        enemy_rand = rand() * 1.0 / RAND_MAX * 20;
        if (locate[ey][ex+1] == '#')
          {
              ex--;

          }
         if (locate[ey+1][ex] == '#')
          {
              ey--;
              ex++;

          }
          if (locate[ey+1][ex] == '#')
          {

              ex++;

          }
          if (locate[ey][ex-1] == '#')
          {

              ex++;
          }
          if (locate[ey-1][ex+1] == '@') ex++;
          if (locate[ey][ex-1] == '@') ex--;
          if (locate[ey-1][ex-1] == '@') ex--;

          if ((locate[ey+1][ex] == ' ') && (locate[ey-1][ex] == ' ') && (locate[ey][ex+1] == ' ') && (locate[ey][ex-1] == ' '))
          {
            if (enemy_rand < enemy_choice)
            {
                ey++;

            } else {ey--;}
            if (enemy_rand == enemy_choice)
            {
                ex++;

            } else {ex--;}
          }

          if ((ey == 3) && (ex < 7))
            ex++;

        //Логика собаки
        dog_rand = rand() * 1.0 / RAND_MAX * 30;
        if (dog_walk < dog_rand)
        {


            //Проверка собаки на столкновение со стеной
            if (locate[dy][dx] == '#')
            {
                dx = oxd;
                dy = oyd;
            }
            if (dog_log == 3)
            {
                if ((dy == 8) && (dx > 7)) dx--;
                if ((dx == 7) && (dy > 6)) dy--;
                if ((dx == 7) && (dy == 7)) {dog_log = 2;}

            }
            if (dog_log == 2)
            {
                if ((dy == 7) && (dx == 7)) dy--;
                if ((dy == 6) && (dx != 1)) dx--;
                if ((dy != 8) && (dx == 1)) dy++;
                if ((dy == 8) && (dx != 5)) dx++;
                if ((dx == 5) && (dy == 8)) {dog_log = 1;}

            }
            if (dog_log == 1)
            {
                if ((dx == 5) && (dy > 5)) dy--;
                if ((dx < 11) && (dy == 5)) dx++;
                if ((dx == 11) && (dy != 1)) dy--;
                if ((dx < 17) && (dy == 1)) dx++;
                if ((dx == 17) && (dy < 6)) dy++;
                if ((dx > 7) && (dy == 6)) dx--;
                if ((dx == 11) && (dy == 6)) {dog_log = 0;}

            }
            if (dog_log == 0)
            {
                if ((dx > 7) && (dy == 6)) dx--;
                if ((dx == 7) && (dy < 8)) dy++;
                if ((dx < 17) && (dy == 8)) dx++;
                if ((dx == 17) && (dy == 8)) {dog_log = 3;}

            }



        }


        // Проверка персонажа на столкновение со стеной
        if (locate[yp][xp] == '#')
        {
            xp = oxp;
            yp = oyp;
        }


        // Проверка врага на столкновение со стеной
         if (locate[ey][ex] == '#')
        {
            ex = oxe;
            ey = oye;
        }




        // Генерация нового ОЧКА если игрок его подобрал
        if ((xp == ax) && (yp == ay))
        {
            axo = rand() * 1.0 / RAND_MAX * 18 + 1;
            ayo = rand() * 1.0 / RAND_MAX * 8 + 1;
            Wall = isWall(locate, axo, ayo);
            if (Wall == 1)
            {
               ax = 2;
               ay = 2;
            } else
            {
                ax = axo;
                ay = ayo;
            }
            score++;
            if (lives <= 11) lives += 2; //lives 13/13
        }

        if (lives < 1) {break;}
        if (key == 'e') {break;}

    } while(key != 'e');

    GameOver(score);
    return exit;
}


int main()
{
    char menu_choice[10][21];
    char info[19][67];
    char key;
    int i;
    int cx = 3, cy = 3, cxx = 16;
    int exit = 1;
    int Game;
    setlocale(LC_ALL, "Russian");
    do
    {
        sprintf(menu_choice[0], "###################");
        sprintf(menu_choice[1], "#   *THE LOOTER*  #");
        sprintf(menu_choice[2], "#                 #");
        sprintf(menu_choice[3], "#    |NEW GAME|   #");
        sprintf(menu_choice[4], "#      |INFO|     #");
        sprintf(menu_choice[5], "#   |GAME CODES|  #");
        sprintf(menu_choice[6], "#      |EXIT|     #");
        sprintf(menu_choice[7], "#                 #");
        sprintf(menu_choice[8], "#    (f - enter)  #");
        sprintf(menu_choice[9], "###################");

        menu_choice[cy][cx] = '>'; // Курсор
        menu_choice[cy][cxx] = '<';

        system("cls");

        for (i = 0; i < 10; i++)
            printf("%s\n", menu_choice[i]);

        key = getch();



        if (key == 's') cy++;
        if (key == 'w') cy--;

        if (cy > 6) cy = 3;
        if (cy <3) cy = 6;


            if ((cy == 3) && (key == 'f'))
            {
               GameMain();
               exit = 3;

            }

            if ((cy == 5) && (key == 'f'))
            {
                Reward();
            }
            if ((cy == 4) && (key == 'f'))
            {
                do
                {


                sprintf(info[0], "##################################################################");
                sprintf(info[1], "# _____  _   _  _____   _      _____  _____  _____  _____ ______ #");
                sprintf(info[2], "#|_   _|| | | ||  ___| | |    |  _  ||  _  ||_   _||  ___|| ___ \\#");
                sprintf(info[3], "#  | |  | |_| || |__   | |    | | | || | | |  | |  | |__  | |_/ /#");
                sprintf(info[4], "#  | |  |  _  ||  __|  | |    | | | || | | |  | |  |  __| |    / #");
                sprintf(info[5], "#  | |  | | | || |___  | |____\\ \\_/ /\\ \\_/ /  | |  | |___ | |\\ \\ #");
                sprintf(info[6], "#  \\_/  \\_| |_/\\____/  \\_____/ \\___/  \\___/   \\_/  \\____/ \\_| \\_|#");
                sprintf(info[7], "#                                                                #");
                sprintf(info[8], "#                                                                #");
                sprintf(info[9], "#                                                                #");
                sprintf(info[10],"# The Looter - эта игра про незадачливого грабителя, который     #");
                sprintf(info[11],"# собирает все яблоки (*) у своего соседа (E). Рядом с домом     #");
                sprintf(info[12],"# есть глупая собака (S), которая может укусить. Ваша задача     #");
                sprintf(info[13],"# насобирать нужное количество яблок и тогда откроется           #");
                sprintf(info[14],"# опеределенная код-награда.                                     #");
                sprintf(info[15],"#                                                                #");
                sprintf(info[16],"#                       *******************                      #");
                sprintf(info[17],"# v. 0.1.0           (для выхода нажмите - e)         by 4EPBEED #");
                sprintf(info[18],"##################################################################");

                system("cls");

                for (i = 0; i < 19; i++)
                    printf("%s\n", info[i]);

                key = getch();
                } while(key != 'e');

            }
            if ((cy == 6) && (key == 'f'))
            {
                system("cls");
                printf("GOOD BYE!");
                getch();
                exit = 3;
                return 3;
            }



    } while(exit != 3);

    return 0;
}
