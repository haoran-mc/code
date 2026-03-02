#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// 判断是否为关键字
bool isKey(char *str) {
    FILE *fp = fopen("/home/haoran/haoran/Code/Major/Compilation_principle/C/Lexical_analysis/keyword.txt", "r");
    char line[81];
    while (fgets(line, 81, fp) != NULL) {
        if (strcmp(str, line) == 0) {
            fclose(fp);
            return true;
        }
    }
    fclose(fp);
    return false;
}

// 判断是否为字符
bool isLetter(char letter) {
    if (('a' <= letter && letter <= 'z') || ('A' <= letter && letter <= 'Z'))
        return true;
    else
        return false;
}

// 判断是否为数字
bool isDigit(char digit) {
    if ('0' <= digit && digit <= '9')
        return true;
    else
        return false;
}

void operatorAdd(char *str, char ch) {
    int len = (int) strlen(str);
    str[len] = ch;
    str[len + 1] = 0;
}

// 词法分析
void analyze(char *chars) {
    for (int i = 0; i < strlen(chars); ++i) {
        char ch = chars[i];
        char *judge = (char *)malloc(100 * sizeof(char));
        judge[0] = 0;
        if (ch == '#') {
            while (ch != '\n' && ch != ' ') {
                operatorAdd(judge, ch);
                ch = chars[++i];
            }
            printf("<%s, 宏>\n", judge);
            i--;
        } else if (isLetter(ch)) {   // 开头是字符
            bool flag = false;   // 判断是不是关键字
            while (isLetter(ch) || isDigit(ch)) {
                operatorAdd(judge, ch);
                ch = chars[++i];
                if (isKey(judge)) {
                    printf("<%s, 关键字>\n", judge);
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                printf("<0, %s>\n", judge);
            }
            i--;
        } else if (isDigit(ch)) {   // 以数字开头
            if (ch == '0' && chars[i + 1] == 'x') {   // 十六进制
                strcat(judge, "0x");
                i += 2;
                ch = chars[i];
                while (isDigit(ch) || ('a' <= ch && ch <= 'f')) {
                    operatorAdd(judge, ch);
                    ch = chars[++i];
                }
                printf("<3, %s>\n", judge);
                i--;
            } else if (ch == '0') {   // 八进制
                while (isDigit(ch)) {
                    operatorAdd(judge, ch);
                    ch = chars[++i];
                }
                printf("<2, %s>\n", judge);
                i--;
            } else {   // 十进制
                while (isDigit(ch)) {
                    operatorAdd(judge, ch);
                    ch = chars[++i];
                }
                printf("<1, %s>\n", judge);
                i--;
            }
        } else
            switch (ch) {   // 运算符与界符
                case '+':
                    printf("<+, ->\n");
                    break;
                case '-':
                    printf("<-, ->\n");
                    break;
                case '*':
                    printf("<*, ->\n");
                    break;
                case '/':
                    printf("</, ->\n");
                    break;
                case '(':
                    printf("<(, ->\n");
                    break;
                case ')':
                    printf("<), ->\n");
                    break;
                case ';':
                    printf("<;, ->\n");
                    break;
                case '{':
                    printf("<{, ->\n");
                    break;
                case '}':
                    printf("<}, ->\n");
                    break;
                case '"':
                    printf("<\", ->\n");
                    break;
                case '\'':
                    printf("<', ->\n");
                    break;
                case '!':
                    printf("<!, ->\n");
                    break;
                case ' ':
                    break;
                case '\n':
                    break;
                case '=': {
                    ch = chars[++i];
                    if (ch == '=')
                        printf("<==, ->\n");
                    else {
                        printf("<=, ->\n");
                        i--;
                    }
                }
                    break;
                case '>': {
                    ch = chars[++i];
                    if (ch == '=')
                        printf("<>=, ->\n");
                    else {
                        printf("<>, ->\n");
                        i--;
                    }
                }
                    break;
                case '<': {
                    ch = chars[++i];
                    if (ch == '=')
                        printf("<<=, ->>\n");
                    else {
                        printf("<<, ->>\n");
                        i--;
                    }
                }
                    break;
                default: {
                    printf("该词法识别不出 %c 此字符\n", ch);
                }
            }
    }
}

// 删除字符数组中指定字符
void delSelectChar(char *str, char n) {
    char *p;
    for (p = str; *p != '\0'; ++p)
        if (*p != n)
            *str++ = *p;
    *str = '\0';
}

// 从文件中读取程序
char *readFileContent(FILE *fp) {
    char *program = (char *)malloc(1000 * sizeof(char));   // 预留1000字节位置，将读取到的数据存放在里面
    program[0] = 0;   // 为了后面的拼接不出现乱码

    char line[81];
    while (!feof(fp)) {
        fgets(line, 81, fp);
        strcat(program, line);
    }

    return program;
}

int main() {
    FILE *fp = fopen("/home/haoran/haoran/Code/Major/Compilation_principle/C/Lexical_analysis/program.c", "r");
    if (fp == NULL) {
        perror("文件不存在");
    } else {
        char *program = readFileContent(fp);

        // 删除换行符和空白符
        // delSelectChar(program, '\n');
        // delSelectChar(program, ' ');

        analyze(program);
    }
    fclose(fp);
    return 0;
}


/*
 * 1. 文件不能太大，允许存储 1000 个字节的数据量
 * 2. 每行不能超过 80 个字符数量
 * 3. 每个标识符不能超过 99 个字符
 *
 * <0, -> 标识符
 * <1, -> 十进制
 * <2, -> 八进制
 * <3, -> 十六进制
 * <if, -> 关键字
 * <{, -> 界符
 * <<, -> 运算符
 * <#include, -> 宏定义
 */
