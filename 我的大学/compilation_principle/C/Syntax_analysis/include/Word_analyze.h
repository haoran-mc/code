//
// Created by haoran on 2022/1/13.
//

#ifndef SYNTAX_ANALYSIS_WORD_ANALYZE_H
#define SYNTAX_ANALYSIS_WORD_ANALYZE_H

#endif //SYNTAX_ANALYSIS_WORD_ANALYZE_H

#pragma

#include <stdbool.h>

typedef struct _WordAnalyze {
    char *expression;
    char **expressions;
} WordAnalyze;

bool isLetter(char letter);
bool isDigit(char digit);
bool analyze(char *chars);
char *readFileContent(char *fileName);
