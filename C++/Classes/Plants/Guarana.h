#include "../Plant.h"
#include <iostream>
using namespace std;

class Guarana : public Plant
{
public:
    Guarana(int x, int y) : Plant("Guarana", 0, 0, x, y) {};

    string draw() override
    {
        return "g";
    };

    void collision(Organism *otherOrganism) override
    {
        otherOrganism->setPower(otherOrganism->getPower() + 3);
    }
};