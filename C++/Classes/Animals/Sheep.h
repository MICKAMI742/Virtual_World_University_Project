#include <iostream>
#include "../Animal.h"
using namespace std;

class Sheep : public Animal
{
public:
    Sheep(int x, int y) : Animal("Sheep", 4, 4, x, y) {};

    string draw() override
    {
        return "S";
    };
};