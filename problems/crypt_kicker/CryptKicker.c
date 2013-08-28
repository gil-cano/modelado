/* 
 * CryptKicker.c
 * 
 * José Galaviz
 * 25 de agosto de 2012
 * Facultad de Ciencias
 * UNAM
 *
 *#	 	 	Problem 				Verdict 		Language 	Run Time
 *10523067 	843 Crypt Kicker 	Accepted 	ANSI C 		0.048 
 *
 *Submission Date 2012-08-26 04:18:12
 * 
 * Programa para resolver el problema 843 (UVa ID), Crypt Kicker,
 * contenido en:
 *
 * Skiena, Steven y Miguel A. Revilla, 
 * "Programming Challenges,the programming contest training manual",
 * Springer Verlag, 2003, Texts in Computer Science, pp. 47.
 * 
 * Se trata de encontrar el mapeo criptográfico monoalfabético usado
 * para cifrar una secuencia de palabras. Se da como entrada el
 * diccionario que contiene las palabras en texto claro y una o varias
 * secuencias de palabras cifradas.
 * 
 */
#include<stdio.h>
#include<string.h>

#define MAXWRDSZ  16    /* Tamaño máximo de las palabras */
#define MAXDICSZ  1000  /* Número máximo de palabras en el diccionario */
#define MAXCARSLN 80    /* Tamaño máximo de la línea cifrada */
#define ALFABSZ   26    /* Cardinalidad del alabeto (letras minúsculas) */
#define MAXWRDSLN MAXCARSLN/2+1 /* Palabras cifradas por línea */

/* Las palabras del diccionario. Se dan en orden alfabético a la
   entrada */
char diccionario[MAXDICSZ][MAXWRDSZ + 1];

/* 
   Estructura de datos para mantener la partición de las palabras.
   El primer índice es la longitud de la palabra.
   El segundo el número de letras distintas en la palabra
   El tercero recorre los índices donde, las palabras que cumplen con
   las condiciones especificadas en los otrs índices, están
   almacenadas en el diccionario.
*/
int  particion[MAXWRDSZ + 1][MAXWRDSZ + 1][MAXDICSZ];

/* Estructura para almacenar el número de palabras en cada categoría */
int  tamcat[MAXWRDSZ + 1][MAXWRDSZ + 1];

/*
  Ejemplo de la información guardada en diccionario y particion.

  Con el diccionario:
  12
  and
  dick
  jane
  jane
  puff
  saca
  seee
  spot
  yertle
  yoyoyoyo
  yoyoyoyo
  yuuuuuuu

  Se produce:
  Tamaño declarado del diccionario: 12
  Tamaño real del diccionario: 10
  0... and
  1... dick
  2... jane
  3... puff
  4... saca
  5... seee
  6... spot
  7... yertle
  8... yoyoyoyo
  9... yuuuuuuu

  Palabras del diccionario de tamaño: 3 compuestas de 3 letras diferentes
  Índices: 0 
  Palabras del diccionario de tamaño: 4 compuestas de 2 letras diferentes
  Índices: 5 
  Palabras del diccionario de tamaño: 4 compuestas de 3 letras diferentes
  Índices: 3 4 
  Palabras del diccionario de tamaño: 4 compuestas de 4 letras diferentes
  Índices: 1 2 6 
  Palabras del diccionario de tamaño: 6 compuestas de 5 letras diferentes
  Índices: 7 
  Palabras del diccionario de tamaño: 8 compuestas de 2 letras diferentes
  Índices: 8 9 
*/

/* Las palabras cifradas */
char cifradas[MAXWRDSLN][MAXWRDSZ + 1];

/* El mapeo de descifrado */
char mapeo[ALFABSZ];

char answer[100];

/*
 * Borra el caracter de cambio de línea al final de la cadena y lo
 * reemplaza por un nulo.
 * Parámetro:
 * s es la cadena en la que se desea reemplazar el cambio de línea.
 *
 * Salida:
 * s sin el cambio de línea (de haberlo tenido)
 */
void removeNL(char *s) {
  int len;
  if (s != NULL) {
    len  = strlen(s);
    if (len > 0 && s[len - 1] == '\n')
      s[len - 1] = '\0';
  }
}

/*
 * Cuenta el número de letras de una palabra que aparecen en ella
 * sólo una vez.
 * Parámetro:
 * s es la cadena en la que se verificarán los caracteres que la
 * componen.
 *
 * Salida:
 * un número entero que indica cuantas letras diferentes 
 * componen a s
 *
 * Se supone el alfabeto de 26 letras minúsculas.
 */
