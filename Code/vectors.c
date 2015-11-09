#include <stdio.h>
#include <stdlib.h>

#include "vectors.h"

struct doubleVector vectorAlloc(int length) {
  struct doubleVector dv;
  dv.length = length;
  dv.data = malloc(length * sizeof(double));
}

struct doubleVector randomVector(int length) {
  struct doubleVector dv = vectorAlloc(length);

  for(int i = 0; i < length; ++i) {
    int r1 = rand();
    int r2 = rand();
    dv.data[i] = (double) r1 / (double) r2;
  }
}

void vectorDisplay(const struct doubleVector * vec) {
  int length = vec->length;

  printf("[");
  if(length > 0) {
    for(int i = 0, j = length - 1; i < j; ++i) {
      printf("%f, ", vec->data[i]);
    }
    printf("%f", vec->data[length - 1]);
  }
  printf("]");
}
