#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int sizeCake1[51];
int sizeMouth[1100];
int n;
int m;
int sizeCake2[51];
priority_queue<int> tmp;

bool cmp(int x, int y){
    return x > y;
}

bool check(int N) {
    int time = 1000;
    while (time--) {                        //既然拼RP，当然要多rand几遍
        for (int i = 1; i <= n; i++)
            sizeCake2[i] = sizeCake1[i];                   //复制一份蛋糕副本

        random_shuffle(sizeCake2+1, sizeCake2+n+1);        //该函数的功能是把一段区间随机打乱

        bool flag;
        for (int i = N; i >= 1; i--) {          //这里对要满足的人从大到小枚举
            flag = false;
            for (int j = 1; j <= n; j++) {      //n比较小，暴力枚举蛋糕
                if (sizeCake2[j] >= sizeMouth[i]) {
                    flag = 1;
                    sizeCake2[j] -= sizeMouth[i];
                    break;
                }
            }
            if (flag == false)
                break;              //如果找不到可以满足这个口的蛋糕，说明不行
        }
        if (flag == true)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &sizeCake1[i]);

    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &sizeMouth[i]);

    sort(sizeMouth+1, sizeMouth+m+1);

    int left  = 0;
    int right = m;
    int ans   = 0;

    while (left <= right) {
        int mid  = (left + right) >> 1;
        if (mid >= 0 && check(mid)) {
            ans  = mid;
            left = mid+1;
        }
        else
            right = mid-1;
    }
    printf("%d", ans);
    return 0;
}
