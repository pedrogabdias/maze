#include "maze.h"
#include <stdlib.h>

Maze::Maze(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;

    this->grid = (char **) malloc(rows * sizeof(char *));
    for (int i = 0; i < cols; ++i) {
        this->grid[i] = (char *) malloc(cols * sizeof(char));
    }
};

Maze::~Maze() {
    for (int i = 0; i < cols; ++i) {
        free(this->grid[i]);
    }
    free(this->grid);
};

void Maze::setCountTreasures(int countTreasures) {
    this->countTreasures = countTreasures;
};

int Maze::getCountTreasures() const {
    return this->countTreasures;
};

int Maze::collectTreasure(Position position) {
    if (this->grid[position.x][position.y] == '*' && this->countTreasures > 0) {
        this->grid[position.x][position.y] = '0';
        this->countTreasures--;
        return 1;
    }
    return 0;
};

int Maze::getRows() const {
    return this->rows;
};

int Maze::getCols() const {
    return this->cols;
};

void Maze::draw() {
    for (unsigned int i = 0; i < this->rows; ++i) {
        for (unsigned int j = 0; j < this->cols; ++j) {
            if (this->grid[i][j] == '*') {
                glColor3f(1.0, 1.0, 0.0); // Amarelo
            } else if (this->grid[i][j] == '0') {
                glColor3f(1.0, 1.0, 1.0); // Branco
            } else {
                glColor3f(0.0, 0.0, 0.0); // Preto
            }

            glBegin(GL_QUADS);
            glVertex2f(j, i);
            glVertex2f(j + 1, i);
            glVertex2f(j + 1, i + 1);
            glVertex2f(j, i + 1);
            glEnd();
        }
    }

    this->player.draw();
};

void Maze::movePlayer(Position newPosition) {
    if (this->checkCollision(newPosition) == 0) {
        this->player.setPosition(newPosition);
    }
};

int Maze::checkCollision(Position position) {
    if (position.x < 0 || position.x >= this->cols || position.y < 0 || position.y >= this->rows) {
        return 1;
    }
    if (this->grid[position.y][position.x] == '1') {
        return 1;
    }
    return 0;
};