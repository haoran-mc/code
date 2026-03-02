#include <cstdio>
const int maxn = 1e5 + 5;
int sequ[maxn];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &sequ[i]);
	if (n >= 100) {
		printf("Yes\n");
		return 0;
	}
	bool flag = false;
	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			for (int k = j+1; k < n; ++k)
				for (int l = k+1; l < n; ++l)
					if ((sequ[i] ^ sequ[j] ^ sequ[k] ^ sequ[l]) == 0)
						flag = true;
	flag ? printf("Yes\n") : printf("No\n");
	return 0;
}
