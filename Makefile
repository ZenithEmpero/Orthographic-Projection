all:
	gcc main.c mul_mat.c -o ./bin/main -I src/include -L src/lib -lmingw32 -lSDL2main -lSDL2
	./bin/main

run:
	./bin/main