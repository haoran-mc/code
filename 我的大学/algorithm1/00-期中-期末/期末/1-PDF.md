深度优先搜索是一种枚举所有完整路径以遍历所有情况的搜索方法。对于当前状态来说，只选择所有可以到达的状态中的其中一种状态。每次搜索皆是如此，一直走到尽头。如果当前状态不满足目标，后退到上次搜索，选择上次搜索中没有选择的状态，如果所有状态都被选完，再次后退，直到搜索到目标
广度优先搜索是一种枚举所有路径的下一次状态的搜索方法，对于当前状态来说，一次性选择能到达的所有状态，依次判断各个状态是否满足条件

两种搜索方法都是图形搜索算法，不同点是深度优先搜索底层是通过栈来实现；广度优先搜索底层是通过队列来实现
深度优先搜索可以用于需要遍历图的情况，结合记忆化搜索和剪枝使深度优先搜索更高效
深度优先搜索能做到的事广度优先搜索都能够做到，而广度优先搜索能做到的事深度优先搜索不一定能做到，比如搜索的深度足够大导致使用深度优先搜索可能会爆栈。广度优先搜索更适合那些寻找单一最短路径的问题，或者是路线可能很深，使用深度优先搜索可能会爆栈的情况

```cpp
// Lake Counting BFS
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 101;
int n;
int m;
char water[maxn][maxn];
int puddle;
struct coord {
    int x;
    int y;
}chess;
queue<coord> quu;
vector<int> vec;
int dirx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int diry[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
bool vis[maxn][maxn];

void BFS(int x, int y){
    vis[x][y] = true;
    for (int i = 0; i < 8; ++i)
        if (x+dirx[i] > 0 && x+dirx[i] <= n && y+diry[i] > 0 && y+diry[i] <= m && water[x+dirx[i]][y+diry[i]] == 'W' && !vis[x+dirx[i]][y+diry[i]]) {
            vis[x+dirx[i]][y+diry[i]] = true;
            chess.x = x + dirx[i];
            chess.y = y + diry[i];
            quu.push(chess);
        }
}

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    getchar();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%c", &water[i][j]);
        }
        getchar();
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (water[i][j] == 'W' && !vis[i][j]) {
                int size = 0;
                chess.x = i;
                chess.y = j;
                quu.push(chess);
                while (!quu.empty()) {
                    BFS(quu.front().x, quu.front().y);
                    quu.pop();
                    ++size;
                }
                ++puddle;
                vec.push_back(size);
            }
    printf("%d ", puddle);
    sort(vec.begin(), vec.end());
    for (auto it = vec.begin(); it != vec.end(); ++it)
        it == vec.end() - 1 ? printf("%d", *it) : printf("%d ", *it);
    return 0;
}
```

![Lake-Counting-BFS](/home/haoran/图片/typora-photo/Lake-Counting-BFS.png)


