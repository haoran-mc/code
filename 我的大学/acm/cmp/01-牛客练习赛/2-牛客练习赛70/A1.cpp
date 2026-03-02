/*----------------------------------------------------------------
 *
 *   文件名称：A1.cpp
 *   创建日期：2020年09月25日 ---- 21时20分
 *   题    目：nowcoder
 *   算    法：贪心
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
using namespace std;

string like = "puleyaknoi";
string input;
string quu;
int realIndex[14];
map<char, int> mp;
map<char, bool> judge;

/*初始化judge与mp两组映射*/
void init() {
    int ch = 'a';
    for (int i = 0; i < 26; i++, ch++) {
        mp[ch] = -1;
        judge[ch] = false;
    }

    int cnt = 0;
    for (int i = 0; i < (int)like.length(); i++) {
        mp[like[i]] = cnt++;
        judge[like[i]] = true;
    }
}

/*单纯判断是否有自己喜欢的字串*/
int Func1() {
    int count = 0;
    for (int i = 0; i < (int)input.length(); i++) {
        if (judge[input[i]] == true) {
            judge[input[i]] = false;
            count++;
        }
        if (count == 10) {
            return 1;
        }
    }
    return -1;
}

/*找到最小字串*/
int Func2() {
    int minSubstr = 0;
    int count = 1;
    int index;
    /*第一个喜欢的字串*/
    char ch1;
    char ch2;
    for (int i = 0; i < (int)input.length(); i++) {
        if (mp[input[i]] != -1) {
            ch1 = input[i];
            quu += input[i];
            realIndex[mp[input[i]]] = i;
            break;
        }
    }
    for (int i = 0; i < (int)input.length(); i++) {
        if (mp[input[i]] != -1 && ch1 == input[i]) {
            realIndex[mp[input[i]]] = i;
        }
        else if (mp[input[i]] != -1) {
            ch1 = input[i];
            quu += input[i];
            count++;
        }
        if (count == 10) {
            minSubstr = realIndex[mp[quu[9]]] - realIndex[mp[quu[0]]] + 1;
            index = i;
            break;
        }
    }
    /*继续寻找，找到最小的字串*/
    for (int i = index+1; i < (int)input.length(); i++) {
        if (ch1 == input[i]) {
            realIndex[mp[input[i]]] = i;
        }
        if (input[i] == quu[0]) {
            ch2 = quu[0];
            quu.erase(quu.begin());
            quu += ch2;
            /*突然发现，如果现在需要寻找a，而遇到的是b，恰巧
             * 以b开头的字串是最短的，没法用这段代码处理*/
        }
    }
    return minSubstr;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        cin >> input;
        init();
        if (Func1() == -1)
            printf("-1\n");
        else {
            int ans = Func2();
            printf("%d\n", ans);
        }

        /*
         *int pointer = haveLike();
         *if (pointer == -1)
         *    printf("-1\n");
         *else {
         *    minLike(pointer);
         *    printf("%d\n", minSubstr);
         *}
         */
    }
    return 0;
}
