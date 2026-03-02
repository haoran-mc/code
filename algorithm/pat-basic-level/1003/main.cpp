// P前面A的个数 * PT中间A的个数 = T后面A的个数
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    while (n--) {
        string input;
        cin >> input;

        bool flag = 0;
        for (int i = 0; i < input.length(); i++) {
            if (input[i] != 'P' && input[i] != 'A' && input[i] != 'T') {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "NO" << endl;
            continue;
        }

        if (input.find("P") == string::npos ||
            input.find("T") == string::npos ||
            input.find("A") == string::npos) {
            cout << "NO" << endl;
            continue;
        }
        int p_pos = input.find("P");
        int t_pos = input.find("T", p_pos);
        int p_cnt = count(input.begin(), input.end(), 'P');
        int t_cnt = count(input.begin(), input.end(), 'T');
        int a = p_pos;
        int b = t_pos - p_pos - 1;
        int c = input.length() - t_pos - 1;

        // P 和 T 只能有一个
        // P前面A的个数 * PT中间A的个数 = T后面A的个数
        if (b == 0 || p_cnt > 1 || t_cnt > 1 || a * b != c) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
