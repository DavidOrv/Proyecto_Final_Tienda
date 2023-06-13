//juego simon dice

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>

typedef struct ELEMENTO{
    int turno;
    int color;
}elemento;

#include "queue.h"

void color();

int main(){
    Queue q;
    create(&q);
    srand(time(NULL));
    elemento e;
    int i, c;

    system("cls");
    color();
    return 0;
}

void color(){
    int color;
    
    do{
        color = (rand()%7)+1;
    }while(color != 1 && color != 2 && color != 4 && color != 6);

    switch (color){
    case 1:
        system("color 10");
        break;
    case 2:
        system("color 20");
        break;
    case 4:
        system("color 40");
        break;
    case 6:
        system("color 60");
        break;
    
    default:
        break;
    }
}