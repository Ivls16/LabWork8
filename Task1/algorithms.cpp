#include <iostream>
#include <cstring>
#include "product_functions.h"

void sort(product* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j].price < arr[j + 1].price) {
                std::swap(arr[j], arr[j + 1]);
            }
            else {
                break;
            }
        }
    }
}

void addNProducts(product*& arr, int& n) {
    std::cout << "Введите, сколько товаров вы хотите добавить в массив.\n";
    int m;
    std::cin >> m;
    n += m;
    arr = (product*)realloc(arr, n * sizeof(product));
    for (int i = n - m; i < n; i++) {
        read(arr[i]);
    }
}

void addUntilBeer(product*& arr, int& n) {
    std::cout << "Новые товары будут добавляться до товара с наименованием 'пиво'.\n";
    while (true) {
        n++;
        arr = (product*)realloc(arr, n * sizeof(product));
        read(arr[n - 1]);
        if (strcmp(arr[n - 1].name, "пиво") == 0) {
            break;
        }
    }
}

void addUntilEnd(product*& arr, int& n) {
    while (true) {
        std::cout << "Хотите продолжить ввод?(0 или 1): ";
        bool cont;
        std::cin >> cont;
        if (!cont) {
            break;
        }
        n++;
        arr = (product*)realloc(arr, n * sizeof(product));
        read(arr[n - 1]);
        if (strcmp(arr[n - 1].name, "конец") == 0) {
            break;
        }
    }
}

void displayAll(product*& arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Товар " << i << ": ";
        display(arr[i]);
    }
}

void findAllWithName(product*& arr, int& n) {
    std::cout << "Введите наименование, все товары с которым нужно найти.\n";
    char str[20];
    std::cin >> str;
    for (int i = 0; i < n; i++) {
        if (strcmp(str, arr[i].name) == 0) {
            display(arr[i]);
        }
    }
}

void deleteAllWithName(product*& arr, int& n) {
    std::cout << "Введите наименование, все товары с которым нужно удалить.\n";
    char str[20];
    std::cin >> str;
    for (int i = 0; i < n; i++) {
        if (strcmp(str, arr[i].name) == 0) {
            n--;
            for (int j = i; j < n; j++) {
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }
    arr = (product*)realloc(arr, n * sizeof(product));
}

void sortAndShow(product*& arr, int& n) {
    sort(arr, n);
    for (int i = 0; i < n; i++) {
        if (arr[i].price > 100.341) {
            display(arr[i]);
        }
        else {
            break;
        }
    }
}