#include "Organism.h"
#include "World.h"
#include <random>

class Animal : public Organism
{
private:
    // it helps me to generate random x and y to place my animal on the map
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_int_distribution<int> distribX;
    std::uniform_int_distribution<int> distribY;

public:
    // function draws random coordinates of next free space and puts there animal
    void action()
    {
        int x = distribX(gen);
        int y = distribY(gen);
    };

    // function defines what happens when animals have to fight
    void collision() {

    };

    // constructor
    Animal(int power, int initiative, int x, int y, World &world);
};