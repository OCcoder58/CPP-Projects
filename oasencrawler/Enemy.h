#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class World;

class Enemy {
private:
    int x;
    int y;

public:
    Enemy();

    int getX() const;
    int getY() const;

    void setPosition(int newX, int newY);
    void moveTowards(const Character& player, const World& world);
};

#endif
