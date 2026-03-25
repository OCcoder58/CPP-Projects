#ifndef WORLD_H
#define WORLD_H

#include "Character.h"
#include "Enemy.h"

class World {
private:
    char grid[5][5];
    int totalRelics;

public:
    World();

    void generateWorld();
    void printWorld(const Character& player, const Enemy& enemy) const;
    void handleField(Character& player, int dangerDamage);
    int getTotalRelics() const;
    bool isBlocked(int x, int y) const;
};

#endif
