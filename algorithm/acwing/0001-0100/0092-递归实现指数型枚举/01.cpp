/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月11日 ---- 16时17分
 *   题    目：<++>
 *   算    法：<++>
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
using namespace std;
#define NEXTLINE puts("");
vector<int> chosen;
int n;

void calc(int x) {
    if (x == n + 1) {
        for (int i = 0; i < chosen.size(); ++i)
            printf("%d ", chosen[i]); NEXTLINE;
        return ;
    }
    calc(x + 1);
    chosen.push_back(x);
    calc(x + 1);
    chosen.pop_back();
}

int main() {
    scanf("%d", &n);
    calc(1);
    return 0;
}
