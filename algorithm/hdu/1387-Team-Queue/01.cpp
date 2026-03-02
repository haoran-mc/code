/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年04月08日 ---- 16时55分
 *   题    目：hdu1387 Team Queue
 *   算    法：<++>
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn = 1e6 + 5;
int team[maxn]; //散列存储成员所在的小组
char cmd[10];

int main() {
    /*
     * #ifndef ONLINE_JUDGE
     *     freopen("in.txt", "r", stdin);
     *     freopen("out.txt", "w", stdout);
     * #endif
     */
    int t, cnt = 0;
    while (scanf("%d", &t) && t) {   //t个小组
        memset(team, -1, sizeof(team));
        queue<int> quu[1005]; //最多1000个队伍，第1005个用来存放小组顺序
        for (int i = 0; i < t; ++i) {
            int sum; //每一组有多少人
            scanf("%d", &sum);
            for (int j = 0; j < sum; ++j) {
                int num;
                scanf("%d", &num);
                team[num] = i;
            }
        }
        printf("Scenario #%d\n", ++cnt);
        while (scanf("%s", cmd)) {
            if (!strcmp(cmd, "STOP"))
                break;
            else if (!strcmp(cmd, "ENQUEUE")) {
                int num;
                scanf("%d", &num);
                if (quu[team[num]].empty())
                    quu[1004].push(team[num]);
                quu[team[num]].push(num);
            }
            else if (!strcmp(cmd, "DEQUEUE")) {
                int tmp = quu[1004].front();
                if (quu[tmp].size() == 1)
                    quu[1004].pop();
                int num = quu[tmp].front();
                quu[tmp].pop();
                printf("%d\n", num);
            }
        }
        printf("\n");
    }
    return 0;
}

