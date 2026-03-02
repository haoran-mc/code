#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef unsigned long long LL;
#define bug printf("<------>\n");

vector<LL> numtox;
void Dtoanyx(LL num_D, int base_C = 2) {
    do {
        numtox.push_back(num_D % base_C);
        num_D /= base_C;
    }while (num_D != 0);
}

vector<LL> numtoy;
void Dtoanyy(LL num_D, int base_C = 2) {
    do {
        numtoy.push_back(num_D % base_C);
        num_D /= base_C;
    }while (num_D != 0);
}

int main() {
     //printf("%lld\n", (LL)pow(2, 56));
    // 72057594037927936
    LL x, y;
    scanf("%lld %lld", &x, &y);
    Dtoanyx(x);
    Dtoanyy(y);
    LL res1, res2, res3;
    res1 = (LL)pow(2, numtox.size() - 1);
    res1 = x - res1;
    //x -= res1;
    if (numtoy.size() == numtox.size())
        res2 = y - (LL)pow(2, numtoy.size() - 1);
    else
        res2 = y;
    if (numtoy.size() != numtox.size())
        res3 = (LL)pow(2, numtox.size() - 1);
    else {
        printf("2\n%lld %lld\n", res1, res2);
        return 0;
    }
    /*
     *vector<LL> res;
     *for (int i = 0; i < (int)numtox.size() - 1; ++i) {
     *    if (numtox[i] == numtoy[i])
     *        res.push_back(0);
     *    else
     *        res.push_back(1);
     *}
     *for (int i = (int)numtoy.size(); i < (int)numtox.size(); ++i)
     *    res.push_back(numtox[i]);
     */

    /*
     *printf("---> ");
     *for (auto it = numtox.begin(); it != numtox.end(); ++it)
     *    printf("%lld ", *it);
     *printf("\n");
     *printf("---> ");
     *for (auto it = numtoy.begin(); it != numtoy.end(); ++it)
     *    printf("%lld ", *it);
     *printf("\n");
     *printf("---> ");
     *for (auto it = res.begin(); it != res.end(); ++it)
     *    printf("%lld ", *it);
     */

    /*
     *LL out = 0;
     *for (auto it = res.end() - 1; it != res.begin() - 1; --it)
     *    if (*it == 1)
     *        out += pow(2, it - res.begin());
     */
    printf("3\n%lld %lld %lld\n", res1, res2, res3);
    return 0;
}
