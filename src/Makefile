CC=gcc
FLAGS=
#-Wall -Werror -Wextra
OBJ_FILES=main.o ndraw.o
BUILD=../build/renderer

all: build_cpp clang clean.o

build_cpp: main_cpp.o window.o
	clang++  main_cpp.o window.o -o $(BUILD) -lncurses

build: $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(BUILD) -lncurses

main_cpp.o: main.c
	clang++ main.cpp -c -o main_cpp.o 

window.o: window.cpp
	clang++ window.cpp -c  

main.o: main.c
	$(CC) $(FLAGS) -c main.c

ndraw.o: ndraw.c
	$(CC) $(FLAGS) -c ndraw.c

clean.o:
	rm *.o

clean: clean.o
	rm -rf ../build/*

rebuild: clean build

clang:
	clang-format -i *.c *.h *.cpp

git:
	git add .
	git commit -m "regular make commit"
	git push origin develop_cpp
