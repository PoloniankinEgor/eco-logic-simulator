#pragma once

void drawMap();
void createTrash();
void cleanTrash();

void moveUp();
void moveDown();
void moveLeft();
void moveRight();

void moveTo(int x, int y);

int getRobotX();
int getRobotY();

int getRobotEnergy();
int getRobotScore();
int getRobotMoves();

void addEnergy(int value);
void spendEnergy(int value);
void addScore();

void autoClean();
