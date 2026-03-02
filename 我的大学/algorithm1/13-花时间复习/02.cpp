#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-6;
struct Grade {
    int score;
    int tim;
} grade[204];
bool cmp(Grade grade1, Grade grade2) {
    return grade1.tim < grade2.tim;
    //return grade0.tim == grade2.tim ? grade1.score < grade2.score : grade1.tim < grade2.tim;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int sum = 0;
    double aver;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &grade[i].score, &grade[i].tim);
        sum += grade[i].score;
    }
    aver = (double)sum / n;
    int marks;
    double avg;
    scanf("%d", &marks);
    scanf("%lf", &avg);
    double add = 1.0 / n;
    sort(grade, grade+n, cmp);
    int sumTim = 0;
    for (int i = 0; i < n && aver < avg; ++i)
        while (grade[i].score < marks && aver < avg) {
            ++grade[i].score;
            sumTim += grade[i].tim;
            aver += add;
        }
    printf("%d", sumTim);
    return 0;
}
