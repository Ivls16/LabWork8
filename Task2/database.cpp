#include <iostream>
#include <fstream>
#include "item.h"

void clearDatabase() {
    std::ofstream out;
    out.open("database.txt");
    out << "0       $\n";
    out.close();
}

void displayDatabase() {
    std::fstream in;
    in.open("database.txt");
    int n;
    in >> n;
    char buffer;
    in >> buffer;
    item* arr = new item[n];
    for (int i = 0; i < n; i++) {
        arr[i].readWithoutFeedback(in);
    }
    displayItems(arr, n);
    delete[] arr;
    in.close();
}

void addToDatabase() {
    std::cout << "Введите данные о предмете, который необходимо добавить в базу данных.\n";
    item p;
    p.read();
    std::fstream io;
    io.open("database.txt", std::ios::in | std::ios::out);
    int n;
    io >> n;
    n++;
    io.seekp(NUMBER_BUFFER + ITEM_BUFFER * (n - 1));
    io << ' ';
    p.writeRaw(io);
    io.seekp(0);
    io << n;
    for (int i = 0; i < 8 - intLen(n); i++) {
        io << ' ';
    }
    io << "$ ";
    io.close();
}

void deleteFromDatabase() {
    std::fstream io;
    io.open("database.txt", std::ios::in | std::ios::out);
    int n;
    io >> n;
    if (n == 0) {
        std::cout << "База данных пуста, нечего удалять.\n";
        io.close();
        return;
    }
    displayDatabase();
    std::cout << "Введите номер предмета, который нужно удалить из базы: ";
    int m;
    std::cin >> m;
    for (int i = m; i < n - 1; i++) {
        io.seekp(NUMBER_BUFFER + ITEM_BUFFER * (i + 1));
        item p;
        p.readWithoutFeedback(io);
        io.seekp(NUMBER_BUFFER + ITEM_BUFFER * i);
        p.writeRaw(io);
    }
    n--;
    io.seekp(0);
    io << n;
    for (int i = 0; i < 8 - intLen(n); i++) {
        io << ' ';
    }
    io << "$ ";
    std::cout << "Предмет успешно удален.\n";
    io.close();
}

void changeInDatabase() {
    std::fstream io;
    io.open("database.txt", std::ios::in | std::ios::out);
    int n;
    io >> n;
    if (n == 0) {
        std::cout << "База данных пуста, нечего изменять.\n";
        io.close();
        return;
    }
    displayDatabase();
    std::cout << "Введите номер предмета, информацию о котором нужно изменить: ";
    int m;
    std::cin >> m;
    item p;
    io.seekp(NUMBER_BUFFER + ITEM_BUFFER * m);
    p.readWithoutFeedback(io);
    p.changeField();
    io.seekp(NUMBER_BUFFER + ITEM_BUFFER * m);
    p.writeRaw(io);
    std::cout << "Информация о предмете успешно обновлена.\n";
    io.close();
}