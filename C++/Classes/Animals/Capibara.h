#include "../Animal.h"
#include <iostream>
#include <random>
using namespace std;

class Capibara : public Animal
{
public:
    Capibara(int x, int y) : Animal("Capibara", 9, 9, x, y) {};

    string draw() override
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 1);
        int number = dis(gen);
        if (number == 0)
            return "C";
        else
            return "v"; // capibara can hide in grass
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