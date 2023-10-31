#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL Circle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Event event;
    int quit = 0;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Clear the renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw a red circle
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        int radius = 50;
        int x = 400;
        int y = 300;
        for (int i = 0; i < 360; i++) {
            float angle = i * M_PI / 180.0;
            int circleX = x + radius * cos(angle);
            int circleY = y + radius * sin(angle);
            SDL_RenderDrawPoint(renderer, circleX, circleY);
        }

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
