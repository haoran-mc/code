/*----------------------------------------------------------------
 *
 *   文件名称：1010.cpp
 *   创建日期：2020年10月19日 ---- 23时27分
 *   结束日期：2020年10月19日 ---- 23时44分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;
struct Sequence {
    int coef;
    int expo;
}sequence;
vector<Sequence> vec;

int main() {
    while (scanf("%d %d", &sequence.coef, &sequence.expo) != EOF)
        vec.push_back(sequence);

    fo (auto it = vec.begin(); it != vec.end(); it++) {
        if (it -> coef == 0 || it -> expo == 0) {
            vec.erase(it);
            it--;
        }
        else {
            it -> coef *= it -> expo;
            it -> expo--;
        }
    }

    bool flag = false;
    for (auto it = vec.begin(); it != vec.end(); it++) {
        if (it == vec.end() - 1)
            printf("%d %d", it -> coef, it -> expo);
        else
            printf("%d %d ", it -> coef, it -> expo);
        flag = true;
    }
    if (flag == false)
        printf("0 0\n");
    return 0;
}
