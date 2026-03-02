//
// Created by haoran on 2022/1/14.
//

#include "../include/OPGConstruct.h"
#include <iostream>

using namespace std;

void OPGConstruct::printFirstVt() {
    std::cout << ".......................FirstVt集......................." << std::endl;
    for (int i = 0; i < row; i++) {
        std::cout << "FirstVt(" << grammar.getVn(i) << "):" << std::endl;
        for (int j = 0; j < column; j++) {
            if (firstVt[i][j] == 1) {
                std::cout << grammar.getVt(j) << " " << std::endl;
            }
        }
        cout << std::endl;
    }
}

void OPGConstruct::printLastVt() {
    std::cout << ".......................LastVt集......................." << std::endl;
    for (int i = 0; i < row; i++) {
        cout << "LastVt(" << grammar.getVn(i) << "):" << endl;
        for (int j = 0; j < column; j++) {
            if (lastVt[i][j] == 1) {
                cout << grammar.getVt(j) << " " << endl;
            }
        }
        cout << endl;
    }
}

void OPGConstruct::printOPGMatrix() {
    cout << endl;
    cout << "  ";
    for (int i = 0; i < column; i++) {
        cout << grammar.getVt(i) + " ";
    }
    cout << endl;
    for (int i = 0; i < column; i++) {
        cout << grammar.getVt(i) + " ";
        for (int j = 0; j < column; j++) {
            if (opgMatrix[i][j] == 0) {
                cout << "? ";
            } else if (opgMatrix[i][j] == 1) {
                cout << "= ";
            } else if (opgMatrix[i][j] == 2) {
                cout << "< ";
            } else if (opgMatrix[i][j] == 3) {
                cout << "> ";
            }
        }
        cout << endl;
    }
}

void OPGConstruct::insertStack(bool flag, int tempVn, int tempVt) {
    if (flag) {
        if (firstVt[tempVn][tempVt] == 0) {
            firstVt[tempVn][tempVt] = 1;
            stk.push(tempVn);
            stk.push(tempVt);
        }
    } else {
        if (lastVt[tempVn][tempVt] == 0) {
            lastVt[tempVn][tempVt] = 1;
            stk.push(tempVn);
            stk.push(tempVt);
        }
    }
}

void OPGConstruct::constructFirstVt() {
    basic_string<char> chs;
    while (!stk.empty())
        stk.pop();
    int tempVn = 0, tempVt = 0;//临时变量
    // 判别每一个产生式
    for (string value: strForm) {
        chs = value;
        // 找到产生式左边字符在vn中的位置
        if (grammar.isVn(chs[0]) != -1) {
            tempVn = grammar.isVn(chs[0]);
        }
        // 形如A→a...
        if (grammar.isVt(chs[2]) != -1) {
            tempVt = grammar.isVt(chs[2]);
            insertStack(true, tempVn, tempVt);
        } else if (chs.length() >= 4) {   // 形如A→Ba...
            if ((grammar.isVn(chs[2]) != -1)
                && (grammar.isVt(chs[3]) != -1)) {
                tempVt = grammar.isVt(chs[3]);
                insertStack(true, tempVn, tempVt);
            }
        }
    }
    //形如A→B...
    while (!stk.empty()) {
        tempVt = stk.top();
        stk.pop();
        tempVn = stk.top();
        stk.pop();
        // 判别每一个产生式
        for (string s: strForm) {
            chs = s;
            // 产生式右边第一个字符是非终结符
            if (grammar.isVn(chs[2]) != -1) {
                if (tempVn == (grammar.isVn(chs[2]))) {
                    insertStack(true, grammar.isVn(chs[0]), tempVt);
                }
            }
        }
    }
}

void OPGConstruct::constructLastVt() {
    basic_string<char> chs;
    while (!stk.empty())
        stk.pop();
    int tempVn = 0, tempVt = 0;//临时变量
    int chLength;//暂存每个产生式长度
    for (string value: strForm) {   //判别每一个产生式
        chs = value;
        chLength = chs.length();
        if (grammar.isVn(chs[0]) != -1) {   //找到产生式左边字符在vn中的位置
            tempVn = grammar.isVn(chs[0]);
        }
        if (grammar.isVt(chs[chLength - 1]) != -1) {   //形如A→....a
            tempVt = grammar.isVt(chs[chLength - 1]);
            insertStack(false, tempVn, tempVt);//入栈
        } else if (chs.length() >= 4) {   //形如A→.....aB
            if ((grammar.isVn(chs[chLength - 1]) != -1)
                && (grammar.isVt(chs[chLength - 2]) != -1)) {
                tempVt = grammar.isVt(chs[chLength - 2]);
                insertStack(false, tempVn, tempVt);
            }
        }
    }
    //形如A→...B
    while (!stk.empty()) {
        tempVt = stk.top();
        stk.pop();
        tempVn = stk.top();
        stk.pop();
        for (string s: strForm) {   //判别每一个产生式
            chs = s;
            chLength = chs.length();
            if (grammar.isVn(chs[chLength - 1]) != -1) {   //产生式最后一个字符是非终结符
                if (tempVn == (grammar.isVn(chs[chLength - 1]))) {
                    insertStack(false, grammar.isVn(chs[0]), tempVt);
                }
            }
        }
    }
}

void OPGConstruct::constructOPGMatrix() {
    constructLastVt();
    constructFirstVt();
    string chs;
    int chLength;//暂存每个产生式长度
    //判别每一个产生式
    for (string s: strForm) {
        chs = s;
        chLength = chs.length();
        if (chLength > 3) {   // 不考虑A→B这种情况
            for (int j = 2; j <= chLength - 2; j++) {
                searchEqual(chLength, j, chs);
                searchSmall(j, chs);
                searchBig(j, chs);
            }
        }
    }
}

void OPGConstruct::searchEqual(int chLength, int j, string chs) {
    int X = grammar.isVt(chs[j]);
    int Y = grammar.isVt(chs[j + 1]);
    //形如A→aa
    if ((X != -1) && (Y != -1)) {
        opgMatrix[X][Y] = 1;
    }
    //形如A→aBa
    if (j <= chLength - 3) {
        int L = grammar.isVt(chs[j]);
        int M = grammar.isVn(chs[j + 1]);
        int N = grammar.isVt(chs[j + 2]);
        if ((L != -1) && (M != -1) && (N != -1)) {
            opgMatrix[L][N] = 1;
        }
    }
}

void OPGConstruct::searchSmall(int j, string chs) {
    //形如A→aB
    int P = grammar.isVt(chs[j]);
    int Q = grammar.isVn(chs[j + 1]);
    if ((P != -1) && (Q != -1)) {
        for (int k = 0; k < column; k++) {
            if (firstVt[Q][k] != 0) {
                opgMatrix[P][k] = 2;
            }
        }
    }
}

void OPGConstruct::searchBig(int j, string chs) {
    //形如A→Ba
    int A = grammar.isVn(chs[j]);
    int B = grammar.isVt(chs[j + 1]);
    if ((A != -1) && (B != -1)) {
        for (int k = 0; k < column; k++) {
            if (lastVt[A][k] != 0) {
                opgMatrix[k][B] = 3;
            }
        }
    }
}
