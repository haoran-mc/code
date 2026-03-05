/*----------------------------------------------------------------
 *
 *   文件名称：01.cpp
 *   创建日期：2021年05月29日 星期六 13时17分01秒
 *   题    目：AcWing 113 特殊排列
 *   算    法：二分
 *   描    述：首先看一道LeetCode上的题目：LeetCode 0162 Find Peak Element
 *
 *          ^
 *         / \                   ^                 ^
 *        /   \   ^       ^     / \               / \
 *       /     \ / \     / \   /   \         ^   /   \
 *      /       V   \   /   \ /     \       / \ /     \
 *                   \ /     V       \     /   V       \
 *                    V               \   /
 *                                     \ /
 *                                      V
 *
 *
 *      这道题是将一些可以比较的数排列，由于题目不要求时间复杂度，
 *      只要求操作的次数，所以使用什么排序方法无所谓，这里使用插入排序
 *      假设现在已经放好了n个数，那么使用二分结合上面LeetCode的题目
 *
 *      首先自定义：如果已排好的数列中的数比要插入的值大，就是一个上升
 *      的线段，如果这个数比要插入的值小，就是一个下降的线段
 *
 *      所以我们需要找找极小值，这里极小值的意思是前面的一个数比正要插
 *      入的这个数小，后面的一个数比正要插入的这个数大，也就满足题目要
 *      求(前面的数比后面的数小)
 *
 ----------------------------------------------------------------*/

// Forward declaration of compare API
// bool compare(int a, int b);
// return bool means whether a is less than b.

#include <cstdio>
#include <vector>
using namespace std;

class solution {
    public:
        vector<int> specialSort(int N) {
            vector<int> vec;
            vec.push_back(1);
            for (int i = 2; i <= N; ++i) {
                int l = 0, r = vec.size() - 1;
                while (l < r) {
                    int mid = (l + r + 1) >> 1;
                    if (compare(vec[mid], i))
                        l = mid;
                    else
                        r = mid - 1;
                }
                vec.push_back(i);
                for (int j = vec.size() - 2; j > r; --j)
                    swap(vec[j], vec[j + 1]);
                if (compare(i, vec[r]))
                    swap(vec[r], vec[r+1]);
            }
            return vec;
        }
};

int main() {
    solution su;
    vector<int> vec = su.specialSort(10);
    for (auto it = vec.begin(); it != vec.end(); ++it)
        printf("%d ", *it);
    return 0;
}
