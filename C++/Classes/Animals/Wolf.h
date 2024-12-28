#include "../Animal.h"
using namespace std;
class Wolf : public Animal
{
public:
    Wolf(int x, int y) : Animal("Wolf", 9, 5, x, y) {};

    string draw() override
    {
        return "W";
    };
};