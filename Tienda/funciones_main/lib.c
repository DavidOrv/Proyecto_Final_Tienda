void menu_inicio()
{
    list L;
    listCarrito carrito;
    usuario user;
    createL(&L);
    createLC(&carrito);
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
            }
            break;
        case 2:
            // menu del Usuario
            system("cls");
            menu_usuario(&L, &carrito);
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

void menu_usuario(list *L, listCarrito *carrito)
{
    int opc, opcAgregar, opcCompra;
    int IDProducto;
    element PEncontrado;
    elementC new;
    do
    {
        printf("Bienvenido Usuario\n");
        printf("1.- Realizar compras \n");
        printf("2.- Salir\n");
        printf("Escoge una opci%cn: ", 162);
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            // realizar compras
            system("cls");
            do
            {
                printf("Aqui la lista de los productos en existencia...\n");
                showList(L);
                printf("|--------------------------------------------------------|\n");
                printf("|Desea agregar un producto al carrito? 1.- Si 2.- No|\n");
                scanf("%d", &opcAgregar);
                switch (opcAgregar)
                {
                case 1:
                    printf("Ingrese el ID del producto que desea comprar: ");
                    scanf("%d", &IDProducto);
                    PEncontrado = searchProduct(IDProducto, L);
                    if (PEncontrado.id != -1)
                    {
                        printf("Producto encontrado\n");
                        printf("Nombre: %s\n", PEncontrado.nombre);
                        printf("Precio: %.2f\n", PEncontrado.precio);
                        printf("Cantidad: %d\n", PEncontrado.cantidad);
                        printf("Ingrese la cantidad que desea comprar: ");
                        scanf("%d", &new.cantidad);
                        if (new.cantidad <= PEncontrado.cantidad)
                        {
                            new.id = PEncontrado.id;
                            strcpy(new.nombre, PEncontrado.nombre);
                            new.Precio_pieza = PEncontrado.precio;
                            new.total = new.cantidad *new.Precio_pieza;
                            insertEndC(carrito, new);
                            PEncontrado.cantidad -= new.cantidad;
                            updateProducto(L, PEncontrado.id, PEncontrado);
                            printf("Producto agregado al carrito\n");
                        }
                        else
                        {
                            printf("No hay suficientes productos\n");
                        }
                    }
                    else
                    {
                        printf("Producto no encontrado\n");
                    }
                }
            } while (opcAgregar != 2);
            break;
        case 2:
            if (isEmptyLC(carrito))
            {
                printf("No hay productos en el carrito\n");
                printf("Gracias por su visita\n");
            }
            else
            {
                printf("Gracias por su visita\n");
                printf("Su compra es la siguiente:\n");
                showListC(carrito);
                printf("|--------------------------------------------------------|\n");
                do
                {
                    printf("Desea pagar o cancelar la compra? 1.- Pagar 2.- Cancelar\n");
                    scanf("%d", &opcCompra);
                    if (opcCompra == 1)
                    {
                        printf("Gracias por su compra\n");
                        printf("Presione cualquier tecla para continuar\n");
                        getch();
                        freeListC(carrito);
                        break;
                    }
                    else if (opcCompra == 2)
                    {
                        printf("Compra cancelada\n");
                        printf("Presione cualquier tecla para continuar\n");
                        getch();
                        freeListC(carrito);
                    }
                    else
                    {
                        printf("Opci%cn no valida\n", 162);
                        printf("Presione cualquier tecla para continuar\n");
                        getch();
                    }
                } while (opcCompra != 1 || opcCompra != 2);
                break;
            }
            break;
        default:
            printf("Opci%cn no valida\n", 162);
            break;
        }
    } while (opc != 2);
}