#include "Organism.h"

class World
{
private:
    Organism **organisms;
    int capacity;
    int numberOfOrganisms;

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
        for (int i = 0; i < numberOfOrganisms; i++)
        {
            organisms[i]->draw();
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