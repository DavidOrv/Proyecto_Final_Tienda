void createLC(listCarrito *L){
    L->head = NULL;
    L->tail = NULL;
}

void insertFirstC(listCarrito *L, elementC e){
    NodeLC *new = (NodeLC *)malloc(sizeof(NodeLC));
    if (isEmptyLC(L))
    {
        L->tail = new;
    }
    new->e = e;
    new->next = L->head;
    L->head = new;
}

bool isEmptyLC(listCarrito *L){
    return L->head == NULL && L->tail == NULL ? true : false;
}

void insertEndC(listCarrito *L, elementC e){
    NodeLC *new = (NodeLC *)malloc(sizeof(NodeLC));
    if (L->head == NULL)
    {
        L->head = new;
    }
    else
    {
        L->tail->next = new;
    }
    new->next = NULL;
    L->tail = new;
    new->e = e;
}

void showListC(listCarrito *L){
    NodeLC *aux;
    aux = L->head;
    printf("Productos:\n");
    while (aux != NULL)
    {
        printf("-------------------------------\n");
        printf("ID:%d\n", aux->e.id);
        printf("Nombre:%s\n", aux->e.nombre);
        printf("Cantidad:%d\n", aux->e.cantidad);
        printf("Precio por pieza:%.2f\n", aux->e.Precio_pieza);
        printf("Precio:%.2f\n\n", aux->e.total);
        printf("-------------------------------\n");
        aux = aux->next;
    }
}

void freeListC(listCarrito *L){
    NodeLC *aux;
    while (L->head != NULL)
    {
        aux = L->head;
        L->head = L->head->next;
        free(aux);
    }
    L->tail = NULL;
}

element searchProduct(int id, list *L){
    NodeL *aux;
    aux = L->head;
    while (aux != NULL)
    {
        if (aux->e.id == id)
        {
            return aux->e;
        }
        aux = aux->next;
    }
    element e;
    e.id = -1;
    return e;
}

int totalCompra(listCarrito *L){
    NodeLC *aux;
    aux = L->head;
    int total = 0;
    while (aux != NULL)
    {
        total += aux->e.total;
        aux = aux->next;
    }
    return total;
}