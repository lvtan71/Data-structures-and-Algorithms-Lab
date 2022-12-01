IDIR=./include
ODIR=./obj
BDIR=./bin

CC=g++
CFLAGS=-I $(IDIR) -std=c++17

_DEPS = HashTable.h LinkedList.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = HashTable.o LinkedList.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o $(BDIR)/main main.cpp $^ $(CFLAGS)

run: $(BDIR)/main
	$(BDIR)/main

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o  $(BDIR)/*
