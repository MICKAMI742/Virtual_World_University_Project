#include "../Animal.h"
#include "../Organism.h"
#include <iostream>
#include <random>
using namespace std;

class Mosquito : public Animal
{
public:
    // default constructor
    Mosquito(int x, int y) : Animal("Mosquito", 1, 1, x, y) {};

    // read file constructor
    Mosquito(int power, int initiative, int x, int y) : Animal("Mosquito", power, initiative, x, y) {};

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
            if (world.checkCollision(this->getX(), this->getY() - 1) == nullptr && this->checkIfFitsInMap(this->getX(), this->getY() - 1))
                world.addOrganism(new Mosquito(this->getX(), this->getY() - 1));
        }
        else
        {
            if (willBeBeaten(otherOrganism) == false)
            {
                this->setPosition(this->getX(), this->getY());
            }
            else
            {
                Animal::collision(world, otherOrganism);
            }
        }
    }

    bool willBeBeaten(Organism *otherOrganism) // check if organism will be beaten
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 1);
        if (otherOrganism->getPower() > this->getPower())
        {
            return dis(gen) == 1;
        }
        return false;
    }

    int numberOfNearbyMosquitos(World &world) // count mosquitos in group
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

    void setDefault() // set power and initiative to default values
    {
        this->setPower(1);
        this->setInitiative(1);
    }

    void addPowerBecauseMosquitosInGroupStronger(World &world) // add power and initiative because of mosquitos in group
    {
        this->setPower(this->getPower() + numberOfNearbyMosquitos(world));
        this->setInitiative(this->getInitiative() + numberOfNearbyMosquitos(world));
    }
};