#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 2e5 + 5;
struct Team {
    int skill;
    int start;
} team[maxn];

bool cmp(Team T1, Team T2) {
    return T1.skill <= T2.skill;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &team[i].skill);
    sort(team, team+n, cmp);
    team[0].start = 0;
    int cnt = 1;
    int res = 0;
    for (int i = 1; i < n; ++i) {
        if (team[i].skill <= team[team[i-1].start].skill + 5) {
            team[i].start = team[i-1].start;
            ++cnt;
        }
        else {
            res = max(res, cnt);
            cnt = 1;
            team[i].start = i;
        }
    }
    /*
     *for (int i = 0; i < n; ++i)
     *    printf("%d %d\n", team[i].skill, team[i].start);
     */
    res = max(res, cnt);
    printf("%d\n", res);
    return 0;
}
