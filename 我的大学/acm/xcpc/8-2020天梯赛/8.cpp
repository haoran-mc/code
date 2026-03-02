#include <cstdio>
bool hash[10];
int arr[4][4];
void coin(int elect) {
    int res = 0;
    if (elect == 1)
        for (int i = 1; i < 4; ++i)
            res += arr[1][i];
    else if (elect == 2)
        for (int i = 1; i < 4; ++i)
            res += arr[2][i];
    else if (elect == 3)
        for (int i = 1; i < 4; ++i)
            res += arr[3][i];
    else if (elect == 4)
        for (int i = 1; i < 4; ++i)
            res += arr[i][1];
    else if (elect == 5)
        for (int i = 1; i < 4; ++i)
            res += arr[i][2];
    else if (elect == 6)
        for (int i = 1; i < 4; ++i)
            res += arr[i][3];
    else if (elect == 7)
        res = arr[1][1] + arr[2][2] + arr[3][3];
    else if (elect == 8)
        res = arr[1][3] + arr[2][2] + arr[3][1];
    switch(res) {
        case 6: printf("10000");break;
        case 7: printf("36");break;
        case 8: printf("720");break;
        case 9: printf("360");break;
        case 10: printf("80");break;
        case 11: printf("252");break;
        case 12: printf("108");break;
        case 13: printf("72");break;
        case 14: printf("54");break;
        case 15: printf("180");break;
        case 16: printf("72");break;
        case 17: printf("180");break;
        case 18: printf("119");break;
        case 19: printf("36");break;
        case 20: printf("306");break;
        case 21: printf("1080");break;
        case 22: printf("144");break;
        case 23: printf("1800");break;
        case 24: printf("3600");break;
    }
}
int main()
{
    for (int i = 1; i < 4; ++i)
        for (int j = 1; j < 4; ++j) {
            scanf("%d", &arr[i][j]);
            hash[arr[i][j]] = true;
        }
    int num;
    for (int i = 1; i < 10; ++i)
        if (!hash[i])
            num = i;
    for (int i = 1; i < 4; ++i)
        for (int j = 1; j < 4; ++j)
            if (!arr[i][j])
                arr[i][j] = num;
    for (int i = 0; i < 3; ++i) {
        int x;
        int y;
        scanf("%d", &x);
        scanf("%d", &y);
        printf("%d\n", arr[x][y]);
    }
    int elect;
    scanf("%d", &elect);
    coin(elect);
    return 0;
}
