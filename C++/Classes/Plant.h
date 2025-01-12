#pragma once
#include "Organism.h"
#include <random>
// plants will be represented with small letters on the map
class Plant : public Organism
{

public:
    Plant(string genre, int power, int initiative, int x, int y) : Organism(genre, power, 0, x, y) {};
    void action(World &world) override {

    };

    void collision(World &world, Organism *otherOrganism) override {

    };

    bool canSeed()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 100);
        if (dis(gen) <= 1)
        {
            return true;
        }
        return false;
    }
};