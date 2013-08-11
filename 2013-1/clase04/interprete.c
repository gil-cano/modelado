/*  interprete.c

    Simulador de un Interpreter

    by: Gildardo Bautista
    Septiembre 04, 2012
*/

#include <stdio.h>

int registers[10];
char ram[1000][4];

int main(int argc, char const *argv[])
{
    int instruction_pointer = 0;

    int ram_location = 0;
    while(scanf("%3s", ram[ram_location]) != EOF){
        printf("%s\n", ram[ram_location]);
        ram_location++;
    }

}