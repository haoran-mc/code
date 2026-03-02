/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：1005.cpp
 *   创建日期：2020年10月15日 ---- 22时56分
 *   结束日期：2020年10月16日 ---- 14时34分
 *   题    目：PAT
 *   算    法：散列
 *   描    述：<++>
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 101;
bool Hash[maxn];
int num[maxn];

bool cmp(int A, int B) {
    return A > B;
}

int main()
{
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &num[i]);
        Hash[num[i]] = true;
    }

    int temp;
    for (int i = 0; i < K; i++) {
        temp = num[i];
        while (temp != 1) {
            if (temp & 1)
                temp = (3 * temp + 1) / 2;
            else
                temp /= 2;

            if (temp < 100 && Hash[temp] == true)
                Hash[temp] = false;
        }
    }

    vector<int> ans;
    for (int i = 0; i < K; i++)
        if (Hash[num[i]] == true)
            ans.push_back(num[i]);

    sort(ans.begin(), ans.end(), cmp);

    for (auto it = ans.begin(); it != ans.end() - 1; it++)
        printf("%d ", *it);

    auto it = ans.end() - 1;
    printf("%d", *it);

    return 0;
}
