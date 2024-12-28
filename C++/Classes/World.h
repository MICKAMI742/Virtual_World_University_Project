#pragma once
#include "Organism.h"
using namespace std;

class World
{
private:
    Organism **organisms;
    int capacity;
    int numberOfOrganisms;
    string world[20][20];

public:
    // allows every organism to make a turn
    void makeTurn()
    {
        for (int i = 0; i < numberOfOrganisms; i++)
        {
            organisms[i]->action();
        }
    };
    // draws every organism on their position
    void drawWorld()
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                world[i][j] = "-"; // empty field
            }
        }
        for (int i = 0; i < numberOfOrganisms; i++)
        {
            world[organisms[i]->getY()][organisms[i]->getX()] = organisms[i]->draw();
        }
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                cout << world[i][j];
            }
            cout << endl;
        }
    };
    // adds an organism to the pointers to organism array
    void addOrganism(Organism *organism)
    {
        if (numberOfOrganisms < capacity)
        {
            organisms[numberOfOrganisms] = organism;
            numberOfOrganisms++;
        }
    };

    // Constructor
    World(int capacity) : capacity(capacity), numberOfOrganisms(0)
    {
        organisms = new Organism *[capacity];
    };

    // Destructor
    ~World()
    {
        for (int i = 0; i < numberOfOrganisms; i++)
        {
            delete organisms[i];
        }
        delete[] organisms;
    };
};