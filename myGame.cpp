/*
 * Miguel Angel Medina Ruperto
 * A01023656
 * 25/05/2020
 * Snakes & Ladders Game
 */

#include "Player.h"
#include "Board.h"
#include "Tile.h"
#include "Dice.h"
#include <iostream>

class MyGame
{
    public:
        // Constructor
        MyGame() = default;
        // Methods
        void start();
        // Destructor
        ~MyGame();
};

void MyGame::start()
{
    //======/Start/================//

    // Make and print the board.
    GameBoard snakes_ladders = GameBoard("snakes_ladders", 5);
    snakes_ladders.makeBoard();

    // Make the dice.
    Dice myDice = Dice(6, "white");

    // Make the 2 players (Stack).
    Player player_1 = Player("Macro", 19, 1, 0, 1);
    Player player_2 = Player ("Rosa", 17, 2, 0, 1);

    // Print the board.
    // snakes_ladders.printBoard();

    // Ask in order to begin the game.
    std::string start;
    std::cout << "" << std::endl;
    std::cout << "=======||Press C to continue next turn, or E to end the game||========" << std::endl;
    std::cin >> start;

    while (start != "C" && start != "E")
    {
        std::cout << "Sorry, that's an invalid option, please press C to continue next turn or E to end the game." << std::endl;
        std::cin >> start;
    }

    if(start == "E")
    {
        std::cout << "---GAME OVER---" << std::endl;
    }

    else
    {
        // When the maximum turns are surpassed, the game automatically ends.
        int limit = 0;

        while (start != "E" || limit > snakes_ladders.getTurns()) //|| newPosition == 30)
        {
            // Play.
            player_1.play(snakes_ladders, myDice);
            player_2.play(snakes_ladders, myDice);

            limit ++;

            // Players's time to either choose to continue or end.
            std::cout << " " << std::endl;
            std::cin >> start;
        }

        if (start == "E")
        {
            std::cout << "---GAME OVER---" << std::endl;
            std::cout << "Thanks for playing, " << player_1.getName() << " & " << player_2.getName() << "!!!" << std::endl;
        }

        else if (limit > snakes_ladders.getTurns())
        {
            std::cout << "The maximum number of turns has been reached... " << std::endl;
            std::cout << "---GAME OVER---" << std::endl;
        }

        else
        {
            std::cout << "---GAME OVER---" << std::endl;
            // For player 1
            if (player_1.getPosition() == 30)
            {
                std::cout << "Player" << player_1.getID() << ", " << player_1.getName() << " " << "is the Winner!" << std::endl;
            }
            // For player 2
            else
            {
                std::cout << "Player" << player_2.getID() << ", " << player_2.getName() << " " << "is the Winner!" << std::endl;
            }
            std::cout << "Thanks for playing " << player_1.getName() << "and " << player_2.getName() << "!!!" << std::endl;
        }
    }
}

MyGame::~MyGame()
{
    //std::cout << "Destructor of MyGame." << std::endl;
}

int main()
{
    //======/RUN-GAME/================//
    MyGame g = MyGame();
    g.start();
    return 0;
}
