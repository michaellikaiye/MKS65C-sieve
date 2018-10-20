all: ./primetest

./primetest: sieve.c main.c
	gcc -o primetest sieve.c main.c -lm -g
run:
	./primetest $(args)
test:
	valgrind ./primetest $(args)
clean:
	rm -f primetest sieve.o main.o *~

