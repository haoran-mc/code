//
// Created by haoran on 2022/1/13.
//

#include "../include/WordAnalysis.h"
#include <cstdio>

bool WordAnalysis::isLetter(char letter) {
    return (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
}

bool WordAnalysis::isDigit(char digit) {
    return digit >= '0' && digit <= '9';
}

std::string WordAnalysis::readFileContent(FILE *fp) {
    std::string program;
    char line[81];
    while (!feof(fp)) {
        fgets(line, 81, fp);
        program += line;
    }
    return program;
}

bool WordAnalysis::analyze(std::string chars) {
    for (int i = 0; i < (int) chars.length(); ++i) {
        char ch = chars[i];
        if (isLetter(ch)) {
            while (isLetter(ch) || isDigit(ch)) {
                ch = chars[++i];
            }
            this->expression += 'i';
            i--;
        } else if (isDigit(ch)) {   // 遇到数字
            while (isDigit(ch)) {
                ch = chars[++i];
            }
            if (isLetter(ch)) {   // 标识符不能以数字开头，返回错误
                return false;
            }
            this->expression += 'i';
            i--;
        } else if (ch == '(' || ch == ')' || ch == '+' || ch == '*') {
            this->expression += ch;
        } else if (ch == ';') {
            this->expressions.push_back(expression);
            this->expression = "";
        }
        // 不会关注空格符、回车符
    }
    return true;
}

std::vector<std::string> WordAnalysis::getExpressions() {
    return this->expressions;
}
