#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;

extern int robotX;
extern int robotY;

vector<vector<char>> mapGrid(SIZE, vector<char>(SIZE, '.'));

void createTrash() {
    mapGrid[2][3] = 'M';
    mapGrid[5][5] = 'M';
    mapGrid[7][1] = 'M';
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
        cout << "Мусор убран!" << endl;
    } else {
        cout << "Здесь нет мусора!" << endl;
    }
}
