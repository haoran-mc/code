#include <cstdio>
const int maxn = 1e5+5;
int suger[maxn];
int mAx[maxn];
int mIn[maxn];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int mIn    = 100000;
        int mAx    = 0;
        int maxidx = 0;
        int minidx = 100000;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &suger[i]);
            if (suger[i] <= mIn) {
                mIn = suger[i];
                minidx = i;
            }
            else if (suger[i] >= mAx) {
                mAx = suger[i];
                maxidx = i;
            }
        }
        int numB = 0;
        int numJ = 0;
    }
    return 0;
}
