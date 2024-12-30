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

    void collision(World &world, Organism *otherOrganism) override
    {
        if (this->getGenre() == otherOrganism->getGenre())
        {
            if (!world.isOrganismThere(this->getX(), this->getY() - 1))
                world.addOrganism(new Wolf(this->getX(), this->getY() - 1));
        }
        else
        {
            Animal::collision(world, otherOrganism);
        }
    }
};