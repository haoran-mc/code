/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年04月09日 ---- 10时27分
 *   题    目：CH1202
 *   算    法：队列
 *   描    述：只有原先的队列是优先队列是因为要对原先的蚯蚓排序
 *      而另外两个队列不需要排序，每次生成的新的蚯蚓都是不断变短的
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, m, q, u, v, t, delta = 0;
priority_queue<ll> pqu; //原先的蚯蚓
//被按比例切两半的蚯蚓
//q1 = u/v * len; q2 = (1-u/v) * len;
queue<ll> q1, q2;

int main() {
    scanf("%d %d", &n, &m); //n只蚯蚓，m秒后援兵
    scanf("%d", &q); //每苗生长q
    scanf("%d %d", &u, &v); // u/v = p 截断比例
    scanf("%d", &t); //输出间隔
    //输入n个蚯蚓的长度
    for (int i = 1; i <= n; ++i) {
        ll a;
        scanf("%lld", &a);
        pqu.push(a);
    }
    //第t秒，2t秒，3t秒截断的蚯蚓长度
    for (int i = 1; i <= m; ++i) {
        ll maxi = -inf;
        int flag;
        //下面三个判断语句是找到三个队列中最大长的那只蚯蚓
        if (pqu.size() && maxi < pqu.top())
            maxi = pqu.top(), flag = 0;
        if (q1.size() && maxi < q1.front())
            maxi = q1.front(), flag = 1;
        if (q2.size() && maxi < q2.front())
            maxi = q2.front(), flag = 2;

        //找到最长的那只蚯蚓，切成两半
        if (flag == 1) q1.pop();
        else if (flag == 2) q2.pop();
        else pqu.pop();

        maxi += delta;
        q1.push(maxi * u / v - delta - q);
        q2.push(maxi - maxi * u / v - delta - q);
        delta += q;
        if (i % t == 0)
            printf("%lld ", maxi);
    }
    printf("\n");

    //m秒后蚯蚓的长度
    for (int i = 1; i <= n + m; ++i) {
        ll maxi = -inf;
        int flag;
        //同样找到最长的那只蚯蚓
        if (pqu.size() && maxi < pqu.top())
            maxi = pqu.top(), flag = 0;
        if (q1.size() && maxi < q1.front())
            maxi = q1.front(), flag = 1;
        if (q2.size() && maxi < q2.front())
            maxi = q2.front(), flag = 2;

        if (flag == 1) q1.pop();
        else if (flag == 2) q2.pop();
        else pqu.pop();

        if (i % t == 0)
            printf("%lld ", maxi + delta);
    }
    printf("\n");
    return 0;
}
