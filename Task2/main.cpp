#include <iostream>
#include "item.h"

int main() {
    int n = 0;
    item *arr = nullptr;
    while (true) {
        std::cout << "Введите номер операции, которую хотите выполнить:\n"
                     "0:  Завершить работу программы.\n"
                     "1:  Добавить в массив записи об n предметах.\n"
                     "2:  Удалить из массива запись о предмете.\n"
                     "3:  Обновить запись о предмете.\n"
                     "4:  Вывести содержимое массива предметов.\n"
                     "5:  Вывести статистику по группам предметов.\n"
                     "6:  Просмотреть базу данных предметов.\n"
                     "7:  Добавить в базу запись о новом предмете.\n"
                     "8:  Удалить из базы запись о предмете.\n"
                     "9:  Обновить в базе запись о предмете.\n"
                     "10: Очистить базу данных.\n";
        int op;
        std::cin >> op;
        std::cout << "--------------------------------------------------\n";
        switch (op) {
            case 1:
                addNItems(arr, n);
                break;
            case 2:
                deleteFromArray(arr, n);
                break;
            case 3:
                editItem(arr, n);
                break;
            case 4:
                displayItems(arr, n);
                break;
            case 5:
                displayItemsStats(arr, n);
                break;
            case 6:
                displayDatabase();
                break;
            case 7:
                addToDatabase();
                break;
            case 8:
                deleteFromDatabase();
                break;
            case 9:
                changeInDatabase();
                break;
            case 10:
                clearDatabase();
                break;
            default:
                free(arr);
                return 0;
        }
        std::cout << "--------------------------------------------------\n";
    }
}