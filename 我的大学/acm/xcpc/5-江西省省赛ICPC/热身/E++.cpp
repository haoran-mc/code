/*#include  < bits/stdc++.h > */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
int coin[100], v[100], n, len, cnt;

bool dfs(int stick, int cab, int last){
    if (stick > cnt) //可以
        return true;
    if (cab == len)
        return dfs(stick+1, 0, 1);
    int fail = 0;
    for (int i = last; i <= n; i++){
        if (!v[i] && cab+coin[i] <= len && fail != coin[i]){
            v[i] = 1;
            if (dfs(stick, cab+coin[i], i+1))
                return true;
            fail = coin[i];
            v[i] = 0;
            if (cab == 0 || cab+coin[i] == len)
                return false;
        }
    }
    return false;
}

int main(){
    int t;
    scanf("%d",  &t);
    while (t--){
        scanf("%d",  &n);
        int sum = 0;
        int val = 0;
        for (int i = 1; i <= n; i++){
            scanf("%d", &coin[i]);
            sum += coin[i];          //金币总和
            val = max(val, coin[i]); //金币最大值
        }
        sort(coin+1, coin+1+n);      //金币排序
        reverse(coin+1, coin+1+n);   //倒转
        for (len = val; len <= sum; len++){ //从最大值到总和遍历
            if (sum % len)           //如果len是sum的因子，说明不可以，continue
                continue;
            cnt = sum / len;         //cnt是什么？sum/len
            memset(v, 0, sizeof(v)); //每次都更改了，所以变回来
            if (dfs(1, 0, 1))        //如果不是0，说明找到了
                break;
        }
        printf("%d\n", len);
    }
}
