#include <stdio.h>


void swap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char const *argv[])
{
    int a = 4;
    int b = 8;
    swap(&a, &b);
    printf("valor de a: %i\n", a);
    printf("valor de b: %i\n", b);
    return 0;
}