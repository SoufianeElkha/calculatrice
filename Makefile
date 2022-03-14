CC=gcc -Wall -Wextra -pedantic -g -fsanitize=address -fsanitize=leak -lm

programmes: calculatrice

$stack_char.o: $ stack_char.c $ stack_char.h
	$(CC) -c $<

$ logic.o: $ logic.c $ logic.h
	$(CC) -c $<

$ stack_double.o: $ stack_double.c $ stack_double.h
	$(CC) -c $<

calculatrice: calculatrice.o $ stack_char.o $ logic.o $ stack_double.o
	$(CC) $^ -o $@ -lm

calculatrice.o: calculatrice.c $ stack_char.h $ logic.h $ stack_double.h
	$(CC) -c $<

clean:
	rm -f *.o calculatrice && clear

rebuild: clean programmes