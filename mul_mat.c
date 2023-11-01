#include <stdio.h>
#include <SDL2/SDL.h>
#include "main.h"

int mm(int x[2][3], int y[3][1]) {

    int mr[2][1] = {{0}, {0}};
    // Matrix Multiplication
    for (int i = 0; i < 2; i++) { // MR ROW
    for (int j = 0; j < 1; j++) { // MR COLUMN
        
        for (int k = 0; k < 3; k++) {
        mr[i][j] += x[i][k] * y[k][j];
        }
    }
    }
    for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
        printf("%d\t", mr[i][j]);
    }
    printf("\n");
    }  


}


int drawPoint(int x, int y, int s, SDL_Renderer* renderer) {
    SDL_Rect myRect = {x - (s/2), y - (s/2), s, s};
    SDL_RenderFillRect(renderer, &myRect);
}

