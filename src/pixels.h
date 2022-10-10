#ifndef PIXELS_H
#define PIXELS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t r, g, b; 
} color;

typedef color** pixels;

void put(pixels pixels, uint8_t x, uint8_t y, color c) {
    if(x >= 200 || x < 0 || y >= 200 || y < 0) return;
    pixels[x][y] = c;
}

pixels create_pixels(int width, int height) {
    pixels columns = (pixels) malloc(height * sizeof(color*));
    for(int i = 0; i < height; i++) {
        columns[i] = (color*) malloc(width * sizeof(color));
    }
    return columns;
}

void write_out(pixels pixels, int width, int height) {
    FILE* output = fopen("out.ppm", "w");

    if(output == NULL) {
        fprintf(stderr, "Error when opening file\n");
        goto END;
    }

    fprintf(output, "P3\n");
    fprintf(output, "%i %i\n", width, height);
    fprintf(output, "255\n");

    for(int x = 0; x < width; x++) {
        for(int y = 0; y < height; y++) {
            color color = pixels[y][x];
            fprintf(output, "%i %i %i ", color.r, color.g, color.b);
        }
        fprintf(output, "\n");
    }

END:
    fclose(output);
}

void free_pixels(pixels pixels, int width, int height) {
    for (int y = 0; y < height; y++)
    {
        free(pixels[y]);
    }
    free(pixels);    
}

#endif