#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>

class Board
{
private:
    int size;
    std::vector<std::vector<std::string>> grid;
public:
    Board(int n);
    void printBoard() const;
    bool makeMove(int cell, const std::string& playerSymbol);
    bool checkFull() const;
    std::string getCell(int row, int col) const;
    int getSize() const;
    void resetCell(int row, int col);
};

#endif // BOARD_H
