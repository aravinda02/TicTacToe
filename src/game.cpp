#include <iostream>
#include "game.h"
using namespace std


Game(){
    Board board = board()

}


void runGame(){
    using namespace std;
    bool gameOver = false;
    while (!gameOver){
        if(turn == 0){
        cout << "Enter your move in the form row,column" << endl;
        cin >> playerInput;
        stringstream ss(playerInput);
        string temp;

        getline(ss, temp, ',');
        int row = stoi(temp);

        getline(ss, temp, ',');
        int col = stoi(token);

        board.makeMove(row, col, '0');
        board.printBoard();
        }
    }
    

}
