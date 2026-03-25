#include "Enemy.h"
#include "World.h"

Enemy::Enemy() {
    x = 4;
    y = 4;
}

int Enemy::getX() const {
    return x;
}

int Enemy::getY() const {
    return y;
}

void Enemy::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

void Enemy::moveTowards(const Character& player, const World& world) {
    int newX = x;
    int newY = y;


    if (x < player.getX()) {
        newX++;
    }
    else if (x > player.getX()) {
        newX--;
    }
    else if (y < player.getY()) {
        newY++;
    }
    else if (y > player.getY()) {
        newY--;
    }

    // Brunnen prüfen
    if (!world.isBlocked(newX, newY)) {
        x = newX;
        y = newY;
    }

}
