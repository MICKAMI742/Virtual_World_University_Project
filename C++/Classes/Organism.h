#pragma once
#include <iostream>
using namespace std;

// forward declaration
class World;
// Organism class is a base class for all other classes
class Organism
{
private:
    string genre;
    int power;
    int initiative;
    int x;
    int y;

public:
    virtual void action(World &world) = 0;
    virtual void collision(World &world, Organism *otherOrganism) = 0;
    virtual string draw() = 0;
    Organism(string genre, int power, int initiative, int x, int y) : genre(genre), power(power), initiative(initiative), x(x), y(y) {};

    int getPower() { return power; };
    int getInitiative() { return initiative; };
    int getX() { return x; };
    int getY() { return y; };
    string getGenre() { return genre; };

    void setPosition(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void setPower(int power)
    {
        this->power = power;
    }

    virtual ~Organism() {};
};