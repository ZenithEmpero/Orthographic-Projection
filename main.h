#define WIDTH 800
#define HEIGHT 600

#include <SDL2/SDL.h>

int drawPoint(int x, int y, int s, SDL_Renderer* renderer);
float proj_mm(float Projection_Matrix[2][3], float Rotation_Matrix[3][1], float Matrix_Result[2][1]);
float rot_mm(float angle, float Point[3], float Rotated_Matrix[3][1]);
int drawLine(SDL_Renderer* renderer, float x1, float y1, float x2, float y2);