typedef int element;
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

#include "stack.c"