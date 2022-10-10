#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "renderer.h"
#include "math.h"
#include "pixels.h"

int main() {
    int width = 200;
    int height = 200;
    pixels pixels = create_pixels(width, height);

    paint(pixels, width, height);

    printf("Writing image...\n");

    write_out(pixels, width, height);
    free_pixels(pixels, width, height);

    return 0;
}