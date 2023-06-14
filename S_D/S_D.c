//juego simon dice
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

#define PRINT 219 

typedef struct ELEMENTO{
    int turno;

    int color_Az;
    int color_Ro;
    int color_Ve;
    int color_Am;

    int color_AzC;
    int color_RoC;
    int color_VeC;
    int color_AmC;
}elemento;

typedef struct TAM{
    int colum;
    int fil;
    int c_Medio;
    int f_Medio;
}tam_Cons;

#include "queue.h"

void screen_Color(tam_Cons tam, elemento e);
void tam_Screen(tam_Cons *tam);

int main(){
    //Queue q;
    elemento e;
    tam_Cons tam;
    int i;


    //create(&q);
    srand(time(NULL));

    system("cls");

    tam_Screen(&tam);
    screen_Color(tam, e);

    return 0;
}

void screen_Color(tam_Cons tam, elemento e){ //Cambia el color de la consola conforme avanza el juego
    int i, k;

    for(i=0; i<tam.fil; i++){ //Filas
        for(k=0; k<tam.colum; k++){ //Columnas
            if(i == 0)
                printf("\033[0;37m%c\033[0m", PRINT); //Blanco
            
            else if(k == 0 || k == tam.c_Medio || k == tam.colum)
                printf("\033[0;37m%c\033[0m", PRINT); //Blanco

            else if(i > 0 && i < tam.f_Medio){
                if(k > 0 && k < tam.c_Medio){
                    if(e.color_Ro == 1)
                        printf("\033[0;31m%c\033[0m", PRINT); //Rojo
                    else
                        printf("\033[0;91m%c\033[0m", PRINT); //Rojo claro                    
                }
                /*else{
                    if(e.color_Az == 1)
                        printf("\033[0;34m%c\033[0m", PRINT); //Azul
                    else
                        printf("\033[0;36m%c\033[0m", PRINT); //Azul claro
                }*/
            }
        }
    }
}

void tam_Screen(tam_Cons *tam){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        tam->fil = csbi.srWindow.Bottom - csbi.srWindow.Top;
        tam->colum = csbi.srWindow.Right - csbi.srWindow.Left;

        tam->f_Medio = tam->fil / 2;
        tam->c_Medio = tam->colum / 2;
        
        /*printf("Numero de filas: %d\n", tam->fil);
        printf("Numero de columnas: %d\n", tam->colum);
        printf("Numero medio de filas: %d\n", tam->f_Medio);
        printf("Numero medio de columnas: %d\n", tam->c_Medio);*/
    }
}