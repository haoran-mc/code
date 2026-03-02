#include <cstdio>
#include <cmath>
#include <unordered_map>
using namespace std;
const int maxn = 1e5 + 1;
struct Line {
    int value;
    int index;
}line[maxn];
int main()
{
     int t;
     scanf("%d", &t);
     while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &line[i].value);

        for (int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            for (int j = 0; j < n; j++)
                if (line[j].value == num)
                    line[j].index = j;

        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += abs(line[i].index - i);

        printf("%d\n", sum / 2);
     }
     return 0;
}
