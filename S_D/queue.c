void create(Queue *q){
    q->head = q->tail = NULL;
}

bool isEmpty(Queue q){
    return (q.tail == q.head && q.tail == NULL) ? true : false;
}

void enqueue(Queue *q, elemento e){
    Node *nuevo = (Node *)malloc(sizeof(Node));
    if (isEmpty(*q))
    {
        q->head = nuevo;
        nuevo->next = NULL;
        q->tail = nuevo;
        q->tail->e = e;
    }else{
        q->tail->next = nuevo;
        q->tail = nuevo;
        q->tail->e = e;
        nuevo->next = NULL;
    }
}

elemento dequeue(Queue *q){
    elemento e;
    if (isEmpty(*q))
    {
        printf("La cola esta vacia\n");
        return e;
    }else{
        if (q->head->next == NULL)
        {
            q->tail = NULL;
        }
        Node *aux = q->head;
        q->head = q->head->next;
        e = aux->e;
        free(aux);
        return e;
    }
}

void show(Queue q){
    if (isEmpty(q))
    {
        printf("La cola esta vacia\n");
    }else{
        Node *aux = q.head;
        while (aux != NULL)
        {
            printf("%c", aux->e);
            aux = aux->next;
        }
        printf("\n");
    }
}

void vaciar(Queue *q){
    if (isEmpty(*q))
    {
        printf("La cola esta vacia\n");
    }else{
        Node *aux = q->head;
        while (aux != NULL)
        {
            q->head = q->head->next;
            free(aux);
            aux = q->head;
        }
        q->head = q->tail = NULL;
    }
}