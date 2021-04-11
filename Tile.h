/*
 * Miguel Angel Medina Ruperto
 * A01023656
 * 25/05/2020
 * Tiles header
 */

#include "Dice.h"
#include <iostream>
#pragma once

class Tile
{
    // no identifier == private.
    private:
        //Attributes
        std::string name; // It's gonna be called S, L or N.
        int type; // Internally it represents the name, but it masks it with a number.
        void setName(std::string name);

    public:
        // Constructors
        Tile() = default;
        Tile(int type);
        // Methods
        std::string getName();
        int reward(int* aNumber);
        int penalty(int* aNumber);
        // Destructor
        ~Tile();
};
