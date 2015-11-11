#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "vectors.h"

int main(void) {
  srand(time(NULL));

  struct doubleVector a = vector_alloc(5);
  struct doubleVector b = vector_alloc(5);
  struct doubleVector c = vector_alloc(5);

  for(int i = 0; i < 5; ++i) {
    a.data[i] = 1.0;
    b.data[i] = 2.0;
    c.data[i] = 3.0;
  }

  struct doubleVector a2 = vector_clone(&a);
  struct doubleVector b2 = vector_clone(&b);
  struct doubleVector c2 = vector_clone(&c);

  scalar_fma(&a, &b, &c);
  printf("Scalar result: ");
  vector_display(&a);

  vector_fma(&a2, &b2, &c2);
  printf("\nVector result: ");
  vector_display(&a2);
  printf("\n");

  free(a.data);
  free(b.data);
  free(c.data);
  free(a2.data);
  free(b2.data);
  free(c2.data);
}
