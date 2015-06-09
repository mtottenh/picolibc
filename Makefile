#TOOLS
AR=ar
CC=gcc
#FLAGS
CFLAGS=-std=c99

#DIRS
INC_DIRS=./include
OBJDIR=obj
BINDIR=bin
TESTDIR=tests
LIBDIR=lib
SRCDIR=src

#FILES
SRC=mem.c string.c io.c
OBJ=$(patsubst %.c, %.o, $(SRC))

#$(BINDIR)/mem.o $(BINDIR)/string.o $(BINDIR)/io.o
LIB=mycstdlib
LIB_A=lib$(LIB).a
TEST=printf.c
TEST_OUT=$(patsubst %.c, %_test, $(TEST))


all: $(LIBDIR)/$(LIB_A) $(BINDIR)/$(TEST_OUT)

$(BINDIR)/$(TEST_OUT): $(TESTDIR)/$(TEST) 
	$(CC) $(CFLAGS) -I $(INC_DIRS) -L $(LIBDIR) -o $(BINDIR)/$@ $^ -l$(LIB)

$(LIBDIR)/$(LIB_A): $(OBJ:%=obj/%)
	$(AR) rcs $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIRS) -c $< -o $@ 


clean:
	-rm $(BINDIR)/*
	-rm $(LIBDIR)/*
	-rm $(OBJDIR)/*
.PHONY: clean
