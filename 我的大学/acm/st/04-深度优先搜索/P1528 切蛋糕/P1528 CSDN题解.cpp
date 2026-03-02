#include <cstdio>
#include <algorithm>
using namespace std;
int n, m;                                      //蛋糕的数目, 人的数目
int totalCake;                                 //蛋糕的总数量
int needCake;                                  //这是需要的蛋糕总量
int sizeCake[60];                              //蛋糕的大小
int sizeMouth[1025];                           //嘴的大小
int prefixAnd[1025];                           //嘴巴的前缀和
bool flag = false;                             //标志蛋糕是否足够

void DFS(int mouthIndex, int cakeIndex) {      //mouthIndex是0~mouthIndex的嘴是否能够满足，cakeIndex是从第cakeIndex开始吃
    if (flag == true)                          //如果已经可以了，直接返回，剪枝
        return ;
    if (mouthIndex < 0) {                      //如果小于零的话，蛋糕必定吃完了，即标记返回
        flag = true;
        return ;
    }
    if (totalCake < needCake)                  //如果蛋糕总数小于所需蛋糕数，直接返回
        return ;
    if (totalCake < sizeMouth[0])              //发现蛋糕总量会小于人口最小的量并且此时mouthIndex不是<0，则此种情况不可能，返回
        return ;
    for (int i = cakeIndex; i < n; i++) {
        if (sizeCake[i] >= sizeMouth[mouthIndex]) {           //如果蛋糕的大小大于人口的大小，则开始切蛋糕
            sizeCake[i] -= sizeMouth[mouthIndex];
            totalCake   -= sizeMouth[mouthIndex];
            needCake    -= sizeMouth[mouthIndex];
            if (sizeCake[i] < sizeMouth[0])                   //如果蛋糕剩余的量小于最小人口的大小，则这部分的蛋糕为无用蛋糕，直接去除
                totalCake -= sizeCake[i];
            if (sizeMouth[mouthIndex] == sizeMouth[mouthIndex - 1]) //如果前一个人的嘴的大小和后一个人的大小一样大，可以延续上述蛋糕的变化，直接DFS(mouthIndex-1, i)，否则超时
                DFS(mouthIndex - 1, i);
            else
                DFS(mouthIndex - 1, 0);                       //否则，再从0搜索
            if (sizeCake[i] < sizeMouth[0])                   //回溯
                totalCake += sizeCake[i];
            sizeCake[i] += sizeMouth[mouthIndex];
            totalCake   += sizeMouth[mouthIndex];
            needCake    += sizeMouth[mouthIndex];
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &sizeCake[i]);
        totalCake += sizeCake[i];
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &sizeMouth[i]);

    sort(sizeMouth, sizeMouth + m);
    prefixAnd[0] = sizeMouth[0];                    //初始化前缀和
    for (int i = 1; i < m; i++)
        prefixAnd[i] = prefixAnd[i-1] + sizeMouth[i];

    int left = 0;
    int right = m - 1;
    while (totalCake < prefixAnd[right])            //优化剪枝，如果总的蛋糕量小于前缀和，则可以缩小右边界
        right--;
    while (left <= right) {                         //二分法
        flag = false;                               //首先初始化标志为false
        int mid = (left + right) >> 1;              //二分
        needCake = prefixAnd[mid];                  //需要的蛋糕总量是前缀和
        DFS(mid, 0);                                //搜索判断
        flag == true ? left = mid + 1 : right = mid - 1;//如果蛋糕足够的话，左边界右移；如果不够的话，右边界左移
    }
    printf("%d\n", left);                           //由于这里是从零开始，本来是l-1，这里变成l
    return 0;
}