int letrasDif(char *s) {
  int i, cnt[ALFABSZ], tam, sum = 0;

  tam = strlen(s);
  for(i = 0; i < ALFABSZ; i++)
    cnt[i] = 0;

  /* cnt[j] contiene el número de veces que aparece la j-ésima letra
     del alfabeto */
  for(i = 0; i < tam; i++)
    cnt[s[i] - 'a'] = 1;

  /* En sum contamos cuantas letras tienen frecuencia distinta de cero */
  for(i = 0; i < ALFABSZ; i++)
    sum += (cnt[i])? 1 : 0;

  return sum;
}

/*
 * Lee el diccionario de la entrada estándar, construye la partición
 * del diccionario de acuerdo con el tamaño de las palabras y el
 * número de letras diferentes que las componen.
 * Parámetros:
 * dic es el diccionario, un arreglo de cadenas.
 * part es la partición, es un arreglo trimensional. La peimera
 * dimensión es para indicar el tamaño de las cadenas en la categoría.
 * La segunda para indicar el número de letras diferentes que componen
 * las palabras en la categoría y la última dimensión es para indicar
 * los índices (en el diccionario) en los que están almacenadas las
 * palabras en la categoría.
 * 
 * Salida:
 * un entero con el tamaño real del diccionario (se excluyen palabras
 * duplicadas suponiendo que se reciben en orden alfabético.
 */
int leeDiccionario(char dic[MAXDICSZ][MAXWRDSZ + 1],
                   int  part[MAXWRDSZ + 1][MAXWRDSZ + 1][MAXDICSZ],
                   int  catsz[MAXWRDSZ + 1][MAXWRDSZ + 1]) {
  int  i, n, diclen, dictidx;
  char linea[MAXCARSLN + 1];
  int  lonpal, letdif;

  /* número de palabras en el diccionario */
  scanf("%d\n", &diclen);

#ifdef DEBUG1
  fprintf(stderr,"Tamaño declarado del diccionario: %d\n", diclen);
#endif

  /* Lectura del diccionario */
  dictidx = 0;
  n = diclen;
  while(n--) {
    fgets(linea, MAXCARSLN + 1, stdin);
#ifdef DEBUG1
    fprintf(stderr,"linea prenl: |%s|\n",linea);
#endif
    removeNL(linea); /* quitamos cambio de línea */
#ifdef DEBUG1
    fprintf(stderr,"linea posnl: |%s|\n",linea);
#endif
    /* si es la primera vez que pasamos, 
       o la palabra leída es distinta de la anterior,
       incluimos la palabra */
    if ((!dictidx) || (strcmp(linea, dic[dictidx - 1]))) {
      strcpy(dic[dictidx], linea);
      /* Inclusión en la tabla descriptora de la partición */
      lonpal = strlen(linea);
      letdif = letrasDif(linea);
      i = catsz[lonpal][letdif]++;
      part[lonpal][letdif][i] = dictidx;

      ++dictidx;
    }
  }
  return dictidx; /* tamaño efectivo del dicionario */
}

/*
 * Extrae las palabras contenidas en la línea de criptotexto.
 * Parametros:
 * crline es la línea de criptotexto a tokenizar
 * crlist es la lista en que hay que guardar cada token
 *
 * Salida:
 * un entero especificando el número de palabras cifradas que se
 * extrajeron de la línea.
 */
int tokenizar(char *crline, char crlist[][MAXWRDSZ + 1]) {
  char *ptrnxt = crline;
  char *final = crline + strlen(crline);
  int  carsparsed, idx = 0;

  while (ptrnxt < final) {
    sscanf(ptrnxt, "%s%n", crlist[idx++], &carsparsed);
    ptrnxt += carsparsed;
  }
  return idx;
}

/*
 * Prueba si el mapeo resultante de empatar una pareja de criptotexto
 * y texto claro es compatible con la hipótesis de mapeo que se tiene
 * hasta ahora.
 * Que sea compatible significa que no mapea una letra contenida en el
 * actual mapeo y la transforma en otra distinta de la ya contemplada
 * en éste.
 *
 * Parametros:
 * map es el mapeo que se tiene hasta ahora. En el lugar i-ésimo del
 * arreglo se guarda la letra de texto claro que el cifrado mapea en
 * la i-ésima letra del alfabeto cifrado. 
 *
 * cri es una palabra cifrada que se ha determinado, puede empatarse
 * con una palabra clara.
 *
 * cla es una palabra en texto claro que se presume, puede
 * corresponder con "cri" al ser cifrada.
 *
 * Salida:
 * 1 si el mapeo entre la pareja cifrada/clara es compatible con el
 * mapeo map. 
 *
 * LEGACY CODE. FPRMABA PARTE DEL DISEÑO DEL BACKTRACK QUE APARECE MÁS
 * ABAJO COMO LEGACY CODE Y QUE NO FUNCINÓ.
 *
 */
