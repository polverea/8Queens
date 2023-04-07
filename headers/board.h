#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <vector>

class Board
{
public:
    Board(int lines, int columns);
    ~Board();
    void drawBoard();
    bool checkQueen(int line, int column);
    void backtrack(int line);
    int totalSol_;
private:
    int lines_;
    int columns_;

    std::vector<std::vector<int>> matrix_;

};

#endif
