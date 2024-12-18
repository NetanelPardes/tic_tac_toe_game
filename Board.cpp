#include "Board.h"
#include <iostream>
#include <iomanip>

Board::Board(int n) : size(n), grid(n, std::vector<std::string>(n))
{
    int cellNumber = 1;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            grid[i][j] = std::to_string(cellNumber++);
        }
    }
}

void Board::printBoard() const
{
    for (const auto& row : grid)
    {
        for (const auto& cell : row)
        {
            std::cout << std::setw(4) << cell;
        }
        std::cout << "\n";
    }
}

bool Board::makeMove(int cell, const std::string& playerSymbol)
{
    int row = (cell - 1) / size;
    int col = (cell - 1) % size;

    if (row < 0 || row >= size || col < 0 || col >= size || !isdigit(grid[row][col][0]))
    {
        return false; // Invalid move
    }
    grid[row][col] = playerSymbol;
    return true;
}

bool Board::checkFull() const
{
    for (const auto& row : grid)
    {
        for (const auto& cell : row)
        {
            if (isdigit(cell[0])) return false;
        }
    }
    return true;
}

std::string Board::getCell(int row, int col) const
{
    return grid[row][col];
}

int Board::getSize() const
{
    return size;
}

void Board::resetCell(int row, int col)
{
    grid[row][col] = std::to_string(row * size + col + 1);
}
