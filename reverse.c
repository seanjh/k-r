#include <stdio.h>

#define MAX_LENGTH 1000
#define OK 0

int reverse(char line[], int num) {
  int i, j;
  i = 0;
  j = num;
  /*printf("reading from %p between %d and %d\n", line, i, j);*/

  int tmp;
  while (i < j) {
    /*printf("Swapping %c with %c (%d<->%d)\n", line[i], line[j], i, j);*/
    tmp = line[j];

    line[j] = line[i];
    line[i] = tmp;

    ++i;
    --j;
  }

  return OK;
}

int main(void) {
  char line[MAX_LENGTH + 1];
  for (int i = 0; i < MAX_LENGTH + 1; i++) {
    line[i] = 0;
  }

  int c;
  for (int i = 0; i < MAX_LENGTH; ++i) {
    c = getchar();

    if (c == '\n') {
      reverse(line, i - 1);
      line[i] = 0;
      i = 0;  // reset line index
      printf("%s\n", line);

    } else if (c == EOF) {
      break;

    } else {
      line[i] = c;
    }

  }

  return OK;
}
