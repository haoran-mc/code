#include <cstdio>
#include <algorithm>
using namespace std;

int num[100000] = {0};

int main()
{
    int T;
    scanf("%d", &T);

    while (T--) {
        int n = 0;
        scanf("%d", &n);
        int zero   = -1;
        int mult   = 0;
        int record = 0;

        //input mysterious numbers
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);

        //sort mysterious numbers
        sort (num, num + n);

        //count the number of zero
        //chroose one of mult
        for (int i = 0; i < n; i++) {
            if (!num[i])
                zero++;
            else {
                mult = num[i];
                break;
            }
        }

        //operation parts of this product
        for (int i = n-1; i > zero; i--) {
            num[i] *= mult;
            num[i] += record;
            record  = 0;
            if (num[i] > 9) {
                record = num[i] / 10;
                num[i] %= 10;
            }
        }

        //首位进位记录
        if (record)
            printf("%d", record);

        //输出结果
        for (int i = zero; i < n; i++) {
            if (i == zero+1) {
                if (zero) {
                    for (int j = 0; j <= zero; j++, i++)
                        printf("0");
                }
            }
            printf("%d", num[i]);
        }


        if (T)
            printf("\n");
    }

    return 0;
}
