#include "game.hpp"
#include <fstream>

Game::Game() {
    this->maze = nullptr;
    this->tempo = 0;
    this->playerCanMove = true;
    this->gameStarted = false;
}

void Game::start(const char * file) {
    this->gameStarted = true;
    if (this->loadMaze(file) == 1) {
        this->end();
    }
}

void Game::end() {
    this->gameStarted = false;
    delete this->maze;
}

int Game::loadMaze(const char* file) {
    unsigned int rows, cols;
    std::ifstream input(file);

    if (!input.is_open()) {
        return 1;
    }

    input >> rows >> cols;
    this->maze = new Maze(rows, cols);

    Position playerPosition;
    input >> playerPosition.x >> playerPosition.y;

    this->maze->player.setPosition(playerPosition);

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            input >> this->maze->grid[i][j];
            if (this->maze->grid[i][j] == '*') {
                this->maze->setCountTreasures(this->maze->getCountTreasures() + 1);
            }
        }
    }

    return 0;
}