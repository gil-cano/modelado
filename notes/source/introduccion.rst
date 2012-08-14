Introducción
============

Como trabaja *C*
----------------

Las computadoras solo entienden un lenguaje, el lenguaje de maquina,
una secuencia binaria de 0's y 1's. Para convertir nuestro codigo *C*
en lenguaje maquina usamos un **compilador**.

.. code-block:: c

    #include <stdio.h>

    int main(int argc, char const *argv[])
    {
      puts("C Rocks!");
      return 0;
    }

.. code-block:: sh

    $ ls
    display.c
    $ gcc display.c -o display
    $ ls
    display     display.c
    $ ./display 
    C Rocks!


Como se ve un programa en *C*?
------------------------------

Los programas cominezan con un comentario, que describen el propodito
del codigo en el archivo y puede incluir informacion de la licencia o
los derechos de autor.

.. code-block:: c

    /*
    * Programa para traducir fechas del calendario gregoriano y juliano al
    * calendario ritual Nahuatl (cuenta de los días o Tonalpohualli) de acuerdo
    * con la correlación establecida por Alfonso Caso.
    *
    * Copyright (C) 2009 José Galaviz <jgc@fciencias.unam.mx>
    * Facultad de Ciencias,
    * Universidad Nacional Autónoma de México, Mexico.
    */

Luego esta la sección de bibliotecas a incluir

.. code-block:: c

    #include <stdio.h>

Por ultimo estan las funciones. La funcion principal en cada programa
se llama funcion **main()**, En esta funcion comienza la ejecución del
programa.

.. code-block:: c

    int main(int argc, char const *argv[])
    {
      char c;
      FILE *in_file = fopen(argv[1], "r");
      while((c = getc(in_file)) != EOF) {
        putchar(c);
      }
      return 0;
    }

Para revisar el estado de salida:

.. code-block:: sh

    $ echo %?

