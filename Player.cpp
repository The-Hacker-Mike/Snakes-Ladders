/*
 * Miguel Angel Medina Ruperto
 * A01023656
 * 25/05/2020
 * Player
 */

#include "Player.h"

// Constructor
Player::Player(std::string name, int age, int id, int position, int turn)
{
    this->name = name;
    this->age = age;
    this->id = id;
    this->position = position;
    this->turn = turn;
}

// Destructor
Player::~Player()
{
    //std::cout << "Destructor of Player." << std::endl;
}

int Player::getID()
{
    return id;
}

std::string Player::getName()
{
    return name;
}

int Player::getAge()
{
    return age;
}

int Player::getPosition()
{
    return position;
}

int Player::getTurn()
{
    return turn;
}

int Player::play(GameBoard gameBoard, Dice dice)
{
    turn = this->getTurn();
    position = this->getPosition();

    // The player throws the dice. The result is stored in diceThrow.
    int diceThrow = dice.rollDice();

    // Obtaining the new position by adding the number of the dice roll.
    int newPosition = position + diceThrow;

    // "getPosition()" Method is called to discover where he/she landed.
    int tileResult = gameBoard.getPosition(newPosition);

    // "getTileType()" Method is called to discover in what type of tile he/she landed.
    std::string tileType = gameBoard.getTileType(newPosition);

    // Print the statistics.
    this->showScore(turn, diceThrow, tileResult, tileType);

    // Update values.
    position = tileResult;
    turn ++;

    return tileResult;
}

void Player::showScore(int turn, int diceThrow, int tileResult, std::string tileType)
{
    // Print the characteristics of the player.
    std::cout << "For the player: " << this->getName() << ". Aged: " << this->getAge() << ". And ID number: " << this->getID() << std::endl;

    // Print: (Turn, player_id, tile_num, dice_num, tile_type, tile_result_num)
    std::cout << turn << " " << id << " " << position+1 << " " << diceThrow << " " << tileType << " " << tileResult+1 << std::endl;
}
// Pointer GameoBoard only if I am going to change the original values.
