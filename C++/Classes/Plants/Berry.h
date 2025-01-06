#include "../Plant.h"
#include <iostream>
#include <random>
using namespace std;

class Berry : public Plant
{
public:
    Berry(int x, int y) : Plant("Berry", 99, 0, x, y) {};

    string draw() override
    {
        return "B";
    };

    void action(World &world) override
    {
        if (canSeed())
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> dis(0, 19);
            std::uniform_int_distribution<> dis2(0, 19);
            int x = dis(gen);
            int y = dis2(gen);
            if (world.checkCollision(x, y) == nullptr)
            {
                world.addOrganism(new Berry(x, y));
            }
        }
    }

    void collision(World &world, Organism *otherOrganism) override
    {
        world.removeOrganism(otherOrganism);
    }
};