#pragma once
#include "Organism.h"
using namespace std;

class World
{
private:
    Organism **organisms;
    int width;
    int height;
    int capacity;
    int numberOfOrganisms;
    int numberOfBorn = 0; // number of born in one round
    int numberOfDead = 0; // number of dead in one round
    int numberOfEatenPlants = 0;
    string **world = new string *[width];

public:
    // sorts organisms by they initiative and age
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
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                world[i][j] = "_"; // dirt
            }
        }
        for (int i = 0; i < numberOfOrganisms; i++)
        {
            world[organisms[i]->getX()][organisms[i]->getY()] = organisms[i]->draw();
        }
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
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

    // returns number of organisms
    int getNumberOfOrganisms()
    {
        return numberOfOrganisms;
    };

    // checks if there is an organism on the given position on map
    bool isOrganismThere(int x, int y)
    {
        if (world[x][y] != "_")
        {
            return true;
        }
        return false;
    };

    // checks collision with other animals
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
    World(int x, int y) : width(x), height(y), capacity(x * y), numberOfOrganisms(0)
    {
        organisms = new Organism *[capacity];
        world = new string *[width];
        for (int i = 0; i < width; i++)
        {
            world[i] = new string[height];
        }
        for (int i = 0; i < width; i++)
        {
            for (int j = 0; j < height; j++)
            {
                organisms[i] = nullptr;
            }
        }
    };

    // removes organism from the table and moves another organism to it's place
    void removeOrganism(Organism *organism)
    {
        for (int i = 0; i < numberOfOrganisms; i++)
        {
            if (organisms[i]->getGenre() == "Berry" || organisms[i]->getGenre() == "Guarana")
            {
                numberOfEatenPlants++;
            }
            if (organisms[i] == organism)
            {
                int x = organisms[i]->getX();
                int y = organisms[i]->getY();
                delete organisms[i];
                numberOfOrganisms--;
                numberOfDead++;
                for (int j = i; j < numberOfOrganisms; j++)
                {
                    organisms[j] = organisms[j + 1];
                }
                organisms[numberOfOrganisms] = nullptr; // Set the last element to nullptr
                break;
            }
        }
    }
    // displays statistics after round
    void statsAfterRound()
    {
        cout << endl;
        cout << "Number of organisms: " << numberOfOrganisms << endl;
        cout << "Number of born: " << numberOfBorn << endl;
        cout << "Number of dead: " << numberOfDead << endl;
        cout << "Number of eaten plants: " << numberOfEatenPlants << endl;
        numberOfBorn = 0;
        numberOfDead = 0;
        numberOfEatenPlants = 0;
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