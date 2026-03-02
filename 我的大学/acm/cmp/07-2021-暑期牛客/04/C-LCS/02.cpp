#include <cstdio>
const int maxn = 1e5 + 5;
const double eps = 1e-6;

inline int dcmp(double x, double y) { //比较两个浮点数：0 相等；-1 小于；1 大于
    if (fabs(x - y) < eps) return 0;
    else return x < y ? -1 : 1;
}

struct Info {
    double avg;
    int val;
    int sta, len, sum;
} a[maxn], b[maxn];

Info solve(Info I[], int len) {
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            I[i].avg = (double)I[i].val;
            I[i].sta = 0;
            I[i].len = 1;
            I[i].sum = I[i].val;
            continue;
        }

        if (dcmp((double)I[i].val, I[i-1].avg) > 0) {
            I[i].sum = I[i-1].sum + I[i].val;
            I[i].len = I[i-1].len + 1;
            I[i].sta = I[i-1].sta;
            I[i].avg = (double)I[i].sum / (double)I[i].len;
        } else {
            I[i].sum = I[i].val;
            I[i].len = 1;
            I[i].sta = i;
            I[i].avg = (double)I[i].sum / (double)I[i].len;
        }
    }
    Info ret;
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            ret.avg = I[i].avg;
            ret.sta = 0;
            ret.len = 1;
            continue;
        }
        if (dcmp(I[i].avg, ret.avg) > 0) {
            ret.avg = I[i].avg;
            ret.sta = I[i].sta;
            ret.len = I[i].len;
        }
    }
}

int main() {
    int n, m, x, y;
    scanf("%d %d %d %d", &n, &m, &x, &y);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i].val);
    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i].val);
    Info ret_a = solve(a, n);
    Info ret_b = solve(b, m);
    return 0;
}
