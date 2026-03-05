/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年08月05日 星期四 22时04分04秒
 *   题    目：AcWing 0130 火车进栈问题
 *   算    法：卡特兰数
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;
#define NEXTLINE puts("");

void multi(vector<int> &vec, int b) {
    int t = 0;
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = vec[i] * b + t;
        t = vec[i] / 10;
        vec[i] %= 10;
    }
    while (t) {
        vec.push_back(t % 10);
        t /= 10;
    }
}

void div(vector<int> &vec, int b) {
    int t = 0;
    for (int i = vec.size() - 1; i >= 0; --i) {
        vec[i] += t * 10;
        t = vec[i] % b;
        vec[i] /= b;
    }
    while (vec.size() > 1 && vec.back() == 0)
        vec.pop_back();
}

int main() {
    int n; scanf("%d", &n);
    vector<int> res;
    res.push_back(1);
    for (int i = 2 * n, j = 1; j <= n; --i, ++j) {
        multi(res, i);
        div(res, j);
    }
    div(res, n + 1);

    for (int i = res.size() - 1; i >= 0; --i)
        printf("%d", res[i]);
    NEXTLINE
    return 0;
}
