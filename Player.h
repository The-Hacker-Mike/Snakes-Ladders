/*
 * Miguel Angel Medina Ruperto
 * A01023656
 * 25/05/2020
 * Player header
 */

#include "Board.h"
#include <iostream>
#pragma once

class Player
{
private:

    // Attributes
    std::string name;
    int age;
    int id;
    int position;
    int turn;
    GameBoard aBoard;

public:

    // Constructors
    Player() = default;
    Player(std::string name, int age, int id, int position, int turn);
    // Methods
    int getID();
    int getAge();
    std::string getName();
    int getPosition();
    int getTurn();
    int play(GameBoard gameBoard, Dice dice);
    void showScore(int turn, int diceThrow, int tileResult, std::string tileType);
    // Destructor
    ~Player();
};
