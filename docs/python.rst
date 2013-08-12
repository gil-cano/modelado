Python
======

.. ifslides::

   .. figure:: /_static/python.png
      :class: fill

.. ifnotslides::

   Este documento es una breve introducción a Python.

Indice
------

* ¿Que es Python?
* Sintaxis basica
* modulos estandar y de terceros


¿Que es Python?
---------------

Python es un lenguaje interpretado

(el interprete de *python* lee archivos *\*.py*)

* Lenguaje de proposito general
* Fácil de aprender
* Muy conocido y usado
* Multi-plataforma
* Poderoso
* Rapido (comparado con otros lenguajes de script)
* Dinámicamente tipado

Interpretes y Compiladores
--------------------------

Un interprete lee un programa y lo ejecuta. Procesa el programa leyendo una linea  a
la vez y la ejecuta.

   .. figure:: /_static/interpret.png

Un copilador lee el programa completo y lo traduce antes de que el programa se ejecute. 

   .. figure:: /_static/compile.png

Versiones
---------

* Python 2.4, 2.5, 2.6
* Python 2.7
* Python 3.0, 3.3 (aka Python 3000)
   * Incompatible con Python 2.x en algunos aspectos 
   * reorganización y "limpieza"
   * No ha sido adoptado por la mayoria de los proyectos


¿Cuando usar Python?
--------------------

* Manejo de archivos
* Generación de datos
* Analisis de datos
* Applicaiones Web
   - Plone, Django, Pyramid, web2py, Zope, Flask, ...
* Aplicaicones graficas (GUI)
* ...


The Zen of Python (Tim Peters)
------------------------------

El código que sigue los principios de Python de legibilidad y transparencia se dice que es "pythonico"

::

   >>> import this



The Zen of Python (Tim Peters)
------------------------------

::

   >>> import this
   Beautiful is better than ugly.
   Explicit is better than implicit.
   Simple is better than complex.
   Complex is better than complicated.
   Flat is better than nested.
   Sparse is better than dense.
   Readability counts.
   Special cases aren't special enough to break the rules.
   Although practicality beats purity.
   Errors should never pass silently.
   Unless explicitly silenced.
   In the face of ambiguity, refuse the temptation to guess.
   There should be one-- and preferably only one --obvious way to do it.
   Although that way may not be obvious at first unless you're Dutch.
   Now is better than never.
   Although never is often better than *right* now.
   If the implementation is hard to explain, it's a bad idea.
   If the implementation is easy to explain, it may be a good idea.
   Namespaces are one honking great idea -- let's do more of those!


El Interprete de Python
-----------------------

* Ejecuta *python* en la linea de comandos ::

    $ python
    Python 2.7.1 (r271:86832, Jul 31 2011, 19:30:53)
    Type "help", "copyright", "credits" or "license" for more information.
    >>> 

* Util para probar cosas ::

    >>> print 'Hola, Mundo!'
    Hola, Mundo!


El Interprete de Python
-----------------------

* Calculadora instantanea! ::

    >>> 64*8
    512

* Sentencias en multiples lineas ::

    >>> for i in range(3):
    ...     print "El valor de i es:", i
    ... 
    El valor de i es: 0
    El valor de i es: 1
    El valor de i es: 2


Sentencias
-----------

* Una sentencia por linea (no se usa **;**)
* Sitaxis sensible a mayúsculas y minúsculas
* sentencias multiples en una linea se separan por **;** ::

    >>> import pdb; pdb.set_trace()

* Una sentencia puede usar mas de una linea usando **\\** al final de cada linea ::

    >>> if a == 0 and \
    ...     b != 1:
    ...     print 'a es 0, pero b no es 1'


Bloques
-------

* No usa llaves **{** **}**
* Los bloques se indentan
* Python es sensible a los espacios
* Configura tu editor para remplazar tabs por 4 espacios ::

    >>> if a != b:
    ...     print "dentro del bloque"
    ...     print "seguimos en el bloque"
    >>> print "salimos del bloque"


Archivos y modulos
------------------

* Los scripts de Python son guardados en archivos **.py**, y se ejecutan con el interprete ::

    $ python test.py

* Los archivos se ejecutan de inmediato de arriba a abajo
* A cada archivo se le llama modulo
* Los modulos se pueden juntar en paquetes
* Un paquete es un directorio con un archivo magico llamado *__init__.py*
    (puede ser vacio o contener código)


Archivos y modulos
------------------

* Los modulos pueden importar otros modulos

::

    >>> from csv import DictReader  # un modulo de una biblioteca estandar
    >>> reader = DictReader(...)     # lo usamos
    >>> import mymodule             # un modulo en el paquete actual
    >>> mymodule.someobj             # notacion .
    >>> from somemodule import *   # importamos todo (mala practica)


