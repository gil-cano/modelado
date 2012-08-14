#include <stdio.h>


int main(int argc, char const *argv[])
{
  char c;
  FILE *in_file = fopen(argv[1], "r");
  while((c = getc(in_file)) != EOF) {
    putchar(c);
  }
  return 0;
}