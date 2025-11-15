#ifndef BOARD_H
#define BOARD_H

class Board{

    public:
    Board();
    std::array<char, 9> gameBoard;
    

    void makeMove(int index, char character);
    void printBoard();
};

#endif