Sentencia print
---------------

* Util para aplicaciones simples
* Argumentos multiples separados por espacios en la salida ::

    >>> print "Hola", "Mundo"
    Hola Mundo

* podemos escribir a un archivo ::

    >>> outfile = open('outfile.txt', 'w')
    >>> print >>outfile, "Hola, Mundo"


Variables
---------

* Se crean automaticamente
* Los nombres de variables empiezan con una letra o guion bajo.
  Pueden contener números, letras y guion bajo
* Las cadenas pueden usar comillas simples o dobles
* Los enteros son simples números, los enteros largos (long) se siguen de una **L**,
  los flotantes usan punto
* Las variables reciben un typo dinamicamente.
  Una misma variable puede tomar valores de distinto tipo en distintos momentos
* El chequeo de tipos se realiza durante el tiempo de ejecución


Variables
---------

::

    >>> x = 10
    >>> _s = 'Hello ' + "world“ + str(x)  # also, int(), float()
    >>> _s
    'Hello world10'
    >>> type(3L)
    <type 'long'>
    >>> type(x)
    <type 'int'>
    >>> x = 10.0
    >>> type(x)
    <type 'float'>


Palabas reservadas
------------------

::

    and       as      assert   break      class    continue
    def       del     elif     else       except   exec
    finally   for     from     global     if       import
    in        is      lambda   nonlocal   not      or
    pass      raise   return   try        while    with
    yield     True    False    None


Operadores
----------

* Los missmos que C: +, -, \*, /, %
* Operadores de asignación: +=, -=, \*=, /=, %=  (no tiene --, ++) ::

    >>> x = 4
    >>> x += 2
    >>> x
    6

* Potencia:\*\*
* Multiplicación de cadenas ::

    >>> 2 ** 3
    8
    >>> "hey" * 3
    'heyheyhey'


Operadores Booleanos
--------------------

* Como C, tiene: ==, !=, <, >, <=, >=
* A diferencia de C, usa **and**, **or**, **not** como operadores lógicos
* Define conatantes **True** y **False**
* La constante **None** es una contante especial "sin valor" (null)
* **0**, **""** (cadena vacia) y **None**  se evaluan a **False** ::

    >>> 1 == 2
    False
    >>> 1 == 1 and 2 == 2 True
    >>> 1 != 1 or 2 != 3 True

Operadores Booleanos
--------------------

* **in** (y **not in**)
  Verifica si un valor esta en una sequiencia (cadena, lista, tupla) 

::

    >>> 'H' in "Hola"
    True
    >>> 'H' not in "Hola"
    False


Cadenas
-------

* Las cadenas se enciarran con comillas simples o dobles
* Las comillas triples permiten cadenas de multiples lineas ::

     >>> s = """una cadena
     ... en avarias lineas"""

* Caracters especiales se escapan con \\
* Las cadenas son imutables (como en Java),
  si concatenas cadenas un nuevo objeto cadena es creado
* Las cadenas on ASCII por default. Usa **u""** para unicode 

Cadenas
-------

* Las cadenas pueden usar la sintaxis de printf() ::

     >>> numlines = 3
     >>> filename = "myfile.txt"
     >>> "Quiero %02d lineas de %s." % (numlines, filename)
     "Quiero 03 lineas de myfile.txt."


Operadores de Cadenas
---------------------

