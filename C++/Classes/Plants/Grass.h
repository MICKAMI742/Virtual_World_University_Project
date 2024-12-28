#include "../Plant.h"
#include <iostream>
using namespace std;

class Grass : public Plant
{
public:
    Grass(int x, int y) : Plant("Grass", 0, 0, x, y) {};

    string draw() override
    {
        return "v"; // v for grass (verdue)
    };
};