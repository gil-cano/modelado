/*
* Programa que resuelve el problema 'Stack of Flapjacks' (UVa 120)
* Programming Challenges, Skiena, pp 89
*
* 2012 Gildardo Bautista <gil@ciencias.unam.mx>
* Facultad de Ciencias
* Universidad Nacional Autónoma de México, México.
*/

#include <stdio.h>
#include <string.h>

void flipArray(int a[], int start, int end){
    // flip a subarray
    int n;

    while (start < end) {
        n = a[start];
        a[start] = a[end];
        a[end] = n;
        start++;
        end--;
    }
}

int findLargest(int a[], int start, int end){
    int max = start;
    start ++;
    while (start <= end){
        if (a[max] < a[start])
            max = start;
        start++;
    }
    return max;
}

int main(int argc, char const *argv[]){
    int stack[5] = {4, 3, 2, 1, 5};

    char flips[60];
    char index[3];
    memset(flips, '\0', sizeof(flips));

    int largest;
    int start = 0;
    int end = 4;

    while (start < end){
        largest = findLargest(stack, start, end);
        // si el elemento ya esta ordenado nos movemos al siguiente
        if (largest != start){
            // si el mas grande ya esta en el tope no es necesario el flip
            if (largest < end){
                sprintf(index, "%d ", largest+1);
                strcat(flips, index);
                flipArray(stack, largest, end); //mandamos el mas grande hasta arriba.
            }
            sprintf(index, "%d ", start+1);
            strcat(flips, index);
            flipArray(stack, start, end); //lo ordenamos en su pocicion
        }
        start++; //el siguiente indice a ordenar
    }

    strcat(flips, "0");

    int i;
    for(i=0; i<5; printf("%d ",stack[i]), i++);
    
    printf("\n%s\n", flips);

    return 0;
}