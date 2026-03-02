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

int main()
{
    int var;
    int dem;
     scanf("%d", &var);
     scanf("%d", &dem);
     for (int i = 0; i < var; i++)
         scanf("%lf", &cake[i].stock);
     for (int i = 0; i < var; i++)
         scanf("%lf", &cake[i].price);
     for (int i = 0; i < var; i++)
         cake[i].unit_price = (double)cake[i].price / (double)cake[i].stock;
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


