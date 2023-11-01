#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "main.h"

int proj_mm(int x[2][3], int y[3], int Matrix_Result[2][1]) {

    
    // Matrix Multiplication
    for (int i = 0; i < 2; i++) { // Matrix_Result ROW
        for (int j = 0; j < 1; j++) { // Matrix_Result COLUMN
            
            for (int k = 0; k < 3; k++) {
            Matrix_Result[i][j] += x[i][k] * y[k];
            }
        }
    }/*
    for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
        printf("%d\t", Matrix_Result[i][j]);
    }
    printf("\n");
    }  */
}

int rot_mm(float angle, int Matrix_Result[2][1], int Rotated_Matrix[2][1]) {
    // Rotation Matrix
    float Rot_Matrix[2][2] = {
        {cos(angle), -sin(angle)}, 
        {sin(angle), cos(angle)}
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 2; k++) {
                Rotated_Matrix[i][j] += Rot_Matrix[i][k] * Matrix_Result[k][j];
            }
        }
    }
    for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 1; j++) {
        printf("%d\t", Rotated_Matrix[i][j]);
    }
    printf("\n");
    } 
    printf("Done\n");

}


int drawPoint(int x, int y, int s, SDL_Renderer* renderer) {
    SDL_Rect myRect = {x - (s/2), y - (s/2), s, s};
    SDL_RenderFillRect(renderer, &myRect);
}

