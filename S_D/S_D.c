//juego simon dice
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <conio.h>

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
int eleccion_Jugador(Queue *simon, int turno);

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
    int color_Ran, turno=0, i, vida, nivel;

    create(&simon);
    create(&jugador);
    screen_Color(e, turno);
    
    do{
        system("cls");
        color_Ran = (rand() % 4) + 1;
        evaluacion(color_Ran, &e);
        enqueue(&simon, e);
        turno++;
        dequeue_Falso(simon, turno);
        vida=eleccion_Jugador(&simon, turno);

        if(vida == 1){
            printf("\nExcelente, acertaste a todos los colores.\nProximo nivel en ");
            for(i=3; i>0; i--){
                printf("%d ", i);
                sleep(1);
            }
        }
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

    for(i=0; i<tam.c_Medio-5; i++)
        printf(" ");

    printf("\033[0;37mSIMON DICE\033[0m\n\n");

    for(i=0; i<tam.fil; i++){ //Filas
        for(k=0; k<tam.colum; k++){ //Columnas
            if(i == 0 || i == tam.f_Medio || i == tam.fil-1) //Margen Horizontal
                printf("\033[0;37m%c\033[0m", PRINT); //Blanco
            
            else if(k == 0 || k == tam.c_Medio || k == tam.colum-1){ //Margen Vertical 
                printf("\033[0;37m%c\033[0m", PRINT); //Blanco
                
                if(k == tam.colum-1 && i == 11)
                    printf("\t 1 Color Rojo");
                else if(k == tam.colum-1 && i == 13)
                    printf("\t 2 Color Azul");
                else if(k == tam.colum-1 && i == 15)
                    printf("\t 3 Color Morado");
                else if(k == tam.colum-1 && i == 17)
                    printf("\t 4 Color Amarillo");
            } 
                

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
    if(turno == 0){
        system("pause");
        system("cls");
    }
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

int eleccion_Jugador(Queue *simon, int turno){
    int num_Jug, i=0;
    char num;
    elemento jugador, auxE;
    Queue aux;

    create(&aux);
    

    printf("\nIngresa la secuencia de colores que se mostraron en pantalla: ");

    while(i < turno){
        num = getch();

        if(num >= '1' && num <= '4'){
            num_Jug = num - '0';
            printf("%d ", num_Jug);

            evaluacion(num_Jug, &jugador);
            auxE = dequeue(simon);

            if(jugador.color_Ro == auxE.color_Ro && jugador.color_Az == auxE.color_Az && jugador.color_Mo == auxE.color_Mo && jugador.color_Am == auxE.color_Am){
                enqueue(&aux, jugador);
            }
            else{
                printf("\nNumero equivocado.\nPerdiste.\n");
                vaciar(&aux);
                vaciar(simon);
                return 0;
            }

            i++;
        }
        else{
            printf("\nNumero equivocado.\nPerdiste.\n");
            vaciar(&aux);
            vaciar(simon);
            return 0;
        }
    }
    for (i = 0; i < turno; i++){
        auxE = dequeue(&aux);
        enqueue(simon, auxE);
    }
    
    vaciar(&aux);
    return 1;
}

void dequeue_Falso(Queue q, int turno){
    elemento e;
    Node *aux;
    int auxT = turno;

    for(int i=0; i<turno; i++){
        if(!isEmpty(q)){
            if (q.head->next == NULL)
                q.tail = NULL;
            
            aux = q.head;
            q.head = q.head->next;
            e = aux->e;
            screen_Color(e, auxT);
            system("cls");
            //free(aux);
        }
    }
    evaluacion(-5, &e);
    screen_Color(e, 10);
}

