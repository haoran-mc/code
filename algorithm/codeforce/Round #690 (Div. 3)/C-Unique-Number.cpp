#include <cstdio>
#include <set>
#include <string>
#include <iostream>
using namespace std;
set<string> st;
string str;

void noremin(int x) {
    if (x >= 0 && x <= 9) {
        printf("%d", x);
        x = 0;
    }
    else if (x >= 10 && x <= 17) {
        st.insert("9");
        x -= 9;
        printf("%d", x);
    }
    else if (x >= 18 && x <= 24) {
        st.insert("9");
        st.insert("8");
        x -= 17;
        printf("%d", x);
    }
    else if (x >= 25 && x <= 30) {
        st.insert("9");
        st.insert("8");
        st.insert("7");
        x -= 24;
        printf("%d", x);
    }
    else if (x >= 31 && x <= 35) {
        st.insert("9");
        st.insert("8");
        st.insert("7");
        st.insert("6");
        x -= 30;
        printf("%d", x);
    }
    else if (x >= 36 && x <= 39) {
        st.insert("9");
        st.insert("8");
        st.insert("7");
        st.insert("6");
        st.insert("5");
        x -= 35;
        printf("%d", x);
    }
    else if (x >= 40 && x <= 42) {
        st.insert("9");
        st.insert("8");
        st.insert("7");
        st.insert("6");
        st.insert("5");
        st.insert("4");
        x -= 39;
        printf("%d", x);
    }
    else if (x >= 43 && x <= 44) {
        st.insert("9");
        st.insert("8");
        st.insert("7");
        st.insert("6");
        st.insert("5");
        st.insert("4");
        st.insert("3");
        x -= 42;
        printf("%d", x);
    }
    else if (x == 45) {
        st.insert("9");
        st.insert("8");
        st.insert("7");
        st.insert("6");
        st.insert("5");
        st.insert("4");
        st.insert("3");
        st.insert("2");
        st.insert("1");
    }
    else
        printf("-1\n");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    scanf("%d", &t);
    while (t--) {
        int x;
        scanf("%d", &x);
        noremin(x);
        for (auto it = st.begin(); it != st.end(); ++it)
            str += *it;
        cout << str << endl;
        st.clear();
        str.clear();
    }
    return 0;
}
