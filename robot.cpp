#include <iostream>

using namespace std;

int robotX = 0;
int robotY = 0;

void moveUp() {
    if (robotY > 0) robotY--;
}

void moveDown() {
    if (robotY < 9) robotY++;
}

void moveLeft() {
    if (robotX > 0) robotX--;
}

void moveRight() {
    if (robotX < 9) robotX++;
}
