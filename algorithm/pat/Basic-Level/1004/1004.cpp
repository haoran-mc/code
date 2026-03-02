/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：1004.cpp
 *   创建日期：2020年10月15日 ---- 17时12分
 *   结束日期：2020年10月15日 ---- 22时55分
 *   题    目：PAT
 *   算    法：cmp
 *   描    述：无
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

struct info {
    char name[10];
    char ID[10];
    int score;
}temp;
vector<info> stu;

bool cmp(info stu1, info stu2) {
    return stu1.score < stu2.score;
}

int main()
{
    int n;
    scanf("%d", &n);
    while (n--) {
        scanf("%s", temp.name);
        scanf("%s", temp.ID);
        scanf("%d", &temp.score);
        stu.push_back(temp);
    }
    sort(stu.begin(), stu.end(), cmp);
    auto it = stu.end() - 1;
    printf("%s %s\n", it -> name, it -> ID);
    it = stu.begin();
    printf("%s %s\n", it -> name, it -> ID);
    return 0;
}
