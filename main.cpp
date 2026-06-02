#include <iostream>
#include <sstream>
#include "functions.h"

using namespace std;

extern int robotX;
extern int robotY;

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

        cout << "===== СИМУЛЯТОР ЭКО-ЛОГИКИ =====" << endl;
        cout << "Команды: UP DOWN LEFT RIGHT CLEAN EXIT" << endl;
        cout << "Введите команду: ";

        getline(cin, commands);

        if (command == "UP") moveUp();
        else if (command == "DOWN") moveDown();
        else if (command == "LEFT") moveLeft();
        else if (command == "RIGHT") moveRight();
        else if (command == "CLEAN") cleanTrash();
        else if (command == "EXIT") break;
    }

    return 0;
}
