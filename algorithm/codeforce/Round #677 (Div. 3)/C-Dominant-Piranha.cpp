/*----------------------------------------------------------------
 *
 *   文件名称：C-Dominant-Piranha.cpp
 *   创建日期：2020年10月21日 ---- 00时02分
 *   结束日期：2020年10月21日 ---- 00时29分
 *   题    目：codeforce
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 3e5;
int prianha[maxn];
vector<int> vec1;
vector<int> vec2;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int size;
            scanf("%d", &size);
            vec1.push_back(size);
        }
        vec2 = vec1;
        sort(vec2.begin(), vec2.end());
        auto it = vec2.end() - 1;
        int dominant = *it;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (vec1[i] == dominant && ((i-1 >= 0 && vec1[i-1] != dominant) || (i+1 <n && vec1[i+1] != dominant))) {
                flag = true;
                printf("%d\n", i + 1);
                break;
            }
        }
        if (flag == false)
            printf("-1\n");

        vec1.clear();
        vec2.clear();
    }
    return 0;
}
