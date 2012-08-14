#include <stdio.h>

/* la variable y vivira en la seccion global con alguna direccion y valor 1 */
int y = 1;

int main(int argc, char const *argv[])
{
    /* la variable x vivira en el stack con alguna direccion x valor 4 */
    int x = 4;
    printf("x ocupa la dirección %p\n", &x);

    int *direccion_de_x = &x;
    printf("x ocupa la idrección %p\n", direccion_de_x);

    int valor_guardado = *direccion_de_x;
    printf("EL valor de x es %i\n", valor_guardado);

    *direccion_de_x = 99;
    printf("El nuevo valor de x es %i\n", x);
    return 0;
}