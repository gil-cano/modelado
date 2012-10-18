#include <stdio.h>

int main()
{
    long x, y,;
    int distancias[2147483648];
    
    int i = 0;
    distancias[0] = 0
    for (i=1; i < 2147483648; i++){
        distancias[i] = distancias[i-1] + (i+1)/2
    }

    while(scanf("%ld %ld", &x, &y) != EOF){
        if (maximo < minimo){
            steps =  ciclo_maximo(maximo, minimo);
        }
        else {
            steps = ciclo_maximo(minimo, maximo);
        }

        printf("%ld\n", steps);
    }
    return 0;
}