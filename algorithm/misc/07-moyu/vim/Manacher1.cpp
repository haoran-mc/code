#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> radius, expand_str;

int Manacher(const string &str) {
    int original_len = str.length();
    int expand_len = (original_len + 1) << 1;
    int max_len = 0;

    radius.resize(expand_len + 1);
    expand_str.resize(expand_len +1);

    expand_str[0] = '@';
    expand_str[1] = '#';
    expand_str[expand_len] = '$';

    for (int i = 1; i <= original_len; i++) {
        expand_str[i << 1] = str[i - 1];
        expand_str[i << 1 | 1] = '#';
    }

    radius[1] = 1;
    for (int max_right = 0, center = 0, i = 2; i < expand_len; i++) {
        if (i < max_right)
            radius[i] = min(max_right - i, radius[2 * center - i]);
        else
            radius[i] = 1;

        while (expand_str[i - radius[i]] == expand_str[i + radius[i]])
            radius[i]++;

        if (radius[i] + i > max_right) {
            max_right = radius[i] + i;
            center = i;
        }

        max_len = max(max_len, radius[i] - 1);
    }

    return max_len;
}

int main()
{
    string str = "BABCBAA";
    int max_len = Manacher(str);
    printf("%d\n", max_len);

    cout << str << endl;

    return 0;
}
