#include <vector>
#include <array>
#include <iostream>

#include "ai.h"

int main(){

    AI ai;

    std::vector<std::array<char, 9>> states = ai.generateAllStates();

    std::cout << states.size() << std::endl;


}