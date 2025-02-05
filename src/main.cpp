#include <GL/glut.h>
#include "maze.cpp"
#include "player.cpp"
#include <fstream>
#include <iostream>
#include <string>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"
#include "game.cpp"

GLuint wallTexture;
#define VELOCITY_OF_PLAYER_MS 150

using namespace std;

Game game;

/**
 * Renderiza um texto na tela
 * @param x Posição x
 * @param y Posição y
 * @param text Texto a ser renderizado
 */
void renderText(float x, float y, const char* text) {
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *text);
        text++;
    }
}

/**
 * Habilita o movimento do player
 */
void enableMove(int value) {
    if (game.gameStarted) {
        game.playerCanMove = true;
    }
    glutTimerFunc(VELOCITY_OF_PLAYER_MS, enableMove, 0); // atualizar a cada tempo
}

GLuint loadTexture(const char* filename) {
    int width, height, nrChannels;
    unsigned char* data = stbi_load(filename, &width, &height, &nrChannels, 0);
    if (!data) {
        cerr << "Falha ao carregar a textura: " << filename << endl;
        return 0;
    }

    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Configuração de parâmetros da textura
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);

    return textureID;
}


/**
 * Trata o evento de teclado
 * @param key Tecla pressionada
 * @param x Posição x do mouse
 * @param y Posição y do mouse
 */
void keyboard(unsigned char key, int x, int y) {
    if (game.gameStarted) {
        if (!game.playerCanMove) {
            return;
        } else {
            Position newPlayerPosition = game.maze->player.getPosition();
            switch (key) {
                case 'w':
                    newPlayerPosition.y--;
                    game.maze->movePlayer(newPlayerPosition);
                    break;
                case 's':
                    newPlayerPosition.y++;
                    game.maze->movePlayer(newPlayerPosition);
                    break;
                case 'a':
                    newPlayerPosition.x--;
                    game.maze->movePlayer(newPlayerPosition);
                    break;
                case 'd':
                    newPlayerPosition.x++;
                    game.maze->movePlayer(newPlayerPosition);
                    break;
                case 'q':
                    game.end();
                    break;
            }
            game.playerCanMove = false;
        }
        
    } else {
        switch (key)
        {
            case '1':
                game.start("assets/maps/mapa1.txt");
                break;
            case '2':
                game.start("assets/maps/mapa2.txt");
                break;
            case '3':
                game.start("assets/maps/mapa3.txt");
                break;
            case '4':
                game.start("assets/maps/mapa4.txt");
                break;
            case '5':
                game.start("assets/maps/mapa5.txt");
                break;
        }
    }

    if (key == 27) { // Tecla ESC (valor 27)
        exit(0); // Encerra o programa
    }
    
    glutPostRedisplay();
}

/**
 * Responsavel pela configuração inicial
 */
void initGL() {
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 10, 10, 0);
    wallTexture = loadTexture("assets/textures/parede_3.jpg"); // Realiza a leitura da textura
    glEnable(GL_TEXTURE_2D); // Habilitar texturas 2D
}

/**
 * Responsavel por renderizar a tela
 */
void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Define o fundo preto
    glClear(GL_COLOR_BUFFER_BIT);
    if (game.gameStarted) {
        if (game.maze->getCountTreasures() == 0) {
            glColor3f(1.0f, 1.0f, 0.0f);
            renderText(game.maze->getCols()/2-1, game.maze->getRows()/2-3, "You Win!");
            renderText(game.maze->getCols()/2-1, game.maze->getRows()/2-2, ("Time: " + to_string(game.tempo)).c_str());
            renderText(game.maze->getCols()/2-1, game.maze->getRows()/2-1, "esc -> sair do jogo");
            renderText(game.maze->getCols()/2-1, game.maze->getRows()/2, "q -> voltar ao menu");

        } else {
            game.maze->draw(wallTexture);
            glColor3f(1.0f, 1.0f, 1.0f);
            renderText(1, 0.8, ("Time: " + to_string(game.tempo)).c_str());
            glColor3f(1.0f, 1.0f, 1.0f);
            renderText(3, 0.8, ("Tesouros: " + to_string(game.maze->getCountTreasures())).c_str());
            glColor3f(1.0f, 1.0f, 1.0f);
        }
    } else {
        glColor3f(1.0f, 1.0f, 0.0f);
        renderText(10/2-1, 10/2-3, "Labirinto");
        renderText(10/2-1, 10/2-2, "1 -> Mapa 1");
        renderText(10/2-1, 10/2-1, "2 -> Mapa 2");
        renderText(10/2-1, 10/2, "3 -> Mapa 3");
        renderText(10/2-1, 10/2+1, "4 -> Mapa 4");
        renderText(10/2-1, 10/2+2, "5 -> Mapa 5");
        renderText(10/2-1, 10/2+4, "esq -> sair do jogo");
    }

    glFlush();
}

/**
 * Atualiza o tempo
 */
void timer(int value) {
    if (game.gameStarted && game.maze->getCountTreasures() > 0) {
        game.tempo ++;
    }
    glutPostRedisplay();
    glutTimerFunc(1000, timer, 0); // atualizar a cada segundo
}

void reshape(int w, int h) {
    // Defina o tamanho fixo da janela
    glutReshapeWindow(800, 600);
}

int main (int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Labirinto");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    initGL();

    glutTimerFunc(0, enableMove, 0);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}