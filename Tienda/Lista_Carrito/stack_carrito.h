typedef struct ELEMENTOCARRITO
{
    int id;
    char nombre[150];
    int cantidad;
    float Precio_pieza;
    float total;
}elementC;
typedef struct NODOLISTC
{
    elementC e;
    struct NODOLISTC *next;
} NodeLC;

typedef struct LISTC
{
    NodeLC *head;
    NodeLC *tail;
} listCarrito;

void createLC(listCarrito *L);
void insertFirstC(listCarrito *L, elementC e);
bool isEmptyLC(listCarrito *L);
void insertEndC(listCarrito *L, elementC e);
void showListC(listCarrito *L);
void freeListC(listCarrito *L);
element searchProduct(int id, list *L);
float totalCompra(listCarrito *L);


#include "stack_carrito.c"
