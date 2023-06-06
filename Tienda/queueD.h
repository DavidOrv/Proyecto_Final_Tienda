typedef struct NODE{
    elemento e;
    struct NODE *next;
}Node;

typedef struct QUEUE{
    Node *head;
    Node *tail;
}Queue;

void create(Queue *q);
void enqueue(Queue *q, elemento e);
bool isEmpty(Queue q);
elemento dequeue(Queue *q);
void show(Queue q);
void vaciar(Queue *q);

#include "queueD.c"