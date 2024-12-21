#pragma once

typedef struct product_t {
    bool liquid;
    short year, month, day;
    int units;
    char name[20];
    double price;

    union size {
        double mass;
        double volume;
    } unit_size;
} product;