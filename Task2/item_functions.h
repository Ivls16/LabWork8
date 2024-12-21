#include "item.h"

const int NUMBER_BUFFER = 10, ITEM_BUFFER = 68;

void addNItems(item*&, int&);
void deleteFromArray(item*&, int&);
void displayItems(item*&, int&);
void editItem(item*&, int&);
void displayItemsStats(item*&, int&);

void clearDatabase();
void displayDatabase();
void addToDatabase();
void deleteFromDatabase();
void changeInDatabase();

int intLen(int);

void read(item&);
void display(item&);
void displayWithoutType(item&);
void readWithoutFeedback(item&, std::fstream&);
void writeRaw(item&, std::fstream&);
void changeField(item&);