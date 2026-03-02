#include <cstdio>
#include <unordered_map>
#include <map>
using namespace std;
unordered_map<int, int> mp;
struct Line {
    int index1;
    int index2;
};
map<int, Line> mp1;
int main()
{
     int t;
     scanf("%d", &t);
     while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            mp[num] = 0;
        }

        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            mp[num] = i + 1;
        }
        auto it = mp.begin();
        int sum = 0;
        for (int i = 0; it != mp.end(); it++, i++) {
            int d = i + 1 - it -> second;
            if (d < 0)
                d = -d;
            sum += d;
        }
        printf("%d\n", sum / 2);
        mp.clear();
     }
     return 0;
}
