#ifndef RENDERER_H
#define RENDERER_H

#include <math.h>
#include <stdint.h>

#include "object.h"
#include "vector.h"

typedef struct {
    uint8_t r, g, b; 
} color;

typedef color** pixels;

void put(pixels img, uint8_t x, uint8_t y, color c);

void fill(pixels pixels, int width, int height, color c) {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            put(pixels, x, y, c);
        }
    }
}

void line(float x0, float y0, float x1, float y1, pixels pixels, color c) {
    float xd = (float)x1 - (float)x0;
    float yd = (float)y1 - (float)y0;
    float len = sqrt(xd * xd + yd * yd);

    if(len < 0.001) return;

    xd /= len;
    yd /= len;

    int int_len = ceil(len);

    for(int i = 0; i < int_len; i++) {
        put(pixels, (int)x0, (int)y0, c);
        x0 += xd;
        y0 += yd;
    }
}

void paint(pixels pixels, int width, int height) {
    vector faces = load_model(ASSETS"/monkey.obj");
    fill(pixels, width, height, (color){0, 0, 0});

    color white = {
        255, 255, 255
    };

    for(int i = 0; i < faces.count; i++) {
        polygon* p = (polygon*) faces.values[i];
        vertex a = p->a;
        vertex b = p->b;
        vertex c = p->c;

        line(a.x, a.y, b.x, b.y, pixels, white);
        line(b.x, b.y, c.x, c.y, pixels, white);
        line(c.x, c.y, a.x, a.y, pixels, white);
    }

}

#endif