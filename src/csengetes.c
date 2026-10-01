#include "csengetes.h"
#include <stdio.h>
#include <stdlib.h>

int rend_init(rend_t *rend) {
    *rend = (rend_t){0};
    rend->orak_count = 0;

    FILE *infile = fopen("orak.txt", "r");
    if (!infile) {
        fprintf(stderr, "Failed to open 'orak.txt'!\n");
        return -1;
    }

    ssize_t read;
    char *line = NULL;
    size_t len;
    while ((read = getline(&line, &len, infile)) != -1) {
        if (rend->orak_count >= ORA_MAX) {
            break;
        }

        if (sscanf(line, "%d:%d-%d:%d",
                   &rend->orak[rend->orak_count].kezd.tm_hour,
                   &rend->orak[rend->orak_count].kezd.tm_min,
                   &rend->orak[rend->orak_count].veg.tm_hour,
                   &rend->orak[rend->orak_count].veg.tm_min) == 4) {
            ++rend->orak_count;
        }
    }

    free(line);
    fclose(infile);

    return 0;
}
