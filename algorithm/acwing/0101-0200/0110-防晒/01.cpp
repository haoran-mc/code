/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年06月04日 星期五 15时51分37秒
 *   题    目：AcWing 0110 防晒
 *   算    法：<++>
 *   描    述：自己写了一遍，但是没成功
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int maxn = 2500 + 5;
// int mini[maxn], maxi[maxn];
typedef pair<int, int> PII;
#define bug printf("<-->\n");
vector<PII> spf, sun;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int C, L; scanf("%d %d", &C, &L);
    for (int i = 0; i < C; ++i) {
        int mini, maxi;
        scanf("%d %d", &mini, &maxi);
        // scanf("%d %d", &mini[i], &maxi[i]);
        spf.push_back({mini, maxi});
    }
    for (int i = 0; i < L; ++i) {
        int s, c;
        scanf("%d %d", &s, &c);
        sun.push_back({s, c});
    }
    sort(spf.begin(), spf.end());
    sort(sun.begin(), sun.end());
    printf("<--> %d\n", (int)sun.size());
    vector<PII> nsun;
    for (int i = 0; i < (int)sun.size(); ++i) {
        if (nsun.size() == 0) {
            nsun.push_back({sun[i].first, sun[i].second});
            break;
        }
        auto it = nsun.end() - 1;
        printf("<-->%d\n", (int)(it - nsun.begin()));
        if (it -> first == sun[i].first)
            it -> second += sun[i].second;
        else
            nsun.push_back({sun[i].first, sun[i].second});
    }
    L = (int)nsun.size();

    int st = 0, op = 0;
    int cow = 0;
    while (st < C && op < L) {
        if (nsun[op].first < spf[st].first)
            ++op;
        else if (nsun[op].first > spf[st].second)
            ++st;
        else if (nsun[op].first >= spf[st].first && nsun[op].first <= spf[st].second && nsun[op].second > 0) {
            if (!(--nsun[op].second))
                ++op;
            ++cow;
            ++st;
        }
        else
            ++op;
        // printf("%d %d %d\n", st, op, cow);
    }
    printf("%d\n", cow);
    return 0;
}
