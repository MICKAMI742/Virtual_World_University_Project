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
    World world(40);
    world.addOrganism(new Wolf(10, 10));
    world.addOrganism(new Sheep(15, 15));
    world.addOrganism(new Snail(1, 1));
    world.addOrganism(new Capibara(12, 12));
    world.addOrganism(new Mosquito(11, 2));
    world.addOrganism(new Berry(5, 5));
    world.addOrganism(new Grass(6, 6));
    world.addOrganism(new Guarana(7, 7));
    bool simulationState = true;
    while (simulationState)
    {
        system("cls");
        cout << "Michal Kaminski 200788" << endl;
        world.makeTurn();
        world.drawWorld();
        cout << "Press any key to continue or 'q' to quit: ";
        char key = _getch();
        if (key == 'q')
        {
            simulationState = false;
        }
    }
    return 0;
}