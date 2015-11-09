#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "vectors.h"

int main(void) {
  srand(time(NULL));
  struct doubleVector v1 = randomVector(5);
  struct doubleVector v2 = vectorClone(&v1);

  printf("V1: ");
  vectorDisplay(&v1);
  printf("\nV2: ");
  vectorDisplay(&v2);
  printf("\n");

  free(v1.data);
  free(v2.data);
}
