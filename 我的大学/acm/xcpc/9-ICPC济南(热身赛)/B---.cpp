#include <cstdio>
const int maxn=3e5+10;
int a[maxn];
int dp[maxn][4];

int main() {
	int n;
    scanf("%d",&n);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (dp[a[i]][3] == 1) {
			printf("Yes\n");
            return 0;
		}
		for (int j = 0; j <= 3e5; j++)
			for (int k = 2; k >= 0; k--) {
				if (dp[j][k] == 0)
                    continue;
				dp[j^a[i]][k+1] = 1;
			}
	}
	printf("No\n");
    return 0;
}
