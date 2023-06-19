typedef struct usuario
{
    char nombre[55];
    char password[55];
}usuario;


void menu_inicio();
bool menu_login(usuario *user);
void menu_admin(list *L);
void menu_usuario(list *L, listCarrito *carrito);

#include "lib.c"