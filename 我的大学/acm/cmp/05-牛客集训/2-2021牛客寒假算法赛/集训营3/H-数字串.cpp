#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
string str;

void R(int pos) {
    switch (str[pos] - 'a' + 1) {
        case 11: str.replace(pos, 1, "aa"); break;
        case 12: str.replace(pos, 1, "ab"); break;
        case 13: str.replace(pos, 1, "ac"); break;
        case 14: str.replace(pos, 1, "ad"); break;
        case 15: str.replace(pos, 1, "ae"); break;
        case 16: str.replace(pos, 1, "af"); break;
        case 17: str.replace(pos, 1, "ag"); break;
        case 18: str.replace(pos, 1, "ah"); break;
        case 19: str.replace(pos, 1, "ai"); break;
        case 21: str.replace(pos, 1, "ba"); break;
        case 22: str.replace(pos, 1, "bb"); break;
        case 23: str.replace(pos, 1, "bc"); break;
        case 24: str.replace(pos, 1, "bd"); break;
        case 25: str.replace(pos, 1, "be"); break;
        case 26: str.replace(pos, 1, "bf"); break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> str;
    int flag = 0;
    for (int i = 0; i < (int)str.length(); ++i)
        if (str[i] > 'j' && str[i] != 't') {
            ++flag;
            R(i);
            if (flag == 13)
                break;
        }
    if (!flag) {
        int pos;
        pos = str.find("aa");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "k");
            goto loop;
        }
        pos = str.find("ab");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "l");
            goto loop;
        }
        pos = str.find("ac");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "m");
            goto loop;
        }
        pos = str.find("ad");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "n");
            goto loop;
        }
        pos = str.find("ae");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "o");
            goto loop;
        }
        pos = str.find("af");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "p");
            goto loop;
        }
        pos = str.find("ag");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "q");
            goto loop;
        }
        pos = str.find("ah");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "r");
            goto loop;
        }
        pos = str.find("ai");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "s");
            goto loop;
        }
        pos = str.find("ba");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "u");
            goto loop;
        }
        pos = str.find("bb");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "v");
            goto loop;
        }
        pos = str.find("bc");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "w");
            goto loop;
        }
        pos = str.find("bd");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "x");
            goto loop;
        }
        pos = str.find("be");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "y");
            goto loop;
        }
        pos = str.find("bf");
        if (pos != (int)string::npos) {
            ++flag;
            str.replace(pos, 2, "z");
            goto loop;
        }
    }

loop:
    if (!flag) cout << "-1" << endl;
    else cout << str << endl;

    return 0;
}
