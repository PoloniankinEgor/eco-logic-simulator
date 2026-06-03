#include <iostream>

using namespace std;

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

void moveUp() {

    if (robot.y > 0) {

        robot.y--;
        robot.moves++;
    }
}

void moveDown() {

    if (robot.y < 9) {

        robot.y++;
        robot.moves++;
    }
}

void moveLeft() {

    if (robot.x > 0) {

        robot.x--;
        robot.moves++;
    }
}

void moveRight() {

    if (robot.x < 9) {

        robot.x++;
        robot.moves++;
    }
}
