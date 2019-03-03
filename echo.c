#include <stdio.h>

int main()
{
  printf("EOF: %d\n", EOF);

  int c;
  while ((c = getchar()) != EOF) {
    putchar(c);
  }
}
