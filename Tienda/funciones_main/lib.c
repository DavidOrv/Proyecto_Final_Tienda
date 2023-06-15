void menu_inicio()
{
    list L;
    usuario user;
    createL(&L);
    llenarLista(&L);
    int opcion;
    do
    {
    system("cls");
    printf("|--------------------------------------|\n");
    printf("|                                      |\n");
    printf("| By: Gonzalez Luna Alexis             |\n");
    printf("| By: Liceaga Cardoso Angel David      |\n");
    printf("| By: Rodr%cguez Vidals David Osvaldo  |\n", 161);
    printf("|                                      |\n");
    printf("|--------------------------------------|\n");
    printf("Bienvenido\n");
    printf("1.- Administrador\n");
    printf("2.- Usuario\n");
    printf("3.- Salir\n");
    printf("Escoge una opci%cn: ", 162);
    scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            // menu del Administrador
            system("cls");
            printf("Ingresa tu nombre de usuario: ");
            scanf("%s", &user.nombre);
            printf("Ingresa tu contrase%ca: ", 164);
            scanf("%s", &user.password);
            if (!menu_login(&user))
            {
                printf("Usuario o contrase%ca incorrectos\n", 164);
                printf("Presione cualquier tecla para continuar\n");
                getch();
                system("cls");
            }
            else
            {
                menu_admin(&L);
                break;
            }
        case 2:
            break;
        default:
            printf("Opci%cn no valida\n", 162);
            system("cls");
            menu_inicio();
            break;
        }
    } while (opcion != 2);
    freeList(&L);
}

bool menu_login(usuario *user)
{
    return (strcmp(user->nombre, "admin") == 0) && (strcmp(user->password, "admin") == 0) ? true : false;
}

void menu_admin(list *L)
{
    int opc, opcID;
    NodeL *eliminado, *modificado;
    element new;
    do
    {
        system("cls");
        printf("Bienvenido Administrador\n");
        printf("1.- Agregar producto\n");
        printf("2.- Eliminar producto\n");
        printf("3.- Modificar producto\n");
        printf("4.- Ver productos\n");
        printf("5.- Salir\n");
        printf("Escoge una opci%cn: ", 162);
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            // agregar producto
            system("cls");
            printf("Ingresa el nombre del producto: ");
            scanf("%s", new.nombre);
            printf("Ingresa el precio del producto: ");
            scanf("%f", &new.precio);
            printf("Ingresa la cantidad del producto: ");
            scanf("%d", &new.cantidad);
            new.id = getLastId(L) + 1;
            insertEnd(L, new);
            break;
        case 2:
            // eliminar producto
            system("cls");
            printf("%cQue producto desea eliminar?\n", 168);
            showList(L);
            printf("Ingresa el ID del producto: ");
            scanf("%d", &opcID);
            eliminado = deleteProducto(L, opcID);
            if (eliminado != NULL)
            {
                printf("El producto %s ha sido eliminado\n", eliminado->e.nombre);
            }
            else
            {
                printf("El producto no existe\n");
            }
            printf("Presione cualquier tecla para continuar\n");
            getch();
            system("cls");
            showList(L);
            printf("Presione cualquier tecla para continuar\n");
            getch();
            break;
        case 3:
            // modificar producto
            system("cls");
            printf("%cQue producto desea modificar?\n", 168);
            showList(L);
            printf("Ingresa el ID del producto: ");
            scanf("%d", &opcID);
            modificado = shearchProducto(L, opcID);
            if (modificado != NULL)
            {
                printf("Ingresa el nuevo nombre del producto: ");
                scanf("%s", modificado->e.nombre);
                printf("Ingresa el nuevo precio del producto: ");
                scanf("%f", &modificado->e.precio);
                printf("Ingresa la nueva cantidad del producto: ");
                scanf("%d", &modificado->e.cantidad);
                updateProducto(L, opcID, modificado->e);
            }
            else
            {
                printf("El producto no existe\n");
            }
            printf("Presione cualquier tecla para continuar\n");
            getch();
            system("cls");
            showList(L);
            printf("Presione cualquier tecla para continuar\n");
            getch();
            break;
        case 4:
            // ver productos
            system("cls");
            showList(L);
            printf("Presione cualquier tecla para continuar\n");
            getch();
            break;
        case 5:
            // salir
            printf("Adios\n");
            break;
        default:
            printf("Opci%cn no valida\n", 162);
            system("cls");
            menu_inicio();
            break;
        }
        // Menu Usuario

    } while (opc != 5);
}