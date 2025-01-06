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

    void action(World &world) override
    {
        int points = addPointsToStrengthWhenMosquitosNearby(world);
        if (points > 0)
        {
            this->setPower(this->getPower() + points);
            this->setInitiative(this->getInitiative() + points);
        }
        Animal::action(world);
    }

    void collision(World &world, Organism *otherOrganism) override
    {
        if (this->getGenre() == otherOrganism->getGenre())
        {
            if (!world.isOrganismThere(this->getX(), this->getY() - 1) && this->checkIfFitsInMap(this->getX(), this->getY() - 1))
                world.addOrganism(new Mosquito(this->getX(), this->getY() - 1));
        }
        else
        {
            Animal::collision(world, otherOrganism);
        }
    }

    int addPointsToStrengthWhenMosquitosNearby(World &world)
    {
        int points = 0;
        if (world.isOrganismThere(this->getX(), this->getY() - 1))
        {
            Organism *organism = world.checkCollision(this->getX(), this->getY() - 1);
            if (organism->getGenre() == "Mosquito")
            {
                points++;
            }
        }
        if (world.isOrganismThere(this->getX() + 1, this->getY()))
        {
            Organism *organism = world.checkCollision(this->getX() + 1, this->getY());
            if (organism->getGenre() == "Mosquito")
            {
                points++;
            }
        }
        if (world.isOrganismThere(this->getX(), this->getY() + 1))
        {
            Organism *organism = world.checkCollision(this->getX(), this->getY() + 1);
            if (organism->getGenre() == "Mosquito")
            {
                points++;
            }
        }
        if (world.isOrganismThere(this->getX() - 1, this->getY()))
        {
            Organism *organism = world.checkCollision(this->getX() - 1, this->getY());
            if (organism->getGenre() == "Mosquito")
            {
                points++;
            }
        }
        return points;
    }
};