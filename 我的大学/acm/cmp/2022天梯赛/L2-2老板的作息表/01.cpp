#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 60 * 60 * 60 * 2;
struct Time {
    int hh1, mm1, ss1;
    int hh2, mm2, ss2;
} time[maxn];
int idx = 0;

bool cmp(Time i1, Time i2) {
    return i1.hh1 == i2.hh1 ? (i1.mm1 == i2.mm1 ? i1.ss1 < i2.ss1 : i1.mm1 < i2.mm1) : i1.hh1 < i2.hh1;
}

bool has_gap(Time i1, Time i2) {
    if (i1.hh2 != i2.hh1 || i1.mm2 != i2.mm1 || i1.ss2 != i2.ss1)
        return true;
    else
        return false;
}

int main() {
    int n; scanf("%d", &n);
    while (n -- ) {
        int hh1, mm1, ss1;
        int hh2, mm2, ss2;
        scanf("%d:%d:%d - %d:%d:%d", &hh1, &mm1, &ss1, &hh2, &mm2, &ss2);
        time[idx ++ ] = {hh1, mm1, ss1, hh2, mm2, ss2};
    }
    sort(time, time + idx, cmp);
    Time start = {-1, -1, -1, 0, 0, 0};
    Time end   = {23, 59, 59, -1, -1, -1};
    if (has_gap(start, time[0])) {
        Time i1 = start;
        Time i2 = time[0];
        printf("%02d:%02d:%02d - %02d:%02d:%02d\n", i1.hh2, i1.mm2, i1.ss2, i2.hh1, i2.mm1, i2.ss1);
    }
    for (int i = 1; i < idx; i ++ ) {
        Time i1 = time[i - 1];
        Time i2 = time[i];
        if (has_gap(i1, i2))
            printf("%02d:%02d:%02d - %02d:%02d:%02d\n", i1.hh2, i1.mm2, i1.ss2, i2.hh1, i2.mm1, i2.ss1);
    }
    if (has_gap(time[idx - 1], end)) {
        Time i1 = time[idx - 1];
        Time i2 = end;
        printf("%02d:%02d:%02d - %02d:%02d:%02d\n", i1.hh2, i1.mm2, i1.ss2, i2.hh1, i2.mm1, i2.ss1);
    }
    return 0;
}