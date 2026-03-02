/*----------------------------------------------------------------
 *
 *   文件名称：1008.cpp
 *   创建日期：2020年10月19日 ---- 17时56分
 *   题    目：PAT
 *   算    法：reverse函数
 *   描    述：如果M > N，M %= N
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    int M;
    scanf("%d", &M);
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        vec.push_back(num);
    }
    if (M > N)
        M %= N;
    reverse(vec.begin(), vec.begin() + N - M);
    reverse(vec.begin() + N - M, vec.end());
    reverse(vec.begin(), vec.end());
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (it == vec.end() - 1)
            printf("%d", *it);
        else
            printf("%d ", *it);
    }
    return 0;
}
