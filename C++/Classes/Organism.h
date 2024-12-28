#include <iostream>

// Organism class is a base class for all other classes
class Organism
{
private:
    int power;
    int initiative;
    int x;
    int y;

public:
    virtual void action() = 0;
    virtual void collision(Organism *otherOrganism) = 0;
    virtual void draw() = 0;
    Organism(int power, int initiative, int x, int y) : power(power), initiative(initiative), x(x), y(y) {};

    int getPower() { return power; };
    int getInitiative() { return initiative; };
    int getX() { return x; };
    int getY() { return y; };

    void setPosition(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    virtual ~Organism() {};
};