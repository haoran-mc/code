#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct infos {
    string name;
    string ID;
    bool sta;
    int h;
    int m;
    int i;
    int day;
}info[1005];
vector<infos> vec;
bool cmp(infos info1, infos info2) {
    return info1.h == info2.h ? info1.m == info2.m ? info1.i < info2.i : info1.m < info2.m : info1.h < info2.h;
}
int main()
{
    int D;
    int P;
    scanf("%d", &D);
    scanf("%d", &P);
    for (int j = 0; j < D; ++j) {
        int T;
        int S;
        scanf("%d", &T);
        scanf("%d", &S);
        for (int i = 0; i < T; ++i) {
            cin >> info[i].name;
            cin >> info[i].ID;
            cin >> info[i].sta;
            scanf("%d:%d", &info[i].h, &info[i].m);
            info[i].i = i;
            bool flag = false;
            if (info[i].sta == true) {
                for (auto it = vec.begin(); it != vec.end(); ++it)
                    if (*it.name == info[i].name)
                        flag = true;
                if (flag == false)
                    vec.push_back(info[i]);
            }
        }
        sort(info, info+T, cmp);
        for (int i = 0; i < T; ++i)
            if (info[i].day == 0 || info[i].day <= j-P-1)
                cout << info[i].name << " " << info[i].ID << endl;
    }
    for (auto it = vec.begin(); it != vec.end(); ++it)
        cout << *it.name << " " << *it.ID << endl;
    return 0;
}