int compatible(char map[], char *cri, char *cla) {
  int i, j, compa = 1;
  for (i = 0; (i < strlen(cri)) && compa; i++) {
    /* Verificación para que el mapeo sea inyectivo */
    /* Si en el mapeo, alguna de las letras de la palabra cifrada ya
    era mapeada en otra distinta de la que aparece en la palabra
    clara, no son compaibles */
    if ((map[cri[i]-'a'] != '*') && (map[cri[i] - 'a'] != cla[i]))
      compa = 0;
    /* Verificación para que además sea función */
    /* Cada letra de la palabra clara no debe aparecer más que en el
       lugar que le corresponde según el empate que se está probando */
    for (j = 0; compa && (j < ALFABSZ); j++) {
      if (j != (cri[i] - 'a')) compa = (cla[i] != map[j]);
    }
  }
  return compa;
}

/*
 * Suponiendo un mapeo entre texto claro y texto cifrado, expresado en
 * un mapeo, descifra una cadena.
 *
 * Parámetros:
 * map es el mapeo que se utilizará para descifrar la cadena. map[i]
 * contiene la letra de texto claro que le corresponde al caracter
 * i-ésimo del alfabeto cifrado, i.e. map[i] descifra la letra 'a'+i
 *
 * cri es el criptograma que se desea descifrar.
 *
 * Salida:
 * escribe en la salida estándar la cadena que descifra a cri, según
 * el mapeo proporcionado.
 */
/*
void descifra(char map[], char *cri) {
  int i;
#ifdef DEBUG3
    for (i = 0; i < ALFABSZ; i++)
      fprintf(stderr, "%c --> %c\n", 'a' + (char)i, map[i]);   
    fprintf(stderr, "%s\n", cri);
#endif
  for (i = 0; i < strlen(cri); i++) {
    if ((cri[i] >= 'a') && (cri[i] <= 'z'))
      printf("%c", map[cri[i] - 'a']);
    else
      printf("%c", cri[i]);
  }
  printf("\n");
}
*/
void descifra(char map[], char pcif[][MAXWRDSZ+1], int npal) {
  int i, j, tam;
  for (i = 0; i < npal; i++) {
    tam = strlen(pcif[i]);
    for (j = 0; j < tam; j++)
      printf("%c", map[pcif[i][j] - 'a']);
    if (i < npal - 1) printf(" ");
  }
  printf("\n");
}


/*
 * Búsca un mapeo adecuado para descifrar las palabras dadas en el
 * criptograma, de acuerdo con un diccionario de palabras en texto
 * claro.
 *
 * Parámetros:
 * map es el mapeo que, hasta el momento, se ha construido como
 * hipótesis de haber sido usado para cifrar. En map[i] se guarda la
 * que, hasta el momento, parece ser la letra que se cifró como 'a'+i
 * en el alfabeto convencional de 26 letras minúsculas.
 *
 * pcif es un arreglo de palabras cifradas.
 *
 * dic es el diccionario de palabras claras. Las palabras en "pcif"
 * son resultado de cifrar palabras de éste diccionario.
 *
 * part es la estructura que mantiene la partición del diccionario de
 * acuerdo con: el tamaño de las palabras (primer índice) y el número
 * de letras diferentes en la palabra (segúndo índice) el tercer
 * indice recorre las referencias (índices del diccionario) de las
 * palabras en cada categoría de acuerdo con la pareja (tamaño de
 * palabra, número de letras diferentes).
 * 
 * nump contiene, en su entrada [i][j] el número total de palabras del
 * diccionario de longitud i y j letras diferentes. i.e. el número de
 * entradas disponibles en part[i][j]. Así que part[i][j][k] con k en
 * {0, ..., nump[i][j] - 1}.
 *
 * npal es el número de palabras cifradas en el arreglo pcif. Es decir
 * hay que considerar cómo válidas las entradas de pcif desde el
 * índice 0  hasta el npal-1. 
 * 
 * ipal es el índice de la palabra del arreglo pcif a ser considerado
 * en ésta llamada.
 *
 * Salida:
 * 1 si ya se encontró un mapeo que logre descifrar todas las palabras
 * del arreglo pcif simultáneamente sin contradicción.
 * 0 en otro caso.
 *
 * Nota: Esta función es recursiva. Hace una busqueda con retroceso
 * mínimo (backtrack) buscando el mapeo entre letras cifradas y letras
 * claras que logre descifrar todas las palabras contenidas en un
 * criptograma. Empata una pareja de palabras (cifrada, clara) que
 * tengan tanto el mismo tamaño como el mismo número de letras
 * diferentes. Se busca que éste empate sea compatible con el mapeo
 * construido hasta el momento (hecho siguiendo el mismo procedimiento
 * con las palabras cifradas previas). Se termina cuando se han
 * logrado descifrar TODAS las palabras del criptograma.
 *
 * LEGACY CODE. POR ALGUNA EXTRAÑA RAZÓN NO FUNCIONÓ, PERO SU DISEÑO
 * ES MEJOR QUE EL DE LA FUNCIÓN QUE SÍ FUNCIONÓ.
 *
 */
