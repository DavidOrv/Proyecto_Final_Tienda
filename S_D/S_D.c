//juego simon dice
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <windows.h>

#define PRINT 219 

typedef struct ELEMENTO{
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
int juego();
void screen_Color(elemento e, int turno);
void evaluacion(int color, elemento *e);
int eleccion_Jugador(Queue *simon, Queue *jugador, int turno);
int comparacion(Queue *simon, Queue *jugador, int turno);
void dequeue_Falso(Queue q, int turno);

int main(){
    int vida, centinela;
    srand(time(NULL));

    instrucciones();

    do{
        vida = juego();
        if(vida == 0){
            system("pause");
            system("cls");
            printf("Deseas volver a jugar? 1 Si\t2 No\n");
            scanf("%d", &centinela);
        }
    }while(centinela == 1);

    return 0;
}

void instrucciones(){
    system("cls");
    printf("\tBienvenido al juego de Simon Dice\n");
    printf("\nTu mision es recordar la secuencia de colores que te mostrare\n");
    printf("y repetirla en el mismo orden\n");
    printf("\nSi fallas, pierdes\n");
    printf("\nLos colores son:\n1 Rojo\n2 Azul\n3 Morado\n4 Amarillo\n\n");
    printf("Y solo tendras que ingresar el numero de los colores que se mostraron en cada turno\n\n");
    printf("\tComencemos\n\n");
    system("pause");
    system("cls");
}

int juego(){
    elemento e, aux;
    Queue simon, jugador;
    int color_Ran, turno=0, i, vida;

    create(&simon);
    create(&jugador);
    screen_Color(e, turno);
    
    do{
        color_Ran = (rand() % 4) + 1;
        printf("%d", color_Ran);
        evaluacion(color_Ran, &e);
        enqueue(&simon, e);
        turno++;
        
        dequeue_Falso(simon, turno);
        
        vida=eleccion_Jugador(&simon, &jugador, turno);
    }while (vida == 1);

    return vida;
}

void screen_Color(elemento e, int turno){ //Cambia el color de la consola conforme avanza el juego
    int i, k;
    tam_Cons tam;

    tam.colum = 63;
    tam.fil = 28;
    tam.c_Medio = tam.colum / 2;
    tam.f_Medio = tam.fil / 2;

    for(i=0; i<tam.fil; i++){ //Filas
        for(k=0; k<tam.colum; k++){ //Columnas
            if(i == 0 || i == tam.f_Medio || i == tam.fil-1) //Margen Horizontal
                printf("\033[0;37m%c\033[0m", PRINT); //Blanco
            
            else if(k == 0 || k == tam.c_Medio || k == tam.colum-1) //Margen Vertical
                printf("\033[0;37m%c\033[0m", PRINT); //Blanco

            else if(i > 0 && i < tam.f_Medio){
                if(k > 0 && k < tam.c_Medio){
                    if(e.color_Ro == 1)
                        printf("\033[0;31m%c\033[0m", PRINT); //Rojo
                    else
                        printf("\033[0;90m%c\033[0m", PRINT); //Gris                    
                }
                else{
                    if(e.color_Az == 1)
                        printf("\033[0;34m%c\033[0m", PRINT); //Azul
                    else
                        printf("\033[0;90m%c\033[0m", PRINT); //Gris
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
                        printf("\033[0;90m%c\033[0m", PRINT); //Gris
                }
            }
        }
        printf("\n");
    }
    printf("\n");
    if(turno == 0)
        system("pause");
    else if(turno > 0 && turno < 5)
        sleep(3);
    else if(turno >= 5 && turno < 10)
        sleep(2);
    else if(turno >= 10)
        sleep(1);
}

void evaluacion(int color, elemento *e){
    switch(color){
        case 1:
            e->color_Ro = 1;
            e->color_Az = 0;
            e->color_Mo = 0;
            e->color_Am = 0;
            break;
        case 2:
            e->color_Ro = 0;
            e->color_Az = 1;
            e->color_Mo = 0;
            e->color_Am = 0;
            break;
        case 3:
            e->color_Ro = 0;
            e->color_Az = 0;
            e->color_Mo = 1;
            e->color_Am = 0;
            break;
        case 4:
            e->color_Ro = 0;
            e->color_Az = 0;
            e->color_Mo = 0;
            e->color_Am = 1;
            break;
        case -5:
            e->color_Ro = 0;
            e->color_Az = 0;
            e->color_Mo = 0;
            e->color_Am = 0;
            break;
        
        default:
            printf("\nError\nNumero equivocado.\nPerdiste.\n");
            break;
    }
}

int eleccion_Jugador(Queue *simon, Queue *jugador, int turno){
    int eleccion, i, vida;
    elemento e;

    for(i=0; i<turno; i++){
        printf("\nEl color %i fue el: ", i+1);
        scanf("%d", &eleccion);

        evaluacion(eleccion, &e);        
        enqueue(jugador, e);
        
        vida = comparacion(simon, jugador, turno);

        if(vida == 0){
            return 0;
        }
    }

    vaciar(jugador);
    return 1;
}

int comparacion(Queue *simon, Queue *jugador, int turno){
    int i;
    elemento aux1, aux2;
    Queue qaux1, qaux2;
    create(&qaux1);
    create(&qaux2);

    for(i=0; i<turno; i++){
        aux1 = dequeue(simon);
        aux2 = dequeue(jugador);

        if(aux1.color_Ro != aux2.color_Ro || aux1.color_Az != aux2.color_Az || aux1.color_Mo != aux2.color_Mo || aux1.color_Am != aux2.color_Am){
            printf("\nError\nPerdiste.\n");
            return 0;
        }
        enqueue(&qaux1, aux1);
        enqueue(&qaux2, aux2);
    }

    vaciar(simon);
    vaciar(jugador);
    
    for(i=0; i<turno; i++){
        aux1 = dequeue(&qaux1);
        enqueue(simon, aux1);
        aux2 = dequeue(&qaux2);
        enqueue(jugador, aux2);
    }

    vaciar(&qaux1);
    vaciar(&qaux2);
    return 1;
}

void dequeue_Falso(Queue q, int turno){
    elemento e;
    Node *aux;

    for(int i=0; i<turno; i++){
        if(!isEmpty(q)){
            if (q.head->next == NULL)
                q.tail = NULL;
            
            aux = q.head;
            q.head = q.head->next;
            e = aux->e;
            screen_Color(e, turno);
            free(aux);
        }
    }
}