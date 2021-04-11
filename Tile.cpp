/*
 * Miguel Angel Medina Ruperto
 * A01023656
 * 25/05/2020
 * Tiles implementation
 */

#include "Tile.h"
#include "constants.h"

// Constructor
Tile::Tile(int type)
{
    this->type = type;
}

// Destructor
Tile::~Tile()
{
    //std::cout << "Destructor of Tiles." << std::endl;
}

void Tile::setName(std::string name)
{
    this->name = name; // I give to my attribute (name) the value passed into name through the function's firm.
}

std::string Tile::getName()
{
    if (type == LADDER)
    {
        return "L";
    }
    else if (type == SNAKE)
    {
        return "S";
    }
    else
    {
        return "N";
    }
}

int Tile::reward(int* aNumber)
{
    // Derefernce to change the orignal value
    (*aNumber) += 3;
    return *aNumber;
}

int Tile::penalty(int* aNumber)
{
    (*aNumber) -= 3;
    return *aNumber;
}
