#include<bitsdc++.h>
using namespace std;
#define MAXN 1000
int val[MAXN];
double freq[MAXN];

// 快排的partition函数，以最左边为pivot,排序后
// x1.....xp-1 < pivot < xp+1 .. xn 
int partition(int l, int r){
    int pivot = val[l];
    double pfrq = freq[l];
    while (l < r) {
        while (l < r && val[r] >= pivot) 
            -- r;
        val[l]  = val[r];
        freq[l] = freq[r];

        while (l < r && val[l] <= pivot) 
            ++ l;
        val[r]  = val[l];
        freq[r] = freq[l];
    }
    val[l]  = pivot;
    freq[l] = pfrq;
    return l;
}

// 假设第一个数xp是答案，并将小于他的数放在左边，大于他的放在他右边（一次快排的Partition）
// x1..xp-1 < xp < xp+1..xn
// 计算比他小的数的出现几率 lf = sum{freq[1..p-1]}
// 计算比他大的数的出现几率 rf = sum{freq[p+1..n]}
// 如果 lf<1/2 且 rf 1/2 是答案，
// 如果 lf>1/2 则答案比xp小，在xp的左边重新猜一个数
// 如果 rf>1/2 则答案比xp大，在xp的右边重新猜一个数

// 算法复杂度：
//  类似快排计算，最好情况下，每次排除一半 O(nlogn)
//  最坏情况下，每次选的都是区间内的最大值，O(n^2)
int quick(int l, int r, int n) {
    if (l < r) {
        int p = partition(l, r);   // p 左边是比 val[p] 小的数；p 右边是比 val[p] 大的数
        double lf = 0;             // 左边数权重的和
        double rf = 0;             // 右边数权重的和
        for (int i=0; i<p-1; i++)
            lf += freq[i];
        for (int i=p+1; i<n; i++)
            rf += freq[i];
        if (lf < 0.5f && rf < 0.5f)    // 如果 p 恰好是结果
            return val[p];

        if (lf > 0.5f)   // 如果左边的权重和大于 0.5 说明在左区间
            return quick(l,p-1,n);
        else   // 否则在右区间
            return quick(p+1,r,n);
    }
    else
        return val[l];
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) 
        scanf("%d", &val[i]);
    for (int i = 0; i < n; i ++ ) 
        scanf("%lf", &freq[i]);
    
    int mid = quick(0, n-1, n);
    printf("%d\n",mid);
    return 0;
}
