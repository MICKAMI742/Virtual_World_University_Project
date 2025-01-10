#pragma once
#include "Organism.h"
#include "World.h"
#include <random>
using namespace std;
// animals will be represented with big letters on the map
class Animal : public Organism
{

public:
    Animal(string genre, int power, int initiative, int x, int y) : Organism(genre, power, initiative, x, y) {};

    void action(World &world) override
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, 3);
        int direction = dis(gen);
        int x = getX();
        int y = getY();
        /*
            0 - up
            1 - right
            2 - down
            3 - left
        */
        switch (direction)
        {
        case 0:
            if (y - 1 >= 0)
            {
                if (world.checkCollision(x, y - 1) != nullptr)
                {
                    collision(world, world.checkCollision(x, y - 1));
                }
                else
                {
                    setPosition(x, y - 1);
                }
            }
            break;
        case 1:
            if (x + 1 < world.getWidth())
            {
                if (world.checkCollision(x + 1, y) != nullptr)
                {
                    collision(world, world.checkCollision(x + 1, y));
                }
                else
                {
                    setPosition(x + 1, y);
                }
            }
            break;
        case 2:
            if (y + 1 < world.getHeight())
            {
                if (world.checkCollision(x, y + 1) != nullptr)
                {
                    collision(world, world.checkCollision(x, y + 1));
                }
                else
                {
                    setPosition(x, y + 1);
                }
            }
            break;
        case 3:
            if (x - 1 >= 0)
            {
                if (world.checkCollision(x - 1, y) != nullptr)
                {
                    collision(world, world.checkCollision(x - 1, y));
                }
                else
                {
                    setPosition(x - 1, y);
                }
            }
            break;
        }
    };

    bool willBeBeaten(World &world, Organism *otherOrganism)
    {
        if (this->getPower() < otherOrganism->getPower())
        {
            return true;
        }
        return false;
    }

    void collision(World &world, Organism *otherOrganism) override
    {
        if (this->getPower() >= otherOrganism->getPower())
        {
            setPosition(otherOrganism->getX(), otherOrganism->getY());
            world.removeOrganism(otherOrganism);
        }
        else
        {
            otherOrganism->setPosition(this->getX(), this->getY());
            world.removeOrganism(this);
        }
    }

    bool checkIfFitsInMap(int x, int y)
    {
        if (x >= 0 && x < 20 && y >= 0 && y < 20)
        {
            return true;
        }
        return false;
    }
};
