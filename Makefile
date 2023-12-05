all:
	gcc main.c functions.c elements.c -o ./bin/build -I src/include -L src/lib -lmingw32 -lSDL2main -lSDL2
	./bin/build

run:
	./bin/build