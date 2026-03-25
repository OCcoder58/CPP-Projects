#ifndef CHARACTER_H
#define CHARACTER_H

class Character {
private:
    int x;
    int y;
    int health;
    int relics;

public:
    Character();

    int getX() const;
    int getY() const;
    int getHealth() const;
    int getRelics() const;

    bool move(char direction);
    void loseHealth(int amount);
    void gainHealth();
    void addRelic();
    bool isAlive() const;

    void setPosition(int newX, int newY);
    void resetRelics();
};

#endif
