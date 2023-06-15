void menu_inicio()
{
    list L;
    element new;
    createL(&L);
    llenarLista(&L);
    NodeL *eliminado, *modificado;
    int opcion, opc, opcID;
    system("cls");
    printf("|--------------------------------------|\n");
    printf("|                                      |\n");
    printf("| By: Gonzalez Luna Alexis             |\n");
    printf("| By: Liceaga Cardoso Angel David      |\n");
    printf("| By: Rodr%cguez Vidals David Osvaldo  |\n", 161);
    printf("|                                      |\n");
    printf("|--------------------------------------|\n");
    printf("Bienvenido, ya cuenta con una cuenta?\n");
    printf("1.- Si\n");
    printf("2.- No\n");
    printf("Escoge una opci%cn: ", 162);
    scanf("%d", &opcion);
    switch (opcion)
    {
    case 1:
        // menu del Administrador
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
                new.id = getLastId(&L) + 1;
                insertEnd(&L, new);
                break;
            case 2:
                // eliminar producto
                system("cls");
                printf("%cQue producto desea eliminar?\n",168);
                showList(&L);
                printf("Ingresa el ID del producto: ");
                scanf("%d", &opcID);
                eliminado = deleteProducto(&L, opcID);
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
                showList(&L);
                printf("Presione cualquier tecla para continuar\n");
                getch();
                break;
            case 3:
                // modificar producto
                system("cls");
                printf("%cQue producto desea modificar?\n",168);
                showList(&L);
                printf("Ingresa el ID del producto: ");
                scanf("%d", &opcID);
                modificado = shearchProducto(&L, opcID);
                if (modificado != NULL)
                {
                    printf("Ingresa el nuevo nombre del producto: ");
                    scanf("%s", modificado->e.nombre);
                    printf("Ingresa el nuevo precio del producto: ");
                    scanf("%f", &modificado->e.precio);
                    printf("Ingresa la nueva cantidad del producto: ");
                    scanf("%d", &modificado->e.cantidad);
                    updateProducto(&L, opcID, modificado->e);
                }
                else
                {
                    printf("El producto no existe\n");
                }
                printf("Presione cualquier tecla para continuar\n");
                getch();
                system("cls");
                showList(&L);
                printf("Presione cualquier tecla para continuar\n");
                getch();
                break;
            case 4:
                // ver productos
                break;
            case 5:
                // salir
                break;
            default:
                printf("Opci%cn no valida\n", 162);
                system("cls");
                menu_inicio();
                break;
            }
        } while (opc != 5);
        break;
    case 2:
        menu_registro();
        break;
    default:
        printf("Opci%cn no valida\n", 162);
        system("cls");
        menu_inicio();
        break;
    }
    freeList(&L);
}

void menu_login()
{
}

void menu_registro()
{
}