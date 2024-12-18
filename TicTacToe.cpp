#include "TicTacToe.h"
#include <iostream>

TicTacToe::TicTacToe(int n, int m)
    : board(n), winLength(m), player1Symbol("X"), player2Symbol("O") {
}

void TicTacToe::playGame()
{
    int currentTurn = 0;
    std::string currentPlayer = player1Symbol;
    int totalMoves = 0;

    while (true)
    {
        board.printBoard();
        std::cout << "Player " << currentPlayer << ", enter your move: ";
        int move;
        std::cin >> move;

        if (!board.makeMove(move, currentPlayer))
        {
            std::cout << "Invalid move! Try again.\n";
            continue;
        }

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

    // Check rows, columns, diagonals
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            // Horizontal
            if (j <= size - winLength)
            {
                bool win = true;
                for (int k = 0; k < winLength; ++k)
                {
                    if (board.getCell(i, j + k) != symbol) win = false;
                }
                if (win) return true;
            }
            // Vertical
            if (i <= size - winLength)
            {
                bool win = true;
                for (int k = 0; k < winLength; ++k)
                {
                    if (board.getCell(i + k, j) != symbol) win = false;
                }
                if (win) return true;
            }
            // Diagonal (top-left to bottom-right)
            if (i <= size - winLength && j <= size - winLength)
            {
                bool win = true;
                for (int k = 0; k < winLength; ++k)
                {
                    if (board.getCell(i + k, j + k) != symbol) win = false;
                }
                if (win) return true;
            }
            // Diagonal (bottom-left to top-right)
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