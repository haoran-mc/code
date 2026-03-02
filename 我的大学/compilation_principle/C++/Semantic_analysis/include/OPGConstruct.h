//
// Created by haoran on 2022/1/14.
//

#ifndef SEMANTIC_ANALYSIS_OPGCONSTRUCT_H
#define SEMANTIC_ANALYSIS_OPGCONSTRUCT_H

#include "../include/Grammar.h"
#include <stack>
#include <cstring>

// static const int MAX_GRAMMAR = 50;

class OPGConstruct {
private:
    Grammar grammar;
    std::stack<int> stk;
    int firstVt[MAX_GRAMMAR][MAX_GRAMMAR]{};
    int lastVt[MAX_GRAMMAR][MAX_GRAMMAR]{};
    int row;
    int column;
    std::string strForm[MAX_GRAMMAR];
public:
    int opgMatrix[MAX_GRAMMAR][MAX_GRAMMAR]{};
    OPGConstruct() {
        this->row = grammar.lengthVn();
        this->column = grammar.lengthVt();

        // this->strForm = grammar.strForm;
        for (int i = 0; i < MAX_GRAMMAR; ++ i) {
            this->strForm[i] = grammar.strForm[i];
        }

        memset(opgMatrix, 0, sizeof opgMatrix);
        memset(firstVt, 0, sizeof firstVt);
        memset(lastVt, 0, sizeof lastVt);
        constructOPGMatrix();
    }
    void printFirstVt();
    void printLastVt();
    void printOPGMatrix();
    void insertStack(bool flag, int tempVn, int tempVt);
    void constructFirstVt();
    void constructLastVt();
    void constructOPGMatrix();
    void searchEqual(int chLength, int j, std::string chs);
    void searchSmall(int j, std::string chs);
    void searchBig(int j, std::string chs);
};


#endif //SEMANTIC_ANALYSIS_OPGCONSTRUCT_H
