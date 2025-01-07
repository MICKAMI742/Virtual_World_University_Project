#include "../Animal.h"
#include <iostream>
using namespace std;

class Mosquito : public Animal
{
public:
    Mosquito(int x, int y) : Animal("Mosquito", 1, 1, x, y) {};

    string draw() override
    {
        return "M";
    };

    void action(World &world) override
    {
        setDefault();
        addPowerBecauseMosquitosInGroupStronger(world);
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

    int numberOfNearbyMosquitos(World &world)
    {
        int mosquitos = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int x = this->getX() + i;
                int y = this->getY() + j;
                Organism *organism = world.checkCollision(x, y);
                if (organism != nullptr && organism->getGenre() == "Mosquito" && organism != this)
                {
                    mosquitos++;
                }
            }
        }
        return mosquitos;
    }

    void setDefault()
    {
        this->setPower(1);
        this->setInitiative(1);
    }

    void addPowerBecauseMosquitosInGroupStronger(World &world)
    {
        this->setPower(this->getPower() + numberOfNearbyMosquitos(world));
        this->setInitiative(this->getInitiative() + numberOfNearbyMosquitos(world));
    }
};