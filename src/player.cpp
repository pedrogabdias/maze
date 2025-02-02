#include "player.h"

void Player::setPosition(Position position) {
    this->position = position;
};

Position Player::getPosition() const {
    return this->position;
};
