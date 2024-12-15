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

    bool operator < (product_t) const;

    void read();

    void display() const;

    void changeField();
} product;

void displayAll(product*&, int);

void addNProducts(product*&, int&);
void addUntilBeer(product*&, int&);
void addUntilEnd(product*&, int&);
void findAllWithName(product*&, int&);
void deleteAllWithName(product*&, int&);
void sortAndShow(product*&, int&);

void displayDatabase();
void clearDatabase();
void addToDatabase();
void deleteFromDatabase();
void editDatabase();
