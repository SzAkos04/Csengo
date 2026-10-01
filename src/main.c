#include "csengetes.h"
#include "platform.h"
#include "render.h"

int main(void) {
    platform_t platform = {0};
    if (platform_init(&platform, "Csengetés", 640, 400) != 0) {
        return -1;
    }

    rend_t rend = {0};
    if (rend_init(&rend) != 0) {
        platform_free(&platform);
        return -1;
    }

    while (platform.running) {
        // handle events
        platform_handle_events(&platform);

        // render
        render_frame(&platform);

        // update
    }

    platform_free(&platform);
    return 0;
}
