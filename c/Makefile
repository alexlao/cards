CC = gcc
CFLAGS = -Wall -ansi -pedantic
MAIN = calculateRounds
OBJS = library.o main.o
all : $(MAIN)

$(MAIN) : $(OBJS) library.h
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

library.o : library.c library.h
	$(CC) $(CFLAGS) -c library.c
main.o : main.c library.h
	$(CC) $(CFLAGS) -c main.c
clean:
	rm *.o $(MAIN)
