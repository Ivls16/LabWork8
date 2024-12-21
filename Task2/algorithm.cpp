#include <iostream>
#include <cstring>
#include "item_functions.h"

void sort(item* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (strcmp(arr[j].type, arr[j + 1].type) < 0) {
                std::swap(arr[j], arr[j + 1]);
            }
            else {
                break;
            }
        }
    }
}

void addNItems(item*& arr, int& n) {
    std::cout << "Введите, сколько предметов вы хотите добавить в массив.\n";
    int m;
    std::cin >> m;
    n += m;
    arr = (item*)realloc(arr, n * sizeof(item));
    for (int i = n - m; i < n; i++) {
        read(arr[i]);
    }
}

void deleteFromArray(item*& arr, int& n) {
    if (n == 0) {
        std::cout << "Массив пустой, невозможно ничего удалить.\n";
        return;
    }
    displayItems(arr, n);
    std::cout << "Введите номер предмета, который нужно удалить: ";
    int m;
    std::cin >> m;
    for (int i = m; i < n - 1; i++) {
        std::swap(arr[i], arr[i + 1]);
    }
    n--;
    arr = (item*)realloc(arr, n * sizeof(item));
    std::cout << "Предмет успешно удален.\n";
}

void editItem(item*& arr, int& n) {
    if (n == 0) {
        std::cout << "Массив пустой, невозможно ничего обновить.\n";
        return;
    }
    displayItems(arr, n);
    std::cout << "Введите номер предмета, информацию о котором нужно обновить: ";
    int m;
    std::cin >> m;
    changeField(arr[m]);
    std::cout << "Информация о предмете успешно обновлена.\n";
}

void displayItems(item*& arr, int& n) {
    std::cout << "Предметы, хранящиеся в массиве:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Предмет " << i << ": ";
        display(arr[i]);
    }
}

void displayItemsStats(item*& arr, int& n) {
    sort(arr, n);
    std::cout << "Информация о предметах по типам:\n";
    for (int i = 0; i < n; i++) {
        if (i == 0 || strcmp(arr[i].type, arr[i - 1].type) != 0) {
            std::cout << "[" << arr[i].type << "]:\n";
        }
        displayWithoutType(arr[i]);
    }
}