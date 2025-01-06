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
                {
                    if (world.checkCollision(x, y - 1) == nullptr)
                    {
                        world.addOrganism(new Berry(x, y - 1));
                    }
                }
                break;
            case 1:
                if (x + 1 < 20)
                {
                    if (world.checkCollision(x + 1, y) == nullptr)
                    {
                        world.addOrganism(new Berry(x + 1, y));
                    }
                }
                break;
            case 2:
                if (y + 1 < 20)
                {
                    if (world.checkCollision(x, y + 1) == nullptr)
                    {
                        world.addOrganism(new Berry(x, y + 1));
                    }
                }
                break;
            case 3:
                if (x - 1 >= 0)
                {
                    if (world.checkCollision(x - 1, y) == nullptr)
                    {
                        world.addOrganism(new Berry(x - 1, y));
                    }
                }
                break;
            }
        }
    }

    void collision(World &world, Organism *otherOrganism) override
    {
        world.removeOrganism(otherOrganism);
    }
};