default: vectors

vectors: main.c vectors.c
	gcc -fno-inline-small-functions -std=gnu99 -O3 -o main -march=core-avx2 main.c vectors.c -lm

test: test.c vectors.c vectors.s
	gcc -fno-inline-small-functions -std=gnu99 -O3 -o test -march=core-avx2 test.c vectors.c vectors.s -lm
