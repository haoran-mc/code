#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e7+5;
int arr[maxn];
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int k;
        scanf("%d", &n);
        scanf("%d", &k);
        for (int i = 1; i <= n*k; ++i)
            scanf("%d", &arr[i]);
        //reverse(arr+1, arr+n*k+1);
        /*
         *for (int i = 0; i < n*k; ++i)
         *    printf("%d ", arr[i]);
         */
        //int seek = n - n / 2;
        int seek = n / 2 + 1;
        long long sum = 0;
        int num = 0;
        //printf("seek = %d\n", seek);
        for (int i = n*k-seek+1; ; i -= seek) {
            sum += arr[i];
            ++num;
            if (num == k)
                break;
            //printf("num = %d\n", arr[i]);
        }
        //for (int i = 0; i <= k * seek; ++i)
            //if (i % seek == 0 && i != 0) {
                //sum += arr[i-1];
                //printf("num = %d\n", arr[i-1]);
            //}
        printf("%lld\n", sum);
    }
    return 0;
}
