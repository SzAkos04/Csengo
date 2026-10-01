#ifndef PLATFORM_H
#define PLATFORM_H

#include <SDL.h>
#include <stdbool.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool running;
} platform_t;

int platform_init(platform_t *p, const char *title, int w, int h);
void platform_free(platform_t *p);

void platform_handle_events(platform_t *p);

#endif // !PLATFORM_H
