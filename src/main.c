#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "SDL2/SDL.h"

#include "components/renderer.h"
#include "components/maths.h"

#define WIDTH 500
#define HEIGHT 500

int main(int argc, char *argv[]) {
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }

    window = SDL_CreateWindow("Oi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, 0, 0);

    tiny_renderer tiny_renderer = tiny_renderer_new(renderer, (uint32_t)WIDTH, (uint32_t)HEIGHT);
    tiny_renderer_load(&tiny_renderer);

    SDL_Event event;
    char running = 1;
    while(running == 1) {
        while(SDL_PollEvent(&event)) {
            switch (event.type)
            {
            case SDL_QUIT:
                running = 0;
            }
        }
        tiny_renderer_render(&tiny_renderer);
    }

    tiny_renderer_delete(&tiny_renderer);

    return 0;
}