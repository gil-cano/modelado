#include <stdio.h>

long longitud_de_ciclo(long n){
    long longitud = 1;
    while (n > 1){
        if (n%2 == 0){
            n = n/2;
        }
        else{
            n = n*3 + 1;
        }
        longitud = longitud + 1;
    }
    return longitud;
}

long ciclo_maximo(long min, long max){
    long maximo = 1;
    long longitud;
    while(min <= max){
        longitud = longitud_de_ciclo(min);
        if (longitud > maximo){
            maximo = longitud;
        }
        min = min + 1;
    }
    return maximo;
}

int main()
{
    long minimo, maximo, ciclo_max;
    while(scanf("%ld %ld", &minimo, &maximo) != EOF){
        if (maximo < minimo){
            ciclo_max =  ciclo_maximo(maximo, minimo);
        }
        else {
            ciclo_max = ciclo_maximo(minimo, maximo);
        }
        printf("%ld %ld %ld\n", minimo, maximo, ciclo_max);
    }
    return 0;
}