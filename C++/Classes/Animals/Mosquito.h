#include "../Animal.h"
#include <iostream>
using namespace std;

class Mosquito : public Animal
{
public:
    Mosquito(int x, int y) : Animal("Mosqutio", 1, 1, x, y) {};

    string draw() override
    {
        return "M";
    };
};