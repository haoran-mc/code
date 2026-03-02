//枚举子串，枚举中心，二分+字符串哈希，Manacher
//优化枚举中心向外扩张的暴力算法
//d数组，di表示以位置i为中心最长回文子串边界到中心的距离，也就是回文串的半径
//S数组，当前已知最右回文子串

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 建了三个数组？
vector <int> radius, let;
string expand_str;

// int Manacher(string str) {
int Manacher(const string &str) {
    // str = "BABCBAA";
    // 0 1 2 3 4 5 6
    // original_len = 7

    int original_len /* Original length */ = str.length();
    // 新串需要额外空间存放插入字符
    // expand_len = 16
    int expand_len = (original_len + 1) << 1;
    int max_len = 0;

    // 使用resize()，否则需要使用push_back()
    radius.resize(expand_len + 1);
    expand_str.resize(expand_len + 1);

    // @ - 串开始标记， $ - 串结束标记，# - 将字母间隔开。注意这里的字符必须是字符串内不存在的
    // 开始符与结束符不同，否则可能使回弯半径增一
    expand_str[0] = '@';
    expand_str[1] = '#';
    expand_str[expand_len] = '$';

    for (int i = 1; i <= original_len; i++) {
        expand_str[i << 1] = str[i - 1];
        // expand_str[(2 * i) + 1] = '#';
        expand_str[i << 1 | 1] = '#';
    }

    // Manacher 操作。max_right, center 分别维护当前最右回文串的右边界与中心
    radius[1] = 1;
    for (int max_right = 0, center = 0, i = 2; i < expand_len; i++){
        if (i < max_right)
            radius[i] = min(max_right - i, radius[2 * center - i]);
        else
            radius[i] = 1; // Manacher 核心操作

        while (expand_str[i - radius[i]] == expand_str[i + radius[i]])
            radius[i]++; // 暴力向外扩展

        if (radius[i] + i > max_right) {
            max_right = radius[i] + i; // 尝试更新 max_right, center
            center = i;
        }

        max_len = max(max_len, radius[i] - 1); // 更新答案
    }
    return max_len;
}

//知道回文中心，且在build函数运行结束后使用
int start_mid(int x, bool odd) {
    if (odd)
        return radius[(x + 1) << 1] - 1;

    return radius[(x + 1) << 1 | 1] - 1;
}

//知道回文左边界，且在build函数运行结束后使用
int start_left(int x, string str) {
    int expand_len = (str.length() + 1) << 1;
    let.resize(expand_len + 1);


    // 计算维护以每个位置为起点的最长回文串
    for (int i = 0; i <= expand_len; i++)
        let[i] = 0;

    for (int i = 2; i < expand_len; i++)
        if (let[i - radius[i] + 1] < i + 1)
            let[i - radius[i] + 1] = i + 1;

    for (int i = 1; i <= expand_len; i++)
        if (let[i] < let[i - 1])
            let[i] = let[i - 1];

    return let[(x + 1) << 1] - ((x + 1) << 1);
}

int main()
{
    string str = "DDDDBBDBABCBAABBAAABCB";
    int max_len = Manacher(str);
    printf("%d\n", max_len);

    // true 奇回文串
    int radius = start_mid(14, false);
    printf("%d\n", radius);

    max_len = start_left(13, str);
    printf("%d\n", max_len);
    //for (auto it = let.begin(); it != let.end(); ++it)
        //printf("%d\n", *it);
    cout << str << endl;
    return 0;
}
