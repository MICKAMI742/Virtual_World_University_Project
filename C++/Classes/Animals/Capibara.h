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
            world.addOrganism(new Capibara(this->getX(), this->getY()));
        }
        else
        {
            Animal::collision(world, otherOrganism);
        }
    }
};