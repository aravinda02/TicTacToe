#include <iostream>
#include "board.h"


Board::Board(){
    gameBoard= {'-', '-', '-',
        '-', '-', '-',
        '-', '-', '-'};
}

void Board::makeMove(int index, char character){
    gameBoard[index] = character;
}

void Board::printBoard(){
    for (int i = 0; i < 9; i++){
        std::cout << gameBoard[i] << " ";
        if(i % 3 == 0){
            std::cout << std::endl;
        }
    }
}

Board::Board() {
    gameBoard = {'-', '-', '-',
                 '-', '-', '-',
                 '-', '-', '-'};
}