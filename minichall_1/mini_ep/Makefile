# Breno Helfstein Moura       NUSP: 9790972
# Pedro Pereira               NUSP: 9778794

FLAGS = -pthread -Wall -pedantic -g
OBJS = main.o frog.o
EXEC = main

.PHONY: clean

all: $(OBJS)
	$(CC) $(FLAGS) $^ -o main -lm
	make clean

run: $(OBJS)
	$(CC) $(FLAGS) $^ -o main -lm
	make clean
	./main

%.o: %.c %.h
	$(CC) $(FLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	-rm -f *.o *~
