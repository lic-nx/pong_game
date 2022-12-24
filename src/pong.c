#include <stdio.h>
/*объявление глобальных переменных*/
int width = 81;/*размер поля по ширине*/
int height = 21;/*размер поля по высоте*/
int flagX = 0;/*в какую сторону двигаться по х если флаг =0 двигаемся влево иначе в право*/
int flagY = 0;/*двигаемся вверх если =0 иначе вниз*/
int chetOne = 0;/*счет первого игрока*/
int chetTwo = 0;/*счет второго игрока*/
int moveX = 40;/*местоположение по х*/
int moveY = 10;/*местоположение по у*/
int raketkaL = 10;
int raketkaR = 10;

/*объявление методов*/
void ballOnX();
void ballOnY();
void racketLeft();
void racketsRight();
void printFase() /*отрисовка поля*/  { printf("Привет ребята, меня зовут PONGbot!)\n");
    printf("Я ваш помощник к игре PONG\n");
    printf("P.s. снизу я написал правила игры(НЕ ЧИТАЙ ИХ)\n");
    printf("\n ");
    for (int i = 0; i < width; i++) {
            printf("-");
        }
        printf("\n|%39d : %-39d|\n", chetOne, chetTwo);
        printf(" ");
        for (int i = 0; i < 81; i++) {
            printf("-");
        }
        printf("\n");
        int flag = 0;
        int flagRocket = 0;
    for (int y = 0; y <= height; y++) {
        for (int x = 0; x <= width; x++) {
            if (x-1 == 2 && (y == raketkaL || y == raketkaL+1 || y == raketkaL+2))
            { printf("|");
                flagRocket = 1; }
            else if (x+1 == 79 && (y == raketkaR || y == raketkaR+1 || y == raketkaR+2))
            { printf("|");
            flagRocket = 1;
            } else {
            flagRocket = 0; }
            // if (y == 0) printf("-");
            if ( flag == 0 && x == moveX && y == moveY )
            { printf(".");
                ballOnX();
                ballOnY();
                flag = 1; }
                else  if (y == height) { printf("-"); }
            else if (x == 0 || x == width/2) printf("|");
            else if (x == width) printf("|\n");
            else if (flagRocket == 0) printf(" ");
        }
    }
    printf("\n             PONG\n\n");
    printf("          Как играть?\n\n");
    printf("1 игрок:      ||       2 игрок:\n");
    printf("A - вверх     ||       K - вверх\n");
    printf("Z - вниз      ||       М - вниз\n");
    printf("    Пробел - пропуск хода\n\n");
    printf("Правила:\n");
    printf("Нужно отбить мяч ракеткой и забить его противнику\n");
    printf("Когда один из игроков набирает 21 очко игра заканчивается\n");
}
void ballOnX()/*перемещение по х*/
{ if ((moveX == 4 || moveX == 3) && (moveY == raketkaL || moveY == raketkaL+1 ||moveY == raketkaL+2 )) {
        flagX = 1;
    }
    if ((moveX == 77 || moveX == 78) && (moveY == raketkaR || moveY == raketkaR+1 || moveY == raketkaR+2 )) {
        flagX = 0;
    }

     if (flagX == 0 )
     { moveX--;
     }
     if (moveX < 1)
         { flagX = 1;
             chetTwo = chetTwo + 1;
             moveX = width/2;
         }
     if (flagX == 1 )
     { moveX++;
        }
     if (moveX >= width-1)
         { flagX = 0;
             chetOne = chetOne+1;
             moveX = width /2;
         }
}
void ballOnY()/*перемещение по у*/
{ if (flagY == 0 )
     { moveY = moveY-1;
     }
     if (moveY < 1)
         { flagY = 1;
         }
     if (flagY == 1)
     { moveY = moveY+1; }
     if (moveY >= height-1)
         { flagY = 0; }
}
void Raketka(char upOrDown)
{ if (upOrDown == 'a')
    { if (raketkaL-1 !=0)
        raketkaL -= 1;
    }
    if (upOrDown == 'z')
    { if (raketkaL+1 !=19)
        raketkaL += 1;
    }
}
void RaketkaRight(char upOrDown)
{ if (upOrDown == 'k')
    { if (raketkaR-1 != 0)
        raketkaR -= 1;
}
     if (upOrDown == 'm')
{ if (raketkaR+1 != 19)
        raketkaR += 1;
}
}
int main()
{ while (1) {
    char upOrDown = '1';
    printFase();
    while (upOrDown != 'z' && upOrDown != 'a' &&     upOrDown != 'm' &&  upOrDown != 'k' && upOrDown != ' ') {
    scanf("%c", &upOrDown); }
        if (chetOne == 21 || chetTwo == 21) {break; }

            printf("\e[1;1H\e[2J");
            printFase();
            Raketka(upOrDown);
            RaketkaRight(upOrDown);
        }
    printf("\e[1;1H\e[2J");
    printf("ИГРА ЗАКОНЧЕНА!");
    return 0;
}


