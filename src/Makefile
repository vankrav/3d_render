CC=gcc
FLAGS=-Wall -Werror -Wextra
OBJ_FILES=main.o draw.o
BUILD=../build/renderer

all: build clang clean.o

build: $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(BUILD)

main.o: main.c
	$(CC) $(FLAGS) -c main.c

draw.o: draw.c
	$(CC) $(FLAGS) -c draw.c

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
