INC_DIRS=./include
AR=ar
CC=gcc
CFLAGS=-std=c99
BINDIR=bin
OBJ=$(BINDIR)/mem.o $(BINDIR)/string.o
LIBDIR=./lib
LIB=mycstdlib

TEST=printf_test

all: $(LIBDIR)/lib$(LIB).a $(TEST)

printf_test: printf.c 
	$(CC) $(CFLAGS) -I $(INC_DIRS) -L $(LIBDIR) -o $@ $^ -l$(LIB)

$(LIBDIR)/lib$(LIB).a: $(OBJ)
	$(AR) rcs $@ $^

$(BINDIR)/%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIRS) -c $^ -o $@ 


clean:
	-rm bin/*
	-rm lib/*
	-rm $(TEST)

.PHONY: clean
