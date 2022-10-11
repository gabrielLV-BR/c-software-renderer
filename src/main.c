#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "renderer.h"
#include "math.h"
#include "pixels.h"

int main() {
    float a[3][3] = {
        { 1, 2, 0 },
        { 0, 1, 0 },
        { 3, 0, 1 }
    };

    float b[3][3] = {
        { 2, 2, 0 },
        { 0, 1, 0 },
        { 3, 0, 2 }
    };
    
    float out[3][3];
    mat3x3_mult(a, b, out);
    mat3x3_print(out);

    // int width = 200;
    // int height = 200;
    // pixels pixels = create_pixels(width, height);

    // paint(pixels, width, height);

    // printf("Writing image...\n");

    // write_out(pixels, width, height);
    // free_pixels(pixels, width, height);

    // return 0;
}