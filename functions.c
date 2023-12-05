#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include "main.h"

float proj_mm(float Projection_Matrix[2][3], float Rotation_Matrix[3][1], float Matrix_Result[2][1]) {

    // Matrix Multiplication
    for (int i = 0; i < 2; i++) { // Matrix_Result ROW
        for (int j = 0; j < 1; j++) { // Matrix_Result COLUMN
            
            for (int k = 0; k < 3; k++) {
            Matrix_Result[i][j] += Projection_Matrix[i][k] * Rotation_Matrix[k][j];
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
float b = 10;
float rot_mm(float angle, float Point[3], float Rotated_Matrix[3][1]) {
    // Rotation Matrix
    int a = 0;
    float Rot_Matrix_X[3][3] = {
        {1, 0, 0},
        {0, cos(a), -sin(a)},
        {-sin(a), 0, cos(a)}
    };

    float Rot_Matrix_Y[3][3] = {
        {cos(angle), 0, sin(angle)}, 
        {0, 1, 0},
        {-sin(angle), 0, cos(angle)}
    };

    float RM1[3][1] = {{0}, {0}, {0}};
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 3; k++) {
                RM1[i][0] += Rot_Matrix_Y[i][k] * Point[k];
            }
        }
    }
    
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 1; j++) {
            for (int k = 0; k < 3; k++) {
                Rotated_Matrix[i][j] += Rot_Matrix_X[i][k] * RM1[k][j];
            }
        }
    }
    /*
    for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 1; j++) {
        printf("%d\t", Rotated_Matrix[i][j]);
    }
    printf("\n");
    } 
    printf("Done\n");
    */
}


int drawPoint(int x, int y, int s, SDL_Renderer* renderer) {
    SDL_Rect myRect = {(x - (s/2)) + (WIDTH/2), (y - (s/2)) + (HEIGHT/2), s, s};
    SDL_RenderFillRect(renderer, &myRect);
}

int drawLine(SDL_Renderer* renderer, float x1, float y1, float x2, float y2) {
    SDL_RenderDrawLine(renderer, x1 + (WIDTH/2), y1 + (HEIGHT/2), x2 + (WIDTH/2), y2 + (HEIGHT/2));
}
