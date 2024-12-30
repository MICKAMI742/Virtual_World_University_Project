#include "../Animal.h"
#include <iostream>
using namespace std;

class Mosquito : public Animal
{
public:
    Mosquito(int x, int y) : Animal("Mosqutio", 1, 1, x, y) {};

    string draw() override
    {
        return "M";
    };

    void collision(World &world, Organism *otherOrganism) override
    {
        if (this->getGenre() == otherOrganism->getGenre())
        {
            if (!world.isOrganismThere(this->getX(), this->getY() - 1))
                world.addOrganism(new Mosquito(this->getX(), this->getY() - 1));
        }
        else
        {
            Animal::collision(world, otherOrganism);
        }
    }
};