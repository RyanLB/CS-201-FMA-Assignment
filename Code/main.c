#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "vectors.h"

int main(void) {
  
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
  
  // Structs to measure function performance
  struct rusage start;
  struct rusage end;
  struct timeval diff;
 
  // Test scalar performance 
  getrusage(RUSAGE_SELF, &start);
  scalar_fma(&a, &b, &c);
  getrusage(RUSAGE_SELF, &end);
  timersub(&end, &start, &diff);
  printf("Scalar result: ");
  vector_display(&a);
  printf("\nScalar time (seconds): %lf\n", diff.tv_sec + (double)diff.tv_usec / 1000000);
 
  // Test vector performance
  getrusage(RUSAGE_SELF, &start);
  vectorized_fma(&a2, &b2, &c2);
  getrusage(RUSAGE_SELF, &end);
  timersub(&end, &start, &diff);
  printf("Vector result: ");
  vector_display(&a2);
  printf("\nVector time (seconds): %lf\n", diff.tv_sec + (double)diff.tv_usec / 1000000);

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
