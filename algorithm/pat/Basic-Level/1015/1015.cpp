/*----------------------------------------------------------------
 *
 *   文件名称：1015.cpp
 *   创建日期：2020年10月31日 ---- 17时33分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：sort中的cmp函数
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1e5;
struct Rank {
    int ID;
    int virtue;
    int talent;
    int sum;
    int quality;
}info[maxn];

bool cmp(Rank info1, Rank info2) {
    if (info1.quality != info2.quality)
        return info1.quality > info2.quality;
    else if (info1.sum != info2.sum)
        return info1.sum > info2.sum;
    else if (info1.virtue != info2.virtue)
        return info1.virtue > info2.virtue;
    else
        return info1.ID < info2.ID;
}

int main()
{
    int N;
    scanf("%d", &N);
    int minScore;
    int maxScore;
    scanf("%d", &minScore);
    scanf("%d", &maxScore);
    int fail = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &info[i].ID);
        scanf("%d", &info[i].virtue);
        scanf("%d", &info[i].talent);
        info[i].sum = info[i].virtue + info[i].talent;
        if (info[i].virtue >= maxScore && info[i].talent >= maxScore)
            info[i].quality = 4;
        else if (info[i].virtue >= maxScore && (info[i].talent >= minScore && info[i].talent < maxScore))
            info[i].quality = 3;
        else if ((info[i].virtue >= minScore && info[i].talent <maxScore) && (info[i].talent >= minScore && info[i].talent < maxScore) && (info[i].virtue >= info[i].talent))
            info[i].quality = 2;
        else if (info[i].virtue < minScore || info[i].talent < minScore) {
            info[i].quality = 0;
            fail++;
        }
        else
            info[i].quality = 1;
    }
    sort(info, info+N, cmp);
    int succeed = N-fail;
    printf("%d\n", succeed);
    for (int i = 0; i < succeed; ++i) {
        printf("%d ", info[i].ID);
        printf("%d ", info[i].virtue);
        printf("%d\n", info[i].talent);
    }
    return 0;
}
