#pragma once
#include "Organism.h"
#include "Plants/Grass.h"
using namespace std;

class World
{
private:
    Organism **organisms;
    int capacity;
    int numberOfOrganisms;
    string world[20][20];

public:
    void sortOrganismsByInitiative()
    {
        for (int i = 0; i < numberOfOrganisms; i++)
        {
            for (int j = 0; j < numberOfOrganisms - 1; j++)
            {
                if (organisms[j]->getInitiative() < organisms[j + 1]->getInitiative())
                {
                    Organism *temp = organisms[j];
                    organisms[j] = organisms[j + 1];
                    organisms[j + 1] = temp;
                }
            }
        }
    }
    // allows every organism to make a turn
    void makeTurn()
    {
        for (int i = 0; i < numberOfOrganisms; i++)
        {
            organisms[i]->action(*this);
        }
    };
    // draws every organism on their position
    void drawWorld()
    {
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                Grass grass(j, i);
                world[i][j] = grass.draw(); // empty field
            }
        }
        for (int i = 0; i < numberOfOrganisms; i++)
        {
            world[organisms[i]->getX()][organisms[i]->getY()] = organisms[i]->draw();
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

    int getNumberOfOrganisms()
    {
        return numberOfOrganisms;
    };

    bool isOrganismThere(int x, int y)
    {
        if (world[x][y] != "v")
        {
            return true;
        }
        return false;
    };

    // checks for collision with other animals
    Organism *checkCollision(int x, int y)
    {
        for (int i = 0; i < numberOfOrganisms; i++)
        {
            if (organisms[i]->getX() == x && organisms[i]->getY() == y)
            {
                return organisms[i];
            }
        }
        return nullptr;
    }

    // Constructor
    World(int capacity) : capacity(capacity), numberOfOrganisms(0)
    {
        organisms = new Organism *[capacity];
    };

    void removeOrganism(Organism *organism)
    {
        for (int i = 0; i < numberOfOrganisms; i++)
        {
            if (organisms[i] == organism)
            {
                int x = organisms[i]->getX();
                int y = organisms[i]->getY();
                delete organisms[i];
                organisms[i] = new Grass(x, y);
                break;
            }
        }
    }

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