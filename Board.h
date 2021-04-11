/*
 * Miguel Angel Medina Ruperto
 * A01023656
 * 25/05/2020
 * Board header
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include "Tile.h"
#pragma once

class GameBoard
{
    // Attributes
    std::string name;
    int turns;
    std::vector<Tile> board;

public:
    // Constructors
    GameBoard() = default;
    GameBoard(std::string name, int turns);
    // Methods
    int getTurns();
    void makeBoard();
    void printBoard();
    int getPosition(int position);
    std::string getTileType(int index);
    // Destructor
    ~GameBoard();
};
