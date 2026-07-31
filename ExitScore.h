#ifndef EXITSCORE_H
#define EXITSCORE_H

#include <stdint.h>

typedef struct {
    int score;
    char *checkout;
} Checkout;


char *calc_score(int score);

#endif
