#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
const int maxn = 1e5 + 5;
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
    long long inc  = stu[0].L - 1;
    //long long maxi = 0;
    long long res  = 0;
    map<long long, long long> mp;
    map<long long, long long> reco;
    for (int i = 0; i < n; ++i) {
        ++reco[stu[i].R];
        if (mp.find(stu[i].R) == mp.end()) {
            mp[stu[i].R] = stu[i].L;
        }
        else {
            continue;
        }
    }
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it -> second <= inc) {
            res += (inc + 1);
            ++inc;
        }
        else {
            res += it -> second * reco[it -> first];
            inc = it -> second;
        }
    }
    /*
     *for (int i = 0; i < n; ++i) {
     *    if (i == 0) {
     *        res += stu[0].L;
     *        maxi = stu[0].L;
     *        inc  = stu[0].L;
     *    }
     *    else {
     *        if (stu[i].R == stu[i-1].R)
     *            res += maxi;
     *        else {
     *            if (stu[i].L > inc) {
     *                maxi = stu[i].L;
     *                inc  = stu[i].L;
     *                res += stu[i].L;
     *            }
     *            else
     *                res += (++inc);
     *        }
     *    }
     *}
     */
    printf("%lld\n", res);
    return 0;
}