int buscaMapeoX(char map[ALFABSZ], char pcif[][MAXWRDSZ+1],
               char dic[][MAXWRDSZ+1], int part[][MAXWRDSZ+1][MAXDICSZ],
               int nump[][MAXWRDSZ+1], int npal, int ipal) {
  int  resul = 0;
  int  icand = 0;
  int  numcand, tam, cdif;

  char *cifrada = pcif[ipal];

  if (ipal == npal)  /* si ya no quedan palabras por descifrar */
    return 1;

  tam = strlen(cifrada);
  cdif = letrasDif(cifrada);
  numcand = nump[tam][cdif];

  /* Si hay candidatos, buscamos uno que sea compatible con el mapeo
     hecho hasta ahora, mientras no se acaben los candidatos */
  for (icand = 0; icand < numcand; icand++) {
    char *clara = dic[part[tam][cdif][icand]];
    if (compatible(map, cifrada, clara)) {
      /* encontramos un candidato compatible */
      char mapprev[ALFABSZ];
      int i;
      /* salvamos el mapeo que tenemos hasta ahora */
      for (i = 0; i < ALFABSZ; i++) mapprev[i] = map[i];

      /* Ponemos en correspondencia la cadena del diccionario
         que empató con la cifrada y aumentamos el mapeo */
      for (i = 0; i < tam; i++)
        map[cifrada[i] - 'a'] = clara[i];

      /* Backtrack, llamada recursiva */
      if (buscaMapeo(map, pcif, dic, part, nump, npal, ipal + 1))
        return 1;
      /* Algo falló, recuperamos el mapeo previo */
      for (i = 0; i < ALFABSZ; i++) map[i] = mapprev[i];
    }
  } /* for icand */

  return 0;
}

/*
 * Determina si, hasta el momento, no hay caracter claro que se cifre
 * en una letra dada.
 *
 * Parámetro:
 * c es la letra que se desea saber si es posible descifrar en el
 * mapeo actual. OJO se consulta la variable global mapeo para
 * determinarlo. 
 * 
 * Salida:
 * regresa 1 si no hay letra que descifre a la dada como parámetro, 0
 * en otro caso
 */
int nadieDescifra(char c) {
  int i, res;

  for (i = 0; i < ALFABSZ; i++) {
    if (mapeo[i] == c)
      return 0;
  }
  return 1;
}

/*
 * Búsqueda con retroceso mínimo para determinar el mapeo para
 * descifrar un criptograma dado.
 *
 * Se utilizan (sin mdificar) las variables globales:
 * mapeo, diccionario, partición y tamcat
 *
 * Parámetros:
 * line es la línea cifrada que se desea descifrar.
 * deep indica el avance en el descifrado del criptograma.
 *
 * Salida:
 * regresa 1 si tuvo éxito la búsqueda, 0 en otro caso.
 */
