#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "SDL2/SDL.h"

#include "renderer.h"
#include "math.h"
#include "pixels.h"

int main(int argc, char *argv[]) {
    //The window we'll be rendering to
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    // int width = 200;
    // int height = 200;
    // pixels pixels = create_pixels(width, height);

    // paint(pixels, width, height);

    // printf("Writing image...\n");

    // write_out(pixels, width, height);
    // free_pixels(pixels, width, height);

    return 0;
}