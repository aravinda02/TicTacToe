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
    void fillQtableHelper(std::array<char, 9>& board, char currentMove,
                          std::vector<int>& possibleValuesX, std::vector<int>& possibleValuesO,
                          std::vector<int>& actions);

    char whoWins(const std::array<char, 9>& s);

    std::vector<std::tuple<std::array<char, 9>, int, int>> qTableX;
    std::vector<std::tuple<std::array<char, 9>, int, int>> qTableO;

    
    

    public:
    AI();
    bool isWin(std::array<char, 9> s);
    int countWins(const std::array<char,9>& s);
    std::set<std::array<char, 9>> generateAllStates();

    std::pair<std::vector<std::tuple<std::array<char, 9>, int, int>>,
          std::vector<std::tuple<std::array<char, 9>, int, int>>> fillQtable(const std::set<std::array<char, 9>>& states);
    char whoMoves(const std::array<char, 9>& s);

    void printQtable(std::vector<std::tuple<std::array<char, 9>, int, int>> qTable);
};







#endif