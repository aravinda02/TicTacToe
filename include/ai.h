#ifndef AI_H
#define AI_H
#include <array>
#include <vector>
#include <tuple>
#include <set>

class AI{
    private:
    
    bool isValidWin(const std::array<char,9>& s);
    void generateAllStatesHelper(std::array<char, 9>& board, std::set<std::array<char, 9>>& states, char currentMove) ;
    bool isValidState(const std::array<char, 9> s);
    bool isValidCount(std::array<char, 9> s);
    void AI::fillQtableHelper(std::array<char, 9>& board, std::set<std::array<char, 9>>& states, char currentMove);
    char whoWins(const std::array<char, 9>& s);

    std::vector<std::tuple<std::array<char, 9>, int, int>> qTable;

    
    

    public:
    AI();
    bool isWin(std::array<char, 9> s);
    int countWins(const std::array<char,9>& s);
    std::set<std::array<char, 9>> generateAllStates();

    std::vector<std::tuple<std::array<char, 9>, int, int>> fillQtable(const std::set<std::array<char, 9>>);
};







#endif