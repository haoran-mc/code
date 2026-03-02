#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int N;  /*考生数*/
int M;  /*考题数*/
int G;  /*分数线*/
int score[10];
struct info {
    string ID;
    int total;
    int ques;
    int sum;
}stu[1000];

bool cmp(info stu1, info stu2) {
    if (stu1.sum == stu2.sum)
        return stu1.ID > stu2.ID;
    else
        return stu1.sum > stu2.sum;
}

int main() {
    while (scanf("%d", &N) && N != 0) {
        scanf("%d", &M);
        scanf("%d", &G);
        for (int i = 0; i < M; i++)
            scanf("%d", &score[i]);

        int count = 0;  /*及格人数*/
        for (int i = 0; i < N; i++) {
            cin >> stu[i].ID;
            scanf("%d", &stu[i].ques);
            stu[i].sum = 0;
            for (int j = 0, title; j < stu[i].ques; j++) {
                scanf("%d", &title);
                stu[i].sum += score[title - 1];
            }
            if (stu[i].sum >= G)
                count++;
        }
        sort(&stu[0], &stu[N - 1], cmp);
        printf("%d\n", count);
        for (int i = 0; i < count; i++) {
            cout << stu[i].ID << " ";
            printf("%d\n", stu[i].sum);
        }
    }
    return 0;
}
