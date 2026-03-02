#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e5;
#define bug printf("<------>\n");
vector<int> fish(maxn, 0);
int res = 0;

int main() {
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
