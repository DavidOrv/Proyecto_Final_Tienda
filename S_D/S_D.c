//juego simon dice
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <windows.h>

#define PRINT 219 

typedef struct ELEMENTO{
    int puntuacion;

    int color_Az;
    int color_Ro;
    int color_Mo;
    int color_Am;
}elemento;

typedef struct TAM{
    int colum;
    int fil;
    int c_Medio;
    int f_Medio;
}tam_Cons;

#include "queue.h"

void instrucciones();
void screen_Color(tam_Cons tam, elemento e);
void tam_Screen(tam_Cons *tam);
void evaluacion(int color, elemento *e);
void elecion_Jugador(elemento *e, Queue *jugador);
int comparacion(Queue *simon, Queue *jugador, int turno);
elemento dequeue_Falso(Queue q);

int main(){
    Queue simon, jugador;
    elemento e;
    tam_Cons tam;
    int color, turno = 0, vida;

    create(&simon);
    create(&jugador);
    srand(time(NULL));

    instrucciones();

    tam_Screen(&tam);

    evaluacion(-5, &e);
    screen_Color(tam, e);

    color = (rand() % 4) + 1;

    evaluacion(color, &e);
    enqueue(&simon, e);
    screen_Color(tam, e);

    evaluacion(-5, &e);
    screen_Color(tam, e);

    elecion_Jugador(&e, &jugador);
    turno++;

    vida = comparacion(&simon, &jugador, turno);

    if(vida == 1){
        printf("Correcto\n");
    }
    else{
        printf("Incorrecto\n");
    }

    vaciar(&simon);
    vaciar(&jugador);
    return 0;
}

void instrucciones(){
    system("cls");
    printf("\tBienvenido al juego de Simon Dice\n");
    printf("\nTu mision es recordar la secuencia de colores que te mostrare\n");
    printf("y repetirla en el mismo orden\n");
    printf("\nSi fallas, pierdes\n");
    printf("\nLos colores son:\n1 Rojo\n2 Azul\n3 Morado\n4 Amarillo\n\n");
    printf("Y solo tendras que ingresar el numero del color en cada turno\n\n");
    printf("\tComencemos\n\n");
    system("pause");
    system("cls");
}

void screen_Color(tam_Cons tam, elemento e){ //Cambia el color de la consola conforme avanza el juego
    int i, k;

    for(i=0; i<tam.fil; i++){ //Filas
        for(k=0; k<tam.colum; k++){ //Columnas
            if(i == 0 || i == tam.f_Medio || i == tam.fil-1)
                printf("\033[0;37m%c\033[0m", PRINT); //Blanco
            
            else if(k == 0 || k == tam.c_Medio || k == tam.colum-1)
                printf("\033[0;37m%c\033[0m", PRINT); //Blanco

            else if(i > 0 && i < tam.f_Medio){
                if(k > 0 && k < tam.c_Medio){
                    if(e.color_Ro == 1)
                        printf("\033[0;31m%c\033[0m", PRINT); //Rojo
                    else
                        printf("\033[0;91m%c\033[0m", PRINT); //Rojo claro                    
                }
                else{
                    if(e.color_Az == 1)
                        printf("\033[0;34m%c\033[0m", PRINT); //Azul
                    else
                        printf("\033[0;36m%c\033[0m", PRINT); //Azul claro
                }
            }
            else if(i > tam.f_Medio && i < tam.fil){
                if(k > 0 && k < tam.c_Medio){
                    if(e.color_Mo == 1)
                        printf("\033[0;35m%c\033[0m", PRINT); //Morado
                    else
                        printf("\033[0;90m%c\033[0m", PRINT); //Gris
                }
                else{
                    if(e.color_Am == 1)
                        printf("\033[0;33m%c\033[0m", PRINT); //Amarillo
                    else
                        printf("\033[1;33m%c\033[0m", PRINT); //Amarillo claro
                }
            }
        }
        printf("\n");
    }
    printf("\n");
    if(e.puntuacion == 0)
        sleep(1);
    else if(e.puntuacion > 0 && e.puntuacion < 5)
        sleep(3);
    else if(e.puntuacion >= 5 && e.puntuacion < 10)
        sleep(2);
    else if(e.puntuacion > 10)
        sleep(1);
}

void tam_Screen(tam_Cons *tam){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        tam->fil = (csbi.srWindow.Bottom - csbi.srWindow.Top)-5;
        tam->colum = (csbi.srWindow.Right - csbi.srWindow.Left)-3;

        tam->f_Medio = tam->fil / 2;
        tam->c_Medio = tam->colum / 2;

        if(tam->f_Medio % 2 != 0)
            tam->f_Medio -= 1;
        if(tam->c_Medio % 2 != 0)
            tam->c_Medio -= 1;
        
        printf("Numero de filas: %d\n", tam->fil);
        printf("Numero de columnas: %d\n", tam->colum);
        printf("Numero medio de filas: %d\n", tam->f_Medio);
        printf("Numero medio de columnas: %d\n", tam->c_Medio);
    }
}

void evaluacion(int color, elemento *e){
    switch(color){
        case 1:
            e->color_Ro = 1;
            e->color_Az = 0;
            e->color_Mo = 0;
            e->color_Am = 0;
            e->puntuacion += 1;
            break;
        case 2:
            e->color_Ro = 0;
            e->color_Az = 1;
            e->color_Mo = 0;
            e->color_Am = 0;
            e->puntuacion += 1;
            break;
        case 3:
            e->color_Ro = 0;
            e->color_Az = 0;
            e->color_Mo = 1;
            e->color_Am = 0;
            e->puntuacion += 1;
            break;
        case 4:
            e->color_Ro = 0;
            e->color_Az = 0;
            e->color_Mo = 0;
            e->color_Am = 1;
            e->puntuacion += 1;
            break;
        case -5:
            e->color_Ro = 0;
            e->color_Az = 0;
            e->color_Mo = 0;
            e->color_Am = 0;
            e->puntuacion = 0;
            break;
        
        default:
            printf("\nError\nNumero equivocado.\nPerdiste.\n");
            e->puntuacion = -1;
            break;
    }
}

void elecion_Jugador(elemento *e, Queue *jugador){
    int eleccion;

    printf("Elije un color: ");
    scanf("%d", &eleccion);

    evaluacion(eleccion, e);
    enqueue(jugador, *e);
}

int comparacion(Queue *simon, Queue *jugador, int turno){
    int i;
    Node *aux1 = simon->head;
    Node *aux2 = jugador->head;

    for(i=0; i<turno; i++){
        if(aux1->e.color_Ro != aux2->e.color_Ro)
            return 0;
        if(aux1->e.color_Az != aux2->e.color_Az)
            return 0;
        if(aux1->e.color_Mo != aux2->e.color_Mo)
            return 0;
        if(aux1->e.color_Am != aux2->e.color_Am)
            return 0;
        
        aux1 = aux1->next;
        aux2 = aux2->next;
    }
    return 1;
}

elemento dequeue_Falso(Queue q){
    elemento e;

    if(!isEmpty(q)){
        if (q.head->next == NULL)
            q.tail = NULL;
        
        Node *aux = q.head;
        q.head = q.head->next;
        e = aux->e;
        free(aux);
        return e;
    }
}