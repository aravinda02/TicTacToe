#ifndef AI_H
#define AI_H
#include <array>
#include <vector>

class AI{
    private:
    bool isValid(std::array<char, 9> state);
    std::vector<std::array<char, 9>> generateAllStates();
};







#endif