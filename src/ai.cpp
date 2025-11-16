#include <iostream>
#include <fstream>
#include <cmath>
#include "ai.h"
#include <set>


AI::AI(){}


bool AI::isValidWin(const std::array<char, 9>& state){
    int countX = 0, countO = 0;
    for (char c : state) {
        if (c== 'x') {
            countX++;
        }
        if (c== 'o') {
            countO++;
        }
    }
    if (!(countX == countO || countX == countO + 1))
        return false;
    char winner = '_';
    for (int i = 0; i < 9; i++) {
        if (state[i] == 'x' || state[i] == 'o') {
            if ((state[0] == state[1] && state[1] == state[2] && state[0] == state[i]) ||
                (state[3] == state[4] && state[4] == state[5] && state[3] == state[i]) ||
                (state[6] == state[7] && state[7] == state[8] && state[6] == state[i]) ||
                (state[0] == state[3] && state[3] == state[6] && state[0] == state[i]) ||
                (state[1] == state[4] && state[4] == state[7] && state[1] == state[i]) ||
                (state[2] == state[5] && state[5] == state[8] && state[2] == state[i]) ||
                (state[0] == state[4] && state[4] == state[8] && state[0] == state[i]) ||
                (state[2] == state[4] && state[4] == state[6] && state[2] == state[i]))
            {
                winner = state[i];
                break;
            }
        }
    }

    if (winner == 'x') {
        if (countX != countO + 1) {
            return false;
        }
    }
    else if (winner == 'o') {
        if (countO != countX) {
            return false;
        }
    }

    return true; 
}
bool AI::isValidCount(std::array<char, 9> state){
    int countX = 0;
    int countO = 0;
    for(int i=0; i < 9; i++){
        if(state[i] == 'x'){
            countX += 1;
        }

        else if (state[i] == 'o'){
            countO += 1;
        }
    }
    bool correctCount = (countO + 1 == countX || countO == countX);
    return correctCount;

}
bool AI::isValidState(std::array<char, 9> state){
        bool isValidState = false;
        if (isWin(state)){
            if (isValidWin(state) && isValidCount(state)){
                isValidState = true;
            }
        }
        else if (isValidCount(state)){
            isValidState = true;
        }



        return isValidState;
}

void AI::generateAllStatesHelper(std::array<char, 9>& board, std::set<std::array<char, 9>>& states, char currentMove)
{
    states.insert(board);
    if (isWin(board)) {
        return;
    }

    for (int i = 0; i < 9; i++) {
        if (board[i] == '_') {
            board[i] = currentMove;
            char nextMove = (currentMove == 'x' ? 'o' : 'x');
            generateAllStatesHelper(board, states, nextMove);
            board[i] = '_';
        }
    }
}


//public fns

std::set<std::array<char, 9>> AI::generateAllStates(){
    std::array<char, 9> board = 
    {'_', '_', '_',
        '_', '_', '_',
        '_', '_', '_'};
    std::set<std::array<char, 9>> states;
    char currentMove = 'x';

    generateAllStatesHelper(board, states, currentMove);

    std::set<std::array<char, 9>> validStates = {};
    for (std::array<char, 9> s : states) {
        if (isValidState(s)) {
            validStates.insert(s);
        }

    }

    return validStates;
}
bool AI::isWin(std::array<char, 9> state){
    if((state[0] == state[3] && state[3] == state[6] && state[0] != '_')|| \
        (state[1] == state[4] && state[4] == state[7]&& state[1] != '_') || \
        (state[2] == state[5] && state[5] == state[8]&& state[2] != '_') || \
        (state[0] == state[4] && state[4] == state[8] && state[0] != '_')||\
        (state[2] == state[4] && state[4] == state[6] && state[2] != '_') ||
        (state[0] == state[1] && state[1] == state[2] && state[0] != '_')||\
        (state[3] == state[4] && state[4] == state[5] && state[3] != '_')||\
        (state[6] == state[7] && state[7] == state[8] && state[6] != '_'))
        {
        return true;
    }

    return false;
}
int AI::countWins(const std::array<char,9>& s) {
    int wins = 0;

    if (s[0] == s[1] && s[1] == s[2] && s[0] != '_') wins++;
    if (s[3] == s[4] && s[4] == s[5] && s[3] != '_') wins++;
    if (s[6] == s[7] && s[7] == s[8] && s[6] != '_') wins++;

    if (s[0] == s[3] && s[3] == s[6] && s[0] != '_') wins++;
    if (s[1] == s[4] && s[4] == s[7] && s[1] != '_') wins++;
    if (s[2] == s[5] && s[5] == s[8] && s[2] != '_') wins++;

    if (s[0] == s[4] && s[4] == s[8] && s[0] != '_') wins++;
    if (s[2] == s[4] && s[4] == s[6] && s[2] != '_') wins++;

    return wins;
}