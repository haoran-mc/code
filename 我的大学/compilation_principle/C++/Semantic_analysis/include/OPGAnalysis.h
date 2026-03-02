//
// Created by haoran on 2022/1/14.
//

#ifndef SEMANTIC_ANALYSIS_OPGANALYSIS_H
#define SEMANTIC_ANALYSIS_OPGANALYSIS_H

#include "../include/Grammar.h"
#include "../include/OPGConstruct.h"
#include <vector>
#include <string>
#include <stack>

class OPGAnalysis {
private:
    std::vector<std::string> expressions;
    Grammar grammar;
    std::stack<char> stk;
    int opgMatrix[MAX_GRAMMAR][MAX_GRAMMAR];
    OPGConstruct opgCon;
public:
    void analyze(std::string str);
    void run();
    bool isRightStr(std::string chs);
    void checkStr(std::string chs);
    int printReduction(char ch, char pt1, int pnt, int pnum);
    char getStkCh(int i);
};


#endif //SEMANTIC_ANALYSIS_OPGANALYSIS_H
