all:
	gcc main.c -o ./bin/main -I src/include -L src/lib -lmingw32 -lSDL2main -lSDL2

run:
	./bin/main