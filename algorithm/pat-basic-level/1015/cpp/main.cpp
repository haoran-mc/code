#include <algorithm>
#include <cstdio>
using namespace std;

const int maxn = 1e5 + 5;

struct Stu {
    int id;
    int de;  // 德
    int cai; // 才
    int sum;
    int type; // 才德全尽、德胜才、
} stu[maxn];

// stu1 在前、stu2 在后是否正确
bool cmp(Stu stu1, Stu stu2) {
    if (stu1.type != stu2.type) {
        return stu1.type < stu2.type;
    } else if (stu1.sum != stu2.sum) {
        return stu1.sum > stu2.sum;
    } else if (stu1.de != stu2.de) {
        return stu1.de > stu2.de;
    } else {
        return stu1.id < stu2.id;
    }
}

int main() {
    int n, l, h;
    scanf("%d %d %d", &n, &l, &h);

    int m = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &stu[i].id, &stu[i].de, &stu[i].cai);
        stu[i].sum = stu[i].de + stu[i].cai;
        if (stu[i].de < l || stu[i].cai < l) {
            stu[i].type = 5; // 不录取
            continue;
        }

        m++;

        if (stu[i].de >= h && stu[i].cai >= h) {
            stu[i].type = 1;
        } else if (stu[i].de >= h && stu[i].cai < h) {
            stu[i].type = 2;
        } else if (stu[i].de >= stu[i].cai && stu[i].de < h && stu[i].cai < h) {
            // ↑ 这里有坑，de >= cai，而不是 de > cai
            stu[i].type = 3;
        } else {
            stu[i].type = 4;
        }
    }

    sort(stu, stu + n, cmp);

    printf("%d\n", m);
    for (int i = 0; i < m; i++) {
        if (i == m - 1) {
            printf("%d %d %d", stu[i].id, stu[i].de, stu[i].cai);
        } else {
            printf("%d %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
        }
    }
    return 0;
}
