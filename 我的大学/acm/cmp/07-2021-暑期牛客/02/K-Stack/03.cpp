/*----------------------------------------------------------------
 *
 *   文件名称：03.cpp
 *   创建日期：2021年07月29日 星期四 22时59分37秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <utility>
using namespace std;
#define NEXTLINE puts("");
const int maxn = 1e6+10;
pair<int, int> p[maxn];
int a[maxn], b[maxn];
int to[maxn];           // to[i]：i指向to[i]，拓扑关系
int degree[maxn];       // 入度
int stk[maxn], quu[maxn]; // 模拟栈、队列
int n, k;

bool judge() {
    for (int i = 0; i < k; i++) {
        int pos = p[i].first;
        int val = p[i].second;
        if (pos < val)  // 如果当前位置前有比当前位置还多的元素，显然不满足
            return true;
    }
    return false;
}

void topsort() {
    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++)
        if (!degree[i]) 
            quu[tt++] = i;

    while (hh < tt) {  // 用数组模拟队列
        int x = quu[hh++];
        degree[to[x]]--;
        if (degree[to[x]] == 0)
            quu[tt++] = to[x];
    }

    // 拓扑序排好之后，得到的是位置的拓扑序，拓扑序越大，这个位置的数越大
    int t = n;
    for (int i = 0; i < tt; i++) {
        int pos = quu[i];
        a[pos] = t--;
    }

    // 输出结果序列 a
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    puts("");
}

void solve() {
    int tt = 0;
    for (int i = 1; i <= n; i++) {
        // b[i]确定，需满足b[i]，也就是第i个位置前面有b[i]-1个比第i个位置的数小的数
        if (b[i]) { 
            bool flag = false;
            while (tt >= b[i]) {   // 所以只能留下b[i]-1个数
                tt--;
                flag = true;       // 为了保证入栈后，栈中有b[i]个元素
            }
            // 拓扑关系：a[stk[h+1]] > a[i]
            // 所有弹出的位置，这些位置上的数一定是比刚刚插入的那个位置上的数大
            // 由于弹出的所有的位置的拓扑序是排好的，他们里面拓扑序最小的是最后一个被弹出的
            // 那么只需要让最后一个弹出的位置指向刚刚插入的位置，就满足了所有弹出的位置拓扑序大于刚刚插入的位置
            if (flag) 
                to[stk[tt+1]] = i; 
        }
        // b[i]不确定，尽情入栈。不会与b[i]产生冲突
        stk[++tt] = i;
        // 拓扑关系：a[i] > a[stk[h-1]]，反正栈中后面的位置就要比前面的位置拓扑序大
        // 由于前面的拓扑序都排好了，所以只需要排好刚刚入栈的位置与它前面一个的位置的拓扑序
        // 就能满足栈中前面的位置拓扑序小于栈中后面的位置的拓扑序
        to[i] = stk[tt-1];  
        // 这时候我们发现，只要位置i被for语句遍历到了，那么它的拓扑序也就排好了
    }
    // 由于需要进行拓扑排序，我们需要初始化一下所有位置的入度
    for (int i = 1; i <= n; i++)
        degree[to[i]]++;
    // 进行拓扑排序
    topsort();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        int pos, val;
        scanf("%d %d", &pos, &val);
        p[i] = {pos, val};
        b[pos] = val;
    }
    if (judge()) puts("-1");
    else solve();

    return 0;
}
