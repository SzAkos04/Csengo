#ifndef CSENGETES_H
#define CSENGETES_H

#include <stddef.h>
#include <time.h>

#define ORA_MAX 64

typedef struct {
    struct tm kezd;
    struct tm veg;
} ora_t;

typedef struct {
    ora_t orak[ORA_MAX];
    size_t orak_count;
} rend_t;

int rend_init(rend_t *rend);

#endif // !CSENGETES_H
