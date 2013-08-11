/*
** <tonalpohualli.c>
**
** Copyright (C) 2009 José Galaviz <jgc@fciencias.unam.mx>
** Facultad de Ciencias,
** Universidad Nacional Autónoma de México, Mexico.
**
** Programa para traducir fechas del calendario gregoriano y juliano al
** calendario ritual Nahuatl (cuenta de los días o Tonalpohualli) de acuerdo
** con la correlación establecida por Alfonso Caso.
**
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
================================================================================
                         NÚMEROS DE DÍA JULIANO
================================================================================
*/

/*  
   Punto de partida para la correlación:
   13 de agosto de 1521 = 1 serpiente
*/
#define TONALCORR_AG 2276828 /* julian day number, como si fuera fecha juliana*/
#define TONALCORR_DG 2276818 /* julian DN, como si fuera fecha gregoriana */
/* punto de partida para correlación de año: 1519 = 1 caña */
#define TONALCORR_AN 1519 /* año 1 caña */

/* 
Introducción de la reforma gregoriana al calendario. En España y
algunos otros países católicos europeos, en los que se adoptó más
temprano, esto ocurrió cuando se convirtió el 5 de octubre de 1582
en el 15 de octubre de 1582 
*/
/* 4 de octubre de 1582 */
#define IG_EU_AG 2299160 /* julian day number, como si fuera fecha juliana */
#define IG_EU_DG 2299150 /* julian day number, como si fuera fecha gregoriana */

/* 15 de octubre de 1582 */
#define SG_EU_AG 2299171 /* julian day number, como si fuera fecha juliana */
#define SG_EU_DG 2299161 /* julian day number, como si fuera fecha gregoriana */

/* 
En las colonias españolas (Nueva España, por ejemplo) se adoptó al
año siguiente de su introducción en España. 
*/
/* 4 de octubre de 1583 */
#define IG_NE_AG 2299525 /* julian day number, como si fuera fecha juliana */
#define IG_NE_DG 2299515 /* julian day number, como si fuera fecha gregoriana */

/* 15 de octubre de 1583 */
#define SG_NE_AG 2299536 /* julian day number, como si fuera fecha juliana */
#define SG_NE_DG 2299526 /* julian day number, como si fuera fecha gregoriana */

/* Cantidad de numerales usados en Náhuatl */
#define NUMERALES 13

/* Número de símbolos de los días en el Tonpohualli */
#define NSIMDI 20

/* Número de símbolos de los años en Náhuatl  */
#define NSIMAN 4

/* Nombre de los días en español */
char *dias_esp[NSIMDI] = {"Serpiente\x0","Muerte\x0","Venado\x0","Conejo\x0",
                        "Agua\x0","Perro\x0","Mono\x0","Hierba\x0","Caña\x0",
                        "Tigre\x0","Águila\x0","Buitre\x0","Movimiento\x0",
                        "Pedernal\x0","Lluvia\x0","Flor\x0","Lagarto\x0",
                        "Viento\x0","Casa\x0","Lagartija\x0"};

/* Nombre de los días en náhuatl */
char *dias_nah[NSIMDI] = {"Cóatl\x0","Miquiztli\x0","Mázatl\x0","Tochtli\x0",
                        "Atl\x0","Itzcuintli\x0","Ozomatli\x0","Malinalli\x0",
                        "Ácatl\x0","Ocelotl\x0","Cuauhtli\x0",
                        "Cozcacuauhtli\x0","Ollin\x0","Técpatl\x0",
                        "Quiáhuitl\x0","Xóchitl\x0","Cipactli\x0","Ehécatl\x0",
                        "Calli\x0","Cuetzpallin\x0"};

/* Nombre de los años en español */
char *anios_esp[NSIMAN] = {"Caña\x0","Pedernal\x0","Casa\x0","Conejo\x0"};

/* Nombre de los años en náhuatl */
char *anios_nah[NSIMAN] = {"Ácatl\x0","Técpatl\x0","Calli\x0","Tochtli\x0"};

