#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Character.h"
#include "World.h"
#include "Enemy.h"

using namespace std;

int main()
{
    srand(time(0));

    Character player;
    World world;
    Enemy enemy;

    char input;
    bool validInput;
    bool caught = false;
    int difficulty = 1;
    int roundCounter = 0;
    int dangerDamage = 1;

    int ex, ey;
    do
    {
        ex = rand() % 5;
        ey = rand() % 5;
    }
    while (ex == player.getX() && ey == player.getY());

    enemy.setPosition(ex, ey);

    cout << "Willkommen beim Oasencrawler!\n";
    cout << "Steuerung: W = hoch, A = links, S = runter, D = rechts\n";

    while (player.isAlive() && !caught)
    {
        world.printWorld(player, enemy);

        cout << "\nSchwierigkeit: " << difficulty << endl;
        cout << "Position: (" << player.getX() << "," << player.getY() << ")\n";
        cout << "Enemy: (" << enemy.getX() << "," << enemy.getY() << ")\n";
        cout << "Leben: " << player.getHealth() << endl;
        cout << "Relikte dieser Welt: " << player.getRelics() << " / " << world.getTotalRelics() << endl;

        validInput = false;

        while (!validInput)
        {
            cout << "\nBewegung eingeben (W/A/S/D): ";
            cin >> input;

            if (input == 'w' || input == 'W' ||
                    input == 'a' || input == 'A' ||
                    input == 's' || input == 'S' ||
                    input == 'd' || input == 'D')
            {

                if (player.move(input))
                {
                    validInput = true;
                }
                else
                {
                    cout << "Ungueltige Bewegung! Du kannst dort nicht hin.\n";
                }
            }
            else
            {
                cout << "Ungueltige Eingabe! Bitte nur W, A, S oder D eingeben.\n";
            }
        }

        world.handleField(player, dangerDamage);
        dangerDamage++;
        roundCounter++;

        if (player.getRelics() == world.getTotalRelics())
        {
            cout << "\nDu hast das Relikt gefunden!\n";
            cout << "Neue Welt wird erzeugt. Schwierigkeit steigt.\n";

            difficulty++;

            world.generateWorld();
            player.setPosition(0, 0);
            player.resetRelics();

            do
            {
                ex = rand() % 5;
                ey = rand() % 5;
            }
            while (ex == player.getX() && ey == player.getY());

            enemy.setPosition(ex, ey);
        }
        else
        {
            if (roundCounter % 2 == 0)
            {
                enemy.moveTowards(player, world);

                if (enemy.getX() == player.getX() && enemy.getY() == player.getY())
                {
                    cout << "Der Gegner hat dich gefangen!\n";
                    caught = true;
                }
            }
        }

        
    }

    cout << "\n========================\n";

    if (caught)
    {
        cout << "Du hast verloren! Der Gegner hat dich gefangen.\n";
    }
    else
    {
        cout << "Du hast verloren! Keine Lebenspunkte mehr.\n";
    }

    cout << "========================\n";

    return 0;
}
