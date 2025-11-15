#ifndef AI_H
#define AI_H
#include <array>
#include <vector>

class AI{
    private:
    bool isWin(std::array<char, 9> state);
    bool isValid(std::array<char, 9> state);
    void generateAllStatesHelper(std::array<char, 9>& board, 
        std::vector<std::array<char, 9>>& states,
     char currentMove);

    public:
    AI();
    std::vector<std::array<char, 9>> generateAllStates();
};







#endif