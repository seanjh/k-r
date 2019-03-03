#include <stdio.h>

#define MAX_TEMP_F  300
#define MIN_TEMP_F  0
#define STEP_TEMP_F 20

int convert(int temp_fahr) {
  return (temp_fahr - 32) * 5 / 9;
}

int main() {
  for (int i = MIN_TEMP_F; i <= MAX_TEMP_F; i += STEP_TEMP_F) {
    printf("%dF\t%dC\n", i, convert(i));
  }
}
