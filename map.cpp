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

void createTrash() {

    srand(time(0));

  

    int food = 2 + rand() % 4;     // 2–5
    int liquid = 2 + rand() % 4;   // 2–5
    int solid = 1 + rand() % 4;    // 1–4

    for (int i = 0; i < food; i++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        mapGrid[y][x] = 'F';
    }

    for (int i = 0; i < liquid; i++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        mapGrid[y][x] = 'L';
    }

    for (int i = 0; i < solid; i++) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        mapGrid[y][x] = 'S';
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

    char cell = mapGrid[robotY][robotX];

    if (cell == 'F') {
        mapGrid[robotY][robotX] = '.';
        score++;
        cout << "Пищевой мусор убран" << endl;
    }
    else if (cell == 'L') {
        mapGrid[robotY][robotX] = '.';
        score++;
        cout << "Жидкий мусор убран" << endl;
    }
    else if (cell == 'S') {
        mapGrid[robotY][robotX] = '.';
        score++;
        cout << "Твёрдый мусор убран" << endl;
    }
    else {
        cout << "Здесь нет мусора" << endl;
    }
}
