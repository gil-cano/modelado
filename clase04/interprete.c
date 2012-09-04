/*  interprete.c

    Simulador de un Interpreter

    by: Gildardo Bautista
    Septiembre 04, 2012
*/

#include <stdio.h>

int registers[10];
char ram[1000][4];

int decode(int *ip)
{
    int instruction = ram[*ip][0];
    int a = ram[*ip][1];
    int b = ram[*ip][2];
    // printf("%i %i\n", a, b);
    *ip++;

    return 1;
}

 fetcho(){
    return 2;
}

int main(int argc, char const *argv[])
{
    int instruction_pointer = 0;

    int ram_location = 0;
    while(scanf("%3s", ram[ram_location]) != EOF){
        printf("%s\n", ram[ram_location]);
        ram_location++;
    }


    int executed = 1;
    while(decode(&instruction_pointer)){
        executed++;
    }

}