/* Números en náhuatl */
char *numeros_nah[NUMERALES+1] = {"\x0","Ce\x0","Ome\x0","Yei\x0","Nahui\x0","Macuilli\x0",
                        "Chicuace\x0","Chicome\x0","Chicuei\x0","Chiconahui\x0",
                        "Mahtlactli\x0","Mahtlactlionce\x0","Mahtlactliomome\x0",
                        "Mahtlactliomei\x0"};

char *nombre_meses[NUMERALES] = {"\x0","enero\x0","febrero\x0","marzo\x0",
                         "abril\x0","mayo\x0","junio\x0",
                         "julio\x0","agosto\x0","septiembre\x0",
                         "octubre\x0","noviembre\x0","diciembre\x0"};

void uso(char* nombre, int cerr);
int mes(char* mstr);
int anno(char* astr);
int dia(char* dstr, int nmes, int nano);
int bisiesto(int nano);
int diasmes(int nmes, int nano);
int diajulianoposgregoriano(int nano, int nmes, int ndia);
int diajulianopregregoriano(int nano, int nmes, int ndia);

char *nombreMes(int mn);
char *tonalpohualli(int esp, int dia, int mes, int anno);
int mod(int num, int m);
int idxNumeral(int dif);
int idxSimboloA(int dif);
int idxSimboloD(int dif);

/*
** Función para desplegar instrucciones básicas de uso del programa y terminar.
**
** Parámetros.
** nombre es el nombre del programa ejecutable.
** cerr es el código de error que se entrega al salir al S.O.
** 
** Regresa.
** nada
 */
void uso(char* nombre, int cerr) {
  fprintf(stderr, "Programa para traducir años del calendario occidental\n");
  fprintf(stderr, "al calendario ritual náhuatl (Tonalamatl).\n");
  fprintf(stderr, "Uso: %s <día> <mes> <año>\n", nombre);
  fprintf(stderr, "mes es una cadena con el nombre convencional\n");
  fprintf(stderr, "del mes (al menos las primeras tres letras)\n,");
  fprintf(stderr, "mayúsculas y minúsculas son indstinguibles\n");
  fprintf(stderr, "Años anteriores a la era cristiana se anteceden\n");
  fprintf(stderr, "de un signo menos (pero no hay año cero). El año\n"); 
  fprintf(stderr, "debe ser mayor que -4800.\n");
  fprintf(stderr, "Se supone la fecha de adopción de la reforma\n");
  fprintf(stderr, "gregoriana en la Nueva España: 4 de octubre de 1583\n");
  exit(cerr);
}

/*
** Función para obtener el número de mes a partir de una cadena que lo
** especifíca por nombre, al menos tres letras del nombre en castellano.
**
** Parámetros.
** mstr es la cadena que contiene al menos las tres primeras letras 
** del nombre en castellano del mes. No importan mayúsculas y minúsculas.
** 
** Regresa.
** Un entero entre 1 y 12 inclusive, que representa en número de mes.
** Si la cadena no contiene el especificador de nombre de un mes, se 
** regresa cero.
 */
int mes(char* mstr) {
  if      (!strncasecmp("ENE", mstr, 3)) return 1;
  else if (!strncasecmp("FEB", mstr, 3)) return 2;
  else if (!strncasecmp("MAR", mstr, 3)) return 3;
  else if (!strncasecmp("ABR", mstr, 3)) return 4;
  else if (!strncasecmp("MAY", mstr, 3)) return 5;
  else if (!strncasecmp("JUN", mstr, 3)) return 6;
  else if (!strncasecmp("JUL", mstr, 3)) return 7;
  else if (!strncasecmp("AGO", mstr, 3)) return 8;
  else if (!strncasecmp("SEP", mstr, 3)) return 9;
  else if (!strncasecmp("OCT", mstr, 3)) return 10;
  else if (!strncasecmp("NOV", mstr, 3)) return 11;
  else if (!strncasecmp("DIC", mstr, 3)) return 12;
  else return 0;
}

