targets = main.exe test.exe
CC = g++
C_OPTS = -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src -I./src/tools src/polymorphism/book.cpp src/polymorphism/artistic.cpp src/polymorphism/scientific.cpp src/polymorphism/array.cpp src/tools/tobool.cpp

all: run

clean:
	rm -rf dist
prep: clean
	mkdir dist
compile: prep main.exe

main.exe: src/main.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@ -lm

test.exe: test/test.cpp
	$(CC) $(C_OPTS) $< -o ./dist/$@

run: compile
	./dist/main.exe
test: clean prep compile
	./dist/test.exe
	
doxygen: prep
	doxygen Doxyfile