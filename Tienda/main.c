//Alexis no muevas nada pls
//LunaOn
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

typedef struct Elemento{
    int id;
    char nombre[20];
    char descripcion[100];
    float precio;
    int cantidad;
}elemento;

#include "queueD.h"
#include "Lista_p/stack.h"
#include "funciones_main/lib.h"

int main(){
    printf("Hello World!\n");
    menu_inicio();
    return 0;
}