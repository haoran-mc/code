//
// Created by haoran on 2022/1/13.
//

#ifndef SYNTAX_ANALYZE_FORECASTANALYSIS_H
#define SYNTAX_ANALYZE_FORECASTANALYSIS_H

#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

class ForecastAnalysis {
private:
    static const int MAX_GRAMMAR = 50;
    std::vector<std::string> noTerminal;
    std::vector<std::string> terminal;
    std::string grammarRules[MAX_GRAMMAR][2];   // 语法规则存储
    std::string noLeftRecursiveGrammarRules[MAX_GRAMMAR * 2][2];   // 消除左递归的语法规则
    std::string newGrammar[MAX_GRAMMAR * 5][3];
    int grammarRulesLen;
    int noLeftRecursiveGrammarRulesLen;
    int newGrammarLen;
    std::string init;   // 文法开始符号
    std::string firstSet[MAX_GRAMMAR][MAX_GRAMMAR];
    std::string followSet[MAX_GRAMMAR][MAX_GRAMMAR];
    int analysis[MAX_GRAMMAR][MAX_GRAMMAR]{};
public:
    ForecastAnalysis() {
        this->grammarRulesLen = 0;
        this->noLeftRecursiveGrammarRulesLen = 0;
        this->newGrammarLen = 0;
        memset(this->analysis, 0, sizeof this->analysis);
    }

    void inputNoTerminalSymbols();
    void inputTerminalSymbols();
    void inputGrammarRules();
    void divideGrammar(std::string grammar);
    void eliminateLeftRecursion(std::string grammar);
    void first(std::string noTer);
    void follow(std::string noTer);
    void table();
    void analysisStack(std::string test);
    void run();
    static std::string toString(char ch);
    void outputGrammarRules();
    void outputNoLeftRecursiveGrammarRules();
};


#endif //SYNTAX_ANALYZE_FORECASTANALYSIS_H
