/*----------------------------------------------------------------
 *
 *   文件名称：1025.cpp
 *   创建日期：2020年11月02日 ---- 20时53分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <cstdlib>
const int maxn = 1e6;
#define bug printf("******\n");
struct Link {
    int address;
    int data;
    int nxt;
    bool flagEnd;
}link[maxn];

void LinkInsert(int address, int data, int nxt) {
    link[address].address = address;
    link[address].data = data;
    link[address].nxt = nxt;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int Address;
    int N;
    int K;
    scanf("%d", &Address);
    scanf("%d", &N);
    scanf("%d", &K);

    for (int i = 0; i < N; ++i) {
        int address;
        int data;
        int nxt;
        scanf("%d", &address);
        scanf("%d", &data);
        scanf("%d", &nxt);
        if (i >= N-(N%K))
            link[address].flagEnd = true;
        LinkInsert(address, data, nxt);
    }
    int index = Address;
    int temp  = Address;
    for (int i = 0; i < K-1; ++i)
        index = link[index].nxt;
    Address = index;

    index = temp;
    int idx[maxn];
    //index是每K个的第一个
    while (link[index].flagEnd == false && index != -1) {
        for (int i = 0; i < K; ++i) {
            idx[i] = index;
            index = link[index].nxt;
            //printf("index = %d\n", index);
        }
        int seek = index;
        if (link[index].flagEnd == false) {
            for (int i = 0; i < K-1 && seek != -1; ++i)
                seek = link[seek].nxt;
            link[idx[0]].nxt = seek;
        }
        else
            link[idx[0]].nxt = link[idx[K-1]].nxt;
        //printf("link[%d].nxt = %d\n", idx[0],  link[idx[0]].nxt);
        for (int i = K-1; i > 0; --i)
            link[idx[i]].nxt = idx[i-1];
    }
    index = Address;
    while (index != -1) {
        if (link[index].nxt != -1)
            printf("%05d %d %05d\n", link[index].address, link[index].data, link[index].nxt);
        else
            printf("%05d %d %d\n", link[index].address, link[index].data, link[index].nxt);
        index = link[index].nxt;
    }
    return 0;
}
