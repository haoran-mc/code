/*----------------------------------------------------------------
 *
 *   文件名称：1085 Perfect Sequence.cpp
 *   创建日期：2020年09月03日 ---- 13时21分
 *   结束日期：2020年09月04日 ---- 22时09分
 *   题    目：PAT
 *   算    法：二分
 *   描    述：找出最后一个比q*min小的数
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int q;
    scanf("%d", &n);
    scanf("%d", &q);
    vector<int> sequence;
    while (n--) {
        int num;
        scanf("%d", &num);
        sequence.push_back(num);
    }
    sort(sequence.begin(), sequence.end());
    int ans = 1;
    for (int i = 0; i < (int)sequence.size(); i++) {
        /*auto it = upper_bound(sequence.begin() + i, sequence.end(), (long long)(q * sequence[i]));*/
        auto it = upper_bound(sequence.begin() + i, sequence.end(), (long long)q * sequence[i]);
        ans = max(ans, (int)(it - sequence.begin() - i));
    }
    printf("%d\n", ans);
    return 0;
}
