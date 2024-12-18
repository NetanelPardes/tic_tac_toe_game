#include "TicTacToe.h"
#include <iostream>

int main()
{
    try
    {
        TicTacToe game(4, 4); // 4x4 board, win length 4
        game.playGame();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
