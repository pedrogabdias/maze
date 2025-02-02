#pragma once

#include "player.h"

class Maze {
public:
    char ** grid;
    Player player;

    Maze(int rows, int cols);
    ~Maze();

    void setCountTreasures(int countTreasures);
    int getCountTreasures() const;

    int getRows() const;
    int getCols() const;

    /**
     * Coleta um tesouro na posição especificada
     * @param position Posição do tesouro
     * @return 1 se o tesouro foi coletado, 0 caso contrário
     */
    int collectTreasure(Position position);

    void draw();

    void movePlayer(Position newPosition);
private:
    int rows, cols, countTreasures;

    int checkCollision(Position position);
};