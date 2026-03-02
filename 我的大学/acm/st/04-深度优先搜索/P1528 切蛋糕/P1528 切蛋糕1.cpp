/*----------------------------------------------------------------
 *
 *   文件名称：P1528 切蛋糕1.cpp
 *   创建日期：2020年09月17日 ---- 16时33分
 *   题    目：luogu
 *   算    法：贪心，二分，深度优先搜索
 *   描    述：看题解1，自己写
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int m;
int totalCake;
int needCake;
int sizeCake[50];
int sizeMouth[1024];
int prefixAnd[1024];
bool flag = false;

void DFS(int mouthIndex, int cakeIndex) {
    if (flag == true)
        return ;

    if (mouthIndex < 0) {
        flag = true;
        return ;
    }

    if (totalCake < needCake)
        return ;

    if (totalCake < sizeMouth[0])
        return ;

    for (int i = cakeIndex; i < n; i++) {
        if (sizeCake[i] >= sizeMouth[mouthIndex]) {
            sizeCake[i] -= sizeMouth[mouthIndex];
            totalCake   -= sizeMouth[mouthIndex];
            needCake    -= sizeMouth[mouthIndex];

            if (sizeCake[i] < sizeMouth[0])
                totalCake -= sizeCake[i];

            if (sizeMouth[mouthIndex] == sizeMouth[mouthIndex - 1])
                DFS(mouthIndex - 1, i);
            else
                DFS(mouthIndex - 1, 0);

            if (sizeCake[i] < sizeMouth[0])
                totalCake += sizeCake[i];

            sizeCake[i] += sizeMouth[mouthIndex];
            totalCake   += sizeMouth[mouthIndex];
            needCake    += sizeMouth[mouthIndex];
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &sizeCake[i]);
        totalCake += sizeCake[i];
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &sizeMouth[i]);

    sort(sizeMouth, sizeMouth + m);
    prefixAnd[0] = sizeMouth[0];
    for (int i = 1; i < m; i++)
        prefixAnd[i] = prefixAnd[i-1] + sizeMouth[i];

    int left  = 0;
    int right = m - 1;
    while (totalCake < prefixAnd[right])
        right--;
    while (left <= right) {
        flag = false;
        int mid = (left + right) / 2;
        needCake = prefixAnd[mid];
        DFS(mid, 0);

        if (flag == true)
            left  = mid + 1;
        else
            right = mid - 1;
    }
    printf("%d\n", left);
    return 0;
}
