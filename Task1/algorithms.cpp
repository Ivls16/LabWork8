#include <iostream>
#include <cstring>
#include "product.h"

void sort(product* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[j + 1]) {
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
        arr[i].read();
    }
}

void addUntilBeer(product*& arr, int& n) {
    std::cout << "Новые товары будут добавляться до товара с наименованием 'пиво'.\n";
    while (true) {
        n++;
        arr = (product*)realloc(arr, n * sizeof(product));
        arr[n - 1].read();
        if (strcmp(arr[n - 1].name, "пиво") == 0) {
            break;
        }
    }
}

void addUntilEnd(product*& arr, int& n) {
    std::cout << "Новые товары будут добавляться, пока пользователь не введет 'конец'.\n";
    while (true) {
        n++;
        arr = (product*)realloc(arr, n * sizeof(product));
        arr[n - 1].read();
        if (strcmp(arr[n - 1].name, "конец") == 0) {
            break;
        }
    }
}

void displayAll(product*& arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "Товар " << i << ": ";
        arr[i].display();
    }
}

void findAllWithName(product*& arr, int& n) {
    std::cout << "Введите наименование, все товары с которым нужно найти.\n";
    char str[20];
    std::cin >> str;
    for (int i = 0; i < n; i++) {
        if (strcmp(str, arr[i].name) == 0) {
            arr[i].display();
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
            arr[i].display();
        }
        else {
            break;
        }
    }
}