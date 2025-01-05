#include <iostream>
#include "../Animal.h"
using namespace std;

class Sheep : public Animal
{
public:
    Sheep(int x, int y) : Animal("Sheep", 4, 4, x, y) {};

    string draw() override
    {
        return "S";
    };

    void collision(World &world, Organism *otherOrganism) override
    {
        if (this->getGenre() == otherOrganism->getGenre())
        {
            if (!world.isOrganismThere(this->getX(), this->getY() - 1) && this->checkIfFitsInMap(this->getX(), this->getY() - 1))
                world.addOrganism(new Sheep(this->getX(), this->getY() - 1));
        }
        else
        {
            Animal::collision(world, otherOrganism);
        }
    }
};