#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int SIZE = 10;

extern int robotX;
extern int robotY;
extern int score;
extern int moves;

vector<vector<char>> mapGrid(SIZE, vector<char>(SIZE, '.'));
int trashCount = 3;

void createTrash() {

    srand(time(0));

    int created = 0;

    while (created < 3) {

        int x = rand() % SIZE;
        int y = rand() % SIZE;

        if (mapGrid[y][x] != 'M') {

            mapGrid[y][x] = 'M';
            created++;
        }
    }
}

    for (int i = 0; i < 3; i++) {

        int x = rand() % 10;
        int y = rand() % 10;

        mapGrid[y][x] = 'M';
    }
}

void drawMap() {

    system("cls");

    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {

            if (x == robotX && y == robotY)
                cout << "R ";
            else
                cout << mapGrid[y][x] << " ";
        }
        cout << endl;
    }
}

void cleanTrash() {

    if (mapGrid[robotY][robotX] == 'M') {

    mapGrid[robotY][robotX] = '.';

    score++;

    trashCount--;

    cout << "Мусор убран!" << endl;
} else {
        cout << "Здесь нет мусора!" << endl;
    }
    if (trashCount == 0) {

    cout << "Поздравляем! Весь лес очищен!" << endl;
    cout << "Количество ходов: " << moves << endl;
    cout << "Собрано мусора: " << score << endl;
}
}