int buscaMapeo(char *line, int deep) {
  int i, j, n, rep, tam;
  char cword[20];
    
  if(*line == '\0')
    return 1;

  sscanf(line, "%s%n", cword, &n);
  rep = letrasDif(cword);
  tam = strlen(cword);

  for (i = 0; i < tamcat[tam][rep]; i++) {
    char st[20]; /* una pila */
    int  idx = 0, tope = 0;
    char decoded[20];
    for (j = 0; j < 20; decoded[j++] = '\x0');
    char *candidate = diccionario[particion[tam][rep][i]];

    for (j = 0; j < tam; j++) {
      if (mapeo[cword[j] - 'a'] == '*') {
        if (nadieDescifra(candidate[j])) {
          mapeo[cword[j] - 'a'] =  candidate[j];
          st[tope++] = cword[j];
        }
        else
          break;
      }
      decoded[idx++] = mapeo[cword[j] - 'a'];
    }
        
    if(strlen(decoded) == strlen(candidate) && !strcmp(decoded, candidate)) {
      char  tmp[100];
      strcpy(tmp, answer);
      strcat(answer, decoded);
      if(buscaMapeo(line + n, deep + 1))
        return 1;
      strcpy(answer, tmp);
    }

    while(tope)
      mapeo[st[tope--] - 'a'] = '*';
    mapeo[st[tope] - 'a'] = '*';
  }
  return 0;
}


/*
 * Determina si será posible o no descifrar el criptotexto.
 *
 * Parámetros:
 * pcif es la lista de palabras cifradas
 * npal es el número de palabras cifradas en el arreglo previo
 * nump arreglo que en su entrada i,j contiene el número de palabras
 * en el diccionario que tienen longitud i y j letras diferentes
 * 
 * Salida:
 * 1 si es posible, para cada palabra del criptograma, empatarla con
 * al menos una del diccionario
 */
int esPosible(char pcif[][MAXWRDSZ+1], int npal, int nump[][MAXWRDSZ+1]) {
  int i, posible = 1;
  for (i = 0; (i < npal) && posible; i++) {
    posible = (nump[strlen(pcif[i])][letrasDif(pcif[i])] > 0);
  }
  return posible;
}

/*
 * Programa principal. Recibe de la entrada estádar:
 * un número n (tamaño del dicionario)
 * n palabras en texto claro (el diccionario)
 * una o varias líneas de criptogramas construidos cifrando las
 * palabras del dicionario.
 */
int main() {
  int  tamdic;
  char criptotexto[100];
  int  ipal, icar;
  int  numpals;

  /* para debug */
  int  i, j, k;

  /* lectura del diccionario */
  tamdic = leeDiccionario(diccionario, particion, tamcat);

#ifdef DEBUG1
  fprintf(stderr,"Tamaño real del diccionario: %d\n", tamdic);
  for (i = 0; i < tamdic; i++) {
    fprintf(stderr,"%3d... %s\n", i, diccionario[i]);
  }
  for (i = 0; i < MAXWRDSZ; i++) {
    for (j = 0; j < MAXWRDSZ; j++) {
      if (tamcat[i][j]) {
        fprintf(stderr, "Palabras del diccionario de tamaño: %d ", i);
        fprintf(stderr, "compuestas de %d letras diferentes\n", j);
        fprintf(stderr, "Índices: ");
        for (k = 0; k < tamcat[i][j]; k++) {
          fprintf(stderr, "%d ", particion[i][j][k]);
        }
        fprintf(stderr, "\n");
      }
    }
  }
#endif

  while(fgets(criptotexto, 99, stdin) != NULL) {
    removeNL(criptotexto);
    for (ipal = 0; ipal < MAXWRDSLN; ipal++)
      for (icar = 0; icar < MAXWRDSZ + 1; icar++)
        cifradas[ipal][icar] = '\x0';
    for (icar = 0; icar < ALFABSZ; mapeo[icar++] = '*');
    for (icar = 0; icar < 100; answer[icar++] = '\x0');
    numpals = 0;
    numpals = tokenizar(criptotexto, cifradas);

#ifdef DEBUG2
    fprintf(stderr, "Línea cifrada: |%s|\n", criptotexto);
    fprintf(stderr, "Palabras cifradas\n");
    for (i = 0; i < numpals; i++) {
      fprintf(stderr, "|%s|\n", cifradas[i]);
    }
    for (i = 0; i < ALFABSZ; i++)
      fprintf(stderr, "%c --> %c\n", 'a' + (char)i, mapeo[i]);
#endif    
    if (esPosible(cifradas, numpals, tamcat))
        buscaMapeo(criptotexto, 0);
    /* descifra(mapeo, criptotexto); */
    descifra(mapeo, cifradas, numpals);
  }
  return 0;
} /* fin de crypt-kicker.c */
