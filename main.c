#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include "main.h"


int main(int argc, char* argv[]) {
    // SDL FLAGS
    SDL_Init(SDL_INIT_VIDEO); 

    // SDL WINDOW
    SDL_Window* window = SDL_CreateWindow("Nel\'s 3D ENGINE", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    float angle = 0;
    float b = 100;
    b *= -1;
    float linePoints[8][2] = {};
    // Vertices
    float **Points = cube(0, 0, 0, 100, 8); // FIX THE POINTER RETURN 11/11/2023 10:00 PM

    b = 200;
    float axisPoints[3][3] = {
        {-1 * b, 0, 0},
        {0, -1 * b, 0},
        {0, 0, -1 * b}
    };

    float z = 1;
    float Projection_Matrix[2][3] = {
        {z, 0, 0}, 
        {0, z, 0}
    };

    // LOOP
    SDL_Event event;
    int quit = 0;
    while (!quit) { // LOOP OPEN
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }
        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 23, 74, 37, 255);
        SDL_RenderClear(renderer);

        // MAIN AXIS
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int i = 0; i < 3; i++) {
            float Matrix_Result[2][1] = {{0}, {0}};
            float Rotated_Matrix[3][1] = {{0}, {0}, {0}};
            rot_mm(angle, axisPoints[i], Rotated_Matrix);
            proj_mm(Projection_Matrix, Rotated_Matrix, Matrix_Result);
            linePoints[i][0] = Matrix_Result[0][0];
            linePoints[i][1] = Matrix_Result[1][0];
            drawPoint(Matrix_Result[0][0] , Matrix_Result[1][0], 10, renderer);
        }
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        drawLine(renderer, 0, 0, linePoints[0][0], linePoints[0][1]);
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        drawLine(renderer, 0, 0, linePoints[1][0], linePoints[1][1]);
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        drawLine(renderer, 0, 0, linePoints[2][0], linePoints[2][1]);


        // CUBE
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int i = 0; i < 8; i++) {
            float Matrix_Result[2][1] = {{0}, {0}};
            float Rotated_Matrix[3][1] = {{0}, {0}, {0}};
            rot_mm(angle, Points[i], Rotated_Matrix);
            proj_mm(Projection_Matrix, Rotated_Matrix, Matrix_Result);
            linePoints[i][0] = Matrix_Result[0][0] ;
            linePoints[i][1] = Matrix_Result[1][0];
            //drawPoint(Matrix_Result[0][0] , Matrix_Result[1][0], 10, renderer);
        }
        //SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        // Front Face
        drawLine(renderer, linePoints[0][0], linePoints[0][1], linePoints[1][0], linePoints[1][1]);
        drawLine(renderer, linePoints[1][0], linePoints[1][1], linePoints[2][0], linePoints[2][1]);
        drawLine(renderer, linePoints[2][0], linePoints[2][1], linePoints[3][0], linePoints[3][1]);
        drawLine(renderer, linePoints[3][0], linePoints[3][1], linePoints[0][0], linePoints[0][1]);

        // Rear Face
        drawLine(renderer, linePoints[4][0], linePoints[4][1], linePoints[5][0], linePoints[5][1]);
        drawLine(renderer, linePoints[5][0], linePoints[5][1], linePoints[6][0], linePoints[6][1]);
        drawLine(renderer, linePoints[6][0], linePoints[6][1], linePoints[7][0], linePoints[7][1]);
        drawLine(renderer, linePoints[7][0], linePoints[7][1], linePoints[4][0], linePoints[4][1]);

        // Side Face
        drawLine(renderer, linePoints[0][0], linePoints[0][1], linePoints[4][0], linePoints[4][1]);
        drawLine(renderer, linePoints[1][0], linePoints[1][1], linePoints[5][0], linePoints[5][1]);
        drawLine(renderer, linePoints[2][0], linePoints[2][1], linePoints[6][0], linePoints[6][1]);
        drawLine(renderer, linePoints[3][0], linePoints[3][1], linePoints[7][0], linePoints[7][1]);
        angle += .0002;

        // Present the renderer
        SDL_RenderPresent(renderer);
    } // LOOP CLOSE

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    free(Points);
    return 0;
}
