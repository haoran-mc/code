//
// Created by haoran on 2022/1/13.
//

#include "../include/ForecastAnalysis.h"
#include "../include/WordAnalysis.h"
#include <iostream>
#include <algorithm>
#include <stack>

void ForecastAnalysis::inputNoTerminalSymbols() {
    std::cout << "请输入非终结符：" << std::endl;
    std::string noTer = "ETFCG";
    // std::cin >> noTer;
    for (char i : noTer) {
        this->noTerminal.push_back(toString(i));
    }
}

void ForecastAnalysis::inputTerminalSymbols() {
    this->terminal.emplace_back("#");
    std::cout << "请输入终结符：" << std::endl;
    std::string ter = "()i+*-";
    for (char i : ter) {
        this->terminal.push_back(toString(i));
    }
}

void ForecastAnalysis::inputGrammarRules() {
    std::cout << "请输入文法" << std::endl;
    FILE *fp = fopen("/home/haoran/haoran/Code/Major/Compilation_principle/C++/Syntax_analyze/grammar.txt", "r");
    char line[81];
    fgets(line, 81, fp);
    do {
        std::string grammar;
        grammar += line;
        divideGrammar(grammar);
        eliminateLeftRecursion(grammar);
        fgets(line, 81, fp);
    } while (line[0] != '\n');
}

void ForecastAnalysis::divideGrammar(std::string grammar) {
    int divideGrammarPos = (int) grammar.find('|');
    int divideArrowPos = (int) grammar.find("->");

    std::string noTer = toString(grammar[0]);
    if (divideGrammarPos != std::string::npos) {
        this->grammarRules[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), noTer) - this->noTerminal.begin())][0] = grammar.substr(divideArrowPos + 2, divideGrammarPos - divideArrowPos - 2);
        this->grammarRules[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), noTer) - this->noTerminal.begin())][1] = grammar.substr(divideGrammarPos + 1, grammar.length() - divideGrammarPos - 2);
    } else {
        this->grammarRules[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), noTer) - this->noTerminal.begin())][0] = grammar.substr(divideArrowPos + 1, grammar.length() - divideArrowPos - 2);
    }
}

void ForecastAnalysis::eliminateLeftRecursion(std::string grammar) {
    int divideGrammarPos = (int) grammar.find('|');
    int divideArrowPos = (int) grammar.find("->");

    // 如果存在左递归
    if (grammar[0] == grammar[divideArrowPos + 1]) {
        std::string exNoTer;
        // lowerLetter/exNoTer = toString(grammar[0]);   // 但是我们不用这句
        if (grammar[0] == 'E') {
            exNoTer = "C";
        } else if (grammar[0] == 'T') {
            exNoTer = "G";
        }
        this->noTerminal.push_back(exNoTer);
        if (std::find(this->terminal.begin(), this->terminal.end(), "-") == this->terminal.end()) {
            this->terminal.emplace_back("-");
        }
        std::string str;
        int pos = divideArrowPos;
        for (int i = pos; i < grammar.length(); ++ i) {
            str = toString(grammar[i]);
            pos = (int)(std::find(this->terminal.begin(), this->terminal.end(), str) - this->terminal.begin());
            if (pos != grammar.length()) {
                break;
            }
        }
        str = str + grammar.substr(pos + 1, divideGrammarPos - pos) + exNoTer;
        this->noLeftRecursiveGrammarRules[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), exNoTer) - this->noTerminal.begin())][0] = str;
        this->noLeftRecursiveGrammarRules[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), exNoTer) - this->noTerminal.begin())][1] = "-";
        this->noLeftRecursiveGrammarRules[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), toString(grammar[0])) - this->noTerminal.begin())][0] = grammar.substr(divideGrammarPos + 1) + exNoTer;
    } else {
        this->noLeftRecursiveGrammarRules[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), toString(grammar[0])) - this->noTerminal.begin())][0] = this->grammarRules[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), toString(grammar[0])) - this->noTerminal.begin())][0];
        this->noLeftRecursiveGrammarRules[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), toString(grammar[0])) - this->noTerminal.begin())][1] = this->grammarRules[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), toString(grammar[0])) - this->noTerminal.begin())][1];
    }
}

void ForecastAnalysis::first(std::string noTer) {
    int pos = (int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), noTer) - this->noTerminal.begin());
    for (int i = 0; i < 2; ++ i) {
        if (!this->noLeftRecursiveGrammarRules[pos][i].empty()) {
            std::string str = this->noLeftRecursiveGrammarRules[pos][i];
            std::string initials = toString(str[0]);
            if (std::find(this->noTerminal.begin(), this->noTerminal.end(), initials) != this->noTerminal.end()) {
                first(initials);
                for (int j = 0; j < this->terminal.size(); ++ j) {
                    int temp = (int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), initials) - this->noTerminal.begin());
                    if (!this->firstSet[temp][j].empty()) {
                        this->firstSet[pos][j] = this->firstSet[temp][j];
                    }
                }
            } else {
                this->firstSet[pos][(int)(std::find(this->terminal.begin(), this->terminal.end(), initials) - this->terminal.begin())] = str[0];
            }
        }
    }
}

