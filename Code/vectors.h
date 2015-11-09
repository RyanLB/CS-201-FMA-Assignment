#ifndef _RYAN_VEC
#define _RYAN_VEC

struct doubleVector {
  size_t length;
  double * data;
};

struct doubleVector vectorAlloc(int length);
struct doubleVector randomVector(int length);
struct doubleVector vectorClone(const struct doubleVector *original);
void vectorDisplay(const struct doubleVector * vec);

// We could use memcpy(), but here's a good opportunity to see what vector
// instructions look like
void vectorizedCopy(double * src, double * dst, int length);

#endif
