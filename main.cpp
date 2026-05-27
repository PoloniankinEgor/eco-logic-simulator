#include <iostream>
#include "functions.h"

using namespace std;

extern int robotX;
extern int robotY;

int main() {

    createTrash();

    string command;

    while (true) {

        drawMap();

        cout << "===== СИМУЛЯТОР ЭКО-ЛОГИКИ =====" << endl;
        cout << "Команды: UP DOWN LEFT RIGHT CLEAN EXIT" << endl;
        cout << "Введите команду: ";

        cin >> command;

        if (command == "UP") moveUp();
        else if (command == "DOWN") moveDown();
        else if (command == "LEFT") moveLeft();
        else if (command == "RIGHT") moveRight();
        else if (command == "CLEAN") cleanTrash();
        else if (command == "EXIT") break;
    }

    return 0;
}
