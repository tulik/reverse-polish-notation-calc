CC=gcc
CFLAGS=-Wall -ansi -pedantic
OBJS=converse.o my_complex.o stack.o main.o

calc: $(OBJS)
	$(CC) $(LFLAGS) $^ -o $@ -lm

converse.o: converse.c
	$(CC) $(CFLAGS) -c $< -o $@ -lm

my_complex.o: my_complex.c
	$(CC) $(CFLAGS) -c $< -o $@ -lm

stack.o: stack.c
	$(CC) $(CFLAGS) -c $< -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@ -lm

clean:
	rm -fv *.o calc
