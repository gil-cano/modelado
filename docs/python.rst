Python
======

.. slides::

   .. figure:: /_static/python.png
      :class: fill

.. notslides::

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

* No usa **{** **}**
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

• Strings literals are enclosed in single or double quotes (no difference).
• Triple-quotes allow string literals over multiple lines.
 >>> s = """a string
 ... on multiple lines"""
• Special characters escaped with \, e.g. "a backslash is \\".
• ... except in raw strings: marked with r"" (useful for regular expressions etc.)
• Strings are immutable (like Java) – if you concatenate strings, a new string object is allocated (see buffer()).
• Strings are ASCII by default. Unicode string literals are marked by u"".
• All strings can use printf() style interpolation
 >>> numlines = 3
 >>> filename = "myfile.txt"
 >>> "I want %02d lines from %s." % (numlines, filename)
 "I want 03 lines from myfile"


Operadores de Cadenas
---------------------

• These all allocate and return new strings
• See http://docs.python.org/lib/string-methods.html
>>> "hello".upper() # also lower() 'HELLO'
>>> "hello".capitalize()
'Hello'
>>> ' hello '.strip()
'hello'
>>> 'hello'.replace('l', y')
'heyyo'
>>> 'one,two,three'.split(',') # default is to split on whitespace ['one', 'two', 'three']
>>> ','.join(['uno', 'dos', 'tres'])
'uno,dos,tres'


Números
-------

• Integer division truncates
>>> 5 / 2 5
• Any floating point number in a calculation will cause type promotion
>>> 5 / 2.0 2.5
• Can type cast with float(), int(), long(), str(), list(), tuple()
 >>> float(5/2)     # only casts the result
 2.0
 >>> float(5) / 2   # invokes type promotion
 2.5


Listas y tuplas
---------------

• Lists are mutable, enclosed in square brackets
 >>> mylist = [1,2]
 >>> mylist.append(3)
 >>> mylist
 [1, 2, 3]
• Tuples are immutable, enclosed in parentheses
>>> mytuple = (1, 2, 3)
>>> mytuple += (4, 5) # allocates a new tuple >>> mytuple
(1, 2, 3, 4, 5)


Indices y rebanadas
-------------------

• Apply to lists and strings (and other sequence types).
• Sequences are zero-based
• Select a (possibly open-ended) range of items.
• Start index goes before the colon; after colon is one-past-last-index
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

• Negative numbers count from the end of the sequence
 >>> data = ['a', 'b', 'c', 'd']
 >>> data[-1]
 'd'
 >>> data[1:-2]
 ['a', 'b']
 >>> data[-2:]
 ['c', 'd']


Funciones de Listas
-------------------

• Length of a list or string
 >>> len([1,2,3])
 3
• Reverse, sort a list in-place (do not return a value)
 >>> x = [1,2,3]
 >>> x.reverse()
 >>> x
 [3, 2, 1]
 >>> x.sort()
 >>> x
 [1, 2, 3]
• Lists are passed by reference
 >>> y = x
 >>> y.append(4)
 >>> x
 [1, 2, 3, 4]

• Find an element with index():
 >>> x = ['a', 'b', 'c']
 >>> x.index('b')
 2
• Append, remove, insert:
 >>> x.append('d')
 >>> x
 ['a', 'b', 'c', 'd']
 >>> x.remove('b')
 ['a', 'c', 'd']
 >>> del x[0]
 ['c', 'd']
 >>> x.insert(1, 'e')
 ['c', 'e', 'd']


List comprehensions
-------------------

• Build a list on the fly, optionally with a filter
>>> [i * 2 for i in range(4)] [0, 2, 4, 6]
>>> x = ['A', 'BB', 'CC', 'D', 'EE', 'F'] >>> [c.lower() for c in x if len(c) == 2] ['bb', 'cc', 'ee']

Diccionarios
------------

• Store key-value pairs
• Keys can be (almost) anything, don't all have to be of the same type (but normally they should be)
• Values can be anything, of any type
• Access is O(1)
>>> d = {}
>>> d['one'] = 1 >>> d['two'] = 2 >>> 'one' in d True
>>> d.keys() ['one', 'two'] >>> d.values() [1, 2]


Funciones de Dictionarios
-------------------------

• Loop over items in a dict with items(). Note that dicts are unordered! >>> x = {'one' : 1, 'two' : 2}
 >>> for k, v in x.items():
 ...    print "key", k, "is", v
 key one is 1
 key two is 2
• Delete an item:
 >>> del x['one']
 >>> x
 {'two' : 2}
• Not sure if it's there? Use get(): >>> x.get('foo', 'default')
 'default'
 >>> x.get('one', 'default')
 1
• Create if not there – use setdefault()
>>> x.setdefault('bar', 'newvalue') 'newvalue'


Conjuntos
---------

• Like dicts without values. Still unordered! A frozenset is immutable and faster. >>> x = set([1,2,3])
>>> for v in x:
... print "item", v
 item 1
 item 3
 item 2
• Add an item:
 >>> x.add(4)
 >>> x.update([2,4,6]) # can be any iterable
• Delete an item:
 >>> x.remove(1)
 >>> x
 set([2,3,4,6])
• Intersection, difference, subtraction
 >>> y = set([2,4,6])
 >>> x.intersection(y) # try also union(), difference()
 set([2,4,6])


Condicionales
-------------

• Useif,elifandelse. • Blocks are indented.
• Conditional statement ends with a colon:
 >>> if 1 == 2:
 ...     print "pigs can fly"
 ... elif 'a' == 'A' or 'b' == 'B':
 ...     print "no, we're case sensitive"
 ... else:
...
print "world is sane"


Ciclos y rangos
---------------

• Main type of loop is for – loop over the items in a sequence • Can use break or continue to terminate or re-loop
 >>> for x in [1,2,3]:
 ...     if x == 1: continue
 ...     print "What you wanted was", x
 ...     If x == 2: break
 What you wanted was 2
• Can use range() to generate a list of indexes (or other sequence of integers)
 >>> arr = ['a', 'b', 'c']
 >>> for idx in range(3): # results in [0,1,2]
 ...     print "At", idx, "we have", arr[idx]
 At 0 we have a
 At 1 we have b
 At 2 we have c

 • Other type of loop is while. There is no do-while loop.
• Loops until condition is False, break and continue still work
 >>> import random
 >>> max = random.randint(0, 10) # random int, 0-10
 inclusive
 >>> counter = 0
 >>> while counter <= max:
... ...
print "Ok, we have", counter
counter += 2


Funciones
---------

• Defined with def, take zero or more arguments, may or may not return >>> def add_two_numbers(x, y):
 ...     return x + y
• Call by name – optionally use keyword arguments
 >>> add_two_numbers(1, 2)
 3
 >>> add_two_numbers(y=3, x=2)
 5
• Variable positional and keyword arguments – read as lists, dicts
 >>> def print_args(x, *args, **kwargs):
 ...     print x, "and", args, "and", kwargs
 >>> print_args(1, 2, 3, a=2, b=3)
 1 and (2, 3) and {'a': 2, 'b': 3}

 