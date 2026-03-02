//
// Created by haoran on 2022/1/13.
//

#ifndef SYNTAX_ANALYZE_RECURSIVEDESCENTANALYSIS_H
#define SYNTAX_ANALYZE_RECURSIVEDESCENTANALYSIS_H

#pragma once
#include <string>

class RecursiveDescentAnalysis {
private:
    std::string expression;
    char sym;
    int index;
    bool hasErr;
public:
    RecursiveDescentAnalysis() {
        this -> sym = ' ';
        this -> index = -1;
        this -> hasErr = false;
    }
    void E();
    void C();
    void T();
    void G();
    void F();
    void advance();
    void run();
    // static void error();
    // static void correct();
};


#endif //SYNTAX_ANALYZE_RECURSIVEDESCENTANALYSIS_H
