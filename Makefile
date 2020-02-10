CC=gcc
OUT=bin/lc3vm

all:
	$(CC) -o $(OUT) $(wildcard *.c)
