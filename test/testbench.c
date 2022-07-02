/*  testbench.cpp -- A companion library to SDL for working with Pango.
    Copyright (C) 2004 NAKAMURA Ken'ichi

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
*/

#include "SDL2_Pango.h"
#include "stdio.h"
#include "stdlib.h"

SDLPango_Context *context;
SDL_Window *window;
char *text;

int resizeLoop(SDL_Surface **framebuf)
{
    SDL_Event event;

    while( SDL_PollEvent( &event ) ){
        switch( event.type ){
        case SDL_QUIT:
            return 0;

        case  SDL_WINDOWEVENT:
            if(event.window.event == SDL_WINDOWEVENT_RESIZED)
                *framebuf = SDL_GetWindowSurface(window);
            break;

        case SDL_KEYUP:
            if(event.key.keysym.sym == SDLK_RETURN)
                SDLPango_SetMarkup(context, text, -1);
            else if(event.key.keysym.sym == SDLK_SPACE)
                SDLPango_SetText(context, text, -1);
            break;

        default:
            break;
        }
    }

    return -1;
}

char *readFile(const char *filename)
{
    long file_size;
    char *text;
    FILE *file = fopen(filename, "rb");
    if(! file)
        exit(1);

    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    text = (char *)malloc(file_size + 1);
    (void)!fread(text, file_size, 1, file);  /* (void)! suppresses unused-result warning */
    text[file_size] = '\0';

    return text;
}

int main(int argc, char *argv[])
{
    SDL_Surface *framebuf;
    SDL_Surface *surface;

    if(argc == 1) {
        fprintf(stderr, "Usage: ./testbench markup.txt\n");
        exit(1);
    }

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        fprintf(stderr, "%s\n", SDL_GetError());
        exit(1);
    }

    if(SDLPango_Init() < 0) {
        fprintf(stderr, "Failed to initialize SDL2_Pango\n");
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_SWSURFACE | SDL_WINDOW_RESIZABLE);
    if(!window) {
        fprintf(stderr, "%s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    framebuf = SDL_GetWindowSurface(window);
    if(!framebuf) {
        fprintf(stderr, "%s\n", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    context = SDLPango_CreateContext();
    if(!context) {
        fprintf(stderr, "Failed to create SDL2_Pango context\n");
        SDL_Quit();
        exit(1);
    }

#ifdef SET_DPI
    SDLPango_SetDpi(context, 200.0, 200.0);
#endif

    SDLPango_SetDefaultColor(context, MATRIX_TRANSPARENT_BACK_WHITE_LETTER);

    SDLPango_SetMinimumSize(context, 640, 0);

#ifdef SET_BASE_DIRECTION
    SDLPango_SetBaseDirection(context, SDLPANGO_DIRECTION_RTL);
#endif

    text = readFile(argv[1]);

    surface = NULL;
    SDLPango_SetMarkup(context, text, -1);

    while(resizeLoop(&framebuf)) {
        SDL_Surface *surface;

        SDLPango_SetMinimumSize(context, framebuf->w, 0);

#ifdef GET_LAYOUT_WIDTH
        {
            int w, h;
            w = SDLPango_GetLayoutWidth(context);
            h = SDLPango_GetLayoutHeight(context);
        }
#endif

#ifdef CREATE_SURFACE_DRAW
        surface = SDLPango_CreateSurfaceDraw(context);
#else
        surface = SDL_CreateRGBSurface(SDL_SWSURFACE, framebuf->w, framebuf->h,
            32, (Uint32)(255 << (8 * 3)), (Uint32)(255 << (8 * 2)),
            (Uint32)(255 << (8 * 1)), 255);
        SDLPango_Draw(context, surface, 0, 0);
#endif

        SDL_FillRect(framebuf, NULL, SDL_MapRGBA(framebuf->format, 0, 0, 0, 0));
        SDL_BlitSurface(surface, NULL, framebuf, NULL);
        SDL_UpdateWindowSurface(window);

        SDL_FreeSurface(surface);
    }

    free(text);

    SDLPango_FreeContext(context);

    SDL_Quit();
    return 0;
}

