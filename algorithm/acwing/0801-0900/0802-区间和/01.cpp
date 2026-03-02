/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年06月01日 星期二 08时44分20秒
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：离散化：将稀疏的大的"坐标"离散化为紧密的小的"坐标"
 *          C++中用vector离散化
 *          离散化之前的数组: arr[1] = 1, arr[3] = 40, arr[40] = 50
 *                  arr[65] = 79, arr[78] = 20, arr[92] = 54
 *          1            40        50            79
 *          ---------...--------...-----------...----------...----
 *          这样非常稀疏，时间复杂度很高
 *
 *          离散化之后: a[1] = 1, a[2] = 40, a[3] = 50, a[4] = 79
 *                  a[5] = 20, a[6] = 54(之所以从1开始，为了方便前缀和)
 *          *还不一定，询问的l, r也会被离散化，这里只是原数组坐标的离散化*
 *          比如如果查询[35, 70]之间的数的和，那我们还要将35, 70这两个坐标
 *          离散化
 *          也就是a[1] = 1, a[2] = 40, a[3] = _, a[4] = 50, a[4] = 79, 
 *          a[5] = _, a[6] = 20, a[7] = 54
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
const int maxn = 3e5 + 5;
int n, m;
int a[maxn], preS[maxn];
vector<int> alls; //存的需要离散化的值
vector<PII> add, query;

//第一个大于等于idx的位置
int find(int idx) { //求x离散化之后的结果
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (alls[mid] >= idx)
            r = mid;
        else
            l = mid + 1;
    }
    return r + 1;  //映射到从1开始，方便前缀和
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        int idx, c;
        scanf("%d %d", &idx, &c);
        // 为什么不在这里就直接让a[i] += c?
        // 是因为要把所有的都存好，这样才能离散化
        add.push_back({idx, c});  //这里的idx是很大的坐标
        alls.push_back(idx);
    }

    for (int i = 0; i < m; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);
        query.push_back({l, r});  //这里的l, r是很大的坐标
        alls.push_back(l);
        alls.push_back(r);
    }

    //去重，否则1, 3, 3, 5, 7, 9, 这些都是坐标
    //所以应该去重1, 3, 5, 7, 9
    //映射为1, 2, 3, 4, 5
    //而不是1, 2, 3, 4, 5, 6
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());

    for (auto item : add) {  //很大的坐标映射到小坐标
        int idx = find(item.first);
        a[idx] += item.second;
    }

    //预处理前缀和
    for (int i = 1; i <= alls.size(); ++i)
        preS[i] = preS[i-1] + a[i];

    // 处理询问
    for (auto item : query)  {
        int l = find(item.first);
        int r = find(item.second);
        printf("%d\n", preS[r] - preS[l - 1]);
    }
    return 0;
}
