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

    // Vertices
    int point1[3][1] = {{-50}, {-50}, {0}};
    int point2[3][1] = {{50}, {-50}, {0}};
    int point3[3][1] = {{50}, {50}, {0}};
    int point4[3][1] = {{-50}, {50}, {0}}; 

    // Orthographic Projection Matrix
    int Ortho_Matrix[2][3] = {{1, 0, 0}, {0, 1, 0}};

    mm(Ortho_Matrix, point1);

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
        drawPoint(WIDTH/2, 10, 10, renderer);

        


        // Present the renderer
        SDL_RenderPresent(renderer);
    } // LOOP CLOSE

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
