#include "product.h"

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

void read(product_t&);
void display(product_t&);
void changeField(product_t&);