default: vectorized_fma

scalar: scalar_fma.c vectors.c vectors.s
	gcc -fno-inline-small-functions -std=gnu99 -O3 -g -o scalar_fma -march=core-avx2 scalar_fma.c vectors.s vectors.c -lm

vectorized_fma: vectorized_fma.c vectors.c vectors.s
	gcc -fno-inline-small-functions -std=gnu99 -O3 -g -o vectorized_fma -march=core-avx2 vectorized_fma.c vectors.c -lm

test: test.c vectors.c vectors.s
	gcc -fno-inline-small-functions -std=gnu99 -O3 -g -o test -march=core-avx2 test.c vectors.s vectors.c -lm

clean:
	rm -f scalar_fma
	rm -f vectorized_fma
