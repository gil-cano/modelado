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
    long masgrandote = min;
    while(min <= max){
        longitud = longitud_de_ciclo(min);
        if (longitud > maximo){
            maximo = longitud;
            masgrandote = min;
        }
        min = min + 1;
    }
    printf("el mas grandote fue %ld\n", masgrandote);
    return maximo;
}

int main()
{
    long minimo, maximo;
    while(scanf("%ld %ld", &minimo, &maximo) != EOF){
        printf("%ld %ld %ld\n", minimo, maximo, ciclo_maximo(minimo, maximo));
    }
    return 0;
}