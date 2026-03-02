#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

char* low(char string[]){
    int i;
    for (i = 0; string[i] != '\0'; i++){
        // if (string[i] >= 'a' && string[i] <= 'z'){
        //     string[i] = string[i] - 32;
        // }
        if (string[i] >= 'A' && string[i] <= 'Z'){
            string[i] = string[i] + 32;
        }
    }
    return string;
}

int main()
{
    char str[10];
    char str0[10] = "lovely";
    int flag = 0;
    while(scanf("%s", str) != EOF) {
        flag = 0;
        strcpy(str, low(str));

        for (int i = 0; i < 6; i++) {
            if (str[i] != str0[i] ){
                flag = 1;
                printf("ugly\n");
                break;
            }
        }
        if (flag == 0)
        printf("lovely\n");
    }
    return 0;
}
