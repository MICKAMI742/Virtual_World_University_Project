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
    int numberOfBorn = 0; // number of born in one round
    int numberOfDead = 0; // number of dead in one round
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
                world[i][j] = "_"; // dirt
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
            numberOfBorn++;
        }
    };

    int getNumberOfOrganisms()
    {
        return numberOfOrganisms;
    };

    bool isOrganismThere(int x, int y)
    {
        if (world[x][y] != "_")
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
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                organisms[i] = nullptr;
            }
        }
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
                numberOfOrganisms--;
                numberOfDead++;
                for (int j = i; j < numberOfOrganisms - 1; j++)
                {
                    organisms[j] = organisms[j + 1];
                }
                break;
            }
        }
    }

    void statsAfterRound()
    {
        cout << endl;
        cout << "Number of organisms: " << numberOfOrganisms << endl;
        cout << "Number of born: " << numberOfBorn << endl;
        cout << "Number of dead: " << numberOfDead << endl;
        numberOfBorn = 0;
        numberOfDead = 0;
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