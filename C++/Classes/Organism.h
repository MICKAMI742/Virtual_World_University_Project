#include <iostream>
#include "World.h"

// Organism class is a base class for all other classes
class Organism
{
private:
    int power;
    int initiative;
    int x;
    int y;
    World &world;

public:
    void action();
    void collision();
    void draw();
    Organism(int power, int initiative, int x, int y, World &world);
};