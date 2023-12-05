#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>

int mainAxis() {

}

float **cube(float x, float y, float z, float size, int num_of_points) {
    float angle = 0;
    float hs = size/2;
    x += hs; y += hs; z += hs;
    float s = size;
    s *= -1;
    // Cube Vertices
    float POINTS[][3] = {
        {x, y, z},
        {x, y + s, z},
        {x + s, y + s, z},
        {x + s, y, z},
        {x, y, z + s},
        {x, y + s, z + s},
        {x + s, y + s, z + s},
        {x + s, y, z + s}
    };
    // Allocate memory for the array of pointers
    float** points = (float**)malloc(num_of_points * sizeof(float*));

    // Allocate memory for each row
    for (int i = 0; i < num_of_points; i++) {
        points[i] = (float*)malloc(3 * sizeof(float)); // 3 because there are 3 positions in a 3D plane
    }

    for (int rows = 0; rows < num_of_points; rows++) {
        for (int cols = 0; cols < 3; cols++) {
            points[rows][cols] = POINTS[rows][cols];
        }
    }

    return points;
}