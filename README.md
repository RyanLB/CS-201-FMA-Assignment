#Your Task

This assignment requires you to write a function, using inline assembly, that takes three arbitrary-length vectors of double-precision floating point numbers `a`, `b`, and `c`, and perform the following operation:
```
for(int i = 0, j = length; ++i) {
  a[i] += b[i] * c[i];
}
```

The code above will calculate the correct result, but it performs slowly. Yours will need to be faster. Fortunately, we have hardware support for this; modern processors have a set of vector extensions called AVX2 that will allow us to perform calculations on up to four doubles at a time. In fact, AVX2 adds support for exactly this purpose through the use of the new FMA3 [fused multiply-add](https://en.wikipedia.org/wiki/Multiply–accumulate_operation#Fused_multiply.E2.80.93add) instructions.

This repo provides skeleton code for creating random vectors and testing the performance of your code against a naïve scalar implementation like the one above.

###What to Submit

Your submission should be a single file with the title `<D2L username>.c`. This file should contain, at minimum, a function with the following signature:

`void vectorized_fma(const struct doubleVector * a, const struct doubleVector * b, const struct doubleVector * c)`

This function should work with the provided `main.c` and `Makefile`; there is no need to write or include your own.

###Grading Criteria

// TODO

# Background: AVX2 and Vectorized Instructions

// TODO

#Notes and Hints

// TODO
