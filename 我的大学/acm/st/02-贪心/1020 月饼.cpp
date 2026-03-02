/*----------------------------------------------------------------
 *
 *   文件名称：1020 月饼.cpp
 *   创建日期：2020年08月26日 ---- 10时08分
 *   结束日期：2020年08月26日 ---- 23时08分
 *   题    目：月饼
 *   算    法：贪心
 *   描    述：使用struct结构体将库存量，总价格，单价联系起来
 *             只是正数而不是整数，使用double
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <algorithm>

struct moon_cake{
    double stock;
    double price;
    double unit_price;
} cake[1001];

bool cmp(moon_cake A, moon_cake B) {
    return A.unit_price > B.unit_price;
}

int main() {
    int var;
    int dem;
     scanf("%d", &var);
     scanf("%d", &dem);
     for (int i = 0; i < var; i++)
         scanf("%lf", &cake[i].stock);
     for (int i = 0; i < var; i++)
         scanf("%lf", &cake[i].price);
     for (int i = 0; i < var; i++)
         cake[i].unit_price = cake[i].price / cake[i].stock;
     std::sort(cake, cake + var, cmp);

     double sum = 0;
     for (int i = 0; i < var; i++) {
         if (cake[i].stock < dem) {
             dem -= cake[i].stock;
             sum += cake[i].price;
         }
         else {
             sum += (dem * cake[i].unit_price);
             break;
         }
     }
     printf("%.2f\n", sum);
     return 0;
}

