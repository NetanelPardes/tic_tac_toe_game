#include "TicTacToe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

TicTacToe::TicTacToe(int n, int m)
    : board(n), winLength(m), player1Symbol("X"), player2Symbol("O") {
    std::srand(std::time(0));
}

void TicTacToe::playGame()
{
    int currentTurn = 0;
    std::string currentPlayer = player1Symbol;
    int totalMoves = 0;

    while (true)
    {
        board.printBoard();
        std::cout << "Player " << currentPlayer << ", making a move...\n";
        int move;

        do {
            move = std::rand() % (board.getSize() * board.getSize()) + 1;
        } while (!board.makeMove(move, currentPlayer));

        ++totalMoves;

        if (checkWin(currentPlayer))
        {
            board.printBoard();
            std::cout << "Player " << currentPlayer << " wins!\n";
            return;
        }

        if (totalMoves == board.getSize() * board.getSize())
        {
            board.printBoard();
            std::cout << "It's a draw!\n";
            return;
        }

        currentPlayer = (currentPlayer == player1Symbol) ? player2Symbol : player1Symbol;
    }
}

bool TicTacToe::checkWin(const std::string& symbol) const
{
    int size = board.getSize();

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (j <= size - winLength)
            {
                bool win = true;
                for (int k = 0; k < winLength; ++k)
                {
                    if (board.getCell(i, j + k) != symbol) win = false;
                }
                if (win) return true;
            }

            if (i <= size - winLength)
            {
                bool win = true;
                for (int k = 0; k < winLength; ++k)
                {
                    if (board.getCell(i + k, j) != symbol) win = false;
                }
                if (win) return true;
            }

            if (i <= size - winLength && j <= size - winLength)
            {
                bool win = true;
                for (int k = 0; k < winLength; ++k)
                {
                    if (board.getCell(i + k, j + k) != symbol) win = false;
                }
                if (win) return true;
            }

            if (i >= winLength - 1 && j <= size - winLength)
            {
                bool win = true;
                for (int k = 0; k < winLength; ++k)
                {
                    if (board.getCell(i - k, j + k) != symbol) win = false;
                }
                if (win) return true;
            }
        }
    }

    return false;
}
