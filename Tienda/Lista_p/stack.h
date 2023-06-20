typedef struct ELEMENTO
{
    int id;
    char nombre[150];
    int cantidad;
    float precio;
}element;
typedef struct NODOLIST
{
    element e;
    struct NODOLIST *next;
} NodeL;

typedef struct LIST
{
    NodeL *head;
    NodeL *tail;
} list;

void createL(list *L);
void insertFirst(list *L, element e);
bool isEmptyL(list *L);
void insertEnd(list *L, element e);
void insertBeforeNode(list *L, element e, NodeL *act);
void insertAfterNode(list *L, element e, NodeL *act);
void showList(list *L);
void llenarLista(list *L);
int getLastId(list *L);
void freeList(list *L);
NodeL *deleteProducto(list *L, int id);
void updateProducto(list *L, int id, element e);
NodeL* shearchProducto(list *L, int id);
element searchProduct(int id, list *L);
void limpiar_Producto(list *L);


#include "stack.c"