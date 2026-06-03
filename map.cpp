#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int SIZE = 10;

int getRobotX();
int getRobotY();

vector<vector<char>> mapGrid(SIZE, vector<char>(SIZE, '.'));

class Trash
{
public:

    char symbol;
    int energyCost;
};

class FoodTrash : public Trash
{
public:

    FoodTrash()
    {
        symbol = 'F';
        energyCost = 2;
    }
};

class LiquidTrash : public Trash
{
public:

    LiquidTrash()
    {
        symbol = 'L';
        energyCost = 3;
    }
};

class SolidTrash : public Trash
{
public:

    SolidTrash()
    {
        symbol = 'S';
        energyCost = 5;
    }
};

class EnergyBlock
{
public:

    char symbol;
    int value;
};

void createTrash()
{
    srand(time(0));

    int food = 2 + rand() % 4;
    int liquid = 2 + rand() % 4;
    int solid = 1 + rand() % 4;

    for (int i = 0; i < food; i++)
    {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        mapGrid[y][x] = 'F';
    }

    for (int i = 0; i < liquid; i++)
    {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        mapGrid[y][x] = 'L';
    }

    for (int i = 0; i < solid; i++)
    {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        mapGrid[y][x] = 'S';
    }

    int e3 = 1 + rand() % 3;
    int e5 = 1 + rand() % 3;
    int e10 = 1 + rand() % 2;

    for (int i = 0; i < e3; i++)
    {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        mapGrid[y][x] = '3';
    }

    for (int i = 0; i < e5; i++)
    {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        mapGrid[y][x] = '5';
    }

    for (int i = 0; i < e10; i++)
    {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        mapGrid[y][x] = 'T';
    }
}

void drawMap()
{
    system("cls");

    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {
            if (x == getRobotX() && y == getRobotY())
                cout << "R ";
            else
                cout << mapGrid[y][x] << " ";
        }

        cout << endl;
    }
}

void cleanTrash()
{
    int x = getRobotX();
    int y = getRobotY();

    char cell = mapGrid[y][x];

    if (cell == 'F')
    {
        mapGrid[y][x] = '.';
        cout << "Пищевой мусор убран" << endl;
    }

    else if (cell == 'L')
    {
        mapGrid[y][x] = '.';
        cout << "Жидкий мусор убран" << endl;
    }

    else if (cell == 'S')
    {
        mapGrid[y][x] = '.';
        cout << "Твердый мусор убран" << endl;
    }

    else if (cell == '3')
    {
        mapGrid[y][x] = '.';
        cout << "+3 энергии" << endl;
    }

    else if (cell == '5')
    {
        mapGrid[y][x] = '.';
        cout << "+5 энергии" << endl;
    }

    else if (cell == 'T')
    {
        mapGrid[y][x] = '.';
        cout << "+10 энергии" << endl;
    }

    else
    {
        cout << "Здесь ничего нет" << endl;
    }
}
