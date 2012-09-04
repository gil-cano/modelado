El problema  **3n + 1**
=======================

Considera el siguiente algoritmo para generar una secuencia de numeros.
Comenzamos con un entero **n**. Si **n** es par, lo dividimos entre 2.
Si **n** es impar, lo multiplicamos por **3** y le sumamos **1**.
Repetimos este proceso con el nuevo valor de **n** y terminamos cuando **n = 1**.
Por ejemplo la siguiente secuencia de números es generada para **n = 22**

.. code-block:: c

    22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1

Dada una entrada **n**, la longitud de ciclo de **n** es el número de números
generado hasta **1**. En el ejemplo anterior la longitud de ciclo de **22** es **16**.

Dados dos números **i** y **j**, determinar la maxima longitud de ciclo sobre todos
los números entre **i** y **j**, incluyendo los.

Entrada
-------

La entrada consiste en una serie de parejas de enteros **i** y **j**, una pareja de enteros por linea.
Todos los enteros seran menores que 1,000,000 y mayores que **0**.

Salida
------



.. code-block:: c

    1 10                       1 10 20
    100 200                    100 200 125
    201 210                    201 210 89
    900 1000                   900 1000 174
