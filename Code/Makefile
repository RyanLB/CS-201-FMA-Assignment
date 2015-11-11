default: main

main: main.c vectors.c vectors.s
	gcc -fno-inline-small-functions -std=gnu99 -g -O0 -o main -march=core-avx2 main.c vectors.s vectors.c -lm

test: test.c vectors.c vectors.s
	gcc -fno-inline-small-functions -std=gnu99 -g -o test -march=core-avx2 test.c vectors.s vectors.c -lm

clean:
	rm -f main
	rm -f vectorized_fma
