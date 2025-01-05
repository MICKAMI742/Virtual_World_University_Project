#include "../Animal.h"
#include <iostream>
using namespace std;

class Snail : public Animal
{
public:
    Snail(int x, int y) : Animal("Snail", 1, 1, x, y) {};

    string draw() override
    {
        return "G"; // G for snail (gastropod)
    };

    void collision(World &world, Organism *otherOrganism) override
    {
        if (this->getGenre() == otherOrganism->getGenre())
        {
            if (!world.isOrganismThere(this->getX(), this->getY() - 1) && this->checkIfFitsInMap(this->getX(), this->getY() - 1))
                world.addOrganism(new Snail(this->getX(), this->getY() - 1));
        }
        else
        {
            Animal::collision(world, otherOrganism);
        }
    }
};