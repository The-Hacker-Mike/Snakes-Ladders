/*
 * Miguel A. Medina R.
 * A01023656
 * 31/05/2020
 * Dice header
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#pragma  once

class Dice
{
private:
        // Attributes
        int faces; // I refer to this attribute with "this"
        std::string color;

    public:
        // Constructors
        Dice() = default;
        Dice(int faces, std::string color); // The faces, here, is different to the attribute, it's a parameter that I give in start.
        // Methods
        int getFaces();
        std::string getColor();
        int rollDice();
        // Destructor
        ~Dice();
};