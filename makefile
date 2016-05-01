CC = clang
OPT = -O1 -Wall

ARRAY_SRC = array.c
ARRAY_OBJ = $(ARRAY_SRC:%.c=%.o)

DEBUG_SRC = debug.c
DEBUG_OBJ = $(DEBUG_SRC:%.c=%.o)
DEBUG_OPT = -O3 -Wall

test: test.o debug.o
	$(CC) $(OPT) -o $@ $^

test.o: t.c
	$(CC) $(OPT) -o $@ -c $^

debug.o: $(DEBUG_SRC)
	$(CC) $(DEBUG_OPT) -o $@ -c $^

clean:
	rm -rf *.o