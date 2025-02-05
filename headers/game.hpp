#pragma once
#include "maze.hpp"

class Game {
public:
    Maze * maze;
    int tempo;
    bool playerCanMove;
    bool gameStarted;

    Game();

    void start(const char * file);
    void end();

private:
    /**
     * Carrega o labirinto a partir de um arquivo
     * @param file Caminho do arquivo
     * @return 1 se o arquivo foi carregado com sucesso, 0 caso contrário
     */
    int loadMaze(const char* file);
};