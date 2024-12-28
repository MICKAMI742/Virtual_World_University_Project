#include "../Animal.h"
#include <iostream>
using namespace std;

class Snail : public Animal
{
public:
    Snail(int x, int y) : Animal("Snail", 1, 1, x, y) {};

    string draw() override
    {
        return "G"; // G for snail (gastropod)
    };
};