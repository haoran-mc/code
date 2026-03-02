#include<iostream>
#include<algorithm>
using namespace std;

struct Goods {
    int id;
    float weight;
    float value;
    float per_item_value;
    float rate;   //使用率
};

bool cmp(Goods a, Goods b) {
    return a.per_item_value > b.per_item_value;
}

Goods goods[100];   // 最多可以有 100 件商品
float rate[100];

int main() {
    int n;     // n个物品
    float m;   // 背包容量为m
    scanf("%d %f", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d %f %f", &goods[i].id, &goods[i].value, &goods[i].weight);
        goods[i].per_item_value = goods[i].value / goods[i].weight;   // 计算性价比
        goods[i].rate = 0;   // 初始化使用率
    }

    sort(goods, goods + n, cmp);   // 按性价比排序

    int j = 0;
    for (j = 0; j < n; j++) {
        if (goods[j].weight <= m) {
            goods[j].rate = 1;
            m -= goods[j].weight;
            // 重量为：价值为：比例
            rate[goods[j].id] = goods[j].rate;
        }
        else
            break;
    }
    // 物品没装完
    if (j < n) {
        goods[j].rate = m / goods[j].weight;
        m = 0;
        rate[goods[j].id] = goods[j].rate;
    }
    for (int i = 1; i <= n; i ++ ) {
        printf("%.2f ", rate[i]);
    }
    return 0;
}