/*
** Función para obtener el número de año a partir de una cadena que lo contiene.
**
** Parámetros.
** astr es una cadena que contiene el año; por ejemplo "2012". El
** número puede ir precedido de un "-" indicando años anteriores a la
** era común. Si el número es cero (inválido como número de año) se
** regresa tal cual, lo que equivale al código de error.
**
** Regresa.
** El año en formato numérico; en el ejemplo: 2012.
** Si la cadena no contenía un número se regresa cero.
 */
int anno(char* astr) {
  char *fin;
  int anio = strtol(astr, &fin, 0);
  return (astr != fin)? anio : 0;
}

/*
** Función para obtener el número de día del mes a partir de una
** cadena que lo contiene. 
**
** Parámetros.
** dstr es una cadena que contiene el día. El día debe ser mayor o
** igual a 1 y menor que el número de días del mes.
** nmes es el número que indica el mes del año {1, ..., 12}. Este
** parámetro, junto con el año, validan el número de día contenido en
** la cadena dstr.
** nano es el número del año. Este parámetro se utiliza para validar
** el número de día en dstr. Por ejemplo, el "29" de febrero de 1983
** es inválido.
**
** Regresa.
** el número de día contenido en la cadena dstr, si es válido o cero
** si no lo es o no había número en la cadena.
 */
int dia(char* dstr, int nmes, int nano) {
  char *fin;
  int ddia = strtol(dstr, &fin, 0);
  
  if (dstr == fin) return 0;
  if ((ddia >= 1) && (ddia <= diasmes(nmes, nano))) return ddia;
  else return 0;
}

/*
** Función para determinar si un año es bisiesto de acuerdo con el
** calendario gregoriano o no.
**
** Parámetros.
** nano es el número de año por el que se pregunta.
**
** Regresa.
** 1 si el año dao es bisiesto o cero si no lo es. Un año es bisiesto
** si y sólo si:
** Es múltiplo de 4 pero no múltiplo de 100, a menos que también lo
** sea de 400. 
** Es decir todos los mútiplos de 400 son bisiestos, y también lo son
** los múltiplos de 4, a menos que también sean centenarios.
 */
int bisiesto(int nano) {
  if (!(nano % 400)) return 1;
  else if (!(nano % 100)) return 0;
  else if (!(nano % 4)) return 1;
  else return 0;
}

/*
** Función para obtener el número de días en un mes de un año dado.
**
** Parámetros.
** nmes es el mes del que se requiere saber el número de días que tiene.
** nano es el número de año que contiene al mes cuya longitud se requiere.
**
** Regresa.
** El número de días en el mes solicitado: 
** 31 días para enero (1), marzo (3), mayo (5), julio (7), agosto (8),
** octubre (10) y diciembre (12). 30 días para abril (4), junio (6),
** septiembre (9) y noviembre (11). 28 o 29 días para febrero,
** dependiendo de si el año es bisiesto o no, respectivamente. 
 */
int diasmes(int nmes, int nano) {
  switch (nmes) {
    case 1  :
    case 3  :
    case 5  :
    case 7  :
    case 8  :
    case 10 :
    case 12 : return 31;
    case 4  :
    case 6  :
    case 9  :
    case 11 : return 30;
    case 2  : return (bisiesto(nano)) ? 29 : 28;
    default : return 0;
  }
}

/*
** Función para calcular el número de día juliano (JDN) para un día en
** la era posterior a la reforma gregoriana del calendario (al jueves
** 4 de octubre de 1582 le siguió el viernes 15 de octubre de 1582,
** haciendo una diferencia de 10 días que nunca existieron: del 5 al
** 14 de octubre). Hay que señalar que esta reforma se adoptó en
** España en la fecha señalada, pero en otros paises fue posterior (en
** Francia en diciembre del mismo año, en las colonias españolas, como
** la Nueva España, en los mismos días, pero en 1583). Se supone que
** la fecha dada como entrada debe ser posterior a la fecha de apoción
** de la reforma, de no ser así habrá discrepancias al hacer
** correlación de fechas.
**
** Parámetros.
** nmes es el mes de la fecha que se requiere obtener.
** nano es el número de año.
** ndia es el día de la fecha que se requiere mapear al día juliano.
**
** Regresa.
** El número de día juliano en el esquema de medición de fechas
** julianas, es decir, es el número de días transcurridos desde el
** 1 de enero del año 4713 a. e. c. (a. C).
 */
