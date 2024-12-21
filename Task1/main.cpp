#include <iostream>
#include "product_functions.h"

int main() {
    int n = 0;
    product *arr = nullptr;
    while (true) {
        std::cout << "Введите номер операции, которую хотите выполнить:\n"
                     "0:  Завершить работу программы.\n"
                     "1:  Добавить в массив записи об n товарах.\n"
                     "2:  Добавлять в массив записи о товарах, пока не появится пиво.\n"
                     "3:  Добавлять в массив записи о товарах, пока пользователь не введет 'конец'\n"
                     "4:  Вывести содержимое массива товаров.\n"
                     "5:  Поиск в массиве товаров с заданным наименованием.\n"
                     "6:  Удаление из массива товаров с заданным наименованием.\n"
                     "7:  Просмотреть базу данных товаров.\n"
                     "8:  Отсортировать товары по убыванию цены и вывести данные о тех, стоимость которых превышает 100.341.\n"
                     "9:  Добавить в базу запись о новом товаре.\n"
                     "10: Удалить из базы запись о товаре.\n"
                     "11: Изменить в базе запись о товаре.\n"
                     "12: Очистить базу данных.\n";
        int op;
        std::cin >> op;
        std::cout << "--------------------------------------------------\n";
        switch (op) {
            case 1:
                addNProducts(arr, n);
                break;
            case 2:
                addUntilBeer(arr, n);
                break;
            case 3:
                addUntilEnd(arr, n);
                break;
            case 4:
                displayAll(arr, n);
                break;
            case 5:
                findAllWithName(arr, n);
                break;
            case 6:
                deleteAllWithName(arr, n);
                break;
            case 7:
                displayDatabase();
                break;
            case 8:
                sortAndShow(arr, n);
                break;
            case 9:
                addToDatabase();
                break;
            case 10:
                deleteFromDatabase();
                break;
            case 11:
                editDatabase();
                break;
            case 12:
                clearDatabase();
                break;
            default:
                free(arr);
                return 0;
        }
        std::cout << "--------------------------------------------------\n";
    }
}