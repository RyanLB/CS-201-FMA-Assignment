#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "vectors.h"

bool testWithLength(int length);

// This function prototype is the worst thing I have ever written
int perfTest(struct doubleVector *a,
              const struct doubleVector *b,
              const struct doubleVector *c,
              bool(*fma)(struct doubleVector *,
                         const struct doubleVector *,
                         const struct doubleVector *));

int main(void) {
  testWithLength(10000000); 
}

/*
 * bool testWithLength(int length)
 *
 * Creates three random vectors with the given length and times the performance of scalar_fma() and
 * vectorized_fma() with these vectors as input.
 *
 * Returns true if the results match.
 */
bool testWithLength(int length) {
  // Create (and clone) three vectors with the given length
  struct doubleVector a = random_vector(length);
  struct doubleVector b = random_vector(length);
  struct doubleVector c = random_vector(length);

  struct doubleVector a2 = vector_clone(&a);
  struct doubleVector b2 = vector_clone(&b);
  struct doubleVector c2 = vector_clone(&c);
  
 
  // Test scalar performance 
  //printf("Scalar result: ");
  //vector_display(&a);
  printf("\nScalar cycle count: %d\n", perfTest(&a, &b, &c, scalar_fma));
 
  // Test vector performance
  //printf("Vector result: ");
  //vector_display(&a2);
  //printf("\nVector time (seconds): %lf\n", diff.tv_sec + (double)diff.tv_usec / 1000000);

  // Compare results
  bool correct = vectorized_compare(a.data, a2.data, length);
  
  // Free dynamic resources
  free(a.data);
  free(b.data);
  free(c.data);
  free(a2.data);
  free(b2.data);
  free(c2.data);

  return correct;
}

// This function prototype is the worst thing I have ever written
int perfTest(struct doubleVector *a,
             const struct doubleVector *b,
             const struct doubleVector *c,
             bool(*fma)(struct doubleVector *,
                        const struct doubleVector *,
                        const struct doubleVector *)) {
  
  int startCycles = rdtsc();
  fma(a, b, c);
  int endCycles = rdtsc();
  return endCycles - startCycles;
}