int diajulianoposgregoriano(int nano, int nmes, int ndia) {
  int  a = (int)((14 - nmes) / 12);
  int  y = nano + 4800 - a;
  int  m = nmes + 12 * a - 3;
  int  jd = ndia + (int)((153 * m + 2) / 5) + 365 * y;
  jd = jd + (int)(y / 4) - (int)(y / 100) + (int)(y / 400) - 32045;
  return jd;
}

/*
** Función para calcular el número de día juliano (JDN) para un día en
** la era anterior a la reforma gregoriana del calendario (al jueves
** 4 de octubre de 1582 le siguió el viernes 15 de octubre de 1582,
** haciendo una diferencia de 10 días que nunca existieron: del 5 al
** 14 de octubre). Hay que señalar que esta reforma se adoptó en
** España en la fecha señalada, pero en otros paises fue posterior (en
** Francia en diciembre del mismo año, en las colonias españolas, como
** la Nueva España, en los mismos días, pero en 1583). Se supone que
** la fecha dada como entrada debe ser anterior a la fecha de apoción
** de la reforma, de no ser así habrá discrepancias al hacer
** correlación de fechas.
**
** Parámetros.
** nmes es el mes de la fecha que se requiere obtener.
** nano es el número de año.
** ndia es el día de la fecha que se requiere mapear al día juliano.
**
** Regresa.
** El número de día juliano en el esquema de medición de fechas
** julianas, es decir, es el número de días transcurridos desde el
** 1 de enero del año 4713 a. e. c. (a. C).
 */
int diajulianopregregoriano(int nano, int nmes, int ndia) {
  int  a = (int)((14 - nmes) / 12);
  int  y = nano + 4800 - a;
  int  m = nmes + 12 * a - 3;
  int  jd = ndia + (int)((153 * m + 2) / 5) + 365 * y;
  jd = jd + (int)(y / 4) - 32083;
  return jd;
}

/* 
** Obtiene el residuo de dividir un número entre otro.
** En C el residuo obtenido por el operador módulo ("%") tiene el
** signo del dividendo, lo que no está acorde a lo estipulado por el
** "algoritmo de la división" en el que el residuo debe ser siempre no
** negativo. Ésta función es una adecuación del operador módulo para
** que funcione de acuerdo con el algoritmo de la división.
**
** Parámetros.
** num es el dividendo, el número que se divide entre el módulo.
** m es el módulo.
**
** Regresa.
** un entero no negativo con el residuo.
*/
int mod(int num, int m) {
  int res = num % m;
  return (res >= 0) ? res : m + res;
}

/*
** Regresa el numeral náhuatl que corresponde con el año cuya
** diferencia con 1519 es dada como parámetro. Si la diferencia es
** negativa funciona correctamente.
**
** Parámetros.
** danno es la diferencia entre el año que se requiere traducir y el
** año 1519 = 1 caña.
**
** Regresa.
** el númeral entre 1 y 13, inclusive, que corresponde al año cuya
** diferencia con 1519 se proporcionó.
*/
int idxNumeral(int danno) {
  return mod(danno, NUMERALES) + 1;
}

/*
** Regresa el índice del arreglo de símbolos de año que le corresponde
** al año cuya diferencia con 1519 se proporciona como parámetro.
**
** Parámetros.
** danno es la diferencia entre el año que se requiere traducir y el
** año 1519 = 1 caña.
**
** Regresa.
** el índice que le corresponde al símbolo del año cuya diferencia con
** 1519 se proporcionó.
 */
int idxSimboloA(int danno) {
  return mod(danno, NSIMAN);
}

