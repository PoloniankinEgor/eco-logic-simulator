#include <iostream>
#include <sstream>
#include "functions.h"

using namespace std;

extern int robotX;
extern int robotY;
extern int score;
extern int moves;

int main() {
    

    createTrash();
   cout << "Добро пожаловать в Симулятор Эко-Логики!" << endl;
cout << "Очистите лес от мусора и завершите симуляцию." << endl;
cout << endl;

cout << "Управляйте роботом и очищайте лес от мусора" << endl;
cout << "===== СИМУЛЯТОР ЭКО-ЛОГИКИ =====" << endl;
cout << "===================================" << endl;
    
string commands;

    while (true) {

    drawMap();

    cout << "Собрано мусора: " << score << endl;
    cout << "Количество ходов: " << moves << endl;
    cout << endl;

    cout << "===== СИМУЛЯТОР ЭКО-ЛОГИКИ =====" << endl;
        cout << "Команды: UP DOWN LEFT RIGHT CLEAN EXIT" << endl;
        cout << "Введите команду: ";

        getline(cin, commands);

stringstream ss(commands);

string command;

while (ss >> command) {

    if (command == "UP")
        moveUp();

    else if (command == "DOWN")
        moveDown();

    else if (command == "LEFT")
        moveLeft();

    else if (command == "RIGHT")
        moveRight();

    else if (command == "CLEAN")
        cleanTrash();

    else if (command == "EXIT")
        return 0;
}
    }

    return 0;
}
