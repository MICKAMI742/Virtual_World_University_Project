#include "../Animal.h"
using namespace std;
class Wolf : public Animal
{
public:
    // default constructor
    Wolf(int x, int y) : Animal("Wolf", 9, 5, x, y) {};

    // read file constructor
    Wolf(int power, int initiative, int x, int y) : Animal("Wolf", power, initiative, x, y) {};

    string draw() override
    {
        return "W";
    };

    void collision(World &world, Organism *otherOrganism) override
    {
        if (this->getGenre() == otherOrganism->getGenre())
        {
            if (!world.isOrganismThere(this->getX(), this->getY() - 1) && this->checkIfFitsInMap(this->getX(), this->getY() - 1))
                world.addOrganism(new Wolf(this->getX(), this->getY() - 1));
        }
        else
        {
            Animal::collision(world, otherOrganism);
        }
    }
};