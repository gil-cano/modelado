O: dah dah dah!
===============

El código morse es un método de transmisión de información sin el uso de los símbolos comunes. 
La información es representada con un alfabeto binario compuesto de beeps cortos y largos. 
El beep corto se conoce como dih y el beep largo como dah. 
Dado que la codificación contiene prefijos tenemos un tercer símbolo, el silencio. 
El código entre dos letras es silencio y el código entre dos palabras es doble silencio.

EL objetivo es traducir un mensaje en código morse. Las señales han sido digitalizadas de la siguiente manera:

* dih es representado por .
* dah es representado por -
* silencio es representado por espacio
* doble silencio es representado por doble espacio


.. code-block:: c

    Symbol  Code     Symbol  Code        Symbol  Code
    A       .-       S       ...         .       .-.-.-      
    B       -...     T       -           ,       - -..- -    
    C       -.-.     U       ..-         ?       ..- -..     
    D       -..      V       ...-        '       .- - - -.   
    E       .        W       .- -        !       -.-.- -     
    F       ..-.     X       -..-        /       -..-.       
    G       - -.     Y       -.- -       (       -.- -.      
    H       ....     Z       - -..       )       -.- -.-     
    I       ..       0       - - - - -   &       .-...       
    J       .- - -   1       .- - - -    :       - - -...
    K       -.-      2       ..- - -     ;       -.-.-.
    L       .-..     3       ...- -      =       -...-
    M       - -      4       ....-       +       .-.-.
    N       -.       5       .....       -       -....-
    O       - - -    6       -....       _       ..- -.-
    P       .- -.    7       - -...      "       .-..-.
    Q       - -.-    8       - - -..     @       .- -.-.
    R       .-.      9       - - - -.  

Entrada
-------
La primera linea da el número de mensajes, T (1 <= T <= 10). 
Cada mensaje es una secuencias de puntos, guiones y espacios.
Cada mensaje esta en una linea. El tamaño máximo del mensaje es 2000.

Salida
------
La salida es un párrafo por mensaje. El párrafo correspondiente al n-esimo mensaje comienza con el texto
'Message #n' en una linea. El mensaje decodificado aparece en la siguiente linea. Dos párrafos son separados por una linea en blanco.
El mensaje se debe mostrar en mayúsculas.


Ejemplo de Entrada
------------------
.. code-block:: c

    2
    ... --- ...
    .--- --- -...  -.. --- -. .  ..--..  ..-. .. -. . -.-.--


Ejemplo de Salida
-----------------

.. code-block:: c

    Message #1
    SOS

    Message #2
    JOB DONE ? FINE!

