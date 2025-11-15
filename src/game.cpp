#include <iostream>
#include "game.h"

using namespace std;


Game::Game(){
    
};


void Game::runGame(){
    using namespace std;
    bool gameOver = false;
    while (!gameOver){
        if(turn == 0){
        cout << "Enter your move in the form row,column" << endl;
        cin >> playerInput;
        }
    }
    

}
