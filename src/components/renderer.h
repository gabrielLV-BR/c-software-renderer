#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include "vector.h"

typedef struct {
    SDL_Renderer* renderer;
    vector models;
    uint32_t width, height;
} tiny_renderer;

tiny_renderer tiny_renderer_new(SDL_Renderer* renderer, uint32_t width, uint32_t height);
void tiny_renderer_load(tiny_renderer* tr);
void tiny_renderer_render(tiny_renderer* r);
void tiny_renderer_delete(tiny_renderer* r);

#endif