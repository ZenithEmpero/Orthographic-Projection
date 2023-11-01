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

    float angle = 10;
    int b = 100;
    // Vertices
    int points[][3] = {
        {-b, -b, 0},
        {b, -b, 0},
        {b, b, 0},
        {-b, b, 0}
    };

    // Orthographic Projection Matrix
    int Ortho_Matrix[2][3] = {
        {1, 0, 0}, 
        {0, 1, 0}
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
        SDL_SetRenderDrawColor(renderer, 50, 168, 82, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        for (int i = 0; i < 4; i++) {
            int Matrix_Result[2][1] = {{0}, {0}};
            int Rotated_Matrix[2][1] = {{0}, {0}};
            proj_mm(Ortho_Matrix, points[i], Matrix_Result);
            rot_mm(angle, Matrix_Result, Rotated_Matrix);
            drawPoint(Rotated_Matrix[0][0] + (WIDTH/2), Rotated_Matrix[1][0] + (HEIGHT/2), 10, renderer);
        }

        angle += .001;

        // Present the renderer
        SDL_RenderPresent(renderer);
    } // LOOP CLOSE

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
