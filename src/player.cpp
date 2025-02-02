#include "player.h"

void Player::setPosition(Position position) {
    this->position = position;
};

Position Player::getPosition() const {
    return this->position;
};

void Player::draw() {
    glColor3f(0.0, 1.0, 0.0); // Verde
    glBegin(GL_QUADS);
        glVertex2f(this->position.x, this->position.y);
        glVertex2f(this->position.x + 1, this->position.y);
        glVertex2f(this->position.x + 1, this->position.y + 1);
        glVertex2f(this->position.x, this->position.y + 1);
    glEnd();
};