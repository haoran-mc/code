/*----------------------------------------------------------------
 *
 *   文件名称：C-单词记忆方法.cpp
 *   创建日期：2020年09月19日 ---- 21时49分
 *   题    目：nowcoder
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <map>
using namespace std;

typedef long long ill;
char S[100000];
int pointer = 0;
map<char, int> mp;

ill bracket() {

}

int main()
{
    char ch = 'a';
    for (int i = 0; i < 26; i++)
        mp[ch++] = ++i;

    scanf("%s", S);
}

