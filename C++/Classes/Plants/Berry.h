#include "../Plant.h"
#include <iostream>
using namespace std;

class Berry : public Plant
{
public:
    Berry(int x, int y) : Plant("Berry", 99, 0, x, y) {};

    string draw() override
    {
        return "B";
    };

    void collision(World &world, Organism *otherOrganism) override
    {
        delete otherOrganism;
    }
};