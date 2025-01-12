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

World createRandomMap(int x, int y)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 8);      // number of specified organism
    uniform_int_distribution<> dis2(0, x - 1); // x
    uniform_int_distribution<> dis3(0, y - 1); // y
    uniform_int_distribution<> dis4(0, x * y); // number of organisms on the begining
    World world(x, y);
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
    int width;
    int height;
    int mode;
    cout << "Press 1 to create random map or 2 to load map from file: ";
    cin >> mode;
    switch (mode)
    {
    case 1:
    {
        cout << "Enter width of the map: " << endl;
        cin >> width;
        cout << "Enter height of the map: " << endl;
        cin >> height;
        system("cls");
        World world = createRandomMap(width, height);
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
    }
    break;
    case 2:
    {
        const string filename = "save.txt";
        ifstream file;
        file.open(filename);
        if (file.is_open())
        {
            int width;
            int height;
            int numberOfOrganisms;
            file >> width >> height >> numberOfOrganisms;
            World world(width, height);
            for (int i = 0; i < numberOfOrganisms; i++)
            {
                string genre;
                int power;
                int initiative;
                int x;
                int y;
                file >> genre >> power >> initiative >> x >> y;
                if (genre == "Wolf")
                {
                    world.addOrganism(new Wolf(x, y));
                }
                else if (genre == "Sheep")
                {
                    world.addOrganism(new Sheep(x, y));
                }
                else if (genre == "Snail")
                {
                    world.addOrganism(new Snail(x, y));
                }
                else if (genre == "Capibara")
                {
                    world.addOrganism(new Capibara(x, y));
                }
                else if (genre == "Mosquito")
                {
                    world.addOrganism(new Mosquito(x, y));
                }
                else if (genre == "Berry")
                {
                    world.addOrganism(new Berry(x, y));
                }
                else if (genre == "Grass")
                {
                    world.addOrganism(new Grass(x, y));
                }
                else if (genre == "Guarana")
                {
                    world.addOrganism(new Guarana(x, y));
                }
            }
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
        }
        else
        {
            cout << "File not found!" << endl;
        }
    }
    break;

    default:
        break;
    }
    return 0;
}