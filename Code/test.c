#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

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

  printf("Comparison: %s\n", vector_compare(&v1, &v2) ? "true" : "false");
  v1.data[0] += 5;
  printf("Second comparison: %s\n", vector_compare(&v1, &v2) ? "true" : "false");

  free(v1.data);
  free(v2.data);
}
