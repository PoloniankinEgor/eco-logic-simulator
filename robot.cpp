#include <iostream>
#include <windows.h>

using namespace std;

void drawMap();

class Robot
{
public:

    int x;
    int y;

    int energy;

    int score;

    int moves;

    Robot()
    {
        x = 0;
        y = 0;

        energy = 20;

        score = 0;

        moves = 0;
    }
};

Robot robot;

int getRobotX()
{
    return robot.x;
}

int getRobotY()
{
    return robot.y;
}

int getRobotEnergy()
{
    return robot.energy;
}

int getRobotScore()
{
    return robot.score;
}

int getRobotMoves()
{
    return robot.moves;
}

void addEnergy(int value)
{
    robot.energy += value;
}

void spendEnergy(int value)
{
    robot.energy -= value;
}

void addScore()
{
    robot.score++;
}

void moveUp()
{
    if (robot.y > 0)
    {
        robot.y--;
        robot.moves++;
    }
}

void moveDown()
{
    if (robot.y < 9)
    {
        robot.y++;
        robot.moves++;
    }
}

void moveLeft()
{
    if (robot.x > 0)
    {
        robot.x--;
        robot.moves++;
    }
}

void moveRight()
{
    if (robot.x < 9)
    {
        robot.x++;
        robot.moves++;
    }
}

void moveTo(int targetX, int targetY)
{
    while (robot.x < targetX)
    {
        moveRight();

        drawMap();

        Sleep(200);
    }

    while (robot.x > targetX)
    {
        moveLeft();

        drawMap();

        Sleep(200);
    }

    while (robot.y < targetY)
    {
        moveDown();

        drawMap();

        Sleep(200);
    }

    while (robot.y > targetY)
    {
        moveUp();

        drawMap();

        Sleep(200);
    }
}
