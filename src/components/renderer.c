#include <math.h>
#include <stdint.h>
#include <SDL2/SDL.h>

#include "maths.h"
#include "model.h"
#include "vector.h"

#include "renderer.h"

// void tiny_renderer_fill(tiny_renderer* r, int width, int height, color c) {
//     for(int y = 0; y < height; y++) {
//         for(int x = 0; x < width; x++) {
//             // put(pix, x, y, c);
//         }
//     }
// }

// void tiny_renderer_line(tiny_renderer* r, float x0, float y0, float x1, float y1, color c) {
//     float xd = (float)x1 - (float)x0;
//     float yd = (float)y1 - (float)y0;
//     float len = sqrt(xd * xd + yd * yd);

//     if(len < 0.001) return;

//     xd /= len;
//     yd /= len;

//     int int_len = ceil(len);

//     for(int i = 0; i < int_len; i++) {
//         // put(pix, (int)x0, (int)y0, c);
//         x0 += xd;
//         y0 += yd;
//     }
// }

tiny_renderer tiny_renderer_new(SDL_Renderer* renderer, uint32_t width, uint32_t height) {
    return (tiny_renderer) {
        renderer,
        vector_new(0),
        width, height
    };
}

void tiny_renderer_load(tiny_renderer* tr) {
    vector faces = load_obj_model(ASSETS"/monkey.obj");

    vector_push(&tr->models, &faces);
}

void tiny_renderer_delete(tiny_renderer* r) {
    for(int i = 0; i < r->models.count; i++) {
        vector_free(&r->models + i * sizeof(vector));
    }
    vector_free(&r->models);
}

void tiny_renderer_render(tiny_renderer* r) {
    // for(int j = 0; j < r->models.count; j++) {
    //     vector faces = *(r->models[j]);
    SDL_SetRenderDrawColor(r->renderer, 0, 0, 0, 255);
    
    vector faces = load_obj_model(ASSETS"/monkey.obj");

    for(int i = 0; i < faces.count; i++) {
        polygon* p = (polygon*) faces.values[i];
        vec3 a = p->a;
        vec3 b = p->b;
        vec3 c = p->c;

        SDL_SetRenderDrawColor(r->renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(r->renderer, a.x, a.y, b.x, b.y);
        SDL_RenderDrawLine(r->renderer, b.x, b.y, c.x, c.y);
        SDL_RenderDrawLine(r->renderer, c.x, c.y, a.x, a.y);

        // tiny_renderer_line(tr, a.x, a.y, b.x, b.y, white);
        // tiny_renderer_line(tr, b.x, b.y, c.x, c.y, white);
        // tiny_renderer_line(tr, c.x, c.y, a.x, a.y, white);
    }

    SDL_RenderPresent(r->renderer);
    // }
}