/*
** Regresa el índice del arreglo de símbolos de día que le corresponde
** al año cuya diferencia con 13 de agosto de 1521 se
** proporciona. Funciona incluso si la diferencia proporcionada es
** negativa (día anterior al usado como correlación). Se debe tomar en
** cuenta que los días entre el 5 de octubre y el 14 de octubre
** (incluyéndolos) de 1583 no son traducibles porque nunca existieron
** el el calendario gregoriano de la Nueva España. Fuera de ese rango
** funciona correctamente para fechas tanto anteriores a la reforma
** gragoriana, como posteriores.
**
** Parámetros.
** dif es la diferencia entre el día que se requiere traducir y el 13
** de agosto de 1521 = 1 serpiente de 3 casa.
**
** Regresa.
** el índice que le corresponde al símbolo del año cuya diferencia con
** 1519 se proporcionó.
*/
int idxSimboloD(int dif) {
  return mod(dif, NSIMDI);
}

char *nombreMes(int mn) {
  int tam;
  char *nombre = NULL;
  if ((mn >= 1) && (mn <=12 )) {
    nombre = (char *)calloc(strlen(nombre_meses[mn])+1, sizeof(char));
    strcpy(nombre, nombre_meses[mn]);
  }
  return nombre;
}

/*
** Traduce la representación de una fecha en el calendario occidental
** (antes o después de la reforma gregoriana) en la representación
** usada en el calendario ritual náhuatl (tonalpohualli).
**
** Parámetros.
** esp es una bandera que indica si se solicita la traducción en
** español (1) o en náhuatl (0).
** dia es el número de día en la fecha que se requiere traducir.
** mes es el número de mes en la fecha que se requiere traducir.
** anno es el número de año en la fecha que se requiere traducir.
**
** Regresa.
** Una cadena con la traducción de la fecha requerida.
*/
char *tonalpohualli(int esp, int dia, int mes, int anno) {
  int  jd, diff, difanno;
  char *buff;
  buff = (char *)calloc(100, sizeof(char));
  jd = diajulianopregregoriano(anno, mes, dia);
  if (jd > IG_NE_AG) {   /* despues de reforma gregoriana */
    /* fecha inexistente en el calendario gregoriano (en Nueva España) */
    if (jd < SG_NE_AG) {
      sprintf(buff,"ERROR: Fecha inexistente debido a la reforma gregoriana.");
      return buff;
    }
    else /* fecha posterior a la adopción de la reforma gregoriana */
      jd = diajulianoposgregoriano(anno, mes, dia);
  }
  diff = jd - TONALCORR_AG;
  difanno = anno - TONALCORR_AN;
  if (esp) {
    sprintf(buff, "%d - %s, %d - %s", idxNumeral(diff), dias_esp[idxSimboloD(diff)],
            idxNumeral(difanno), anios_esp[idxSimboloA(difanno)]);
  }
  else {
    sprintf(buff, "%s - %s, %s - %s", numeros_nah[idxNumeral(diff)], 
            dias_nah[idxSimboloD(diff)], numeros_nah[idxNumeral(difanno)], 
            anios_nah[idxSimboloA(difanno)]);
  }
  return buff;
}

/*
Programa principal. Se admite como entrada de la línea de comandos la
especificación de una fecha occidental y se muestra su traducción en
el calendario náhuatl de la cuenta de los días (tonalpohualli). 
*/
int main(int argc, char *argv[]) {
  int  nanio, nmes, ndia, diajul;
  int  i;
  int  jd, diff, difanno;

  /* Errores de uso */
  if (argc != 4) uso(argv[0], 1);
  nanio = anno(argv[3]);
  if (!nanio) uso(argv[0], 2);
  nmes = mes(argv[2]);
  if (!nmes) uso(argv[0], 2);
  ndia = dia(argv[1], nmes, nanio);
  if (!ndia) uso(argv[0], 2);

  printf("%d de %s de %d.\n", ndia, nombreMes(nmes), nanio);

  printf("%s\n", tonalpohualli(1, ndia, nmes, nanio));
  printf("%s\n", tonalpohualli(0, ndia, nmes, nanio));
  exit(0);
}
/* fin de tonalpohualli.c */
