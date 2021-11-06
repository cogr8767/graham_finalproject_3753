UNAME=$(shell uname)

CCFLAGS=-Wall -O3 -std=gnu99
CC=gcc

all: logic

logic: main.o logic.o ctest.h logictests.o
	$(CC) $(LDFLAGS) main.o logic.o logictests.o -o logic

remake: clean all

%.o: %.c ctest.h
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f logic *.o
