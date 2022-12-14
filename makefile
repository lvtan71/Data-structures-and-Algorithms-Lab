IDIR=./include
ODIR=./obj
BDIR=./bin
TDIR=./test

CC=g++
CFLAGS=-I $(IDIR) -Wall -Wextra -std=c++17

_DEPS = option_1.h option_2.h option_3.h HashTable.h Trie.h LinkedList.h Data.h utils.h Constants.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = option_1.o option_2.o option_3.o HashTable.o Trie.o LinkedList.o Data.o utils.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

_TESTS = ll.test ht.test trie.test check_valid_path.test
TESTS = $(patsubst %,$(BDIR)/%,$(_TESTS))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(BDIR)/main: main.cpp $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: build
build: $(BDIR)/main

.PHONY: run
run: build
	$(BDIR)/main

$(BDIR)/%.test: $(TDIR)/%.cpp $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	$@

.PHONY: test
test: $(TESTS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o $(BDIR)/*.exe $(BDIR)/*.test
