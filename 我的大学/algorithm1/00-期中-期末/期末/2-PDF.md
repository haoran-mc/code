一开始想到把所有区间都找到，然后用区间里可以放入的鱼的数量减去以有的鱼的数量就是可以放入的鱼的数量
但是实现起来比较麻烦，各个区间的边界经常搞混，所以我就想是不是我想麻烦了
于是我就看题目中提示的(暴力法)，所以我就打算尝试遍历每个尺寸的鱼是否可以放入鱼缸中，果然成功了

```cpp
// 没成功的通过区间寻找鱼的数量的方法
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5;
#define bug printf("<------>\n");
vector<int> fish(maxn, 0);
int res = 0;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int left;
    int right;
    int n;
    scanf("%d", &left);
    scanf("%d", &right);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &fish[i]);
    sort(fish.begin(), fish.begin()+n);
    auto it = fish.begin();
    res += (*it % 10 ? *it / 10 - 1 : *it / 10 - left);
    if (res < 0) res = 0;
    while (it < fish.begin() + n) {
        int sequR = 2 * *it - 1;
        //printf("sequR = %d\n", sequR);
        auto itR = lower_bound(fish.begin(), fish.begin()+n, sequR);
        //printf("itR   = %d\n", (int)(itR - fish.begin()));
        res += (*itR - *it + 1 - (itR - it + 1));
        int sequL = 10 * *itR;
        auto itL = upper_bound(fish.begin(), fish.begin()+n, sequL);
        //printf("sequL = %d\n", sequL);
        //for (auto ii = fish.begin(); ii != fish.begin()+n; ++ii)
            //printf("%d\n", *ii);
        //printf("%d\n", (int)(itL - fish.begin()));
        if (itL != fish.begin()+n) {
            res += (*itL % 10 ? *itL / 10 - 1 : *itL / 10 - *itR + 1);
            it = itL;
        }
        else if (sequL >= right)
            break;
        else {
            res += (right - 10 * *itR);
            break;
        }
        /*
         *    printf("sequL = %d\n", sequL);
         *    printf("itL   = %d\n", (int)(itL - fish.begin()));
         *res += ((sequR - sequL + 1) - (itR - itL + 1));
         *if (itR == fish.end())
         *    res += (right - sequRR + 1);
         *else
         *    res += (*itR%10==0 ? *itR/10 : *itR/10-1 - sequRR + 1);
         *sequRR = 10 * *itL <= right ? 10 * *itL : right;
         *printf("sequRR = %d\n", sequRR);
         *it = itR + 1;
         */
    }
    res += n;
    printf("%d", res);
    return 0;
}
```

```cpp
// 暴力比较每个尺寸鱼能否放入鱼缸
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e5;
vector<int> fish(maxn, 0);
int main()
{
    int left;
    int right;
    int n;
    scanf("%d", &left);
    scanf("%d", &right);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &fish[i]);
    int res = 0;
    for (int i = left; i <= right; ++i) {
        bool flag = true;
        for (auto it = fish.begin(); it != fish.begin()+n; ++it) {
            if (i <= *it * 10 && i >= *it * 2)
                flag = false;
            else if (!(*it % 10) && i >= *it/10 && i <= *it/2)
                flag = false;
            else if ((*it % 10) && !(*it % 2) && i > *it/10 && i <= *it/2)
                flag = false;
            else if ((*it % 10) && (*it % 2) && i > *it/10 && i < *it/2)
                flag = false;
        }
        if (flag) ++res;
    }
    printf("%d", res);
    return 0;
}
```

![好多鱼](/home/haoran/图片/typora-photo/好多鱼.png)
