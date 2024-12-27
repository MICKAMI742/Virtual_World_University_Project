#include "Organism.h"

class World
{
private:
    Organism *organisms;

public:
    void makeTurn();
    void drawWorld();
    World(Organism *organisms);
};