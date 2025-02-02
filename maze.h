#pragma once

#include "player.h"

class Maze {
public:
    char ** grid;
    Player player;

    Maze(unsigned int rows, unsigned int cols);
    ~Maze();
    void setCountTreasures(unsigned int countTreasures);
    unsigned int getCountTreasures() const;

    /**
     * Coleta um tesouro na posição especificada
     * @param position Posição do tesouro
     * @return 1 se o tesouro foi coletado, 0 caso contrário
     */
    int collectTreasure(Position position);
private:
    unsigned int rows, cols, countTreasures;
};