//
// Created by haoran on 2022/1/14.
//

#ifndef SEMANTIC_ANALYSIS_GRAMMAR_H
#define SEMANTIC_ANALYSIS_GRAMMAR_H

#include <string>

static const int MAX_GRAMMAR = 50;

class Grammar {
private:
    std::string vn;
    std::string vt;
public:
    std::string strForm[MAX_GRAMMAR];
    int isVt(char ch);
    int isVn(char ch);
    int lengthVt();
    int lengthVn();
    // std::string getForm();
    char getVt(int i);
    char getVn(int i);
};


#endif //SEMANTIC_ANALYSIS_GRAMMAR_H
