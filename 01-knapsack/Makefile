OBJS = program.o
EXEC = knapsack

CFLAGS = -Wall -Wpedantic -std=c90
CC = gcc

all: $(EXEC)

debug: CFLAGS += -g
debug: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f *.o $(EXEC)
