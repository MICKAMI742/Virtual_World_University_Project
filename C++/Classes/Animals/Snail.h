#include "../Animal.h"
#include <iostream>
#include <random>
using namespace std;

class Snail : public Animal
{
public:
    Snail(int x, int y) : Animal("Snail", 1, 1, x, y) {};

    string draw() override
    {
        return "G"; // G for snail (gastropod)
    };

    void action(World &world) override
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 3);
        uniform_int_distribution<> dis2(0, 100);
        int direction = dis(gen);
        if (dis2(gen) <= 10)
        {
            Animal::action(world);
        }
    }

    void collision(World &world, Organism *otherOrganism) override
    {
        if (this->getGenre() == otherOrganism->getGenre())
        {
            if (!world.isOrganismThere(this->getX(), this->getY() - 1) && this->checkIfFitsInMap(this->getX(), this->getY() - 1))
                world.addOrganism(new Snail(this->getX(), this->getY() - 1));
        }
        else
        {
            if (otherOrganism->getPower() < 2)
            {
                for (int i = -1; i < 2; i++)
                {
                    for (int j = -1; j < 2; j++)
                    {
                        if (!world.isOrganismThere(this->getX() + i, this->getY() + j) && this->checkIfFitsInMap(this->getX() + i, this->getY() + j))
                        {
                            otherOrganism->setPosition(otherOrganism->getX() + i, otherOrganism->getY() + j);
                            break;
                        }
                    }
                }
            }
            else if (otherOrganism->getPower() > 4)
            {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dis(0, 100);
                int chance = dis(gen);
                if (chance <= 60)
                {
                    for (int i = -1; i < 2; i++)
                    {
                        for (int j = -1; j < 2; j++)
                        {
                            if (!world.isOrganismThere(this->getX() + i, this->getY() + j) && this->checkIfFitsInMap(this->getX() + i, this->getY() + j))
                            {
                                otherOrganism->setPosition(otherOrganism->getX() + i, otherOrganism->getY() + j);
                                break;
                            }
                        }
                    }
                }
            }
            else
            {
                Animal::collision(world, otherOrganism);
            }
        }
    }
};