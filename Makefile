CC = gcc
CFLAGS = -I.
EXEC = bin/grawitex

vpath %.c src
vpath %.h src
vpath %.o bin
vpath % bin

SOURCES := $(wildcard src/*.c)
OBJECTS := $(patsubst src/%.c,bin/%.o,$(SOURCES))

all: $(EXEC)

$(EXEC): $(OBJECTS)
	echo "Sources: $(SOURCES)"
	$(CC) $(OBJECTS) $(CFLAGS) -o $(EXEC)

$(OBJECTS): bin/%.o : src/%.c
	$(CC) -o $@ $(CFLAGS) -c $<

.PHONY: clean run
clean:
	rm -rf bin/*

run: $(EXEC)
	$(EXEC)
