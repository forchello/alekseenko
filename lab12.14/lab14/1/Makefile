targets = main.bin test.bin
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src

all: doxygen run

clean:
	rm -rf dist
prep: clean
	mkdir dist
compile: prep main.bin 

main.bin: src/main.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: compile
	./dist/main.bin
doxygen: prep
	doxygen Doxyfile
format: #TODO

tidy: # TODO
