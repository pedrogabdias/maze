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