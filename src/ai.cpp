#include <iostream>
#include <fstream>
#include <cmath>
#include "ai.h"


AI::AI(){

}

bool AI::isWin(std::array<char, 9> state){
    bool result = false;

    if((state[0] == state[3] && state[3] == state[6] && state[0] != '_')|| \
        (state[1] == state[4] && state[4] == state[7]&& state[1] != '_') || \
        (state[2] == state[5] && state[5] == state[8]&& state[2] != '_'))
        {
            if(result == true)
            { //this condition makes sure there is only one win con
                result = false;
                return result;
            }
            else
            {
                result = true;
            }
        } //Vertical win
        
        
    else if ((state[0] == state[1] && state[1] == state[2] && state[0] != '_')||\
            (state[3] == state[4] && state[4] == state[5] && state[3] != '_')||\
            (state[6] == state[7] && state[7] == state[8] && state[6] != '_'))
        {
            if(result == true)
                { //this condition makes sure there is only one win con
                result = false;
                return result;
            }
            else
            {
                result = true;
            };

        } //horizontal win

    else if ((state[0] == state[4] && state[4] == state[8] && state[0] != '_')||\
            (state[2] == state[4] && state[4] == state[6] && state[2] != '_'))
        {
            if(result == true)
                { //this condition makes sure there is only one win con
                result = false;
                return result;
            }
            else
            {
                result = true;
            }

        }; //diagonal win
    
        return result;

}

bool AI::isValid(std::array<char, 9> state){
    return isWin(state);
    

}


std::vector<std::array<char, 9>> AI::generateAllStates(){
    std::array<char, 9> board = {'_', '_', '_',
        '_', '_', '_',
        '_', '_', '_'};
    std::vector<std::array<char, 9>> states;
    char currentMove = 'x';

    generateAllStatesHelper(board, states, currentMove);
    return states;
}
void AI::generateAllStatesHelper(std::array<char, 9>& board, std::vector<std::array<char, 9>>& states,\
     char currentMove)
    {
        bool full = true;
        for(char c: board){
            if (c == '_'){
                full = false;
                break;
            }
        }
        if(full){
            states.push_back(board);
            return;
        }

        for(int i=0; i < 9; i++){
            if(board[i] == '_'){
                board[i] = currentMove;
                char nextMove = (currentMove == 'x' ? 'o' : 'x');
                generateAllStatesHelper(board, states, currentMove);
                board[i] = '_';
            }

        }



};


