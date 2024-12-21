#include <iostream>
#include <cstring>
#include <fstream>
#include "item_functions.h"

char buffer[60];

int intLen(int x) {
    int res = 1;
    while (x > 10) {
        res++;
        x /= 10;
    }
    return res;
}

void read(item& p) {
    std::cout << "Введите тип предмета: ";
    std::cin >> p.type;
    std::cout << "Введите марку предмета: ";
    std::cin >> p.brand;
    std::cout << "Введите дату поступления предмета: ";
    std::cin >> p.day >> p.month >> p.year;
    std::cout << "Отремонтирован ли товар?: ";
    std::cin >> p.finished;
    std::cout << (p.finished ? "Сколько дней товар уже отремонтирован?: " : "Сколько дней осталось на ремонт товара?: ");
    std::cin >> (p.finished ? p.timer.ready : p.timer.left);
}

void readWithoutFeedback(item& p, std::fstream& in) {
    in >> p.type;
    in >> p.brand;
    in >> p.day >> p.month >> p.year;
    in >> p.finished;
    in >> (p.finished ? p.timer.ready : p.timer.left);
    in >> buffer;
}

void writeRaw(item& p, std::fstream& out) {
    out << p.type << ' ' << p.brand << ' ' << p.day << ' ' << p.month << ' ' << p.year << ' ' << p.finished << ' ' << (p.finished ? p.timer.ready : p.timer.left) << ' ';
    int ost = 58 - (int)strlen(p.type) - (int)strlen(p.brand) - intLen(p.day) - intLen(p.month) - intLen(p.year) - 1 - intLen(p.finished ? p.timer.ready : p.timer.left);
    for (int i = 0; i < ost; i++) {
        out << '$';
    }
    out << "# ";
}

void display(item &p) {
    std::cout << "\t["        << p.type << "]: "
                 "[brand: " << p.brand << "] "
                 "[date: "  << p.day << "." << p.month << "." << p.year << "] "
                 "[finished: " << p.finished << "] "
                 "[time : "  << (p.finished ? p.timer.ready : p.timer.left) << "]\n";
}

void displayWithoutType(item& p) {
    std::cout << "  [brand: " << p.brand << "] "
                 "[date: "  << p.day << "." << p.month << "." << p.year << "] "
                 "[finished: " << p.finished << "] "
                 "[time : "  << (p.finished ? p.timer.ready : p.timer.left) << "]\n";
}

void changeField(item& p) {
    std::cout << "Введите номер поля, которое хотите изменить:\n"
                 "1: type\n2: brand\n3: date\n4: finished\n5: timer\n";
    int f;
    std::cin >> f;
    std::cout << "Введите новое значение поля: ";
    switch (f) {
        case 1:
            std::cin >> p.type;
            break;
        case 2:
            std::cin >> p.brand;
            break;
        case 3:
            std::cin >> p.day >> p.month >> p.year;
            break;
        case 4:
            std::cin >> p.finished;
            break;
        case 5:
            std::cin >> (p.finished ? p.timer.ready : p.timer.left);
            break;
        default:
            break;
    }
}