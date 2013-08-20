Introducción a C
================

.. ifslides::

   .. figure:: /_static/c_language.jpg
      :class: fill

.. ifnotslides::

   Este documento es una breve introducción al lenguaje C.

¿Que es C?
----------

* *C* es un lenguaje compilado. Es decir, una vez que escribes tu programa, debes pasarlo por un compilador de *C* para convertirlo en un archivo ejecutable.

* *C* es un lenguaje de tipos estáticos, es decir que debemos especificar el tipo de cada variable (entera, real, etc.).

* Lenguaje de proposito general 

* Multi-plataforma


Estándares
----------

* **K & R (circa 1978)**: Brian Kernighan and Dennis Ritchie escribierón una descripción del lenguaje (*El lenguaje de programación C*) que se convirtio en el primer estándar.

* **ANSI C89**: El estandar publicado por el Instituto Nacional Estadounidense de Estándares (*American National Standards Institute*)

* **ISO C99**: Se agrega muchos tipos de datos, incluyendo long long int, y  un tipo *complex* para números complejos.

* **ISO C11**: el último estándar publicado para *C*.


Herramientas
------------

* **gcc**, compilador de *C*
* **gdb**, debugger
* **make**
* Editor de texto
* **Valgrind**, para verificar errores con el manejo de memoria
* **Doxygen**, para la documentación
* **gprof**, un profiler


Compilador de *C*
-----------------

.. Las computadoras solo entienden un lenguaje, el lenguaje de maquina, una secuencia binaria de 0's y 1's. 

Para convertir nuestro codigo *C* en lenguaje maquina usamos un **compilador**.

.. literalinclude:: ../src/hello.c
    :language: c

.. slide:: 

.. code-block:: sh

    $ ls
    hola.c
    $ gcc hola.c -o hola
    $ ls
    hola     hola.c
    $ ./hola 
    Hola mundo!


Sintaxis
--------

* asignaciones
* declariación de variables y tipos de datos
* aritmetica basica
* condicionales
* ciclos
* comentarios
* funciones
* paso de parámetros
* apuntadores

Asignaciones
------------

.. code-block:: c

    radio = a/b;

* Calcula el valor de *a* entre *b* y lo coloca en *radio*. 
* Hay un punto y coma al final de la linea.

Declariación de variables  y tipos de datos
-------------------------------------------

.. code-block:: c

    int distance = 100;
    float power = 2.345f;
    double super_power = 56789.4532;
    char initial = 'A';
    char first_name[] = "Bruce";
    char last_name[] = "Wayne";

* int  - 32 bits (4 bytes) 
* float - 32 bits (4 bytes)
* double - 64 bits (8 bytes)
* char - un byte (8 bits)
* char name[]

Aritmetica basica
-----------------

.. code-block:: c

    int bugs = 100;
    double bug_rate = 1.2;
    expected_bugs = bugs * bug_rate;


* \+   suma
* \-   resta
* \*   multiplicación
* \/   divición
* \%   modulo

\* y \/ son evaluados antes que \+ y \-

Incrementos
-----------
Es muy comun tener expresiones de la forma  a = a + b , tan comun que *C* tiene una sintaxis especial para ello

.. code-block:: c

    a += b;

.. code-block:: c

    a -= b;
    a *= b;
    a /= b;
    a %= b;

La operación mas comun de estas es incrementar o decrementar por uno, asi que *C* ofrece:

.. code-block:: c

    a++;
    a--;


Condiciones
-----------

Si una expresion es cero, entonces es falsa. De otra manera es verdadera.

.. code-block:: c

    (a > b)
    (a < b)
    (a >= b)
    (a <= b)
    (a == b)
    (a != b)
    (a && b)
    (a || b)
    (!a)

Condicionales
-------------

.. code-block:: c

    if (a > 0){
        b = sqrt(a);
    }
    else {
        b = 0;
    }


ciclos
------

.. code-block:: c

    int i = 0;
    while(i < 5){
        printf("Hola.\n");
        i++;
    }

.. code-block:: c

    for(i=0; i < 5; i++){
        printf("Hola.\n");
    }

.. code-block:: c

    i = 0;
    do{
        printf("Hola.\n");
        i++;
    } while(i < 5);


comentarios
-----------

.. code-block:: c

    /* Comentarios largos que comienzan con slash-star,
       continuan tantas lineas como quieras.
       */
    

.. code-block:: c

    // Cualquier texto en una linea
    // despues de dos slashs
    // sera ignorado


printf
------

.. code-block:: c

    int position = 3;
    char name[] = "Pedro";
    printf("%s es el número %i en la fila\n", name, position);


* *%i* inserta un entero
* *%g* inserta un numero real
* *%s* inserta una cadena
* *\\n* inserta un salto de linea
* *\\t* inserta un tab


.. slide:: 

.. literalinclude:: ../src/printtypes.c
    :language: c

Como se ve un programa en *C*?
------------------------------

Bibliotecas a incluir

.. code-block:: c

    #include <stdio.h>

Funciónes

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

Argumentos
++++++++++

.. literalinclude:: ../src/arguments.c
    :language: c



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

    int main(int argc, char *argv[])
    {
        int a = 4;
        int b = 8;
        swap(a, b);
        printf("valor de a: %i\n", a);
        printf("valor de b: %i\n", b);
        return 0;
    }

Solución
========

.. code-block:: c

    #include <stdio.h>

    void swap(int *x, int *y)
    {
        int temp;

        temp = *x;
        *x = *y;
        *y = temp;
    }

    int main(int argc, char const *argv[])
    {
        int a = 4;
        int b = 8;
        swap(&a, &b);
        printf("valor de a: %i\n", a);
        printf("valor de b: %i\n", b);
        return 0;
    }


Juez  -  http://online-judge.uva.es/
------------------------------------

* Accepted (AC) — Your program is correct, and runs within the given time and memory limits.
* Wrong Answer (WA) — This you should concern you, because your program returned an incorrect answer to one or more of the judge’s secret test cases. You have some more debugging to do.
* Compile Error (CE) — The compiler could not figure out how to compile your program.
* Runtime Error (RE) — Your program failed during execution due to a segmen- tation fault, floating point exception, or similar problem.
* Time Limit Exceeded (TL) — Your program took too much time on at least one of the test cases, so you likely have a problem with efficiency. 
