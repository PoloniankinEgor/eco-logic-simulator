#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int SIZE = 10;

int getRobotX();
int getRobotY();

int getRobotEnergy();

void addEnergy(int value);
void spendEnergy(int value);
void addScore();

void moveTo(int x, int y);

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

    int e3 = 1 + rand() % 3;
    int e5 = 1 + rand() % 3;
    int e10 = 1 + rand() % 2;

    for (int i = 0; i < food; i++)
        mapGrid[rand() % SIZE][rand() % SIZE] = 'F';

    for (int i = 0; i < liquid; i++)
        mapGrid[rand() % SIZE][rand() % SIZE] = 'L';

    for (int i = 0; i < solid; i++)
        mapGrid[rand() % SIZE][rand() % SIZE] = 'S';

    for (int i = 0; i < e3; i++)
        mapGrid[rand() % SIZE][rand() % SIZE] = '3';

    for (int i = 0; i < e5; i++)
        mapGrid[rand() % SIZE][rand() % SIZE] = '5';

    for (int i = 0; i < e10; i++)
        mapGrid[rand() % SIZE][rand() % SIZE] = 'T';
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

    if (cell == 'F' && getRobotEnergy() >= 2)
    {
        spendEnergy(2);
        addScore();
        mapGrid[y][x] = '.';
    }

    if (cell == 'L' && getRobotEnergy() >= 3)
    {
        spendEnergy(3);
        addScore();
        mapGrid[y][x] = '.';
    }

    if (cell == 'S' && getRobotEnergy() >= 5)
    {
        spendEnergy(5);
        addScore();
        mapGrid[y][x] = '.';
    }

    if (cell == '3')
    {
        addEnergy(3);
        mapGrid[y][x] = '.';
    }

    if (cell == '5')
    {
        addEnergy(5);
        mapGrid[y][x] = '.';
    }

    if (cell == 'T')
    {
        addEnergy(10);
        mapGrid[y][x] = '.';
    }
}

void autoClean()
{
    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {
            if (
                mapGrid[y][x] == '3' ||
                mapGrid[y][x] == '5' ||
                mapGrid[y][x] == 'T'
            )
            {
                moveTo(x, y);
                cleanTrash();
            }
        }
    }

    for (int y = 0; y < SIZE; y++)
    {
        for (int x = 0; x < SIZE; x++)
        {
            if (
                mapGrid[y][x] == 'F' ||
                mapGrid[y][x] == 'L' ||
                mapGrid[y][x] == 'S'
            )
            {
                moveTo(x, y);
                cleanTrash();
            }
        }
    }

    cout << endl;
    cout << "Очистка завершена!" << endl;
}
