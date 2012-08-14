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

fopen
-----

.. code-block:: c

    FILE *archivo_de_entrada = fopen("input.txt", "r");

.. code-block:: c

    FILE *archivo_de_salida = fopen("output.txt", "w");

.. code-block:: c

    FILE *archivo_de_salida = fopen("output.txt", "a");

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

