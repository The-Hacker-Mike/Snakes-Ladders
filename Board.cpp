/*
 * Miguel Angel Medina Ruperto
 * A01023656
 * 25/05/2020
 * Board implementation
 */

#include "Board.h"
#include "Tile.h" // As I include the mold, anything with the mold can make an instance, for example: a tile.
#include "constants.h"

// Constructor
GameBoard::GameBoard(std::string, int turns)
{
    this->name = name;
    this->turns = turns;
}

// Destructor
GameBoard::~GameBoard()
{
    //std::cout << "Destructor of GameBoard." << std::endl;
}

int GameBoard::getTurns()
{
    return turns;
}

void GameBoard::makeBoard()
{
    int size = 30;
    //int size2 {30};

    board.reserve(size);

    std::vector<int> ladders {7, 11, 14}; //indexes to search on, ladders.
    std::vector<int> snakes {9, 17, 23}; //indexes to search on, snakes.

    for (int i = 0; i<size; i++)
    {
        if (find(ladders.begin(), ladders.end(), i) != ladders.end())
        {
            board.push_back(Tile(LADDER)); // I pushback an instance of tile called "LADDER"
        }
        else if (find(snakes.begin(), snakes.end(), i) != snakes.end())
        {
            board.push_back(Tile(SNAKE)); // I pushback an instance of tile called "SNAKE"
        }
        else
        {
            board.push_back(Tile(NORMAL)); // I pushback an instance of tile called "NORMAL"
        }
    }

    this->printBoard();
}

void GameBoard::printBoard()
{
    // loop to print the vector
    for (int i = 0; i<board.size(); i++)
    {
        Tile actualTile = board[i]; // Each position of the vector becomes a real Tile!
        std::cout << actualTile.getName() << " ";
    }
}

int GameBoard::getPosition(int position)
{
    Tile positionTile = board[position];

    if (positionTile.getName() == "L")
    {
        //position += 3;
        positionTile.reward(&position); // reward receives the address of the variable position

        if (position > 29)
        {
            return position = 29;
        }

        else
        {
            return position;
        }
    }

    else if (positionTile.getName() == "S")
    {
        //position -= 3;
        positionTile.penalty(&position);

        if (position < 0)
        {
            return position = 0;
        }
        else
        {
            return position;
        }
    }
    else
    {
        return position;
    }
}

std::string GameBoard::getTileType(int index)
{
    // board is my vector of Tiles
    std::string nameTile = board[index].getName();
    return nameTile;
}
