//01背包--恰好装满
#include <iostream>
#include <algorithm>
using namespace std;
//#define max(N1,N2) N1>N2?N1:N2
#define INF 0x80000000
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	int V, N;
    scanf("%d", &N);
    scanf("%d", &V);
    int v[1000], w[1000];
    int f[10000] ;
    //下面是初始化所有的无效状态
    for (int i = 0; i < 10000; i++)
    {
        f[i] = INF;
    }
    //f[0]是有效状态
    f[0] = 0;
    //输入每个物体的体积和价值
    for (int i = 1; i <= N; i++)
    {
        cin >> v[i] >> w[i];
    }
    //动态规划过程
    for (int i = 1; i <= N; i++)
    {
        for (int j = V; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
            if (f[j] < 0)
                f[j] = INF;
        }
    }
    cout << f[V];//背包恰好装满了，输出结果
	return 0;
}

