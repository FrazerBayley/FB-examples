SOURCES = directory.c main.c
HEADERS = directory.h
OBJECTS = $(SOURCES:.c=.o)
LIBS = -lm

CC = gcc
CFLAGS = -std=c99 -g

%.o: %.c
	$(CC) -c $(CFLAGS) $<

main: $(OBJECTS)
	$(CC) -o directory $(OBJECTS)

tests: test-triangle

test-directory: test-directory.o directory.o
	$(CC) -o directory test-directory.o directory.o $(LIBS)

test-directory: test-directory.o directory.o
	$(CC) -o directory test-directory.o directory.o $(LIBS)

test-main: $(OBJECTS)
	$(CC) -o directory $(OBJECTS) $(LIBS)

test-test: test.o directory.o
	$(CC) -o directory test.o directory.o  $(LIBS)

clean: 
	$(RM) main $(OBJECTS) test-*