#pragma once
#include "Organism.h"
#include "World.h"
#include <random>
// animals will be represented with big letters on the map
class Animal : public Organism
{

public:
    Animal(string genre, int power, int initiative, int x, int y) : Organism(genre, power, initiative, x, y) {};
    void action() override
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 3);
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
                setPosition(x, y - 1);
            break;
        case 1:
            if (x + 1 < 20)
                setPosition(x + 1, y);
            break;
        case 2:
            if (y + 1 < 20)
                setPosition(x, y + 1);
            break;
        case 3:
            if (x - 1 >= 0)
                setPosition(x - 1, y);
            break;
        }
    };

    void collision(Organism *otherOrganism) override
    {
        if (this->getGenre() == otherOrganism->getGenre())
        {
        }
        else
        {
            if (this->getPower() >= otherOrganism->getPower())
            {
                setPosition(otherOrganism->getX(), otherOrganism->getY());
            }
            else
            {
                setPosition(getX(), getY());
            }
        }
    };
};