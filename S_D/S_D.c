//juego simon dice

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct ELEMENTO{
    int turno;
    int color;
}elemento;

#include "queueD.h"

int main(){
    Queue q;
    create(&q);
    srand(time(NULL));
    elemento e;
    int i;

    system("cls");
    return 0;
}