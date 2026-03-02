#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
#define bug printf("<------>\n");
/*
9
1 2
1 2
1 4
2 4
3 4
2 5
3 5
4 5
3 7
*/
struct score {
    long long L;
    long long R;
} stu[maxn];

bool cmp(score stu1, score stu2) {
    return stu1.R == stu2.R ? stu1.L > stu2.L : stu1.R <= stu2.R;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld %lld", &stu[i].L, &stu[i].R);
    sort(stu, stu + n, cmp);
    long long inc  = inf;
    long long mini = inf;
    long long res  = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (stu[j].R >= stu[i].L && j < i) {
            ++j;
        }
        mini = min(mini, inc);
        for (int k = i; k < j; ++k) {
            mini = min(mini, stu[i].L);
        }
        if (mini < inc && i == 0)
            mini = inc + 1;
        res += mini * (j - i - 1);
        inc = mini;
        i = j - 1;
    }
    printf("%lld\n", res);
    return 0;
}

