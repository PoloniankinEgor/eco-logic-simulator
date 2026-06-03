#include <iostream>

#include "functions.h"

using namespace std;

int main()
{
    createTrash();

    cout << "===== СИМУЛЯТОР ЭКО-ЛОГИКИ =====" << endl;
    cout << "Начальная энергия: 20" << endl;
    cout << endl;

    drawMap();

    cout << endl;
    cout << "Введите GO для запуска робота" << endl;

    string command;

    cin >> command;

    if (command == "GO")
    {
        autoClean();

        cout << endl;

        cout << "Собрано мусора: "
             << getRobotScore()
             << endl;

        cout << "Осталось энергии: "
             << getRobotEnergy()
             << endl;

        cout << "Количество ходов: "
             << getRobotMoves()
             << endl;
    }

    return 0;
}
