#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vectors.h"

int main(int argc, char ** argv) {
  if (argc == 1 || (argc - 1) % 3 != 0) {
    printf("usage: ./scalar_fma [floats]\n");
    return 1;
  }

  int length = (argc - 1) / 3;
  struct doubleVector a = vector_alloc(length);
  struct doubleVector b = vector_alloc(length);
  struct doubleVector c = vector_alloc(length);

  int firstIndex = 1;
  int secondIndex = 1 + length;
  int thirdIndex = 1 + (2 * length);
  for(int i = 0; i < length; ++i) {
    a.data[i] = strtod(argv[firstIndex++], NULL);
    b.data[i] = strtod(argv[secondIndex++], NULL);
    b.data[i] = strtod(argv[thirdIndex++], NULL);

    // Check validity of arguments
    if (a.data[i] == 0.0 || b.data[i] == 0.0 || c.data[i] == 0.0) {
      printf("Unparsable double encountered.\n");
      return 2;
    }
  }

  printf("a: ");
  vector_display(&a);
  printf("\nb: ");
  vector_display(&b);
  printf("\nc: ");
  vector_display(&c);

  printf("\nResult: ");
  scalar_fma(&a, &b, &c);
  vector_display(&a);
  printf("\n");

  free(a.data);
  free(b.data);
  free(c.data);
}
