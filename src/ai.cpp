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

std::pair<std::vector<std::tuple<std::array<char, 9>, int, int>>,
          std::vector<std::tuple<std::array<char, 9>, int, int>>> 
AI::fillQtable(const std::set<std::array<char, 9>>& states) {
    qTableX.clear();
    qTableO.clear();
    for (const std::array<char, 9>& s : states) {
        std::array<char, 9> board = s;   // ← make a copy you can modify GEN AI GENERATED
        
        char currentMove = whoMoves(s);  
        std::vector<int> possibleValuesX;
        std::vector<int> possibleValuesO;
        std::vector<int> actions;
        fillQtableHelper(board, currentMove, possibleValuesX, possibleValuesO, actions);

        for (size_t i = 0; i < actions.size(); i++) {
            int action = actions[i]; 
            int rewardX = possibleValuesX[i];  
            int rewardO = possibleValuesO[i];  

            if (currentMove == 'x') {
                qTableX.push_back(std::make_tuple(s, action, rewardX));
            } else {
                qTableO.push_back(std::make_tuple(s, action, rewardO));
            }
        }
    }



    return {qTableX, qTableO};
}



void AI::fillQtableHelper(std::array<char, 9>& board, char currentMove,
                          std::vector<int>& possibleValuesX, std::vector<int>& possibleValuesO,
                          std::vector<int>& actions) {
    if (isWin(board)) {
        char winner = whoWins(board);
        if (currentMove == winner && winner == 'x') {
            possibleValuesX.push_back(1);
            possibleValuesO.push_back(-1);
        } else if (currentMove == winner && winner == 'o') {
            possibleValuesX.push_back(-1);
            possibleValuesO.push_back(1);
        } else {
            possibleValuesX.push_back(-1);
            possibleValuesO.push_back(1);
        }
    } else if (std::find(board.begin(), board.end(), '_') == board.end()) {
        possibleValuesX.push_back(0);
        possibleValuesO.push_back(0);
    } else {
        std::vector<int> rewardsX;
        std::vector<int> rewardsO;

        for (int i = 0; i < 9; i++) {
            if (board[i] == '_') {
                board[i] = currentMove;
                char nextMove = (currentMove == 'x' ? 'o' : 'x');

                fillQtableHelper(board, nextMove, possibleValuesX, possibleValuesO, actions);

                board[i] = '_';

                rewardsX.push_back(possibleValuesX.back());
                rewardsO.push_back(possibleValuesO.back());
            }
        }

        if (!rewardsX.empty()) {
            int avgRewardX = std::accumulate(rewardsX.begin(), rewardsX.end(), 0) / rewardsX.size();
            int avgRewardO = std::accumulate(rewardsO.begin(), rewardsO.end(), 0) / rewardsO.size();
            possibleValuesX.push_back(avgRewardX);
            possibleValuesO.push_back(avgRewardO);
        }
    }
}



char AI::whoWins(const std::array<char, 9>& s){
    int countX=0, countO = 0;

    for(char c : s){
        if (c == 'x'){
            countX += 1;
        }
        if (c == 'o'){
            countO += 1;
        }
    }
    if (countX == (countO +1) ){
        return 'x';
    }
    else{
        return 'o';
    }
}

char AI::whoMoves(const std::array<char, 9>& s){
    int countX=0, countO = 0;

    for(char c : s){
        if (c == 'x'){
            countX += 1;
        }
        if (c == 'o'){
            countO += 1;
        }
    }
    if (countX == (countO +1) ){
        return 'o';
    }
    else{
        return 'x';
    }
}

