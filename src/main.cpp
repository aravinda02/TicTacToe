#include <vector>
#include <array>
#include <iostream>

#include "ai.h"
int main(){

    AI ai;

    std::set<std::array<char, 9>> states = ai.generateAllStates();

    std::cout << states.size() << std::endl;

    int xWins = 0;
    int oWins = 0;
    int draws = 0;
    int incomplete = 0;

    for(std::array<char, 9> s : states){
        bool winner = ai.isWin(s);
        if (winner){
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
                xWins ++;
            }
            else{
                oWins ++;
            }
        }
        else{
            if(std::find(s.begin(), s.end(), '_') != s.end()){
                incomplete += 1;

            }
            else{
                draws += 1;
            }
        }
    }


    std::cout << "X Wins:          " << xWins << std::endl;
    std::cout << "O Wins:          " << oWins << std::endl;
    std::cout << "Draws:          " << draws << std::endl;
    std::cout << "Incomplete:          " << incomplete << std::endl;

    std::pair<std::vector<std::tuple<std::array<char, 9>, int, int>>,
          std::vector<std::tuple<std::array<char, 9>, int, int>>> qTables = ai.fillQtable(states);

    std::cout << qTables<<

}