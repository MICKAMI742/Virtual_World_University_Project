#pragma once
#include "Organism.h"
// plants will be represented with small letters on the map
class Plant : public Organism
{

public:
    Plant(string genre, int power, int initiative, int x, int y) : Organism(genre, power, 0, x, y) {};
    void action() override {

    };

    void collision(Organism *otherOrganism) override {

    };
};