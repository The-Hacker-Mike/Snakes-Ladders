/*
 * Miguel A Medina R.
 * A01023656
 * 31/05/2020
 * Dice implementation
 */

#include "Dice.h"

// Constructor
Dice::Dice(int faces, std::string color)
{
    this->faces = faces; // "this" I refer to my attribute
    this->color = color;
    std::srand(std::time(0));
}

// Destructor
Dice::~Dice()
{
    //std::cout << "Destructor of Dice." << std::endl;
}

int Dice::getFaces()
{
    return faces;
}

std::string Dice::getColor()
{
    return color;
}

int Dice::rollDice()
{
    return (std::rand() % faces) + 1; // As the game requires just a roll per player I can return it instead of printing it.
}