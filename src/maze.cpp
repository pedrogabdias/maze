#include "maze.h"
#include <stdlib.h>
#include <GL/gl.h>
#include <math.h>
#define M_PI 3.14159265358979323846

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
    if (this->grid[position.y][position.x] == '*' && this->countTreasures > 0) {
        this->grid[position.y][position.x] = '0';
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

void drawCircle(float cx, float cy, float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Centro do círculo
    for (int i = 0; i <= segments; i++) {
        float angle = 2.0f * M_PI * i / segments;
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void Maze::draw() {
    // Definindo o fundo branco
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Branco (RGBA)
    glClear(GL_COLOR_BUFFER_BIT);        // Limpando o buffer de cor
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            if (this->grid[i][j] == '*') {
                glColor3f(1.0, 1.0, 0.0); // Amarelo

                // Desenhar os tesouros como circulos
                float centerX = j + 0.5f; // Centralizar no bloco
                float centerY = i + 0.5f;
                float radius = 0.25f;      // Tamanho da bolinha
                drawCircle(centerX, centerY, radius, 30);

            } else {
                if (this->grid[i][j] == '0') {
                    glColor3f(1.0, 1.0, 1.0); // Branco
                } else {
                    glColor3f(0.0, 0.0, 0.0); // Preto
                }

                // Desenhar o quadrado
                glBegin(GL_QUADS);
                glVertex2f(j, i);
                glVertex2f(j + 1, i);
                glVertex2f(j + 1, i + 1);
                glVertex2f(j, i + 1);
                glEnd();
            }
        }
    }

    this->player.draw();
}

void Maze::movePlayer(Position newPosition) {
    if (this->checkCollision(newPosition) == 0) {
        this->player.setPosition(newPosition);
        this->collectTreasure(newPosition);
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