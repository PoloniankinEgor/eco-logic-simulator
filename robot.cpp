#include <iostream>

using namespace std;

int robotX = 0;
int robotY = 0;
int score = 0;
int moves = 0;

void moveUp() {

    if (robotY > 0) {

        robotY--;
        moves++;
    }
}

void moveDown() {

    if (robotY < 9) {

        robotY++;
        moves++;
    }
}

void moveLeft() {

    if (robotX > 0) {

        robotX--;
        moves++;
    }
}

void moveRight() {

    if (robotX < 9) {

        robotX++;
        moves++;
    }
}
