/*----------------------------------------------------------------
 *   
 *   文件名称：01.cpp
 *   创建日期：2021年08月05日 星期四 20时13分01秒
 *   题    目：AcWing 0129 火车进栈
 *   算    法：栈
 *   描    述：<++>
 *
 ----------------------------------------------------------------*/

#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
#define NEXTLINE puts("");
vector<int> state1;
stack<int> state2;
int state3 = 1;
int n, cnt = 20;  // 只要求输出20个

/**
 *    [state1]                                [state3]
 *           __________      |      |     ____________
 *                   |       |      |      |
 *                   V       |      |      V
 *  这里是已出栈的数可以用   |      |     这里是还未进栈的数，用一个int变量
 *  一个vector表示这个状态   |      |     就可以表示这个状态
 *                           |      |
 *                           |      |
 *                           |      |   [state2]
 *                           |      |   用一个栈结构表示栈中的状态
 *                           |------|
 *
 */


void DFS() {
    if (!cnt)
        return;
    if (state1.size() == n) {
        cnt--;
        for (auto x: state1)
            printf("%d", x);
        NEXTLINE;
        return;
    }
    // 为什么先运行state2再运行state3，是为了字典序
    if (state2.size()) {
        state1.push_back(state2.top());
        state2.pop();
        DFS();
        state2.push(state1.back());
        state1.pop_back();
    }
    if (state3 <= n) {
        state2.push(state3);
        state3++;
        DFS();
        state3--;
        state2.pop();
    }
}

int main() {
    scanf("%d", &n);
    DFS();
    return 0;
}
