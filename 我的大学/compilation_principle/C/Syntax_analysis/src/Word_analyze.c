//
// Created by haoran on 2022/1/13.
//

#include "Word_analyze.h"
#include <stdbool.h>

// 判断是否是字母
bool isLetter(char letter) {
    return (letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z');
}

// 判断是否是数字
static bool isDigit(char digit) {
    return digit >= '0' && digit <= '9';
}
