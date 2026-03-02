#include <cstdio>
#include <queue>
using namespace std;
const int maxn = 20;
const int inf  = 0x3f3f3f3f;
#define bug printf("<------>\n");
char coord[maxn][maxn];
int step;
int dirx[4] = {-1, 1, 0, 0};
int diry[4] = {0, 0, -1, 1};
bool vis[maxn][maxn];
struct chess{
    int x;
    int y;
};
chess peo;
chess cnt;
queue<chess> quu;

void BFS(int x, int y) {

}

int main()
{
    int n;
    int m;
    scanf("%d", &n);
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%c", &coord[i][j]);
            if (coord[i][j] == 'X')
                peo.x = i,
                peo.y = j;
        }
        getchar();
    }
    quu.push(peo);
    cnt.x = inf;
    cnt.y = inf;
    quu.push(cnt);
    while (!quu.empty()) {
        if (quu.front().x == inf) {
            ++step;
            quu.pop();
            quu.push(cnt);
        }
        BFS(quu.front().x, quu.front().y);
    }
    return 0;
}
