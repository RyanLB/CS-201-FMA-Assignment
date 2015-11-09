#ifndef _RYAN_VEC
#define _RYAN_VEC

struct doubleVector {
  size_t length;
  double * data;
};

struct doubleVector vector_alloc(int length);
struct doubleVector random_vector(int length);
struct doubleVector vector_clone(const struct doubleVector *original);
void vector_display(const struct doubleVector * vec);

// We could use memcpy(), but here's a good opportunity to see what vector
// instructions look like
void vectorized_copy(double * src, double * dst, int length);

// A naive scalar implementation to benchmark ourselves against
bool scalar_fma(struct doubleVector * a,
                const struct doubleVector * b,
                const struct doubleVector * c);

// A prototype for your code
bool vectorized_fma(struct doubleVector * a,
                    const struct doubleVector * b,
                    const struct doubleVector * c);

#endif