void ForecastAnalysis::follow(std::string noTer) {
    for (int i = 0; i < this->noTerminal.size(); ++ i) {
        for (int j = 0; j < 2; ++ j) {
            if (!this->noLeftRecursiveGrammarRules[i][j].empty()) {
                std::string str = this->noLeftRecursiveGrammarRules[i][j];
                // 文法开始符号
                if (noTer == this->init) {
                    this->followSet[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), init) - this->noTerminal.begin())][(int)(std::find(this->terminal.begin(), this->terminal.end(), "#") - this->terminal.begin())] = "#";
                }
                int index = (int) str.find(noTer);
                if (index != std::string::npos && index != str.length() - 1) {
                    std::string ch = toString(str[index + 1]);
                    // ch 是非终结符
                    if (std::find(this->noTerminal.begin(), this->noTerminal.end(), ch) != this->noTerminal.end()) {
                        for (int k = 0; k < this->terminal.size(); ++ k) {
                            if (!this->firstSet[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), ch) - this->noTerminal.begin())][k].empty() && this->firstSet[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), ch) - this->noTerminal.begin())][k] != "-") {
                                this->followSet[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), noTer) - this->noTerminal.begin())][k] = this->firstSet[(int)(std::find(noTerminal.begin(), noTerminal.end(), ch) - this->noTerminal.begin())][k];
                                for (int l = 0; l < this->terminal.size(); ++ l) {
                                    if (!this->followSet[i][l].empty()) {
                                        this->followSet[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), noTer) - this->noTerminal.begin())][l] = this->followSet[i][l];
                                    }
                                }
                            }
                        }
                    } else {
                        // ch 不是非终结符
                        this->followSet[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), noTer) - this->noTerminal.begin())][(int)(std::find(this->terminal.begin(), this->terminal.end(), ch) - this->terminal.begin())] = ch;
                    }
                } else if (index > 0 && index == str.length() - 1) {
                    // noTer 在最后位置，防止死循环
                    if (this->noTerminal[i] != noTer) {
                        follow(this->noTerminal[i]);
                        for (int k = 0; k < this->terminal.size(); ++ k) {
                            if (!this->followSet[i][k].empty()) {
                                this->followSet[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), noTer) - this->noTerminal.begin())][k] = this->followSet[i][k];
                            }
                        }
                    }
                }
            }
        }
    }
}

void ForecastAnalysis::table() {
    int index = 0;
    for (int i = 0; i < this->noTerminal.size(); ++ i) {
        int num = 0, temp = 0;
        int flag[this->terminal.size()];
        for (int j = index; j < this->newGrammarLen; ++ j) {
            if (this->newGrammar[index][1] == newGrammar[j][1]) {
                flag[temp] = std::stoi(this->newGrammar[j][0]);
                num ++ ;
                temp ++ ;
            }
        }
        index += num;
        if (num == 1) {
            for (int j = 0; j < this->firstSet[i]->length(); ++ j) {
                if (!this->firstSet[i][j].empty()) {
                    this->analysis[i][j] = flag[0];
                }
            }
        } else {
            temp = 0;
            for (int j = 0; j < this->firstSet[i]->length(); ++ j) {
                if (!this->firstSet[i][j].empty()) {
                    if (this->firstSet[i][j] != "-") {
                        this->analysis[i][j] = flag[temp];
                        temp ++ ;
                    } else {
                        for (int f = 0; f < this->followSet[i]->length(); ++ f) {
                            if (!this->followSet[i][f].empty()) {
                                this->analysis[i][f] = flag[temp];
                            }
                        }
                    }
                }
            }
        }
    }
}

void ForecastAnalysis::analysisStack(std::string test) {
    std::vector<std::string> stk;
    stk.emplace_back("#");
    stk.emplace_back("E");
    std::string outStk = test + "#";
    bool flag = true;

    while (flag) {
        std::string inStk;
        for (const std::string& val : stk) {
            inStk += val;
        }
        std::cout << inStk << "\t" << outStk << std::endl;
        std::string NT = stk[stk.size() - 1];
        std::string T = toString(outStk[0]);
        if (NT == T && NT == "#") {
            std::cout << "分析成功" << std::endl;
            break;
        } else if (NT == T) {
            stk.pop_back();
            outStk = outStk.substr(1);
        } else {
            if (std::find(this->noTerminal.begin(), this->noTerminal.end(), NT) == this->noTerminal.end() || std::find(this->terminal.begin(), this->terminal.end(), T) == this->terminal.end()) {
                std::cout << "ERROR：分析出错" << std::endl;
                break;
            }
            if (this->analysis[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), NT) - this->noTerminal.begin())][(int)(std::find(this->terminal.begin(), this->terminal.end(), T) - this->terminal.begin())] > 0) {
                int num = analysis[(int)(std::find(this->noTerminal.begin(), this->noTerminal.end(), NT) - this->noTerminal.begin())][(int)(std::find(this->terminal.begin(), this->terminal.end(), T) - this->terminal.begin())];
                std::string str = this->newGrammar[num-1][2];
                stk.pop_back();
                for (int i = (int)str.length() - 1; i >= 0; -- i) {
                    if (str != "-") {
                        stk.push_back(toString(str[i]));
                    }
                }
            } else {
                std::cout << "ERROR：分析出错" << std::endl;
                break;
            }
        }
        break;
    }
}

