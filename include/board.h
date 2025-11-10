#ifndef BOARD_H
#define BOARD_H

class Board{

    public:
    Board();
    char gameBoard[3][3];
    

    void makeMove(int rowIndex, int colIndex, char character);
    void printBoard() const;
};

#endif