* Todos estos metodos regresan una nueva cadena
* ver http://docs.python.org/lib/string-methods.html ::

    >>> "hola".upper() # lower()
    'HOLA'
    >>> "hola".capitalize()
    'Hola'
    >>> ' hola '.strip()
    'hola'
    >>> 'hola'.replace('l', y')
    'hoya'
    >>> 'uno,dos,tres'.split(',') # por default parte por espacios
    ['uno', 'dos', 'tres']
    >>> ','.join(['uno', 'dos', 'tres'])
    'uno,dos,tres'


Números
-------

* divición entera
* Si se usa un float el resultado es float ::

    >>> 5 / 2
    2
    >>> 5 / 2.0
    2.5

* puedes hacer un cast con **float()**, **int()**, **long()**, **str()**,
  **list()**, **tuple()**  

::

     >>> float(5/2)
     2.0
     >>> float(5) / 2
     2.5


Listas y tuplas
---------------

* Las listas se definen entre corchetes y pueden modificarse ::

     >>> mylist = [1,2]
     >>> mylist.append(3)
     >>> mylist
     [1, 2, 3]

• Las tuplas se definen entre parentesis y no pueden modificarse ::

    >>> mytuple = (1, 2, 3)
    >>> mytuple += (4, 5) # nueva tupla
    >>> mytuple
    (1, 2, 3, 4, 5)
    >>> (4)     # ojo no regresa una tupla, usa (4,)
    4


Indices y rebanadas
-------------------

    >>> data = ['a', 'b', 'c', 'd']
    >>> data[1]
    'b'
    >>> data[0:2]
    ['a','b']
    >>> data[1:3]
    ['b', 'c']
    >>> data[2:]
    ['c','d']
    >>> data[:2]
    ['a','b']

    >>> data[-1]
    'd'
    >>> data[1:-2]
    ['b']
    >>> data[-2:]
    ['c', 'd']


Métodos de listas
-------------------

    >>> len([1,2,3])
    3

    >>> x = [1,2,3]
    >>> x.reverse()
    >>> x
    [3, 2, 1]

    >>> x.sort()
    >>> x
    [1, 2, 3]

    >>> y = x  # las listas pasan por referencia
    >>> y.append(4)
    >>> x
    [1, 2, 3, 4]

Métodos de listas
-------------------

     >>> x = ['a', 'b', 'c']
     >>> x.index('b')
     2

    >>> x.append('d')
    >>> x
    ['a', 'b', 'c', 'd']
    >>> x.remove('b')
    ['a', 'c', 'd']
    >>> del x[0]
    ['c', 'd']
    >>> x.insert(1, 'e')
    ['c', 'e', 'd']

Diccionarios
------------

* Guarda parejas llave-valor
* Las llaves pueden ser de casi cualquier tipo, no tienen que ser del mismo tipo
* Los valores pueden ser de cualquier tipo
* El Acceso es O(1) ::

    >>> d = {}
    >>> d['one'] = 1
    >>> d['two'] = 2 
    >>> 'one' in d
    True
    >>> d.keys()
    ['one', 'two'] 
    >>> d.values()
    [1, 2]


Métodos de Diccionarios
-------------------------

    >>> d.items()
    [('two', 2), ('one', 1)]

    >>> del d['one']
    >>> d
    {'two' : 2}

    >>> d['two']
    2
    >>> d['one']
    Traceback (most recent call last):
      File "<input>", line 1, in <module>
    KeyError: 'one'


Métodos de Diccionarios
-------------------------

    >>> d.get('foo', 'default')
    'default'
    >>> d.get('two', 'default')
    2

    >>> d.setdefault('bar', 'newvalue')
    'newvalue'
    >>>d
    {'bar': 'newvalue', 'two': 2}

    >>> d.setdefault('two', 'newvalue')
    2
    >>>d
    {'bar': 'newvalue', 'two': 2}


Condicionales
-------------

* **if**, **elif** y **else**
* Indenta los bloques
* Las sentencias condiconales terminan con **:** ::

    >>> if 1 == 2:
    ...     print "pigs can fly"
    ... elif 'a' == 'A' or 'b' == 'B':
    ...     print "no, we're case sensitive"
    ... else:
    ...      print "world is sane"
    ...
    world is sane

Ciclos y rangos
---------------

    >>> for x in [1,2,3]:
    ...     if x == 1: continue
    ...     print "What you wanted was", x
    ...     if x == 2: break
    What you wanted was 2

    >>> arr = ['a', 'b', 'c']
    >>> for idx in range(3):
    ...     print "At", idx, "we have", arr[idx]
    At 0 we have a
    At 1 we have b
    At 2 we have c

Ciclos y rangos
---------------

    >>> import random
    >>> max = random.randint(0, 10)
    >>> counter = 0
    >>> while counter <= max:
    ...     print "Ok, we have", counter
    ...     counter += 2


Listas
------

    >>> [i * 2 for i in range(4)]
    [0, 2, 4, 6]

    >>> x = ['A', 'BB', 'CC', 'D', 'EE', 'F'] 
    >>> [c.lower() for c in x if len(c) == 2] 
    ['bb', 'cc', 'ee']


Funciónes
---------

* Se deinen con **def**, toman cero o mas argumentos, pueden regresar un valor o no ::

    >>> def add_two_numbers(x, y):
    ...     return x + y

• Se llaman por nombre y opcionalmente usan las llaves de argumento ::

    >>> add_two_numbers(1, 2)
    3
    >>> add_two_numbers(y=3, x=2)
    5

Funciónes
---------

* posicion variable de los argumentos  ::

    >>> def print_args(x, *args, **kwargs):
    ...     print x, "and", args, "and", kwargs

    >>> print_args(1, 2, 3, a=2, b=3)
    1 and (2, 3) and {'a': 2, 'b': 3}
    
    >>> print_args(1, 2, 3, 4, a=2, b=3)
    1 and (2, 3, 4) and {'a': 2, 'b': 3}

 