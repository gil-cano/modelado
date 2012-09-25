/*  dahdahdah.c

    UVA 11223 - O: dah dah dah!

    by: Gildardo Bautista
    Septiembre 11, 2012
*/

#include <stdio.h>

char morse[53][7] = {
".-", "-...", "-.-.", "-..", ".",
"..-.", "--.", "....", "..", ".---",
"-.-", ".-..", "-- ", "-.", "---",
".--.", "--.-", ".-.",  "...", "-",    
"..-", "...-", ".--", "-..-", "-.--",
"--..", "-----", ".----", "..---", "...--",
"....-", ".....", "-....", "--...", "---..",
"----.", ".-.-.-", "--..--", "..--..", ".----.",
"-.-.--", "-..-.", "-.--.", "-.--.-", ".-...",
"---...", "-.-.-.", "-...-", ".-.-.", "-....-",
"..--.-", ".-..-.",".--.-."
};

char alfabeto[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,\?\'!/()&:;=+-_\"@";


int main(int argc, char const *argv[])
{
    

    int n_mensajes = 0;
    char mensaje[2000];
    char codigo[7];
 
    // leemos numero de mensajes
    scanf("%i", &n_mensajes);
    // leemos el salto de linea
    fgets(mensaje, sizeof(mensaje), stdin);

    int  n = 0;
    for (n; n < n_mensajes; n++){
        char mensaje[2000];
        fgets(mensaje, sizeof(mensaje), stdin);
        int i = 0;
        while(mensaje[i] != '\0'){
            printf("%c\n", mensaje[i]);
            i++;
        }
    }
    return 0;
}