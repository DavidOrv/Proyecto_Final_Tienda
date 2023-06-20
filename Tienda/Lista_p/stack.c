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

void insertBeforeNode(list *L, element e, NodeL *act)
{
    if (act == L->head)
    {
        insertFirst(L, e);
    }
    else
    {
        NodeL *aux, *new;
        aux = L->head;
        while (aux->next != act)
        {
            aux = aux->next;
        }
        new = (NodeL *)malloc(sizeof(NodeL));
        aux->next = new;
        new->next = act;
        new->e = e;
    }
}

void insertAfterNode(list *L, element e, NodeL *act)
{
    if (act == L->tail)
    {
        insertEnd(L, e);
    }
    else
    {
        NodeL *new;
        new = (NodeL *)malloc(sizeof(NodeL));
        new->next = act->next;
        act->next = new;
        new->e = e;
    }
}

void showList(list *L)
{
    NodeL *aux;
    aux = L->head;
    printf("Productos:\n");
    while (aux != NULL)
    {
        printf("-------------------------------\n");
        printf("ID:%d\n", aux->e.id);
        printf("Nombre:%s\n", aux->e.nombre);
        printf("Cantidad:%d\n", aux->e.cantidad);
        printf("Precio:%.2f\n\n", aux->e.precio);
        printf("-------------------------------\n");
        aux = aux->next;
    }
}

void llenarLista(list *L)
{
    element e;
    FILE *f;
    f = fopen("Lista_P/productos.txt", "r");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\n");
    }
    else
    {
        while (!feof(f))
        {
            fscanf(f, "%d\n", &e.id);
            fgets(e.nombre, 150, f);
            fscanf(f, "%d\n", &e.cantidad);
            fscanf(f, "%f\n", &e.precio);
            insertEnd(L, e);
        }
    }
    fclose(f);
}

int getLastId(list *L)
{
    return L->tail->e.id;
}

void freeList(list *L)
{
    NodeL *aux;
    while (L->head != NULL)
    {
        aux = L->head;
        L->head = L->head->next;
        free(aux);
    }
    L->tail = NULL;
}

NodeL *deleteProducto(list *L, int id)
{
    NodeL *nodo_actual = L->head;
    // Busca el producto a eliminar
    while (nodo_actual != NULL && nodo_actual->e.id != id)
    {
        nodo_actual = nodo_actual->next;
    }

    if (nodo_actual == NULL)
    {
        return NULL;
    }
    else
    {
        // caso de que sea el primero
        if (nodo_actual == L->head)
        {
            L->head = nodo_actual->next;
            if (L->head == NULL)
            {
                L->tail = NULL;
            }
        }
        else
        {
            NodeL *aux = L->head;
            while (aux->next != nodo_actual)
            {
                aux = aux->next;
            }
            aux->next = nodo_actual->next;
            if (nodo_actual == L->tail)
            {
                L->tail = aux;
            }
        }
        return nodo_actual;
    }
}

NodeL *shearchProducto(list *L, int id)
{
    NodeL *aux;
    aux = L->head;
    while (aux != NULL)
    {
        if (aux->e.id == id)
        {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

void updateProducto(list *L, int id, element e)
{
    NodeL *aux;
    aux = L->head;
    while (aux != NULL)
    {
        if (aux->e.id == id)
        {
            aux->e = e;
            break;
        }
        aux = aux->next;
    }
}

void limpiar_Producto(list *L)
{
    NodeL *aux;
    aux = L->head;
    while (aux != NULL)
    {
        int longitud = strlen(aux->e.nombre);
        if (aux->e.nombre[longitud - 1] == '\n')
        {
            aux->e.nombre[longitud - 1] = '\0';
        }
        aux = aux->next;
    }
}