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
                        world.addOrganism(new Guarana(x, y - 1));
                    }
                }
                break;
            case 1:
                if (x + 1 < 20)
                {
                    if (world.checkCollision(x + 1, y) == nullptr)
                    {
                        world.addOrganism(new Guarana(x + 1, y));
                    }
                }
                break;
            case 2:
                if (y + 1 < 20)
                {
                    if (world.checkCollision(x, y + 1) == nullptr)
                    {
                        world.addOrganism(new Guarana(x, y + 1));
                    }
                }
                break;
            case 3:
                if (x - 1 >= 0)
                {
                    if (world.checkCollision(x - 1, y) == nullptr)
                    {
                        world.addOrganism(new Guarana(x - 1, y));
                    }
                }
                break;
            }
        }
    }

    void collision(World &world, Organism *otherOrganism) override
    {
        otherOrganism->setPower(otherOrganism->getPower() + 3);
    }
};