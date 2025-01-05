#include <iostream>
#include <cstdlib>
#include "Classes/World.h"
#include "Classes/Animals/Wolf.h"
#include "Classes/Animals/Sheep.h"
#include "Classes/Animals/Snail.h"
#include "Classes/Animals/Capibara.h"
#include "Classes/Animals/Mosquito.h"
#include "Classes/Plants/Berry.h"
#include "Classes/Plants/Grass.h"
#include "Classes/Plants/Guarana.h"
#include <conio.h>

using namespace std;

int main()
{
    World world(20 * 20);
    world.addOrganism(new Wolf(10, 10));
    world.addOrganism(new Wolf(19, 9));
    world.addOrganism(new Wolf(19, 10));
    world.addOrganism(new Capibara(9, 19));
    world.addOrganism(new Capibara(19, 19));
    world.addOrganism(new Capibara(19, 18));
    world.addOrganism(new Sheep(11, 11));
    world.addOrganism(new Sheep(12, 11));
    world.addOrganism(new Sheep(12, 13));
    world.addOrganism(new Sheep(12, 14));
    world.addOrganism(new Snail(12, 12));
    bool simulationState = true;
    while (simulationState)
    {
        // system("cls");
        world.sortOrganismsByInitiative();
        cout << "Michal Kaminski 200788" << endl;
        world.makeTurn();
        world.drawWorld();
        world.statsAfterRound();
        cout << "Press any key to continue or 'q' to quit: " << endl;
        char key = _getch();
        if (key == 'q')
        {
            simulationState = false;
        }
    }
    return 0;
}