void ForecastAnalysis::run() {
    FILE *fp = fopen("/home/haoran/haoran/Code/Major/Compilation_principle/C++/Syntax_analyze/expression.txt", "r");
    std::string ex = WordAnalysis::readFileContent(fp);
    WordAnalysis wordAnalysis;
    wordAnalysis.analyze(ex);   // 词法分析

    inputTerminalSymbols();     // 输入终结符
    inputNoTerminalSymbols();   // 输入非终结符
    inputGrammarRules();        // 输入文法

    for (int k = 0; k < wordAnalysis.getExpressions().size(); ++k) {
        std::string test = wordAnalysis.getExpressions()[k];
        std::cout << "------------------基本信息-----------------------" << std::endl;
        std::cout << "产生式：" << std::endl;
        outputGrammarRules();
        std::cout << "终结符：" << std::endl;
        for (const std::string& i : this->terminal) {
            std::cout << i << "     " << std::endl;
        }
        std::cout << std::endl;
        std::cout << "非终结符：" << std::endl;
        for (const std::string& i : this->noTerminal) {
            std::cout << i << "     " << std::endl;
        }
        std::cout << std::endl;
        std::cout << "读取测试：" << std::endl;
        std::cout << test << std::endl;
        std::cout << "-------------------消除左递归---------------------" << std::endl;
        std::cout << "产生式：" << std::endl;
        outputNoLeftRecursiveGrammarRules();
        for (int i = 0; i < this->noTerminal.size(); ++ i) {
            first(this->noTerminal[i]);
            std::cout << "FIRST(" << this->noTerminal[i] << ") = " << std::endl;
            for (int j = 0; j < this->terminal.size(); ++ j) {
                if (!this->firstSet[i][j].empty()) {
                    std::cout << this->firstSet[i][j] << " " << std::endl;
                }
            }
            std::cout << std::endl;
        }
        for (int i = 0; i < this->noTerminal.size(); ++ i) {
            follow(this->noTerminal[i]);
            std::cout << "FOLLOW(" << this->noTerminal[i] << ") = " << std::endl;
            for (int j = 0; j < this->terminal.size(); ++ j) {
                if (!this->followSet[i][j].empty()) {
                    std::cout << this->followSet[i][j] << " " << std::endl;
                }
            }
            std::cout << std::endl;
        }
        std::cout << "----------------LL(1)分析表-----------------" << std::endl;
        table();
        std::cout << "     ";
        for (std::string i : terminal) {
            std::cout << i << "     " << std::endl;
        }
        std::cout << std::endl;
        for (int i = 0; i < this->noTerminal.size(); ++ i) {
            std::cout << this->noTerminal[i] << "     " << std::endl;
            for (int j = 0; j < this->terminal.size(); ++ j) {
                if (this->analysis[i][j] != 0) {
                    std::cout << analysis[i][j] << "     ";
                } else {
                    std::cout << "     ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "--------------------分析栈-------------------" << std::endl;
        printf("%-10s %-10s", "分析栈", "剩余字符串");
        analysisStack(test);
    }
}

std::string ForecastAnalysis::toString(char ch) {
    std::string str;
    str.push_back(ch);
    return str;
}

void ForecastAnalysis::outputGrammarRules() {
    int k = 0;
    for (int i = 0; i < this->grammarRulesLen; ++ i) {
        for (int j = 0; j < this->grammarRules[i]->length(); ++ j) {
            if (!grammarRules[i][j].empty()) {
                this->newGrammar[k][0] = toString(char(k + 1 + '0'));
                this->newGrammar[k][1] = this->noTerminal[i];
                this->newGrammar[k][2] = this->grammarRules[i][j];
                this->newGrammarLen = std::max(this->newGrammarLen, k);
                std::cout << this->newGrammar[k][0] + "     " + this->newGrammar[k][1] + "     " + this->newGrammar[k][2];
                k ++ ;
            }
        }
    }
}

void ForecastAnalysis::outputNoLeftRecursiveGrammarRules() {
    int k = 0;
    for (int i = 0; i < this->noLeftRecursiveGrammarRulesLen; ++ i) {
        for (int j = 0; j < this->noLeftRecursiveGrammarRules[i]->length(); ++ j) {
            if (!noLeftRecursiveGrammarRules[i][j].empty()) {
                this->newGrammar[k][0] = toString(char(k + 1 + '0'));
                this->newGrammar[k][1] = this->noTerminal[i];
                this->newGrammar[k][2] = this->noLeftRecursiveGrammarRules[i][j];
                this->newGrammarLen = std::max(this->newGrammarLen, k);
                std::cout << this->newGrammar[k][0] + "     " + this->newGrammar[k][1] + "     " + this->newGrammar[k][2];
                k ++ ;
            }
        }
    }
}
