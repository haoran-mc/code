//
// Created by haoran on 2022/1/13.
//

#include "../include/RecursiveDescentAnalysis.h"
#include "../include/WordAnalysis.h"
#include <iostream>

// E()
void RecursiveDescentAnalysis::E() {
    T();
    C();
}

// E'()
void RecursiveDescentAnalysis::C() {
    if (this->sym == '+') {
        advance();
        T();
        C();
    }
}

// T()
void RecursiveDescentAnalysis::T() {
    F();
    G();
}

// T'()
void RecursiveDescentAnalysis::G() {
    if (this->sym == '*') {
        advance();
        F();
        G();
    }
}

// F()
void RecursiveDescentAnalysis::F() {
    if (this->sym == 'i')
        advance();
    else {
        if (this->sym == '(') {
            advance();
            E();
            if (this->sym == ')') {
                advance();
            } else {
                this->hasErr = true;
            }
        } else {
            this->hasErr = true;
        }
    }
}

// 指针向前走一步
void RecursiveDescentAnalysis::advance() {
    this->index++;
    this->sym = this->expression[index];
}

void RecursiveDescentAnalysis::run() {
    WordAnalysis wordAnalysis;

    FILE *fp = fopen("/home/haoran/haoran/Code/Major/Compilation_principle/C++/Syntax_analyze/expression.txt", "r");
    std::string ex = WordAnalysis::readFileContent(fp);

    if (!wordAnalysis.analyze(ex))   // 词法分析阶段
        std::cout << "词法分析失败！" << std::endl;
    else {
        for (int i = 0; i < wordAnalysis.getExpressions().size(); i++) {
            std::cout << "(" << i + 1 << ")输出：";
            this->expression = wordAnalysis.getExpressions()[i];
            this->expression += '#';
            this->index = -1;
            this->hasErr = false;
            advance();
            E();

            if (this->hasErr) {
                std::cout << "错误" << std::endl;
            } else if (this->sym == '#') {
                std::cout << "正确" << std::endl;
            } else {
                std::cout << "错误" << std::endl;
            }
        }
    }
}
