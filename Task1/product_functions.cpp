#include <iostream>
#include "product_functions.h"

void read(product_t &p) {
    std::cout << "Введите наименование товара: ";
    std::cin >> p.name;
    std::cout << "Введите стоимость товара: ";
    std::cin >> p.price;
    std::cout << "Введите количество товара: ";
    std::cin >> p.units;
    std::cout << "Введите дату получения товара: ";
    std::cin >> p.day >> p.month >> p.year;
    std::cout << "Жидкий ли товар?: ";
    std::cin >> p.liquid;
    std::cout << (p.liquid ? "Введите объем жидкости: " : "Введите массу товара: ");
    std::cin >> (p.liquid ? p.unit_size.volume : p.unit_size.mass);
}

void display(product_t &p) {
    std::cout << "["        << p.name << "]: "
                 "[price: " << p.price << "] "
                 "[units: " << p.units << "] "
                 "[date: "  << p.day << "." << p.month << "." << p.year << "] "
                 "[size: "  << (p.liquid ? p.unit_size.volume : p.unit_size.mass) << "]\n";
}

void changeField(product_t &p) {
    std::cout << "Введите номер поля, которое хотите изменить:\n"
                 "1: name\n2: price\n3: units\n4: date\n5: liquid\n6: unit_size\n";
    int f;
    std::cin >> f;
    std::cout << "Введите новое значение поля: ";
    switch (f) {
        case 1:
            std::cin >> p.name;
            break;
        case 2:
            std::cin >> p.price;
            break;
        case 3:
            std::cin >> p.units;
            break;
        case 4:
            std::cin >> p.day >> p.month >> p.year;
            break;
        case 5:
            std::cin >> p.liquid;
            break;
        case 6:
            std::cin >> (p.liquid ? p.unit_size.volume : p.unit_size.mass);
            break;
        default:
            break;
    }
}