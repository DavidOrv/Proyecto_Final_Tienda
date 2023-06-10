void menu_inicio(){
    int opcion;
    printf("|--------------------------------------|\n");
    printf("|                                      |\n");
    printf("| By: Gonzales Luna Alexis             |\n");
    printf("| By: Liceaga Cardoso Angel David      |\n");
    printf("| By: Rodr%cguez Vidals David Osvaldo   |\n",161);
    printf("|                                      |\n");
    printf("|--------------------------------------|\n");

    printf("Bienvenido, ya cuenta con una cuenta?\n");
    printf("1.- Si\n");
    printf("2.- No\n");
    printf("Escoge una opci%cn: ",162);
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
            menu_login();
            break;
        case 2:
            menu_registro();
            break;
        default:
            printf("Opci%cn no valida\n",162);
            system("cls");
            menu_inicio();
            break;
    }
}

void menu_login(){

}

void menu_registro(){

}