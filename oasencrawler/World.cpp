#include <iostream>
#include <cstdlib>
#include "World.h"

using namespace std;

World::World()
{
    totalRelics = 0;
    generateWorld();
}

void World::generateWorld()
{
    totalRelics = 0;

    // Welt erzeugen (ohne Relikt)
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            int randomValue = rand() % 10 + 1;

            if (randomValue <= 4)
            {
                grid[i][j] = 'L';   // 40% Leer
            }
            else if (randomValue <= 8)
            {
                grid[i][j] = 'G';   // 40% Gefahr
            }
            else if (randomValue == 9)
            {
                grid[i][j] = 'B';   // 10% Brunnen
            }
            else
            {
                grid[i][j] = 'L';   // 10% auch Leer
            }
        }
    }

    // Startfeld immer leer
    grid[0][0] = 'L';

    // Genau 1 Relikt zufällig setzen
    int rx, ry;
    do
    {
        rx = rand() % 5;
        ry = rand() % 5;
    }
    while (rx == 0 && ry == 0);

    grid[rx][ry] = 'R';
    totalRelics = 1;
}

void World::printWorld(const Character& player, const Enemy& enemy) const
{
    cout << "\nSpielwelt:\n";

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            if (player.getX() == i && player.getY() == j)
            {
                cout << " C ";
            }
            else if (enemy.getX() == i && enemy.getY() == j)
            {
                cout << " E ";
            }
            else
            {
                if (grid[i][j] == 'L')
                {
                    cout << " * ";
                }
                else
                {
                    cout << " " << grid[i][j] << " ";
                }
            }
        }
        cout << endl;
    }

    cout << "\nC = Character | E = Enemy\n";
    cout << "* = Leerfeld | G = Gefahr | B = Brunnen | R = Relikt\n";
}

void World::handleField(Character& player, int dangerDamage)
{
    int x = player.getX();
    int y = player.getY();

    char currentField = grid[x][y];

    if (currentField == 'L')
    {
        cout << "Du bist auf einem leeren Feld.\n";
    }
    else if (currentField == 'G')
    {
        cout << "Gefahrenfeld!\n";

        int chance = rand() % 6;
        if (chance == 0)
        {
            player.loseHealth(dangerDamage);
            cout << "Du wurdest verletzt und verlierst " << dangerDamage << " Lebenspunkte.\n";
        }
        else
        {
            cout << "Du hattest Glueck und verlierst kein Leben.\n";
        }
    }
    else if (currentField == 'B')
    {
        cout << "Brunnen gefunden! Du erhaelst 1 Lebenspunkt.\n";
        player.gainHealth();
    }
    else if (currentField == 'R')
    {
        cout << "Relikt gefunden! Du erhaelst 1 Reliktpunkt.\n";
        player.addRelic();
    }

    grid[x][y] = 'L';
}

int World::getTotalRelics() const
{
    return totalRelics;
}

bool World::isBlocked(int x, int y) const
{
    if (grid[x][y] == 'B')
    {
        return true;
    }
    return false;
}
