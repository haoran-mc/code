/*----------------------------------------------------------------
 *
 *   文件名称：A.cpp
 *   创建日期：2020年09月25日 ---- 19时18分
 *   题    目：nowcoder
 *   算    法：<++>
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
int count = 0;
int realIndex[14];
map<char, int> mp;
map<char, bool> judge;
int minSubstr = 0;

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

int haveLike() {
    char ch;
    int first = 0;
    for (int i = 0; i < (int)input.length(); i++) {
        if (judge[input[i]] == true && first == 0) {
            //printf("%c %d\n", input[i], i);
            first = 1;
            ch = input[i];
            judge[input[i]] = false;
            quu += input[i];
            realIndex[mp[input[i]]] = i;
            count++;
            continue;
        }
        if (first == 1 && ch == input[i]) {
            //printf("%c %d\n", input[i], i);
            realIndex[mp[input[i]]] = i;
        }

        if (judge[input[i]] == true) {
            //printf("%c %d\n", input[i], i);
            first = 2;
            judge[input[i]] = false;
            quu += input[i];
            realIndex[mp[input[i]]] = i;
            count++;
        }
        if (count == 10) {
            minSubstr = realIndex[mp[quu[9]]] - realIndex[mp[quu[0]]] + 1;
            return i;
        }
    }
    return -1;
}

void minLike(int pointer) {
    char ch = quu[0];
    quu.erase(quu.begin());
    realIndex[mp[ch]] = 0;
    int pos = 0;
    pos = input.find(ch, pointer + 1);
    /*只要遇到是like中的字符就更新，因为可能他会成为quu[0]*/
    while (pos != (int)string::npos) {
        count = 0;
        realIndex[mp[ch]] = pos;
        int distance = pos - realIndex[mp[quu[0]]] + 1;
        if (distance < minSubstr)
            minSubstr = distance;

        quu += input[pos];
        ch = quu[0];
        quu.erase(quu.begin());
        realIndex[mp[ch]] = 0;
        pos = input.find(ch, pos + 1);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        cin >> input;
        init();
        int pointer = haveLike();
        if (pointer == -1)
            printf("-1\n");
        else {
            minLike(pointer);
            printf("%d\n", minSubstr);
        }

    }
    return 0;
}
