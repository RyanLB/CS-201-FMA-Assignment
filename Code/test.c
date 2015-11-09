#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vectors.h"

int main(void) {
  srand(time(NULL));
  struct doubleVector v1 = random_vector(5);
  struct doubleVector v2 = vector_clone(&v1);

  printf("V1: ");
  vector_display(&v1);
  printf("\nV2: ");
  vector_display(&v2);
  printf("\n");

  free(v1.data);
  free(v2.data);
}
