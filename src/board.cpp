#include "board.h"

Board::Board(int lines, int columns) : lines_(lines), columns_(columns)
{
    totalSol_ = 0;
    matrix_.resize(lines, std::vector<int>(columns_));
}

void Board::drawBoard()
{
    std::cout<<"New solution" << std::endl;
    std::string s = "";
    for (int z = 0; z < lines_; z++)
    {
        s.append("---");
    }
    std::cout<< s << "--" << std::endl;
    for (int i = 0; i < lines_; i++)
    {
        for (int j = 0; j < columns_; j++)
        {
            std::cout<<"| ";
            if (matrix_[i][j] == 0)
                std::cout << " ";
            else 
                std::cout<< matrix_[i][j] << " ";

        }  
        std::cout<< "|"<<std::endl;
         std::cout<< s << "--" << std::endl;
    }
}

bool Board::checkQueen(int line, int column)
{
    for (int i = 0; i < line; i++)
    {   
        if(matrix_[i][column])
            return false;        
    }

    for (int i = line - 1, j = column - 1; i >= 0 && j >= 0; i--, j--)
        if (matrix_[i][j])
            return false;
    
    for (int i = line - 1, j = column + 1; i >= 0 && j < columns_; i--, j++)
        if (matrix_[i][j])
            return false;

    return true;
}



void Board::backtrack(int line)
{
    if (line == lines_)
    { 
        drawBoard();
        totalSol_++;
        return;
    }
    for (int column = 0; column < columns_; column++) 
    { 
        if (checkQueen(line, column)) 
        {
            matrix_[line][column] = column + 1;
            backtrack(line + 1); // trecem la urmatoarea linie
            matrix_[line][column] = 0;
        }
    }
}


Board::~Board(){}
