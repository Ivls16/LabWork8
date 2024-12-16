#include <iostream>
#include <cstring>
#include <fstream>
#include "item.h"

char buffer[60];

int intLen(int x) {
    int res = 1;
    while (x > 10) {
        res++;
        x /= 10;
    }
    return res;
}

void item::read() {
    std::cout << "Введите тип предмета: ";
    std::cin >> type;
    std::cout << "Введите марку предмета: ";
    std::cin >> brand;
    std::cout << "Введите дату поступления предмета: ";
    std::cin >> day >> month >> year;
    std::cout << "Отремонтирован ли товар?: ";
    std::cin >> finished;
    std::cout << (finished ? "Сколько дней товар уже отремонтирован?: " : "Сколько дней осталось на ремонт товара?: ");
    std::cin >> (finished ? timer.ready : timer.left);
}

void item::readWithoutFeedback(std::fstream& in) {
    in >> type;
    in >> brand;
    in >> day >> month >> year;
    in >> finished;
    in >> (finished ? timer.ready : timer.left);
    in >> buffer;
}

void item::writeRaw(std::fstream& out) {
    out << type << ' ' << brand << ' ' << day << ' ' << month << ' ' << year << ' ' << finished << ' ' << (finished ? timer.ready : timer.left) << ' ';
    int ost = 58 - (int)strlen(type) - (int)strlen(brand) - intLen(day) - intLen(month) - intLen(year) - 1 - intLen(finished ? timer.ready : timer.left);
    for (int i = 0; i < ost; i++) {
        out << '$';
    }
    out << "# ";
}

void item::display() const {
    std::cout << "\t["        << type << "]: "
                 "[brand: " << brand << "] "
                 "[date: "  << day << "." << month << "." << year << "] "
                 "[finished: " << finished << "] "
                 "[time : "  << (finished ? timer.ready : timer.left) << "]\n";
}

void item::displayWithoutType() const {
    std::cout << "  [brand: " << brand << "] "
                 "[date: "  << day << "." << month << "." << year << "] "
                 "[finished: " << finished << "] "
                 "[time : "  << (finished ? timer.ready : timer.left) << "]\n";
}

bool item::operator > (item other) const {
    return strcmp(type, other.type) < 0;
}

void item::changeField() {
    std::cout << "Введите номер поля, которое хотите изменить:\n"
                 "1: type\n2: brand\n3: date\n4: finished\n5: timer\n";
    int f;
    std::cin >> f;
    std::cout << "Введите новое значение поля: ";
    switch (f) {
        case 1:
            std::cin >> type;
            break;
        case 2:
            std::cin >> brand;
            break;
        case 3:
            std::cin >> day >> month >> year;
            break;
        case 4:
            std::cin >> finished;
            break;
        case 5:
            std::cin >> (finished ? timer.ready : timer.left);
            break;
        default:
            break;
    }
}