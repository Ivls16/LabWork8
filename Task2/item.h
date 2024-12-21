#pragma once

typedef struct item_t {
    bool finished = false;
    short day = 0, month = 0, year = 0;
    union {
        int ready, left;
    } timer{};
    char brand[20]{}, type[20]{};
} item;