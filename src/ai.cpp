#include <iostream>
#include <fstream>
#include "ai.h"

AI::AI(){

}

bool isWin(std::array<char, 9> state){
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
            }

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

        } //diagonal win
    
        return result;

    }

bool isValid(std::array<char, 9> state){
    return isWin(state);
    

}