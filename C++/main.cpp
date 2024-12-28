#include <iostream>
#include <cstdlib>
#include "Classes/World.h"
using namespace std;

int main()
{
    World world(40);
    bool simulationState = true;
    while (simulationState)
    {
        system("cls");
        cout << "Michal Kaminski 200788" << endl;
        world.makeTurn();
        world.drawWorld();
        cout << "Press any key to continue or 'q' to quit: ";
        char key;
        cin >> key;
        if (key == 'q')
        {
            simulationState = false;
        }
    }
    return 0;
}