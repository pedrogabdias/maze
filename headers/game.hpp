#pragma once
#include "maze.hpp"

class Game {
public:
    Maze * maze;
    unsigned int tempo;
    bool playerCanMove;
    bool gameStarted;

    Game();

    void start(const char * file);
    void end();

private:
    /**
     * Carrega o labirinto a partir de um arquivo
     * @param file Caminho do arquivo
     * @return 0 se o arquivo foi carregado com sucesso, 1 caso contrário
     */
    int loadMaze(const char* file);

};