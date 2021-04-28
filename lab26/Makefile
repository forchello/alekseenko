targets = main.exe test.exe
CC = g++
C_OPTS = -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src src/book_methods.cpp src/book_array_methods.cpp src/tobool.cpp src/operator_BOOK.cpp src/operator_BOOK_ARRAY.cpp src/heir1.cpp src/heir2.cpp  src/ARR_heir1.cpp src/ARR_heir2.cpp

all: run

clean:
	rm -rf dist
prep: clean
	mkdir dist
compile: prep main.exe test.exe

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