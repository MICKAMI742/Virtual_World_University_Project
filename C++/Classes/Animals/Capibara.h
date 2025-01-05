#include "../Animal.h"
#include <iostream>
using namespace std;

class Capibara : public Animal
{
public:
    Capibara(int x, int y) : Animal("Capibara", 9, 9, x, y) {};

    string draw() override
    {
        return "C";
    };

    void collision(World &world, Organism *otherOrganism) override
    {
        if (this->getGenre() == otherOrganism->getGenre())
        {
            if (!world.isOrganismThere(this->getX(), this->getY() - 1) && this->checkIfFitsInMap(this->getX(), this->getY() - 1))
                world.addOrganism(new Capibara(this->getX(), this->getY() - 1));
        }
        else
        {
            Animal::collision(world, otherOrganism);
        }
    }
};