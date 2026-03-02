//
// Created by haoran on 2022/1/14.
//

#include "../include/Grammar.h"

int Grammar::isVt(char ch) {
    int temp = 0, i;
    for (i = 0; i < vt.length(); ++i) {
        if (ch == vt[i]) {
            temp = i;
            break;
        }
    }
    if (i >= vt.length())
        return -1;
    else
        return temp;
}

int Grammar::isVn(char ch) {
    int temp = 0, i;
    for (i = 0; i < vn.length(); ++ i) {
        if (ch == vn[i]) {
            temp = i;
            break;
        }
    }
    if (i >= vn.length())
        return -1;
    else
        return temp;
}

int Grammar::lengthVt() {
    return vt.length();
}

int Grammar::lengthVn() {
    return vn.length();
}

char Grammar::getVt(int i) {
    char ch = ' ';
    if (i >= 0 && i < vt.length())
        ch = vt[i];
    return ch;
}

char Grammar::getVn(int i) {
    char ch = ' ';
    if (i >= 0 && i < vn.length())
        ch = vn[i];
    return ch;
}
