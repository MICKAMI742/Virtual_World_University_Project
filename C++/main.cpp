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
    world.addOrganism(new Mosquito(0, 0));
    world.addOrganism(new Mosquito(1, 0));
    world.addOrganism(new Mosquito(2, 0));
    world.addOrganism(new Mosquito(3, 0));
    world.addOrganism(new Mosquito(0, 1));
    world.addOrganism(new Capibara(1, 1));
    bool simulationState = true;
    while (simulationState)
    {
        // system("cls");
        world.sortOrganismsByInitiative();
        cout << "Michal Kaminski 200788" << endl;
        world.drawWorld();
        world.statsAfterRound();
        world.writeAllOrganisms();
        world.makeTurn();
        cout << "Press any key to continue or 'q' to quit: " << endl;
        char key = _getch();
        if (key == 'q')
        {
            simulationState = false;
        }
    }
    return 0;
}