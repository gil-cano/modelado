#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Se recibieron %i argumentos\n", argc);
    int i;
    for (i=0; i<argc; i++)
        printf("%s\n", argv[i]); 
    return 0;
}