#include<iostream>
#include<cstring>
#include<string>
using namespace std;

void B(string str, long long length, char map[]) {
    int index_i, index_j, index;
    char ch;
    int flag;
    for(int i = length-1; i >= 0; i--) {
        ch = str[i];
        index_i = i;
        flag = 0;
        for(int j = i; j >=0; j--) {
            index_j = j;
            if(str[j] == ch) {
                flag = 1;
                index = index_i - index_j;
                //将长整型数变为字符串函数
                //map[i] = ?;//存入
            }
        }
        if(flag == 0) {
            map[i] = '0';
        }
    }
}

int main()
{
    long long length;
    string str;
    cin >> length >> str;
    char map[length][length];
    // for(long long i = 0; i < length; i++) {
    //     for(long long j = 0; j < length; j++) {
    //         map[i][j] = -1;
    //     }
    // }
    B(str, str.length(), map[0]);
    for(long long i = 0; i <= length; i++) {
        str.erase(0,1);
        B(str, str.length(), map[i+1]);
    }
    //创建函数排序
    //输出
    return 0;
}