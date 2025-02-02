#pragma once

typedef struct {
    unsigned int x, y;	
} Position;

class Player {
public:
    void setPosition(Position position);
    Position getPosition() const;
private:
    Position position;
};