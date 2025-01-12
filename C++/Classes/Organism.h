#pragma once
#include <iostream>
#include <fstream>
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

    const int getPower() { return power; };
    const int getInitiative() { return initiative; };
    const int getX() { return x; };
    const int getY() { return y; };
    const string getGenre() { return genre; };

    void setPosition(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    void setPower(int power)
    {
        this->power = power;
    }

    void setInitiative(int initiative)
    {
        this->initiative = initiative;
    }

    virtual ~Organism() {};

    void saveToFile(ofstream &file)
    {
        file << genre << " " << power << " " << initiative << " " << x << " " << y << endl;
    }
};