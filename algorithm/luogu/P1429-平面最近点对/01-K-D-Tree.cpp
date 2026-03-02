/*----------------------------------------------------------------
 *
 *   文件名称：01-K-D-Tree.cpp
 *   创建日期：2021年04月23日 ---- 23时03分
 *   题    目：luogu p1429 平面最近点对(加强版)
 *   算    法：K-D Tree
 *   描    述：最近邻问题
 *      给定平面上n个点，找出其中的一对点的距离，使得在这n个点的所
 *      有点对中，该距离为所有点对中最小的
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 200010;
#define bug printf("<-->\n");
/*
 * n个点；d数组表示将当前超长方体按什么维度分割的
 * lc[i]表示这一小段以i为中位数分隔之后左侧的中位数(是坐标的中位数)
 * rc[i]表示这一小段以i为中位数分隔之后右侧的中位数(是坐标的中位数)
 * lc[i]表示结点i的左孩子
 * rc[i]表示结点i的右孩子
 */
int n, d[maxn], lc[maxn], rc[maxn];
double res = 2e18;
struct Point {double x, y;} p[maxn];
double L[maxn], R[maxn], D[maxn], U[maxn];

// double dist(int a, int b) {return hypot((p[a].x - p[b].x), (p[a].y - p[b].y));} //wrong
double dist(int a, int b) {return (p[a].x - p[b].x)*(p[a].x - p[b].x) + (p[a].y - p[b].y)*(p[a].y - p[b].y);}
bool cmp1(Point a, Point b) {return a.x < b.x;}
bool cmp2(Point a, Point b) {return a.y < b.y;}

void maintain(int idx) { //维持，重构
    L[idx] = R[idx] = p[idx].x;
    D[idx] = U[idx] = p[idx].y;
    if (lc[idx])
        //L[idx]：当前结点与左孩子较小的横坐标，R[idx]：当前结点与左孩子较大的横坐标
        L[idx] = min(L[idx], L[lc[idx]]), R[idx] = max(R[idx], R[lc[idx]]),
            //D[idx]：当前结点与左孩子较小的纵坐标，U[idx]：当前结点与左孩子较大的纵坐标
            D[idx] = min(D[idx], D[lc[idx]]), U[idx] = max(U[idx], U[lc[idx]]);
    if (rc[idx])
        //L[idx]：当前结点与右孩子较小的横坐标，R[idx]：当前结点与右孩子较大的横坐标
        L[idx] = min(L[idx], L[rc[idx]]), R[idx] = max(R[idx], R[rc[idx]]),
            //D[idx]：当前结点与右孩子较小的纵坐标，U[idx]：当前结点与右孩子较大的纵坐标
            D[idx] = min(D[idx], D[rc[idx]]), U[idx] = max(U[idx], U[rc[idx]]);
}


void note() {
    /*
     *          ^
     *       10 |             |
     *        9 |             |
     *        8 |       B     |
     *        7 |       *     |   E
     *        6 |             |---*-----
     *        5 |         C   |
     *        4 |---------*---|
     *        3 |   *         |
     *        2 |   A       D *
     *        1 |             | * F
     *          |------------------------>
     *        0   1 2 3 4 5 6 7 8 9 10
     *
     *
     *                     (7, 2) x
     *                     /    \
     *                    /      \
     *             y (5, 4)      (9, 6) y
     *               /    \      /
     *              /      \    /
     *         (2, 3)  (4, 7)  (8, 1)
     */
}

/*如果在l到r这个区间里x维度的方差大，就返回true*/
bool va(int l, int r) {
    double avx = 0, avy = 0, vax = 0, vay = 0;  // average variance
    for (int i = l; i < r; ++i)
        avx += p[i].x, avy += p[i].y;
    avx /= (double)(r - l);  //横坐标平均值
    avy /= (double)(r - l);  //纵坐标平均值
    for (int i = l; i < r; ++i)
        vax += (p[i].x - avx) * (p[i].x - avx),  // 方差(x) = vax / (r - l + 1);
            vay += (p[i].y - avy) * (p[i].y - avy);  // 方差(y) = vay / (r - l + 1);
    return vax >= vay;
}

/*选择p[l]到p[r]的点建树，左闭右开*/
int build(int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) >> 1;
    if (va(l, r))
        d[mid] = 1, nth_element(p+l, p+mid, p+r, cmp1); //d数组表示当前维度选择的分割的方向
    else
        d[mid] = 2, nth_element(p+l, p+mid, p+r, cmp2);
    //左孩子，右孩子
    lc[mid] = build(l, mid), rc[mid] = build(mid + 1, r);
    maintain(mid);
    return mid;
}

double f(int a, int b) {
    double ret = 0;
    //结点b与其左孩子中较小的横坐标大于结点a的横坐标，则加上横坐标二次方
    if (L[b] > p[a].x) ret += (L[b] - p[a].x) * (L[b] - p[a].x);
    //结点b与其左孩子中较大的横坐标小于结点a的横坐标，则加上横坐标二次方
    if (R[b] < p[a].x) ret += (p[a].x - R[b]) * (p[a].x - R[b]);
    //结点b与其右孩子中较小的纵坐标大于结点a的横坐标，则加上纵坐标二次方
    if (D[b] > p[a].y) ret += (D[b] - p[a].y) * (D[b] - p[a].y);
    //结点b与其右孩子中较大的纵坐标小于结点a的横坐标，则加上纵坐标二次方
    if (U[b] < p[a].y) ret += (p[a].y - U[b]) * (p[a].y - U[b]);
    return ret;
}

/*
 * 函数名是query但不是查询，没有return，左闭右开
 * 可以求离p[idx]最近的点离p[idx]的距离，是在函数中更新res的值
 */
void query(int l, int r, int idx) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    if (mid != idx)
        res = min(res, dist(idx, mid));
    if (l == r) return;
    //虽然函数f的理论依据不知，但猜测知是一种高维下的相对距离的表示方法
    double distl = f(idx, lc[mid]), distr = f(idx, rc[mid]);
    //当然是离点p[idx]越近的区域存在离点p[idx]最近的点的概率大
    if (distl < res && distr < res) {
        if (distl < distr) {
            query(l, mid, idx);
            if (distr < res) query(mid+1, r, idx);
        }
        else {
            query(mid + 1, r, idx);
            if (distl < res) query(l, mid, idx);
        }
    }
    else {
        if (distl < res) query(l, mid, idx);
        if (distr < res) query(mid+1, r, idx);
    }
}

void solve() {
    for (int i = 0; i < n; ++i) {
        printf("lc[%d] = %d  ", i, lc[i]);
        printf("rc[%d] = %d\n", i, rc[i]);
    }
    for (int i = 0; i < n; ++i) {
        printf("L[%d] = %f  ", i, L[i]);
        printf("R[%d] = %f\n", i, R[i]);
    }
    for (int i = 0; i < n; ++i) {
        printf("D[%d] = %f  ", i, D[i]);
        printf("U[%d] = %f\n", i, U[i]);
    }
    for (int i = 0; i < n; ++i)
        printf("d[%d] = %d\n", i, d[i]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lf %lf", &p[i].x, &p[i].y);
    build(0, n);
    for (int i = 0; i < n; ++i)
        query(0, n, i);
    printf("%.4lf\n", sqrt(res));

    // solve();
    return 0;
}
