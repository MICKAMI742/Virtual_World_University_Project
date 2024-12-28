#include "../Animal.h"
#include <iostream>
using namespace std;

class Capibara : public Animal
{
public:
    Capibara(int x, int y) : Animal("Capibara", 9, 9, x, y) {};

    string draw() override
    {
        return "C";
    };
};