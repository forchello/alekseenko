targets = main.bin test.bin
CC = gcc
C_OPTS = -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./source source/list.c source/data.c 

all: run

clean:
	rm -rf dist
prep: clean
	mkdir dist
compile: prep test.bin #main.bin

#main.bin: src/main.c
#$(CC) $(C_OPTS) $< -o ./dist/$@ -lm

test.bin: test/test.c
	$(CC) $(C_OPTS) $< -o ./dist/$@

#run: compile
#./dist/main.bin
test: clean prep compile
	./dist/test.bin
	
doxygen: prep
	doxygen Doxyfile
format: #TODO

tidy: # TODO
