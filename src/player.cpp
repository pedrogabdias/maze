#include "player.hpp"
#include <GL/gl.h>
#include <cmath> 
#define M_PI 3.14159265358979323846

void Player::setPosition(Position position) {
    this->position = position;
};

Position Player::getPosition() const {
    return this->position;
};

//Função auxiliar para desenhar um círculo
void drawCircle2(float cx, float cy, float radius, int segments) {
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy); //Centro do círculo
        for (int i = 0; i <= segments; i++) {
            float angle = 2.0f * M_PI * i / segments;
            float x = cx + radius * cos(angle);
            float y = cy + radius * sin(angle);
            glVertex2f(x, y);
        }
    glEnd();
}

void Player::draw() {
    float centerX = this->position.x + 0.5f; //Centraliza na célula
    float centerY = this->position.y + 0.5f;
    float outerRadius = 0.45f; //Raio externo do anel
    float innerRadius = 0.25f; //Raio interno (furo)
    int segments = 40;         //Suavidade do círculo 

    //Cor do anel
    glColor3f(0.6, 0.8, 0.2); //Verde Amarelado
    drawCircle2(centerX, centerY, outerRadius, segments);

    //Cor do furo central
    glColor3f(1.0, 1.0, 1.0); //Branco 
    drawCircle2(centerX, centerY, innerRadius, segments);
};