#include <iostream>
#include "product.h"

void product_t::read() {
    std::cout << "Введите наименование товара: ";
    std::cin >> name;
    std::cout << "Введите стоимость товара: ";
    std::cin >> price;
    std::cout << "Введите количество товара: ";
    std::cin >> units;
    std::cout << "Введите дату получения товара: ";
    std::cin >> day >> month >> year;
    std::cout << "Жидкий ли товар?: ";
    std::cin >> liquid;
    std::cout << (liquid ? "Введите объем жидкости: " : "Введите массу товара: ");
    std::cin >> (liquid ? unit_size.volume : unit_size.mass);
}

void product_t::display() const {
    std::cout << "["        << name << "]: "
                 "[price: " << price << "] "
                 "[units: " << units << "] "
                 "[date: "  << day << "." << month << "." << year << "] "
                 "[size: "  << (liquid ? unit_size.volume : unit_size.mass) << "]\n";
}

bool product_t::operator < (product_t other) const {
    return price < other.price;
}

void product_t::changeField() {
    std::cout << "Введите номер поля, которое хотите изменить:\n"
                 "1: name\n2: price\n3: units\n4: date\n5: liquid\n6: unit_size\n";
    int f;
    std::cin >> f;
    std::cout << "Введите новое значение поля: ";
    switch (f) {
        case 1:
            std::cin >> name;
            break;
        case 2:
            std::cin >> price;
            break;
        case 3:
            std::cin >> units;
            break;
        case 4:
            std::cin >> day >> month >> year;
            break;
        case 5:
            std::cin >> liquid;
            break;
        case 6:
            std::cin >> (liquid ? unit_size.volume : unit_size.mass);
            break;
        default:
            break;
    }
}