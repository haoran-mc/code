//
// Created by haoran on 2022/1/13.
//

#ifndef SYNTAX_ANALYZE_WORDANALYSIS_H
#define SYNTAX_ANALYZE_WORDANALYSIS_H

#pragma once
#include <string>
#include <vector>

class WordAnalysis {
private:
    std::string expression;
    std::vector<std::string> expressions;
public:
    static bool isLetter(char letter);
    static bool isDigit(char digit);
    static std::string readFileContent(FILE *fp);
    bool analyze(std::string chars);
    std::vector<std::string> getExpressions();
};


#endif //SYNTAX_ANALYZE_WORDANALYSIS_H
