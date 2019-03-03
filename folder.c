#include <assert.h>
#include <stdio.h>

#define MAX_LENGTH 30
#define OK 0
#define DEBUG 0

/*
 * Initialize a char array.
 */
void clear_buffer(char buff[], int len) {
  for(int i = 0; i < len; ++i) {
    buff[i] = 0;
  }
}

/*
 * Return the int index of the last non-blank char.
 */
int last_non_blank(char buff[], int i) {
  char c;
  for ( ; i >= 0; --i) {
    c = buff[i];
    if (c != ' ' && c != '\t' && c) {
      break;
    }
  }
#if DEBUG
  printf("Found last characer at index %d: '%c'\n", i, buff[i]);
#endif
  return i;
}

/*
 * Print len total characters from buff.
 */
void dump_line(char buff[], int len) {
  char c;
  for (int i = 0; i < len; ++i) {
    c = buff[i];
    putchar(c);
  }

  if (c != '\n')
    putchar('\n');

  clear_buffer(buff, len);
}

/*
 * Shift elements starting at i to the start of buff.
 * Return the length of the shift.
 *
 * Examples:
 *  {0, 1, 2, 3, 4} i=0, len=5 -- {0, 1, 2, 3, 4} j=5
 *  {0, 1, 2, 3, 4} i=1, len=5 -- {1, 2, 3, 4, X} j=4
 *  {0, 1, 2, 3, 4} i=4, len=5 -- {4, X, X, X, X} j=1
 */
int shift_buff(char buff[], int i, int len) {
  assert (i >= 0 && i <= len);
#if DEBUG
  printf("Shifting buffer starting at index %d (%p)\n", i, buff + i);
#endif

  int shift_len = 0;
  for ( ; i < len; ++i) {
    buff[shift_len] = buff[i];
    ++shift_len;
  }
#if DEBUG
  printf("Shifted %d chars\n", shift_len);
#endif
  assert (shift_len <= len);

  if (shift_len > 0 && len - shift_len > 0) {
    char *ptr = buff + (char) shift_len;
    clear_buffer(ptr, len - shift_len);
  }

  return shift_len;
}

int main(int argc, const char* argv[]) {
  char buff[MAX_LENGTH];
  clear_buffer(buff, MAX_LENGTH);

  int i = 0;
  int c;

  for ((c = getchar()); c != EOF; c = getchar()) {
#if DEBUG
    printf("Loading char '%c' in buff[%d]\n", c, i);
#endif
    buff[i] = c;

    if (c == '\n') {
#if DEBUG
      printf("Handling newline\n");
#endif
      dump_line(buff, i + 1);
      i = 0;

    } else if (i + 1 == MAX_LENGTH) {
#if DEBUG
      printf("Handling MAX_LENGTH\n");
#endif
      int j = last_non_blank(buff, i);
      dump_line(buff, j + 1);
      if (j < i) {
        int shift_len = shift_buff(buff, j + 1, MAX_LENGTH);
        i = shift_len - 1;
      } else {
        i = 0;
      }

    } else {
      ++i;
    }

  }

  return OK;
}
