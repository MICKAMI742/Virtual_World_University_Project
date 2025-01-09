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
#include <random>
using namespace std;

World createRandomMap(int capacity)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 8);         // number of specified organism
    uniform_int_distribution<> dis2(0, 19);       // x
    uniform_int_distribution<> dis3(0, 19);       // y
    uniform_int_distribution<> dis4(0, capacity); // number of organisms on the begining
    World world(20 * 20);
    for (int i = 0; i < dis4(gen); i++)
    {
        int x = dis2(gen);
        int y = dis3(gen);
        switch (dis(gen))
        {
        case 0:
            world.addOrganism(new Wolf(x, y));
            break;
        case 1:
            world.addOrganism(new Sheep(x, y));
            break;
        case 2:
            world.addOrganism(new Snail(x, y));
            break;
        case 3:
            world.addOrganism(new Capibara(x, y));
            break;
        case 4:
            world.addOrganism(new Mosquito(x, y));
            break;
        case 5:
            world.addOrganism(new Berry(x, y));
            break;
        case 6:
            world.addOrganism(new Grass(x, y));
            break;
        case 7:
            world.addOrganism(new Guarana(x, y));
            break;
        }
    }

    return world;
}

int main()
{
    const int capacity = 20 * 20;
    World world = createRandomMap(capacity);
    bool simulationState = true;
    while (simulationState)
    {
        system("cls");
        world.sortOrganismsByInitiative();
        cout << "Michal Kaminski 200788" << endl;
        world.drawWorld();
        world.statsAfterRound();
        cout << "Press any key to continue or 'q' to quit: " << endl;
        char key = _getch();
        if (key == 'q')
        {
            simulationState = false;
            break;
        }
        world.makeTurn();
    }
    return 0;
}