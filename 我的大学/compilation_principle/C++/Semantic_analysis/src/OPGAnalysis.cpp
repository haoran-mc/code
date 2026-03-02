//
// Created by haoran on 2022/1/14.
//

#include "../include/OPGAnalysis.h"
#include "../include/WordAnalysis.h"
#include <iostream>
using namespace std;

void OPGAnalysis::analyze(std::string str) {
    str = str + "#";
    string chs = str;
    if (isRightStr(chs)) {
        cout << "\n......................................................\n" << str << ":\n";
        cout << ".......................归约过程.......................\n" << endl;
        cout << "步骤  符号栈  当前符号  移进或归约\n" << endl;
        checkStr(chs);
    } else {
        cout << "出现非本文法内的终结符，不识别.......1" << endl;
    }
}

bool OPGAnalysis::isRightStr(std::string chs) {
    bool flag = true;
    for (char c : chs) {
        if (grammar.isVt(c) == -1) {
            flag = false;
            break;
        }
    }
    return flag;
}

void OPGAnalysis::checkStr(std::string chs) {
    while (!stk.empty())
        stk.pop();
    int k = 1, j = 1, i = 0;//k指向栈顶，j指向第一个终结符，i控制读字符
    char ch, top;
    stk.push('#');

    char pt1 = stk.top();//临时
    int pn1 = stk.size();//临时
    int pnum = 1;
    cout << "(" << pnum << ")    ";
    cout << "#       ";
    while (i < chs.length()) {
        ch = chs[i];//读入一个字符a
        pnum = printReduction(ch, pt1, pn1, pnum);
        top = stk.top();

        if (grammar.isVt(top) != -1) {//j指向第一个终结符
            j = k;
        } else {
            j = k - 1;
        }
        int X = grammar.isVt(getStkCh(j));
        int Y = grammar.isVt(ch);
        //对于S[j]>a不成立情况
        if ((X != -1) && (Y != -1) && (opgMatrix[X][Y] != 3)) {
            if (opgMatrix[X][Y] != 2) {//对于S[j]<a不成立情况
                if (opgMatrix[X][Y] != 1) {//对于S[j]=a不成立情况
                    cout << "出现不存在的优先关系，不识别.......1" << endl;
                    break;
                } else {
                    int Z = grammar.isVt('#');
                    if (opgMatrix[X][Z] == 1) {//对于S[j]=#情况
                        if (getStkCh(2) == 'W' && getStkCh(1) == '#') {//正常结束
                            cout << "分析成功！" << endl;
                            break;
                        } else {
                            cout << "没有正常结束，不识别.......2" << endl;
                            break;
                        }
                    }
                }
            }
            k = k + 1;
            i = i + 1;
            stk.push(ch);
            cout << "移进    \n";
        }
        //对于S[j]>a成立情况
        if ((X != -1) && (Y != -1) && (opgMatrix[X][Y] == 3)) {
            char q = getStkCh(j);
            int M = grammar.isVt(getStkCh(j));
            int N = grammar.isVt(q);
            do {//寻找归约串

                q = getStkCh(j);
                M = grammar.isVt(getStkCh(j));
                N = grammar.isVt(q);
                if (j > 1 && (grammar.isVt(getStkCh(j - 1)) != -1)) {
                    j = j - 1;
                } else {
                    if (j > 2) {
                        j = j - 2;
                    }
                }
                M = grammar.isVt(getStkCh(j));
            } while ((opgMatrix[M][N] != 2) && (opgMatrix[M][N] != 0));

            if (opgMatrix[M][N] == 2) {//归约
                int temp = k - j;
                for (int t = 0; t < temp; t++) {
                    stk.pop();
                }
                k = j + 1;
                stk.push('W');
                cout << "归约    \n";
            } else if (opgMatrix[M][N] == 0) {//不存在的优先关系
                cout << "识别失败！该语句不可被该文法识别！" << endl;
                break;
            }
        }
    }
}

int OPGAnalysis::printReduction(char ch, char pt1, int pnt, int pnum) {
    char pt = stk.top();
    int pn = stk.size();
    if (pt1 != pt || pnt != pn) {
        pnum++;
        cout << "(" << pnum << ")    ";
        vector<char> en;
        stack<char> temp = stk;
        while (!temp.empty()) {
            en.push_back(temp.top());
            temp.pop();
        }
        for (auto i : en) {
            cout << i;
        }
        for (int q = 0; q < 8 - pn; q++) {
            cout << " ";
        }
    }
    cout << ch << "         ";
    return pnum;
}

char OPGAnalysis::getStkCh(int i) {
    stack<char> temp = stk;
    while (i -- ) {
        temp.pop();
    }
    return temp.top();
}

void OPGAnalysis::run() {
    FILE *fp = fopen("/home/haoran/haoran/Code/Major/Compilation_principle/C++/Semantic_analysis/expression.txt", "r");
    string ex = WordAnalysis::readFileContent(fp);
    WordAnalysis wordAnalysis;
    wordAnalysis.analyze(ex);
    opgCon.printFirstVt();
    opgCon.printLastVt();
    opgCon.printOPGMatrix();
    for (string expression : expressions) {
        analyze(expression);
    }
}
