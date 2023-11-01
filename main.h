#define WIDTH 800
#define HEIGHT 600

#include <SDL2/SDL.h>

int drawPoint(int x, int y, int s, SDL_Renderer* renderer);
int proj_mm(int x[2][3], int y[3], int Matrix_Result[2][1]);
int rot_mm(float angle, int Matrix_Result[2][1], int Rotated_Matrix[2][1]);