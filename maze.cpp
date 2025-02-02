#include "maze.h"
#include <stdlib.h>

Maze::Maze(unsigned int rows, unsigned int cols) {
    this->rows = rows;
    this->cols = cols;

    this->grid = (char **) malloc(rows * sizeof(char *));
    for (unsigned i = 0; i < cols; ++i) {
        this->grid[i] = (char *) malloc(cols * sizeof(char));
    }
};

Maze::~Maze() {
    for (unsigned i = 0; i < cols; ++i) {
        free(this->grid[i]);
    }
    free(this->grid);
};

void Maze::setCountTreasures(unsigned int countTreasures) {
    this->countTreasures = countTreasures;
};

unsigned int Maze::getCountTreasures() const {
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
};