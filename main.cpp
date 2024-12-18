#include "TicTacToe.h"
#include <iostream>

int main()
{
    try
    {
        TicTacToe game(4, 4);
        game.playGame();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
