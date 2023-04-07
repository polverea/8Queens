#include "board.h"
#include <iostream>

int main()
{
    Board b(8, 8);
    b.backtrack(0);
    std::cout<<"Solution number: " << b.totalSol_ << std::endl;
    return 0;
}