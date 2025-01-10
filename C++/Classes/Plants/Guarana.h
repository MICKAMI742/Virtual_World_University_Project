#include "../Plant.h"
#include <iostream>
#include <random>
using namespace std;

class Guarana : public Plant
{
public:
    Guarana(int x, int y) : Plant("Guarana", 0, 0, x, y) {};

    string draw() override
    {
        return "g";
    };

    void action(World &world) override
    {
        if (canSeed())
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, world.getWidth() - 1);
            std::uniform_int_distribution<> dis2(0, world.getHeight() - 1);
            int x = dis(gen);
            int y = dis2(gen);
            if (world.checkCollision(x, y) == nullptr)
            {
                world.addOrganism(new Guarana(x, y));
            }
        }
    }

    void collision(World &world, Organism *otherOrganism) override
    {
        otherOrganism->setPower(otherOrganism->getPower() + 3);
    }
};