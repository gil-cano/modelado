Introducción a C
================

.. ifslides::

   .. figure:: /_static/c_language.jpg
      :class: fill

.. ifnotslides::

   Este documento es una breve introducción al lenguaje C.

¿Que es C?
----------

*C* es un lenguaje tipificado, es decir que debemos especificar si una variable es de tipo
 entera, real, etc.

*C* es un lenguaje compilado

* Lenguaje de proposito general
* Fácil de aprender
* Muy conocido y usado
* Multi-plataforma
* Poderoso

Versiones
---------

* ISO C99
* POSIX

¿Cuando usar *C*?
-----------------



Herramientas
------------

* Compilador de *C*
* Debugger
* make
* bibliotecas de funciones

Compilador de *C*
-----------------

Las computadoras solo entienden un lenguaje, el lenguaje de maquina,
una secuencia binaria de 0's y 1's. Para convertir nuestro codigo *C*
en lenguaje maquina usamos un **compilador**.

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


Sintaxsis
---------

* asignaciones
* declariación de tipos
* aritmetica basica
* condicionales *if-then*
* ciclos
* comentarios

