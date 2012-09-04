Interprete
==========

Una computadora tiene 10 registros y 1000 localidades de RAM. Cada registro o localidad
de RAM puede guardar un entero entre 0 y 999. Las instrucciones son codificadas como enteros
de 3-digitos y son guardadas en RAM. La codificación es la siguiente:

* 100 detenerse
* 2dn guarda en el registro **d** el valor de **n** (entre 0 y 9)  
* 3dn suma **n** al registro **d**
* 4dn multiplica por **n** el registro **d** 
* 5ds copia el valor del registro **s** en el registro **d**
* 6ds suma el valor del registro **s** al registro **d**
* 7ds multiplica el registro **d** por el valor del registro **s**  
* 8da guarda el valor de la localidad de memoria cuya dirección esta en el registro **a** en el registro **d**
* 9sa guarda en la localidad de memoria cuya dirección esta en el registro **a** el valor del registro **s**
* 0ds muevete a la localidad indicada por el registro **d** amenos que el registro **s** sea 0.

Todos los registros inician en 000. El cotenido de la RAM se lee de la entrada estandar.
La primera instrucción a ser ejecutada esta en la direccion de memoria 0. Todos los resultados
son reducidos modulo 1000.

Entrada
-------
La entrada comineza con un entero positivo en una linea indicando el número de prueba
Esta linea es seguida de una linea en blanco y tambien hay una linea en blanco entre dos entradas consecutivas.

La entrada del programa consiste de hasta 1000 enteros de 3-digitos, representando el contenido de la RAM comensando en 0. Las localidades que no se especifiquen se  inicializan en 000.

Salida
------
La salida de es un entero: el número de instrucciones ejecutadas hasta detenserse (inclusive).
Puedes asumir que el programa se detendra.

La salida de dos pruebas consecutivas sera separada por una linea en blanco.


Ejemplo de Entrada
==================

.. code-block:: c

    1

    299
    492
    495
    399
    492
    495
    399
    283
    279
    689
    078
    100
    000
    000
    000

Ejemplo de Salida
=================

.. code-block:: c

    16
