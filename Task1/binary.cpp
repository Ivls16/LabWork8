#include <iostream>
#include "product.h"

FILE *databaseFile = fopen("products.bin", "rb+");

product* getProducts(int& n) {
    fseek(databaseFile, 0L, SEEK_END);
    if (ftell(databaseFile) == SEEK_SET) {
        fwrite(&n, sizeof(int), 1, databaseFile);
    }
    fseek(databaseFile, 0L, SEEK_SET);
    fread(&n, sizeof(int), 1, databaseFile);
    product* arr = new product[n];
    fread(arr, sizeof(product), n, databaseFile);
    return arr;
}

bool emptyDb() {
    int n = 0;
    fseek(databaseFile, 0L, SEEK_END);
    if (ftell(databaseFile) == SEEK_SET) {
        fwrite(&n, sizeof(int), 1, databaseFile);
    }
    fseek(databaseFile, 0L, SEEK_SET);
    fread(&n, sizeof(int), 1, databaseFile);
    return n == 0;
}

void displayDatabase() {
    std::cout << "Товары, хранящиеся в базе данных:\n";
    int n = 0;
    product* arr = getProducts(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Товар " << i << ": ";
        arr[i].display();
    }
    delete[] arr;
}

void clearDatabase() {
    FILE *db = fopen("products.bin", "wb");
    fclose(db);
    std::cout << "База данных очищена.\n";
}

void addToDatabase() {
    int n = 0;
    fseek(databaseFile, 0L, SEEK_END);
    if (ftell(databaseFile) == SEEK_SET) {
        fwrite(&n, sizeof(int), 1, databaseFile);
    }
    std::cout << "Введите данные о товаре, который хотите добавить в базу.\n";
    product p;
    p.read();
    fseek(databaseFile, 0L, SEEK_SET);
    fread(&n, sizeof(int), 1, databaseFile);
    n++;
    fseek(databaseFile, 0L, SEEK_SET);
    fwrite(&n, sizeof(int), 1, databaseFile);
    fseek(databaseFile, 4L + (n - 1) * (long)sizeof(product), SEEK_SET);
    fwrite(&p, sizeof(product), 1, databaseFile);
    std::cout << "Товар добавлен в базу.\n";
}

void deleteFromDatabase() {
    if (emptyDb()) {
        std::cout << "База данных пустая, невозможно ничего удалить.\n";
        return;
    }
    displayDatabase();
    std::cout << "Введите номер товара, который хотите удалить из базы: ";
    int ndel;
    std::cin >> ndel;
    int n = 0;
    fseek(databaseFile, 0L, SEEK_SET);
    fread(&n, sizeof(int), 1, databaseFile);
    n--;
    fseek(databaseFile, 0L, SEEK_SET);
    fwrite(&n, sizeof(int), 1, databaseFile);
    fseek(databaseFile, 4L + ndel * (long)sizeof(product), SEEK_SET);
    while (ftell(databaseFile) < 4L + n * (long)sizeof(product)) {
        fseek(databaseFile, (long)sizeof(product), SEEK_CUR);
        product p;
        fread(&p, sizeof(product), 1, databaseFile);
        fseek(databaseFile, -(long)sizeof(product) * 2, SEEK_CUR);
        fwrite(&p, sizeof(product), 1, databaseFile);
    }
    std::cout << "Товар удален из базы.\n";
}

void editDatabase() {
    if (emptyDb()) {
        std::cout << "База данных пустая, нет товаров для редактирования.\n";
        return;
    }
    displayDatabase();
    std::cout << "Введите номер товара, информацию о котором хотите изменить: ";
    int ndel;
    std::cin >> ndel;
    fseek(databaseFile, 4L + ndel * (long)sizeof(product), SEEK_SET);
    product p;
    fread(&p, sizeof(product), 1, databaseFile);
    p.changeField();
    fseek(databaseFile, -(long)sizeof(product), SEEK_CUR);
    fwrite(&p, sizeof(product), 1, databaseFile);
    std::cout << "Информация о товаре изменена.\n";
}