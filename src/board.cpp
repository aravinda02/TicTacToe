#include <iostream>
#include <fstream>

class Board{

    public:
    char gameBoard[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    void makeMove(int rowIndex, int colIndex, char character){
        gameBoard[rowIndex][colIndex] = character;
    }

    void printBoard(){
        for(int i=0; i < 3; i++){
            for (int j=0; j<3; j++){
                std::cout << gameBoard[i][j];
            }
            std::cout << std::endl;
        }
    }
}