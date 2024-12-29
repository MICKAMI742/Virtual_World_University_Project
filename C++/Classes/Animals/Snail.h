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
            world.addOrganism(new Snail(this->getX(), this->getY()));
        }
        else
        {
            Animal::collision(world, otherOrganism);
        }
    }
};