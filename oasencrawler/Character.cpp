#include "Character.h"

Character::Character() {
    x = 0;
    y = 0;
    health = 5;
    relics = 0;
}

int Character::getX() const {
    return x;
}

int Character::getY() const {
    return y;
}

int Character::getHealth() const {
    return health;
}

int Character::getRelics() const {
    return relics;
}

bool Character::move(char direction) {
    if (direction == 'w' || direction == 'W') {
        if (x > 0) {
            x--;
            return true;
        }
    }
    else if (direction == 's' || direction == 'S') {
        if (x < 4) {
            x++;
            return true;
        }
    }
    else if (direction == 'a' || direction == 'A') {
        if (y > 0) {
            y--;
            return true;
        }
    }
    else if (direction == 'd' || direction == 'D') {
        if (y < 4) {
            y++;
            return true;
        }
    }

    return false;
}

void Character::loseHealth(int amount) {
    health -= amount;

    if (health < 0) {
        health = 0;
    }
}

void Character::gainHealth() {
    health++;
}

void Character::addRelic() {
    relics++;
}

bool Character::isAlive() const {
    return health > 0;
}

void Character::setPosition(int newX, int newY) {
    x = newX;
    y = newY;
}

void Character::resetRelics() {
    relics = 0;
}
