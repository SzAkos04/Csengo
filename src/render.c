#include "render.h"

void render_frame(platform_t *platform) {
    SDL_SetRenderDrawColor(platform->renderer, 0, 0, 0, 255);
    SDL_RenderClear(platform->renderer);

    // draw

    SDL_RenderPresent(platform->renderer);
}
