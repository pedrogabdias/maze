#pragma once

typedef struct {
    int x, y;	
} Position;

class Player {
public:
    void setPosition(Position position);
    Position getPosition() const;
    void draw();
private:
    Position position;
};