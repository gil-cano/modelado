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
        printf("Hola mundo!\n");
        return 0;
    }

.. code-block:: sh

    $ ls
    hola.c
    $ gcc hola.c -o hola
    $ ls
    hola     hola.c
    $ ./hola 
    Hola mundo!


Como se ve un programa en *C*?
------------------------------

Comentarios
+++++++++++

Los programas comienzan con un comentario, que describen el proposito
del codigo en el archivo y puede incluir información de la licencia o
los derechos de autor.

.. code-block:: c

    /*
    * Programa para mostrar la estructura de un programa en C
    *
    * Copyright (C) 2012 Gildardo Bautista <gil@ciencias.unam.mx>
    * Facultad de Ciencias,
    * Universidad Nacional Autónoma de México, Mexico.
    */

Bibliotecas a incluir
+++++++++++++++++++++

.. code-block:: c

    #include <stdio.h>

Funciónes
+++++++++

Por ultimo estan las funciónes. La función principal en cada programa
se llama función **main()**, En esta función comienza la ejecución del
programa.

.. code-block:: c

    int main(int argc, char const *argv[])
    {
        printf("Hola mundo!\n");
        return 0;
    }

Funcíon **main()**
------------------

.. code-block:: c

    int main(int argc, char const *argv[])

* El tipo que regresa simpre debe ser entero.

* Si no tiene argumentos se pueden omitir

.. code-block:: c

    int main()

* El cuerpo de la función esta determinada por corchetes.

.. code-block:: c

    int main()
    {

    }

.. note::
  
    Para revisar el estado de salida:

    .. code-block:: sh

        $ echo %?


Argumentos
++++++++++

.. code-block:: c

    #include <stdio.h>

    int main(int argc, char const *argv[])
    {
        printf("Se recibieron %i argumentos\n", argc);
        int i;
        for (i=0; i<argc; i++)
            printf("%s\n", argv[i]); 
        return 0;
    }

printf
++++++
.. code-block:: c

    printf("%s dice que la cuenta es %i", "Beto", 21);

* %i     integer
* %s     string
* %c     character
* %f     double
* %p     pointer


Apuntadores
-----------

Un apuntador es la dirección de memoria de un dato.

.. code-block:: c

    /* la variable y vivira en la seccion global con alguna direccion y valor 1 */
    int y = 1;

    int main(int argc, char const *argv[])
    {
        /* la variable x vivira en el stack con alguna direccion x valor 4 */
        int x = 4;
        return 0;
    }

dirección de una variable
+++++++++++++++++++++++++

.. code-block:: c

    printf("x ocupa la dirección %p\n", &x);

para guarda la direccion de una variable necesitamos una variable de apuntador.
Estas variables guardan una direccion de memoria.

.. code-block:: c

    int *direccion_de_x = &x;

contenido de una dirección
++++++++++++++++++++++++++
Para leer el contenido de una direccion de memoria se usa el operador *.

.. code-block:: c

    int valor_guardado = *direccion_de_x;

cambiar el contenido de una dirección
-------------------------------------

.. code-block:: c

    *direccion_de_x = 99;


.. code-block:: c

    #include <stdio.h>

    /* la variable y vivira en la seccion global con alguna direccion y valor 1 */
    int y = 1;

    int main(int argc, char const *argv[])
    {
        /* la variable x vivira en el stack con alguna direccion x valor 4 */
        int x = 4;
        printf("x ocupa la dirección %p\n", &x);

        int *direccion_de_x = &x;
        printf("x ocupa la idrección %p\n", direccion_de_x);

        int valor_guardado = *direccion_de_x;
        printf("EL valor de x es %i\n", valor_guardado);

        *direccion_de_x = 99;
        printf("El nuevo valor de x es %i\n", x);
        return 0;
    }

Intercambio de valores
----------------------


.. code-block:: c

    #include <stdio.h>

    void swap(int x, int y)
    {
        int temp;

        temp = x;
        x = y;
        y = temp;
    }

    int main(int argc, char const *argv[])
    {
        int a = 4;
        int b = 8;
        swap(a, b);
        printf("valor de a: %i\n", a);
        printf("valor de b: %i\n", b);
        return 0;
    }


