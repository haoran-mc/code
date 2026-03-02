/*----------------------------------------------------------------
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
 *   文件名称：1092 To Buy or Not to Buy.cpp
 *   创建日期：2020年08月10日
 *   题    目：To Buy or Not to Buy
 *   描    述：散列，进制转换 -> 字符串hash同步
 *
 * •••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <cstring>

char str_shop[1001];
char str_eva[1001];
int hash_shop[62];
int hash_eva[62];
int flag = 0;
int diff = 0;

void hashFunc(int hash[], char str[], int len) {
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            hash[str[i] - 'A']++;
        else if (str[i] >= 'a' && str[i] <= 'z')
            hash[str[i] - 'a' + 26]++;
        else
            hash[str[i] - '0' + 52]++;
    }
}

void compare(int hash_shop[], int hash_eva[]) {
    for (int i = 0; i < 62; i++) {
        if (hash_shop[i] < hash_eva[i]) {
            if (!flag)
                diff = 0;

            flag = 1;
            diff += (hash_eva[i] - hash_shop[i]);
        }
        else
            if (!flag)
                diff += (hash_shop[i] - hash_eva[i]);
    }
}

int main()
{
    scanf("%s", str_shop);
    scanf("%s", str_eva);
    hashFunc(hash_shop, str_shop, strlen(str_shop));
    hashFunc(hash_eva,  str_eva,  strlen(str_eva));
    compare(hash_shop, hash_eva);

    if (flag)   printf("No");
    else        printf("Yes");

    printf(" %d", diff);
    return 0;
}

