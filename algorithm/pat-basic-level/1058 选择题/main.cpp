// 260227 14:32 Fri
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;
int score[105];              // 每题的分数
unordered_set<char> st[105]; // 每题的正确答案
int wrong[105];              // 每题有多少学生做错

int main() {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> score[i];
        int optCnt, correctOptCnt;
        cin >> optCnt >> correctOptCnt;
        for (int j = 0; j < correctOptCnt; j++) {
            char ch;
            cin >> ch;
            st[i].insert(ch);
        }
    }
    int maxWrong = 0;
    for (int i = 0; i < N; i++) { // N 位学生
        int stuScore = 0;
        for (int j = 0; j < M; j++) { // M 题
            int x;                    // i 学生 j 题选择 x 个选项
            if (j == 0)
                scanf("\n(%d", &x);
            else
                scanf(" (%d", &x);
            bool f = true;
            for (int k = 0; k < x; k++) {
                char ch;
                scanf(" %c", &ch);
                if (!st[j].count(ch))
                    f = false;
            }
            if (x != st[j].size())
                f = false;

            if (!f) {
                wrong[j]++;
                maxWrong = max(maxWrong, wrong[j]);
            } else
                stuScore += score[j];

            scanf(")");
        }
        printf("%d\n", stuScore);
    }
    if (!maxWrong) {
        printf("Too simple\n");
    } else {
        printf("%d", maxWrong);
        for (int i = 0; i < M; i++)
            if (wrong[i] == maxWrong)
                printf(" %d", i + 1);
        printf("\n");
    }
    return 0;
}
