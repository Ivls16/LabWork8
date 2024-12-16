#pragma once

typedef struct item_t {
    bool finished = false;
    short day = 0, month = 0, year = 0;
    union {
        int ready, left;
    } timer{};
    char brand[20]{}, type[20]{};

    bool operator > (item_t) const;

    void read();

    void display() const;
    void displayWithoutType() const;

    void readWithoutFeedback(std::fstream&);
    void writeRaw(std::fstream&);

    void changeField();
} item;

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

const int NUMBER_BUFFER = 10, ITEM_BUFFER = 68;