#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 500 * 500 + 5;
// int num[maxn], tmp[maxn];
vector<int> num, tmp(maxn);
ll inverse;

void mergeSort(int l, int r) {
    if (l >= r) return;

    int mid = (l + r) >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);

    // v         v
    // -------------------
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (num[i] <= num[j])
            tmp[k++] = num[i++];
        else {
            tmp[k++] = num[j++];
            /*
             * --------i---------------------
             * ---------------------j--------
             *  num[i] > num[j]
             *  必有num[i+1], num[i+2], ... num[mid] > num[j]
             *  这些对都是逆序对
             */
            inverse += (long long)(mid - i + 1);  //只是在归并排序上添加这句
        }

    while (i <= mid)
        tmp[k++] = num[i++];
    while (j <= r)
        tmp[k++] = num[j++];

    for (i = l, j = 0; i <= r; i++, j++)
        num[i] = tmp[j];
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int _;
                scanf("%d", &_);
                if (_)
                    num.push_back(_);
            }
        inverse = 0;
        mergeSort(0, n * n - 2);
        ll res1 = inverse % 2;
        num.clear();

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int _;
                scanf("%d", &_);
                if (_)
                    num.push_back(_);
            }
        inverse = 0;
        mergeSort(0, n * n - 2);
        ll res2 = inverse % 2;
        num.clear();
        if (res1 == res2)
            printf("TAK\n");
        else
            printf("NIE\n");
    }
    return 0;
}
