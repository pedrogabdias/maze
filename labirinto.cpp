#include <GL/glut.h>
#include "maze.cpp"
#include "player.cpp"
#include <fstream>
#include <iostream>

using namespace std;

Maze * maze;

/**
 * Carrega o labirinto a partir de um arquivo
 * @param file Caminho do arquivo
 * @return 0 se o arquivo foi carregado com sucesso, 1 caso contrário
 */
int loadMaze(const char* file) {
    unsigned int rows, cols;
    std::ifstream input(file);

    if (!input.is_open()) {
        return 1;
    }

    input >> rows >> cols;
    maze = new Maze(rows, cols);

    Position playerPosition;
    input >> playerPosition.x >> playerPosition.y;

    maze->player.setPosition(playerPosition);

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            input >> maze->grid[i][j];
            if (maze->grid[i][j] == '*') {
                maze->setCountTreasures(maze->getCountTreasures() + 1);
            }
        }
    }

    cout << "Player position: " << maze->player.getPosition().x << " " << maze->player.getPosition().y << endl;
    cout << "Treasures: " << maze->getCountTreasures() << endl;
    cout << "Maze:" << endl;
    cout << "----------------" << endl;

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            cout << maze->grid[i][j];
        }
        cout << endl;
    }

    input.close();
    return 0;
};

/**
 * Responsavel pela configuração inicial
 */
void initGL() {
    loadMaze("mapa1.txt");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, maze->getCols(), maze->getRows(), 0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);
    maze->draw();
    glFlush();
}

int main (int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Labirinto");
    glutDisplayFunc(display);
    initGL();

    glutMainLoop();

    return 0;
}