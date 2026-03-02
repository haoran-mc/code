/*----------------------------------------------------------------
 *
 *   文件名称：1024.cpp
 *   创建日期：2020年11月02日 ---- 19时37分
 *   结束日期：2020年11月02日 ---- 20时39分
 *   题    目：PAT
 *   算    法：<++>
 *   描    述：<++>
 *
----------------------------------------------------------------*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string input;
    cin >> input;
    int ptr1 = 0;
    int ptr2 = 0;
    for (int i = 0; i < (int)input.length(); ++i)
        if (input[i] == 'E')
            ptr1 = i;

    ptr2 = ptr1 + 2;
    int judge = ptr1 + 1;
    int expo  = 0;

    while (ptr2 != (int)input.length()) {
        expo = 10 * expo + (input[ptr2] - '0');
        ++ptr2;
    }
    if (input[judge] == '+') {
        if (expo == ptr1 - 3) {
            for (int i = 0; i < ptr1; ++i)
                if (i != 2 && input[i] != '+')
                    cout << input[i];
        }
        else if (expo > ptr1 - 3) {
            for (int i = 0; i < ptr1; ++i)
                if (i != 2 && input[i] != '+')
                    cout << input[i];
            for (int j = 0; j < expo-1; ++j)
                cout << '0';
        }
        else {
            int i;
            for (i = 0; input[i] != '.'; ++i)
                if (input[i] != '+')
                    cout << input[i];
            for (int j = 0; j < expo; ++i, ++j)
                cout << input[i+1];
            cout << '.';
            for (; i < ptr1 - 1; ++i)
                cout << input[i+1];
        }
    }
    else {
        if (input[0] == '-')
            cout << '-';
        cout << "0.";
        for (int i = 0; i < expo - 1; ++i)
            cout << '0';

        for (int i = 1; i < ptr1; ++i)
            if (i != 2 && input[i] != '+')
                cout << input[i];
    }
    return 0;
}
