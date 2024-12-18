#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Board.h"
#include <string>

class TicTacToe
{
private:
    Board board;
    int winLength;
    std::string player1Symbol;
    std::string player2Symbol;
public:
    TicTacToe(int n, int m);
    void playGame();
    bool checkWin(const std::string& symbol) const;

};

#endif // TICTACTOE_H
