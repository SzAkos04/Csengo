#include "platform.h"

int platform_init(platform_t *p, const char *title, int w, int h) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("SDL error: %s", SDL_GetError());
        platform_free(p);
        return -1;
    }

    p->window =
        SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                         w, h, SDL_WINDOW_SHOWN);
    if (!p->window) {
        SDL_Log("SDL error: %s", SDL_GetError());
        platform_free(p);
        return -1;
    }

    p->renderer = SDL_CreateRenderer(p->window, -1, SDL_RENDERER_ACCELERATED);
    if (!p->renderer) {
        SDL_Log("SDL error: %s", SDL_GetError());
        platform_free(p);
        return -1;
    }

    p->running = true;

    return 0;
}

void platform_free(platform_t *p) {
    if (p->renderer) {
        SDL_DestroyRenderer(p->renderer);
    }
    if (p->window) {
        SDL_DestroyWindow(p->window);
    }
    SDL_Quit();
}

void platform_handle_events(platform_t *p) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT: {
            p->running = false;
        } break;
        default: {
        } break;
        }
    }
}
