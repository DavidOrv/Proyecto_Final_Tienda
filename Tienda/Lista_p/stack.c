void createL(list *L)
{
    L->head = L->tail = NULL;
}

bool isEmptyL(list *L)
{
    return L->head == NULL && L->tail == NULL ? true : false;
}

void insertFirst(list *L, element e)
{
    NodeL *new = (NodeL *)malloc(sizeof(NodeL));
    if (isEmptyL(L))
    {
        L->tail = new;
    }
    new->e = e;
    new->next = L->head;
    L->head = new;
}

void insertEnd(list *L, element e)
{
    NodeL *new = (NodeL *)malloc(sizeof(NodeL));
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

void insertBeforeNode(list *L, element e, NodeL *act){
    if(act == L->head){
        insertFirst(L, e);
    }else{
        NodeL *aux, *new;
        aux = L->head;
        while(aux->next != act){
            aux = aux->next;
        }
        new = (NodeL *)malloc(sizeof(NodeL));
        aux->next = new;
        new->next = act;
        new->e = e;
    }
}

void insertAfterNode(list *L, element e, NodeL *act){
    if(act == L->tail){
        insertEnd(L, e);
    }else{
        NodeL *new;
        new = (NodeL *)malloc(sizeof(NodeL));
        new->next = act->next;
        act->next = new;
        new->e = e;
    }
}

void showList(list *L){
    NodeL *aux;
    aux = L->head;
    printf("Productos:\n");
    while(aux != NULL){
        printf("ID:%d\n", aux->e.id);
        printf("Nombre:%s", aux->e.nombre);
        printf("Cantidad:%d\n", aux->e.cantidad);
        printf("Precio:%.2f\n\n", aux->e.precio);
        aux = aux->next;
    }
}

void llenarLista(list *L){
    element e;
    FILE *f;
    f = fopen("Lista_P/productos.txt", "r");
    if(f == NULL){
        printf("Error al abrir el archivo\n");
    }else{
        while(!feof(f)){
            fscanf(f, "%d\n", &e.id);
            fgets(e.nombre, 150, f);
            fscanf(f, "%d\n", &e.cantidad);
            fscanf(f, "%f\n", &e.precio);
            insertEnd(L, e);
        }
    }
    fclose(f);
}