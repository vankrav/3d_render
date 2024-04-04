CC=gcc
FLAGS=
#-Wall -Werror -Wextra
OBJ_FILES=main.o ndraw.o
BUILD=../build/renderer

all: build clang clean.o

build: $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(BUILD) -lncurses

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
	clang-format -i *.c *.h

git:
	git add .
	git commit -m "regular make commit"
	git push origin develop
